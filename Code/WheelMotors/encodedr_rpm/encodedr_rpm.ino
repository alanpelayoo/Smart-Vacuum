
#define ENCODER_A       3 // Amarillo
#define ENCODER_B       4 // Verde
#define enableA  5

float rpm =0;
int in3 = 49;
int in4 = 48;


//Variable global de pulsos compartida con la interrupción
volatile int pulsos = 0;
unsigned long timeold;
float resolution = 374;

//Variable Global Velocidad
int vel = 0;

void setup(){
  Serial.begin(9600);
  //Encoders como entradas
  pinMode(ENCODER_A, INPUT);
  pinMode(ENCODER_B, INPUT);
  pinMode(enableA, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  //Configurar Interrupción
  timeold = 0;
  attachInterrupt(digitalPinToInterrupt(ENCODER_A),leerEncoder,RISING);
  analogWrite(enableA, 125);
  
}

void loop(){
  


  //Espera un segundo para el calculo de las RPM
  if (millis() - timeold >= 1000)
  {
    
    //rpm = float(pulsos * 60.0 / 374); //RPM
    rpm = float((60.0 * pulsos / resolution ) * (1000 / (millis() - timeold)));
    pulsos = 0;
    
    Serial.print("RPM: ");
    Serial.println(rpm);
    timeold = millis();
  }
}


//Función para la lectura del encoder
void leerEncoder(){
  //Lectura de Velocidad
  pulsos++; //Incrementa una revolución
    
}
