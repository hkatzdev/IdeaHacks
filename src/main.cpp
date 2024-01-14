#include <SPI.h>
#include <WiFiNINA.h>
#include <Firebase_Arduino_WiFiNINA.h>

#include <Wire.h>
#include "Adafruit_MCP9808.h"
#include <LiquidCrystal.h>

#define FIREBASE_HOST "arduinodatatable-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "7PN0ud9CO7QfEjeDzuyD2qrTxwlrS8TXpfNWUoO0"

const int HYGROMIN = 400;
const int HYGROMAX = 1023;
const int UPPER = 100;
const int LOWER = 0;

const int rs = 7;
const int en = 8;
const int d4 = 9;
const int d5 = 10;
const int d6 = 11;
const int d7 = 12;

const int POWER_HYGRO_1 = 2;
const int POWER_HYGRO_2 = 3;
const int POWER_HYGRO_3 = 4;

float temperature;
int moisture;

Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char ssid[] = "IEEE";
char pass[] = "Ilovesolder";

int status = WL_IDLE_STATUS;  

WiFiClient wifiClient;

FirebaseData firebaseData;

void setup() {
  Serial.begin(9600);

  /*normal set up begin*/

  lcd.begin(16,2);
  pinMode(POWER_HYGRO_1, OUTPUT);
  pinMode(POWER_HYGRO_2, OUTPUT);
  pinMode(POWER_HYGRO_3, OUTPUT);

  digitalWrite(POWER_HYGRO_1, HIGH);

  while (!Serial); //waits for serial terminal to be open, necessary in newer arduino boards.
  Serial.println("MCP9808 3 Sensor");
  
  if (!tempsensor.begin(0x18)) {
    Serial.println("Couldn't find MCP9808! #1 Check your connections and verify the address is correct.");
    while (1);
  }
  if (!tempsensor.begin(0x19)) {
    Serial.println("Couldn't find MCP9808! #2 Check your connections and verify the address is correct.");
    while (1);
  }
  if (!tempsensor.begin(0x1A)) {
    Serial.println("Couldn't find MCP9808! #3 Check your connections and verify the address is correct.");
    while (1);
  }
    
   Serial.println("Found all MCP9808!");

  tempsensor.setResolution(3);
  
  /*normal set up end*/

  delay(10);

  // Connect to WiFi
  WiFi.begin(ssid, pass);
  // while (WiFi.status() != WL_CONNECTED) {
  //   delay(1000);
  //   Serial.println("Connecting to WiFi...");
  // }
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);
    // wait 10 seconds for connection:
    delay(10000);
  }

  Serial.println("Connected!");

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH, ssid, pass);

  Serial.println("BASED!!!");
}

void loop() {
  // Read L1
  temperature = readTemperature(0x18);
  moisture = readMoisture(A0);
  displayLevel(moisture, temperature, 1);

  // Send L1 to Firebase
  sendToFirebase("temperature", temperature);
  sendToFirebase("moisture", moisture);

  delay(5000); // Send data every 5 seconds

  lcd.clear();

  // Read L2
  temperature = readTemperature(0x19);
  moisture = readMoisture(A1);
  displayLevel(moisture, temperature, 1);

  // Send L2 to Firebase
  sendToFirebase("temperature", temperature);
  sendToFirebase("moisture", moisture);

  delay(5000); // Send data every 5 seconds

  // Read L3
  temperature = readTemperature(0x1A);
  moisture = readMoisture(A2);
  displayLevel(moisture, temperature, 1);

  // Send L3 to Firebase
  sendToFirebase("temperature", temperature);
  sendToFirebase("moisture", moisture);

  delay(5000); // Send data every 5 seconds
}

void displayLevel(int moisture, int temper_F, int level){
  lcd.setCursor(0,0);
  lcd.print("L"); lcd.print(level); lcd.print(" Moist: "); lcd.print(moisture); lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("   Temp: "); lcd.print(temper_F); lcd.print(" F");
}

float readTemperature(uint8_t temper_addr) {
  tempsensor.begin(temper_addr);
  tempsensor.wake();
  float f = tempsensor.readTempF();
  tempsensor.shutdown_wake(1);
  return f;
}

int readMoisture(uint8_t hygro_analog) {
  int mp;
  switch(hygro_analog){
    case A0:
      digitalWrite(POWER_HYGRO_2, HIGH);
      mp = getMoisturePercent(analogRead(hygro_analog));
      delay(500);
      digitalWrite(POWER_HYGRO_1, LOW);
    break;
    case A1:
      digitalWrite(POWER_HYGRO_3, HIGH);
      mp = getMoisturePercent(analogRead(hygro_analog));
      delay(500);
      digitalWrite(POWER_HYGRO_2, LOW);
    break;
    case A2:
      digitalWrite(POWER_HYGRO_1, HIGH);
      mp = getMoisturePercent(analogRead(hygro_analog));
      delay(500);
      digitalWrite(POWER_HYGRO_3, LOW);
    break;  
  }
  return mp;
}

int getMoisturePercent(int value){
  return map(constrain(value, HYGROMIN, HYGROMAX), HYGROMIN, HYGROMAX, UPPER, LOWER);
}

void sendToFirebase(const char* sensorType, float value) {
  String path = "/sensors/" + String(sensorType);
  Firebase.setFloat(firebaseData, path.c_str(), value);
}
