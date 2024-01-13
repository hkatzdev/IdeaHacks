const int HYGROMIN = 400;
const int HYGROMAX = 1023;
const int UPPER = 100;
const int LOWER = 0;

const int hygrometer_1 = A0;
const int hygrometer_2 = A1;
const int hygrometer_3 = A2;
int hygrometer_val;

int moisturePercent(int value){
  return map(constrain(value, HYGROMIN, HYGROMAX), HYGROMIN, HYGROMAX, UPPER, LOWER);
}

int printHydrogmeter(int hygrometer){
    hygrometer_val = moisturePercent(analogRead(hygrometer));
    switch(hygrometer){
      case A0:
        Serial.print("Lvl 1 Moisture:");
        break;
      case A1:
        Serial.print("Lvl 2 Moisture:");
        break;
      case A2:
        Serial.print("Lvl 3 Moisture:");
        break;
  }
  Serial.print(hygrometer_val);
  Serial.print("%\n");
  delay(1000);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  printHydrogmeter(hygrometer_1);
  printHydrogmeter(hygrometer_2);
  printHydrogmeter(hygrometer_3);
  // put your main code here, to run repeatedly:
  
}
