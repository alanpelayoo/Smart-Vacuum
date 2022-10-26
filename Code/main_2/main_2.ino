int enableA = 4;
int in1 = 51;
int in2 = 50;

int enableB = 5;
int in3 = 49;
int in4 = 48;

typedef enum{
  car_init, // estado 0
}raMEF_t;

raMEF_t ra_State;

void setup() {
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  analogWrite(enableA, 170);
  analogWrite(enableB, 130);
}
 
void loop() {
  mefRAinit();

  while(1){
    mefRAupdate();


  }
}


void mefRAinit(void)
{
  ra_State=car_init;

}


void mefRAupdate(void)
{
  switch(ra_State){

  case car_init:
    move_front();
    
    break;

  

  default:
    ra_State=car_init;
    break;

  }
}




void move_front(){
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
