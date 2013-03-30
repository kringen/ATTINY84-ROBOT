#include <avr/io.h>
#include <util/delay.h>
#include "TinyBot.h"
#include "Infrared.h"
#include "Motors.h"



void drive_forward(){
  uint8_t sleft = avg_right(); //Opposite to move away from obstacle
  uint8_t sright = avg_left(); //Opposite to move away from obstacle
  if(sleft <= 5 && sright <= 5)
  {
   // Stop Motors
   motorLeft_stop();
   motorRight_stop();
   _delay_ms(1000);
   // Turn around
   motorLeft_reverse(255);
   motorRight_forward(255);
   _delay_ms(700);
  }
  else
  {
  uint8_t pwm_left = sleft * 255 / 100;
  uint8_t pwm_right = sright * 255 / 100;
  motorLeft_forward(pwm_left);   
  motorRight_forward(pwm_right);
  _delay_ms(20);
 }
}


int main(void) {
	irInit();
	motorInit();
	
	while(1)
		{
		drive_forward();
		}
return(0);
}
