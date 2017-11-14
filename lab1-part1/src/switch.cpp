// Description: This file implements the initialization of an external
// switch.
//----------------------------------------------------------------------//

#include "switch.h"
#include <avr/io.h>

/*
 * Initializes pull-up resistor on PB3 and sets it into input mode
 */
void initSwitchPB3(){
  PORTB |= (1 << PORTB3); // enable the pull-up resistor
  DDRB &= ~(1 << DDB3); // make the switch an input

  PCICR |= (1 << PCIE0); // enable pin-change interrupts
  PCMSK0 |= (1 << PCINT2 | 1 << PCINT3); // enable interrupts on PB3

}
