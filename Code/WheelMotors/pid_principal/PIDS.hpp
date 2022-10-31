float pv;
float pv_2;


float cv; //Normalmente uk 
float cv1;
float error;
float error1;
float error2;

float cv_2; //Normalmente uk 
float cv1_2;
float error_2;
float error1_2;
float error2_2;

float Kp = 2;
float Ki =10;
float Kd =0.001;
float Tm = 0.1; // interval1/ 1000

void pid(int contador, float sp, int enableA){
  pv = 10*contador*(60.0/374.0); //Rpm
  error = sp - pv;
  cv = cv1 + (Kp + Kd/Tm)*error + (-Kp + Ki*Tm - 2*Kd/Tm)*error1 + (Kd/Tm)*error2;
  cv1 = cv;
  error2 = error1;
  error1 = error;

  if (cv > 500.0){
    cv = 500.0;
  }
  if (cv < 30.0){
    cv = 30.0;
  }
  analogWrite(enableA, cv*(255.0/500.0));
}

void pid2(int contador2, float sp, int enableB){
  pv_2 = 10*contador2*(60.0/374.0); //Rpm
  error_2 = sp - pv_2;
  cv_2 = cv1_2 + (Kp + Kd/Tm)*error_2 + (-Kp + Ki*Tm - 2*Kd/Tm)*error1_2 + (Kd/Tm)*error2_2;
  cv1_2 = cv_2;
  error2_2 = error1_2;
  error1_2 = error_2;

  if (cv_2 > 500.0){
    cv_2 = 500.0;
  }
  if (cv_2 < 30.0){
    cv_2 = 30.0;
  }
  
  
  analogWrite(enableB, cv_2*(255.0/500.0));
}

void print_rpms(float sp){
  Serial.print("SP: ");
  Serial.print(sp);
  Serial.print(", PV: ");
  Serial.print(pv);
  Serial.print(", PV2: ");
  Serial.println(pv_2);
  Serial.print("CV1: ");
  Serial.print(cv*(255.0/500.0));
  Serial.print("CV2: ");
  Serial.println(cv_2*(255.0/500.0));
  
}
