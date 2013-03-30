#include "TinyBot.h"

void motorRight_forward(int speed) {
  TCCR1A &= ~((1<<COM1B1));
  TCCR1A |= ((1<<COM1A1));
  OCR1A=speed;
}

void motorRight_reverse(int speed) {
  TCCR1A &= ~((1<<COM1A1));
  TCCR1A |= ((1<<COM1B1));
  OCR1B=speed;
}

void motorRight_stop() {
  TCCR1A &= ~((1<<COM1A1));
  TCCR1A &= ~((1<<COM1B1));
  // And put is all back to a safe 'LOW'
  output_low(mRight1_Reg, mRight1_Port);
  output_low(mRight2_Reg, mRight2_Port);  
}

void motorLeft_forward(int speed) {
  TCCR0A &= ~((1<<COM0A1));
  TCCR0A |= ((1<<COM0B1));
  OCR0B=speed;
}

void motorLeft_reverse(int speed) {
  TCCR0A &= ~((1<<COM0B1));
  TCCR0A |= ((1<<COM0A1));
  OCR0A=speed;
}

void motorLeft_stop() {
  TCCR0A &= ~((1<<COM0A1));
  TCCR0A &= ~((1<<COM0B1));
  // And put is all back to a safe 'LOW'
  output_low(mLeft1_Reg, mLeft1_Port);
  output_low(mLeft2_Reg, mLeft2_Port);  
}

void motorInit() {  

  // Set the pins to output.
  set_output(mLeft1_Reg, mLeft1_Bit);
  set_output(mLeft2_Reg, mLeft2_Bit); 
  set_output(mRight1_Reg, mRight1_Bit); 
  set_output(mRight2_Reg, mRight2_Bit);
  // And set these to an initial value to make sure.
  output_low(mLeft1_Port, mLeft1_Bit);
  output_low(mLeft2_Port, mLeft2_Bit);
  output_low(mRight1_Port, mRight1_Bit);
  output_low(mRight2_Port, mRight2_Bit);  

  //Timer0
  TCCR0A = (0<<WGM01) | (1<<WGM00) | (0<<COM0A1) | (0<<COM0A0) | (0<<COM0B1) | (0<<COM0B0);
  TCCR0B = (0<<WGM02) | (0<<CS02) | (0<<CS01) | (1<<CS00) | (0<<FOC0A) | (0<<FOC0B);

  //Timer1
  TCCR1A = (0<<WGM11) | (1<<WGM10) | (0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0);
  TCCR1B = (0<<WGM12) | (0<<CS12) | (0<<CS11) | (1<<CS10) | (0<<FOC1A) | (0<<FOC1B);

}  

