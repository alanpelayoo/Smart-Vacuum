/* Updates:
  *Added battery control
  *Added driver control
  *Now using pins A5 for battery and 30 for driver
*/

#include "mesf_princ.hpp"

// Input pins
int batteryPin = A5;

// Output pins
char driverPin = 30;

// Constants
const float batteryFull = 12.35;

// Function to read battery voltage  
float readBattery(int batt_input)
{
  int readInput;
  float batt_voltage;
  readInput = analogRead(batt_input);
  batt_voltage = (((readInput*4.9)/1000)*batteryFull)/4.81;
  return batt_voltage;
}

// Setup
void setup() {
  Serial.begin(115200); 
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(batteryPin, INPUT);
  pinMode(driverPin, OUTPUT);
  //for random number library
  randomSeed(analogRead(0));
  // Initializes driverPin to LOW
  digitalWrite(driverPin, LOW);
}

// Main loop
void loop() {
  delay(1000);
  Serial.print("Starting State Machine");
  mefRAinit();
  
  // If battery voltage is above 12V, turns on the fan and initializes mefRAupdate
  if(readBattery(batteryPin)>12.0)
  {
   digitalWrite(driverPin, HIGH);
    // Main inner loop
    do {
    mefRAupdate();
    // To include the battery monitor on each iteration, write the commented line on line 59 instead of the "1" inside the while()
    } while(1); //readBattery(batteryPin)>11.1
  } else
  {
  // Turns off the fan if battery level gets too low
  digitalWrite(driverPin, LOW);
  }
}
