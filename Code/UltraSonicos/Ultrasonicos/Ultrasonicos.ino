//Ultrasonicos 
const int Trigger1 = 2;   
const int Echo1 = 3;   
const int Trigger2 = 8;   
const int Echo2 = 9; 
const int Trigger3 = 6;   
const int Echo3 = 7;  

void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger1, OUTPUT); //pin como salida
  pinMode(Echo1, INPUT);  //pin como entrada
  digitalWrite(Trigger1, LOW);//Inicializamos el pin con 0
  pinMode(Trigger2, OUTPUT); //pin como salida
  pinMode(Echo2, INPUT);  //pin como entrada
  digitalWrite(Trigger2, LOW);//Inicializamos el pin con 0
  pinMode(Trigger3, OUTPUT); //pin como salida
  pinMode(Echo3, INPUT);  //pin como entrada
  digitalWrite(Trigger3, LOW);//Inicializamos el pin con 0
}

void loop(){
/////////////////////////////Sensor Ultrasonico 1 ///////////////////////////////////////////////////////
  long t1; //timepo que demora en llegar el eco
  long d1; //distancia en centimetros
  digitalWrite(Trigger1, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger1, LOW);
  t1= pulseIn(Echo1, HIGH); //obtenemos el ancho del pulso
  d1 = t1/59;             //escalamos el tiempo a una distancia en cm
  if (d1>30){
     d1=30;
  }
  if (d1<0){
  d1=0;
  }
  Serial.print("Distancia1: ");
  Serial.print(d1);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(100);          //Hacemos una pausa de 100ms

///////////////////////////Sensor Ultrasonico 2 ///////////////////////////////////////////////////////
  long t2; //timepo que demora en llegar el eco
  long d2; //distancia en centimetros
  digitalWrite(Trigger2, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger2, LOW);
  t2= pulseIn(Echo2, HIGH); //obtenemos el ancho del pulso
  d2 = t2/59;             //escalamos el tiempo a una distancia en cm
  if (d2>30){
     d2=30;
  }
  if (d2<0){
  d2=0;
  }
  Serial.print("Distancia2: ");
  Serial.print(d2);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  //delay(100);          //Hacemos una pausa de 100ms

/////////////////////////////Sensor Ultrasonico 3 ///////////////////////////////////////////////////////
  long t3; //timepo que demora en llegar el eco
  long d3; //distancia en centimetros
  digitalWrite(Trigger3, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger3, LOW);
  t3= pulseIn(Echo3, HIGH); //obtenemos el ancho del pulso
  d3 = t3/59;             //escalamos el tiempo a una distancia en cm
  if (d3>30){
     d3=30;
  }
  if (d3<0){
  d3=0;
  }
  Serial.print("Distancia3: ");
  Serial.print(d3);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
}
