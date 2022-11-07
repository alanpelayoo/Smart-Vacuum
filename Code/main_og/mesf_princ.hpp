
#include "car_movement.hpp"
#include "ultrasonics_measures.hpp"

// States
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
    us_center = get_cms(usensorC,2);
    us_middleL = get_cms(usensormL,2);
    us_middleR = get_cms(usensormR,2);
    
    
    if ( (us_center <=15) && (us_center > 0) ){
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
    int randNumber;
    
    
    us_right = get_cms(usensorR,3);
    us_left = get_cms(usensorL,3);
    delay(30);
    if ( (us_right <=15) && (us_right > 0) ){
      ra_State = turn_l;
      break;
      
    }else if ((us_left <=15) && (us_left > 0)){
      ra_State = turn_r;
      break;
    }
    else{
      //Generating random number, so we change routes, and clean different areas
      randNumber = random(2);
      if (randNumber == 1){
        ra_State = turn_r;
      }
      else {
        ra_State = turn_l;
      }
      
      break;
    }
    break;
    
    delay(50);
    break;

  case turn_l:
      turn_left();

      us_right = get_cms(usensorR,2);
      us_center = get_cms(usensorC,2);
      us_middleR = get_cms(usensormR,2);

      //10
      if ( (us_right <=12) && (us_right > 0) && (us_center == 0 || us_center > 11 ) && (us_middleR == 0 || us_middleR > 7 ) ){
        ra_State = init_;
        break;
      }
      delay(50);
    break;

  case turn_r:
    turn_right();
    
    us_left = get_cms(usensorL,2);
    us_center = get_cms(usensorC,2);
    us_middleL = get_cms(usensormL,2);
   
    if ( (us_left <=12) && (us_left > 0) && (us_center == 0 || us_center > 11 ) && (us_middleL == 0 || us_middleL > 7 ) ){
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
