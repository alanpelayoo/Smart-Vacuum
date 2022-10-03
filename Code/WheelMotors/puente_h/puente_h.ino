int enableA = 3;
 
void setup() {
  pinMode(enableA, OUTPUT);
}
 
void loop() {
  analogWrite(enableA, 255);
}
