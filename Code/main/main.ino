// PID 2 from https://www.youtube.com/watch?v=bl2k6eXDAGM&list=LL&index=1&t=357s
// PID PRINCIPAL 
#include "configurepins.hpp"
#include "PIDS.hpp"



bool turning_r;
float sp= 100;

volatile int contador = 0;
         int contador2 = 0;

unsigned long previousMillis = 0;
unsigned long previousMillis2 = 0;
long interval = 100;
long interval2 = 500;

#include <NewPing.h>

const int EchoPin = 13;
const int TriggerPin = 12;

const int EchoPin2 = 11;
const int TriggerPin2 = 10;

NewPing sonar(TriggerPin, EchoPin , 40);
NewPing sonar2(TriggerPin2, EchoPin2 , 40);


void setup() {
  Serial.begin(115200); 
  configure_ports();
  attachInterrupt(digitalPinToInterrupt(pinA),interrupcion,RISING);
  attachInterrupt(digitalPinToInterrupt(pinB),interrupcion2,RISING);
  
  
}
void loop() {
  unsigned long currentMillis = millis();
  if (( currentMillis - previousMillis) >= interval)
  {
    previousMillis = currentMillis;
    pid(contador,sp,enableA);
    pid2(contador2,sp,enableB);
    
    contador2 = 0;
    contador = 0;
    if (sonar2.ping_cm() > 0 && sonar2.ping_cm() < 5){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      turning_r = true;
      
    }
    if (turning_r){
      if (sonar.ping_cm() > 0 && sonar.ping_cm() < 7){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      turning_r = false;
      } 
    }
  }
  
  if (( currentMillis - previousMillis2) >= interval2)
  {
  
    previousMillis2 = currentMillis;
    print_rpms(sp);
    Serial.print("Sensor 1: ");
    Serial.print(sonar.ping_cm()); // obtener el valor en cm (0 = fuera de rango)
    Serial.print("cm ");
    Serial.print("  Sensor 2: ");
    Serial.print(sonar2.ping_cm()); // obtener el valor en cm (0 = fuera de rango)
    Serial.println("cm ");

    
  }
}



void interrupcion() {
  contador ++;
}

void interrupcion2() {
  contador2 ++;
}
