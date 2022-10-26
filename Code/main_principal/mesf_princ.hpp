
#include "car_movement.hpp"
#include "ultrasonics_measures.hpp"


unsigned long previousMillis = 0;

typedef enum{
  init_,
  stop_,

}raMEF_t;

raMEF_t ra_State;

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
    if (( currentMillis - previousMillis) >= 1000)
    {
      us_center = get_cms(usensorC);
      
      Serial.print(" Center: ");
      Serial.print(us_center);
      Serial.println("cm");
      previousMillis = currentMillis;
    }
    if ( (us_center <=11) && (us_center > 1) ){
      ra_State =stop_;
      
    }
    
    break;
    
  case stop_:
    move_stop();
    
    break;
    
  

  default:
    ra_State=init_;
    break;

  }
}