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

  analogWrite(enableA, 0);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enableB, 255);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(1000);
  Serial.println("Here");
}
  
