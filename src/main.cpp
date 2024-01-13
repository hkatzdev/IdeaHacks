
/**************************************************************************/
/*!
This is a demo for the Adafruit MCP9808 breakout
----> http://www.adafruit.com/products/1782
Adafruit invests time and resources providing this open source code,
please support Adafruit and open-source hardware by purchasing
products from Adafruit!
*/
/**************************************************************************/

#include <Wire.h>
#include "Adafruit_MCP9808.h"

// Create the MCP9808 temperature sensor object
Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();

void setup() {
  Serial.begin(9600);
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
  // Mode Resolution SampleTime
  //  0    0.5°C       30 ms
  //  1    0.25°C      65 ms
  //  2    0.125°C     130 ms
  //  3    0.0625°C    250 ms
}

void printTemp(uint8_t addr, int level){
  tempsensor.begin(addr);
  tempsensor.wake();

  // Serial.println (tempsensor.getResolution());
  Serial.println(level);
  float c = tempsensor.readTempC();
  float f = tempsensor.readTempF();
  Serial.print("Temp: "); 
  Serial.print(c, 2); Serial.print("*C\t and "); 
  Serial.print(f, 2); Serial.println("*F.");
  
  delay(1000);
  // Serial.println("Shutdown MCP9808.... ");
  tempsensor.shutdown_wake(1); // shutdown MSP9808 - power consumption ~0.1 mikro Ampere, stops temperature sampling
  Serial.println("");
  delay(200);
}

void loop() {
  printTemp(0x18, 1);
  printTemp(0x19, 2);
  printTemp(0x1A, 3);
}
