

#include <NewPing.h>

const int EchoPinC = 53;
const int TriggerPinC = 52;

const int EchoPinL = 47;
const int TriggerPinL = 46;

const int EchoPinR = 45;
const int TriggerPinR = 44;

const int EchoPinMr = 43;
const int TriggerPinMr = 42;

unsigned long pingTimer;
unsigned long pingTimer2;
unsigned long pingTimer3;
unsigned long pingTimer4;

NewPing usensorC(TriggerPinC, EchoPinC , 30);
NewPing usensorL(TriggerPinL, EchoPinL , 30);
NewPing usensorR(TriggerPinR, EchoPinR , 30);
NewPing usensormR(TriggerPinMr, EchoPinMr , 30);

unsigned long previousMillis = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  unsigned long currentMillis = millis();
  if (( currentMillis - previousMillis) >= 1000)
  {
    Serial.print("Center: ");
    pingTimer = usensorC.ping_median(5);
    pingTimer2 = usensorL.ping_median(5);
    pingTimer3 = usensorR.ping_median(5);
    pingTimer4 = usensormR.ping_median(5);
    
    Serial.print(usensorC.convert_cm(pingTimer)); // Send ping, get distance in cm and print result (0 = outside set distance range)
    Serial.print("cm");
    Serial.print(" Left: ");
    Serial.print(usensorL.convert_cm(pingTimer2));
    Serial.print("cm");
    Serial.print(" Right: ");
    Serial.print(usensorR.convert_cm(pingTimer3));
    Serial.print("cm");
    Serial.print(" Mid R: ");
    Serial.print(usensormR.convert_cm(pingTimer4));
    Serial.println("cm");
   
    
  }
}
