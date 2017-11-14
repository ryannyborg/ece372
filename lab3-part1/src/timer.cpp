//Authors: Laura Camp, Ryan Nyborg, Megan Lubbers
//NetIDs: lauracamp, rnyborg, meglubbers
//Date: 3/3/2017
//Project Name: lab3-part1
//
// Description:
//----------------------------------------------------------------------//

#include "timer.h"

void initTimer1(){
  //set timer 1 to fast pwm ocr1a as top
      //TCCR1A &= ~(1 << WGM11 | 1 << WGM10);
      TCCR1B |= (1 << WGM12 | 1 << WGM11 | 1 << WGM10);
      TCCR1B &= ~(1 << WGM13);
}

/* This delays the program an amount specified by unsigned int delay.
* Use timer 1. Keep in mind that you need to choose your prescalar wisely
* such that your timer is precise to 1 millisecond and can be used for 125
* 100 milliseconds
*/
//timer can count up to 65,536
void delayMs(unsigned int delay){
  unsigned int i = 0;
  while (i < delay){
    if(TIFR1 & (1 << OCF1A)){ //if flag raised(1 ms)
      TIFR1 |= (1<< OCF1A); //clear flag
      i++;
    }
  }
}
