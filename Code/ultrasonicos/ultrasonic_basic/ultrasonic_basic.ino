

#include <NewPing.h>

const int EchoPinC = 53;
const int TriggerPinC = 52;

const int EchoPinL = 47;
const int TriggerPinL = 46;
unsigned long pingTimer;
NewPing usensorC(TriggerPinC, EchoPinC , 100);
NewPing usensorL(TriggerPinL, EchoPinL , 100);
unsigned long previousMillis = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  unsigned long currentMillis = millis();
  if (( currentMillis - previousMillis) >= 1000)
  {
    Serial.print("Ping: ");
    pingTimer = usensorC.ping_median(5);
    Serial.print(usensorC.convert_cm(pingTimer)); // Send ping, get distance in cm and print result (0 = outside set distance range)
    Serial.println("cm");
   
    
  }
}
