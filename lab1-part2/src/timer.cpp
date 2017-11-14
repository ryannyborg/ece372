// Description: This file implements functions that utilize the timers
//----------------------------------------------------------------------//

#include "timer.h"
#include <Arduino.h>

/* Initialize timer 1, you should not turn the timer on here. You will need to
* use CTC mode
*/
void initTimer1(){
  // saftey first :)
  TCCR1A &= ~(1 << WGM10 | 1<< WGM11);
  TCCR1B &= ~(1 << WGM12 | 1<< CS10 | 1<< CS11 | 1 << CS12);

  // set up timer with prescaler = 64 and CTC mode
  TCCR1B |= (1 << WGM12)|(1 << CS11)|(1 << CS10);
}

void delayUs(unsigned int delay){
  // Turn on the timer
  TCCR1B |= (1 << WGM12)|(1 << CS11)|(1 << CS10);

  // clear the timer
  TCNT1H = 0x0;
  TCNT1L = 0x0;
  // calculate the TOP value and assign it to OCR1A
  int timer_count = 0;
  int prescalar = 8;

  timer_count = ((delay*0.000001) * (16000000 / prescalar)) - 1;
  OCR1A = timer_count;



  // Do nothing while the OCF1A flag is not up
  while(1){
    if(TCNT1 >= OCR1A){
      break;
    }
  }
  // Clear the OCF1A flag
  TIFR1 |= (1 << OCF1A); // turns off the flag

  // Turn off the timer
  TCCR1B &= ~(1 << WGM12)|(1 << CS11)|(1 << CS10);

}
