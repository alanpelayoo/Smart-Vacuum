
#include "car_movement.hpp"
#include "ultrasonics_measures.hpp"




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
  
  
  
  switch(ra_State){
  
  case init_:
    move_forward();
    us_center = get_cms(usensorC);
    us_middleL = get_cms(usensormL);
    us_middleR = get_cms(usensormR);
    
    
    if ( (us_center <=14) && (us_center > 0) ){
      ra_State =stop_;
      break;
    
    }else if ( (us_middleL <=12) && (us_middleL > 0) ){
      ra_State =turn_r;
      break;
    }else if ( (us_middleR <=12) && (us_middleR > 0) ){
      ra_State =turn_l;
      break;
    }
    delay(50);
  
    break;
    
  case stop_:
    
    move_stop();
    
    us_right = get_cms(usensorR);
    
    if ( (us_right <=10) && (us_right > 0) ){
      ra_State = turn_l;
      break;
    }else{
      ra_State = turn_r;
      break;
    }
    delay(50);
    break;

  case turn_l:
      turn_left();

      us_right = get_cms(usensorR);
      us_center = get_cms(usensorC);
      us_middleR = get_cms(usensormR);

      //10
      if ( (us_right <=12) && (us_right > 0) && (us_center == 0 || us_center > 9 ) && (us_middleR == 0 || us_middleR > 7 ) ){
        ra_State = init_;
        break;
      }
      delay(50);
    break;

  case turn_r:
    turn_right();
    
    us_left = get_cms(usensorL);
    us_center = get_cms(usensorC);
    us_middleL = get_cms(usensormL);
   
    if ( (us_left <=12) && (us_left > 0) && (us_center == 0 || us_center > 9 ) && (us_middleL == 0 || us_middleL > 7 ) ){
      ra_State = init_;
      break;
    }
    delay(50);
      
    break;
    
  

  default:
    ra_State=init_;
    break;

  }
}
