

#include <NewPing.h>

const int EchoPinC = 53;
const int TriggerPinC = 52;

const int EchoPinL = 47;
const int TriggerPinL = 46;

const int EchoPinR = 45;
const int TriggerPinR = 44;

const int EchoPinMr = 43;
const int TriggerPinMr = 42;

const int EchoPinMl = 41;
const int TriggerPinMl = 40;



NewPing usensorC(TriggerPinC, EchoPinC , 30);
NewPing usensorL(TriggerPinL, EchoPinL , 30);
NewPing usensorR(TriggerPinR, EchoPinR , 30);
NewPing usensormR(TriggerPinMr, EchoPinMr , 30);
NewPing usensormL(TriggerPinMl, EchoPinMl , 30);

int us_left;
int us_middleL;
int us_center;
int us_right;
int us_middleR;



unsigned long previousMillis = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int x;
  unsigned long currentMillis = millis();
  if (( currentMillis - previousMillis) >= 1000)
  {
    us_distances();
    Serial.print(us_left); // Send ping, get distance in cm and print result (0 = outside set distance range)
    Serial.print("cm");
    Serial.print(" Mid Left: ");
    Serial.print(us_middleL);
    Serial.print("cm");
    Serial.print(" Center: ");
    Serial.print(us_center);
    Serial.print("cm");
    Serial.print(" Mid Right: ");
    Serial.print(us_middleR);
    Serial.print("cm");
    Serial.print(" Right: ");
    Serial.print(us_right);
    Serial.println("cm");
    
    
  }
}

int get_cms(NewPing sonar){
  unsigned long pingTimer;
  int cm;
  pingTimer = sonar.ping_median(5);
  cm = sonar.convert_cm(pingTimer);
  return cm;
}

void us_distances(){
  us_left = get_cms(usensorL);
  us_middleL = get_cms(usensormL);
  us_center = get_cms(usensorC);
  us_middleR = get_cms(usensormR);
  us_right = get_cms(usensorR);
}
