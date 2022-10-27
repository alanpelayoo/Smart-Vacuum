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



NewPing usensorC(TriggerPinC, EchoPinC , 70);
NewPing usensorL(TriggerPinL, EchoPinL , 30);
NewPing usensorR(TriggerPinR, EchoPinR , 30);
NewPing usensormR(TriggerPinMr, EchoPinMr , 30);
NewPing usensormL(TriggerPinMl, EchoPinMl , 30);

int us_left;
int us_middleL;
int us_center;
int us_right;
int us_middleR;


int get_cms(NewPing sonar){
  unsigned long pingTimer;
  int cm;
  pingTimer = sonar.ping_median(3);
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
