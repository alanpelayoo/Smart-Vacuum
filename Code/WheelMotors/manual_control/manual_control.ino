int enableA = 9;
int in1 = 8;
int in2 = 4;

int enableB = 6;
int in3 = 5;
int in4 = 7;

int input;

void setup() {
  Serial.begin(115200);
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  analogWrite(enableA, 255);
  analogWrite(enableB, 255);
  delay(2000);  
  Serial.println("Manual Operation mode ready to test.....");
  Serial.println("Type one of these options:");
  Serial.println("1: Go front, 2:Go Back, 3: Turn R, 4: Turn L, 5:Stop");
}
 
void loop() {
  if(Serial.available()){
        input = Serial.readStringUntil('\n').toInt();
        Serial.print("You typed: " );
        Serial.println(input);
        switch (input) {
          case 1:
            move_front();
            break;
          case 2:
            move_back();
            break;
          case 3:
            turn_right();
            break;
          case 4:
            turn_left();
            break;
          case 5:
            stop_motors();
            break;
          default:
            Serial.print("Not available command" );
        }
    }
}


void move_front(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  Serial.println("Front");
}
void move_back(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  Serial.println("Back");
}


void turn_right(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  Serial.println("Turning R");
}

void turn_left(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  Serial.println("Turning L");
}
void stop_motors(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.println("Stop");
}
