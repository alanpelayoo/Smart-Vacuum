// PID 2 from https://www.youtube.com/watch?v=bl2k6eXDAGM&list=LL&index=1&t=357s
// PID PRINCIPAL 

int enableA = 9;
int in1 = 8;
int in2 = 4;
int pinA = 2;

int enableB = 6;
int in3 = 5;
int in4 = 7;
int pinB = 3;

float pv;
float pv_2;
float sp;

volatile int contador = 0;
         int contador2 = 0;
         
unsigned long previousMillis = 0;
unsigned long previousMillis2 = 0;
long interval = 100;
long interval2 = 500;

float cv; //Normalmente uk 
float cv1;
float error;
float error1;
float error2;

float cv_2; //Normalmente uk 
float cv1_2;
float error_2;
float error1_2;
float error2_2;

float Kp = 2;
float Ki =10;
float Kd =0.001;
float Tm = 0.1; // interval1/ 1000

void setup() {
  Serial.begin(115200);
  
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
  
  sp = 100;
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
    pid();
    pid2();
    analogWrite(enableA, cv*(255.0/500.0));
    analogWrite(enableB, cv_2*(255.0/500.0));
    
  }
  
  if (( currentMillis - previousMillis2) >= interval2)
  {
  
    previousMillis2 = currentMillis;
    Serial.print("SP: ");
    Serial.print(sp);
    Serial.print(", PV: ");
    Serial.print(pv);
    Serial.print(", PV2: ");
    Serial.println(pv_2);
  }
}

void interrupcion() {
  contador ++;
}

void interrupcion2() {
  contador2 ++;
}

void pid(){
  pv = 10*contador*(60.0/374.0); //Rpm
  error = sp - pv;
  cv = cv1 + (Kp + Kd/Tm)*error + (-Kp + Ki*Tm - 2*Kd/Tm)*error1 + (Kd/Tm)*error2;
  cv1 = cv;
  error2 = error1;
  error1 = error;

  if (cv > 500.0){
    cv = 500.0;
  }
  if (cv < 30.0){
    cv = 30.0;
  }
  contador = 0;
}

void pid2(){
  pv_2 = 10*contador2*(60.0/374.0); //Rpm
  error_2 = sp - pv_2;
  cv_2 = cv1_2 + (Kp + Kd/Tm)*error_2 + (-Kp + Ki*Tm - 2*Kd/Tm)*error1_2 + (Kd/Tm)*error2_2;
  cv1_2 = cv_2;
  error2_2 = error1_2;
  error1_2 = error_2;

  if (cv_2 > 500.0){
    cv_2 = 500.0;
  }
  if (cv_2 < 30.0){
    cv_2 = 30.0;
  }
  contador2 = 0;
}
