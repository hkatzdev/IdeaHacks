const int HYGROMIN = 400;
const int HYGROMAX = 1023;
const int UPPER = 100;
const int LOWER = 0;

#include <Wire.h>
#include "Adafruit_MCP9808.h"
#include <LiquidCrystal.h>
/*
* Ports for the LCD
*/
const int rs = 7;
const int en = 8;
const int d4 = 9;
const int d5 = 10;
const int d6 = 11;
const int d7 = 12;

const int POWER_HYGRO_1 = 2;
const int POWER_HYGRO_2 = 3;
const int POWER_HYGRO_3 = 4;

// Create the MCP9808 temperature sensor object
Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int hygrometer_1 = A0;
const int hygrometer_2 = A1;
const int hygrometer_3 = A2;
float temperature_F;
int moisture_percent;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
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

  tempsensor.setResolution(3); // sets the resolution mode of reading, the modes are defined in the table bellow:
}

void loop() {
  moisture_percent = readHygrometer(A0);
  temperature_F = readTemperature(0x18);
  displayLevel(moisture_percent, temperature_F, 1);
  
  moisture_percent = readHygrometer(A1);
  temperature_F = readTemperature(0x19);
  displayLevel(moisture_percent, temperature_F, 2);

  moisture_percent = readHygrometer(A2);
  temperature_F = readTemperature(0x1A);
  displayLevel(moisture_percent, temperature_F, 3);
  
}

void displayLevel(int moisture_percent, int temper_F, int level){
  lcd.setCursor(0,0);
  lcd.print("L"); lcd.print(level); lcd.print(" Moist: "); lcd.print(moisture_percent); lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("   Temp: "); lcd.print(temper_F); lcd.print(" F");
  delay(1500);
  lcd.clear();
}

void printLevel(int moisture_percent, int temper_F, int level){
  Serial.print("L"); Serial.print(level); Serial.print(" Moist: "); Serial.print(moisture_percent); Serial.println("%");
  Serial.print("   Temp: "); lcd.print(temper_F); lcd.println(" F\n");
  delay(1500);
}

float readTemperature(uint8_t temper_addr){
  tempsensor.begin(temper_addr);
  tempsensor.wake();
  float f = tempsensor.readTempF();
  tempsensor.shutdown_wake(1);
  return f;
}

int readHygrometer(uint8_t hygro_analog){
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
