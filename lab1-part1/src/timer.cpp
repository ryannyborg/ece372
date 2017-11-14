// Description: This file implements functions that utilize the timers
//----------------------------------------------------------------------//

#include "timer.h"
#include "led.h"
#include <Arduino.h>

/* Initialize timer 1, you should not turn the timer on here.
* You will need to use CTC mode
*/
void initTimer1(){
  // saftey first :)
  TCCR1A &= ~(1 << WGM10 | 1<< WGM11);
  TCCR1B &= ~(1 << CS12);

  // set up timer with prescaler = 64 and CTC mode
  TCCR1B |= (1 << WGM12)|(1 << CS11)|(1 << CS10);

  // initialize counter
  TCNT1 = 0;

  // initialize counter
  // OCR1A = 24999;


  //enable the interrupts
  // TIMSK1 |= (1 << OCIE1A);
}

/* This delays the program an amount specified by unsigned int delay.
* Use timer 1. Keep in mind that you need to choose your prescalar wisely
* such that your timer is precise to 1 millisecond and can be used for 125
* 100 milliseconds
*/
void delayMs(unsigned int delay){
  int timer_count = 0;
  int prescalar = 64;

  timer_count = ((delay*0.001) * (16000000 / prescalar)) - 1;
  Serial.println(timer_count);
  OCR1A = timer_count;

  while(1){
    if(TCNT1 >= OCR1A){
      break;
    }
    TIFR1 |= (1 << OCF1A); // turns off the flag
  }

}
