// PID 2 from https://www.youtube.com/watch?v=bl2k6eXDAGM&list=LL&index=1&t=357s
// PID PRINCIPAL 

int PWM_salida = 3;
float pv;
float sp;
int pinA = 2;
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

float Kp = 1;
float Ki =10;
float Kd =0.001;
float Tm = 0.1; // interval1/ 1000

void setup() {
  pinMode(pinA, INPUT);
  pinMode(PWM_salida, OUTPUT);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(pinA),interrupcion,RISING);
  sp = 100;
  
}

void loop() {
  unsigned long currentMillis = millis();
  if (( currentMillis - previousMillis) >= interval)
  {
    previousMillis = currentMillis;
    pv = 10*contador*(60.0/374.0); //Rpm
    contador = 0;
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
    analogWrite(PWM_salida, cv*(255.0/500.0));
    
  }
  if (( currentMillis - previousMillis2) >= interval2)
  {
    if (contador2 >20){
      sp = 120;
    }
    if (contador2 > 50){
      sp = 60;
    }
    previousMillis2 = currentMillis;
    Serial.print("SP: ");
    Serial.print(sp);
    Serial.print(", PV: ");
    Serial.println(pv);
    contador2 ++;
  }
}

void interrupcion() {
  contador ++;
}
