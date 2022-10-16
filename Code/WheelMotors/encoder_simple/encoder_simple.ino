/* Code to plot encoder value */
volatile long int encoder_pos;
int enableA = 6;
int in1 = 5;
int in2 = 7;

void setup() {
  Serial.begin(115200);
  pinMode(3,INPUT);
  pinMode(enableA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  analogWrite(enableA, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  attachInterrupt(digitalPinToInterrupt(3),interrupcion,RISING);
}

void loop() {
  // put your main code here, to run repeate
  
}

void interrupcion(){
  Serial.println(1);
}
