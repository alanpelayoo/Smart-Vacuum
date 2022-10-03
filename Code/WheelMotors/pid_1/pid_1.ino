// PID Controller for motor APZ

const   int T = 10;                     // Sampling period (ms)   
volatile int encoderPos = 0;
int counter[2] = {0,0};     // Counter vector
float rpm = 0;
int pulsos_dif =0;
unsigned long timeold;



//PID
int setpoint = 100;        // Reference variable
int u;
float uk;
float u1;
int e0;
int e1;
int e2;


const   float Kp = .3;                 // Proportional gain
const   int Ti = 10;                  // Integral time
const   int Td = 10;                 // Derivative time

#define ENCODER_A       2 // Amarillo
#define ENCODER_B       4 // Verde
#define enableA  3

void setup(){
  Serial.begin(9600);
  pinMode(ENCODER_A, INPUT);
  pinMode(ENCODER_B, INPUT);
  pinMode(enableA, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(ENCODER_A),leerEncoder,RISING);
}

void loop(){
  speedCalculation();
  pid();
  u = 0;
  while (u < uk){ 
    u += 1; 
  }
  analogWrite(enableA, u);
  Serial.println(rpm);   
  delay(T);
  
}


void speedCalculation(){                 // Considers T, encoder, rpm
  counter[0] = encoderPos;
  pulsos_dif = (counter[0] - counter[1]);
  rpm = float(pulsos_dif * 6000.0 / 374);
  counter[1] = counter[0];              // Shift register
}


void leerEncoder(){
  //Lectura de Velocidad
  encoderPos++; //Incrementa una revolución
}

void pid(){
  e0 = setpoint - rpm;            // Error calculation
  uk = u1 + Kp * (e0 - e1 + T/(Ti) * e0 + Td/(T) * (e0 - 2*e1 + e2));
  uk = (min(max(0, uk), 255));
  e1 = e0;                  // Shifting operation
  e2 = e1;                  // Shifting operation
  u1 = uk;  
}
