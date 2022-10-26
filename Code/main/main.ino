// PID 2 from https://www.youtube.com/watch?v=bl2k6eXDAGM&list=LL&index=1&t=357s
// PID PRINCIPAL 
#include "configurepins.hpp"
#include "PIDS.hpp"




float sp= 120;

volatile int contador = 0;
         int contador2 = 0;

unsigned long previousMillis = 0;
unsigned long previousMillis2 = 0;
long interval = 100;
long interval2 = 1000;

bool flag_pid = true;

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
    
    if (flag_pid){
      pid(contador,sp,enableA);
      pid2(contador2,sp,enableB);
    }
    ;
    
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

int get_cms(NewPing sonar){
  unsigned long pingTimer;
  int cm;
  pingTimer = sonar.ping_median(5);
  cm = sonar.convert_cm(pingTimer);
  return cm;
}

void us_distances(){
  us_left = get_cms(usensorL);
  
}
