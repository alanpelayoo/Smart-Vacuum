
const int relay = 36;

void setup() {
  // put your setup code here, to run once:
  pinMode(relay, OUTPUT);

}

void loop() {
  delay(2000);
  digitalWrite(relay, LOW);

}
