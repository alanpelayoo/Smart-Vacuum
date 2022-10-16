int enableA = 9;
int in1 = 8;
int in2 = 4;

int enableB = 6;
int in3 = 5;
int in4 = 7;
void setup() {
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  analogWrite(enableA, 255);
  analogWrite(enableB, 255);
}
 
void loop() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
}
