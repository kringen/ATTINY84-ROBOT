
// Prototypes
uint8_t speed_right();
uint8_t speed_left();
uint8_t digitalRead(uint8_t pin);
uint8_t burst_right();
uint8_t burst_left();
uint8_t avg_left();
uint8_t avg_right();

void irInit() {
	DDRA = 0x00; // Set as input
	PORTA = 0xFF; // Enable pullup resistors.
}

uint8_t speed_right(){
  uint8_t rspeed = 0;
  if(avg_right() == 0){
    rspeed = 0;
  }
  else if(avg_right() <= 10){
    rspeed = 10;
 }
  else if(avg_right() <= 20){
    rspeed = 20;
 }
  else if(avg_right() <= 30){
    rspeed = 30;
 }
  else if(avg_right() <= 40){
    rspeed = 40;
 }
  else if(avg_right() <= 50){
    rspeed = 50;
 }
  else if(avg_right() <= 60){
    rspeed = 60;
 } 
  else if(avg_right() <= 70){
    rspeed = 70;
 } 
  else if(avg_right() <= 80){
    rspeed = 80;
 } 
  else if(avg_right() <= 90){
    rspeed = 90;
 } 
  else {
    rspeed = 100; 
}
return rspeed;
}

uint8_t speed_left(){
  uint8_t lspeed = 0;
  if(avg_left() == 0){
    lspeed = 0;
  }
  else if(avg_left() <= 10){
    lspeed = 10;
 }
  else if(avg_left() <= 20){
    lspeed = 20;
 }
  else if(avg_left() <= 30){
    lspeed = 30;
 }
  else if(avg_left() <= 40){
    lspeed = 40;
 }
  else if(avg_left() <= 50){
    lspeed = 50;
 }
  else if(avg_left() <= 60){
    lspeed = 60;
 } 
  else if(avg_left() <= 70){
    lspeed = 70;
 } 
  else if(avg_left() <= 80){
    lspeed = 80;
 } 
  else if(avg_left() <= 90){
    lspeed = 90;
 } 

  else {
    lspeed = 100; 
}
return lspeed;
}

uint8_t digitalRead(uint8_t pin){
        if (bit_is_set(PINA, pin)) // IR Receiver goes low when detecting
        {
          return 1;
        }
        return 0;
}

uint8_t burst_right(){
  uint8_t r = 0;
  uint8_t sample_right = 0;
  while(r < 100) {
    sample_right = sample_right + digitalRead(rightIR);
    r++;
  }
  return sample_right;
}

uint8_t burst_left(){
  uint8_t l = 0;
  uint8_t sample_left = 0;
  while(l < 100) {
    sample_left = sample_left + digitalRead(leftIR);
    l++;
  }
  return sample_left;
}

uint8_t avg_left(){
  uint8_t lsample1 = burst_left();
  uint8_t lsample2 = burst_left();
  uint8_t lsample3 = burst_left();
  return (lsample1 + lsample2 + lsample3) / 3;
}

uint8_t avg_right(){
  uint8_t rsample1 = burst_right();
  uint8_t rsample2 = burst_right();
  uint8_t rsample3 = burst_right();
  return (rsample1 + rsample2 + rsample3) / 3;
}
