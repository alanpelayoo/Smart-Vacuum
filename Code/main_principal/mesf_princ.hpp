
#include "car_movement.hpp"
#include "ultrasonics_measures.hpp"


unsigned long previousMillis = 0;

typedef enum{
  init_,
  stop_,
  turn_r,
  turn_l,

}raMEF_t;

raMEF_t ra_State;

int counter = 0;

void mefRAinit(void)
{
  ra_State=0;

}


void mefRAupdate()
{
  
  unsigned long currentMillis = millis();
  
  switch(ra_State){
  
  case init_:
    move_forward();
    if (( currentMillis - previousMillis) >= 50)
    {
      us_center = get_cms(usensorC);
      us_middleL = get_cms(usensormL);
      us_middleR = get_cms(usensormR);
      previousMillis = currentMillis;
    }
    if ( (us_center <=10) && (us_center > 0) ){
      ra_State =stop_;
      break;
      
    }else if ( (us_middleL <=10) && (us_middleL > 0) ){
      ra_State =turn_r;
      break;
    }else if ( (us_middleR <=10) && (us_middleR > 0) ){
      ra_State =turn_l;
      break;
    }
    
    break;
    
  case stop_:
    
    move_stop();
    if (( currentMillis - previousMillis) >= 50)
    {
      us_right = get_cms(usensorR);
      previousMillis = currentMillis;
      counter ++;
    }

    if ( (us_right <=10) && (us_right > 0) ){
      ra_State = turn_l;
      counter=0;
    }else if (counter > 5){
      ra_State = turn_r;
      counter=0;
    }
    break;

  case turn_l:
      turn_left();
      if (( currentMillis - previousMillis) >= 50)
      {
        us_right = get_cms(usensorR);
        us_center = get_cms(usensorC);
        previousMillis = currentMillis;
      }
      if ( (us_right <=10) && (us_right > 0) && (us_center == 0 || us_center > 9 ) ){
        ra_State = init_;
      }
    break;

  case turn_r:
      turn_right();
      if (( currentMillis - previousMillis) >= 50)
      {
        us_left = get_cms(usensorL);
        us_center = get_cms(usensorC);
        previousMillis = currentMillis;
      }
      if ( (us_left <=10) && (us_left > 0) && (us_center == 0 || us_center > 9 ) ){
        ra_State = init_;
      }
    break;
    
  

  default:
    ra_State=init_;
    break;

  }
}
