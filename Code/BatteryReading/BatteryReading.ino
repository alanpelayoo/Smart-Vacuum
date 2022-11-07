/// PINS ///
const int batteryPin = A5;

/// CONSTANTS ///
const float voltageBattCharged = 12.35;

/// VARIABLES ///
float voltage = 0;

float readBattery(int batt_input)
{
  int readInput;
  float batt_voltage;
  readInput = analogRead(batt_input);
  batt_voltage = (((readInput*4.9)/1000)*voltageBattCharged)/4.81;
  return batt_voltage;
}

void setup() {
  pinMode(batteryPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  voltage = readBattery(batteryPin);
  Serial.println(voltage);
  delay(1000);
}
