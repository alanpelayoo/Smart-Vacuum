int enableA = 4;
int in1 = 51;
int in2 = 50;

int enableB = 5;
int in3 = 49;
int in4 = 48;


void move_forward(){
  analogWrite(enableA, 186);
  analogWrite(enableB, 132);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void move_stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void turn_right(){
  //og values
  analogWrite(enableA, 130);
  analogWrite(enableB, 97);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turn_left(){
  analogWrite(enableA, 130);
  analogWrite(enableB, 97);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
