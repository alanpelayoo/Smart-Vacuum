#include "mesf_princ.hpp"




void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); 
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  analogWrite(enableA, 60);
  analogWrite(enableB, 60);

  //for random number library
  randomSeed(analogRead(0));
}

void loop() {
  delay(1000);
  Serial.print("Starting State Machine");
  mefRAinit();
  
  while(1){
    
    mefRAupdate();
  }

}
