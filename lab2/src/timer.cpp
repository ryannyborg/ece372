// Description: This file implements functions that utilize the timers
//----------------------------------------------------------------------//

#include "timer.h"

void initTimer1(){
  //set timer 1 to ctc mode
      TCCR1A &= ~(1 << WGM11 | 1 << WGM10);
      TCCR1B |= (1 << WGM12);
      TCCR1B &= ~(1 << WGM13);
//set timer 3 to ctc mode
      // TCCR4A &= ~(1 << WGM11 | 1 << WGM10);
      // TCCR4B |= (1 << WGM12);
      // TCCR4B &= ~(1 << WGM13);
      
      TCCR3A &= ~(1 << WGM11 | 1 << WGM10);
      TCCR3B |= (1 << WGM12);
      TCCR3B &= ~(1 << WGM13);
}
