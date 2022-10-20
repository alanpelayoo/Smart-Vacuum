int enableA = 9;
int in1 = 8;
int in2 = 4;
int pinA = 2;

int enableB = 6;
int in3 = 5;
int in4 = 7;
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
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(1000);
  Serial.println("Here");
}
  
