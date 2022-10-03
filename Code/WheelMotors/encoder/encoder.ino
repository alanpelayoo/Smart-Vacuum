/* Code to plot encoder value */
volatile long int encoder_pos;

void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
}

void loop() {
  // put your main code here, to run repeate
  print_cuad();
}

void print_cuad(){
  int a = digitalRead(2);
  int b = digitalRead(3);
  Serial.print(a*5);
  Serial.print(" ");
  Serial.print(b*5);
  Serial.println();
}
