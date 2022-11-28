/* Code to plot encoder value */
volatile long int encoder_pos;
int enableA = 11;
int in1 = 12;
int in2 = 13;

void setup() {
  Serial.begin(115200);
  pinMode(2,INPUT);
  pinMode(enableA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  analogWrite(enableA, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  attachInterrupt(digitalPinToInterrupt(2),interrupcion,RISING);
}

void loop() {
  // put your main code here, to run repeate
  
}

void interrupcion(){
  Serial.println(1);
}
