// PID 2 from https://www.youtube.com/watch?v=bl2k6eXDAGM&list=LL&index=1&t=357s
// PID PRINCIPAL 
#include "PIDS.hpp"

int enableA = 9;
int in1 = 8;
int in2 = 4;
int pinA = 2;

int enableB = 6;
int in3 = 5;
int in4 = 7;
int pinB = 3;

float sp= 80;


volatile int contador = 0;
         int contador2 = 0;


unsigned long previousMillis = 0;
unsigned long previousMillis2 = 0;
long interval = 100;
long interval2 = 500;



void setup() {
  Serial.begin(115200);
  Serial.println("Hello");
  pinMode(pinA, INPUT);
  pinMode(enableA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  pinMode(pinB, INPUT);
  pinMode(enableB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(pinA),interrupcion,RISING);
  attachInterrupt(digitalPinToInterrupt(pinB),interrupcion2,RISING);
  
  analogWrite(enableA, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enableB, 255);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
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
    
  }
  
  if (( currentMillis - previousMillis2) >= interval2)
  {
  
    previousMillis2 = currentMillis;
    print_rpms(sp);
  }
}

void interrupcion() {
  contador ++;
}

void interrupcion2() {
  contador2 ++;
}
