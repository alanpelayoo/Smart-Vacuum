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

int enableA = 4;
int in1 = 51;
int in2 = 50;
int pinA = 2;

int enableB = 5;
int in3 = 49;
int in4 = 48;
int pinB = 3;

void configure_ports(){
  pinMode(pinA, INPUT);
  pinMode(enableA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  pinMode(pinB, INPUT);
  pinMode(enableB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  analogWrite(enableA, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enableB, 255);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(1000);
  Serial.println("Here");
}
  
  
