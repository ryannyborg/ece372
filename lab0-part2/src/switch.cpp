// Description: This file implements the initialization of an external
// switch.
//----------------------------------------------------------------------//

#include "switch.h"
#include <avr/io.h>

/*
 * Initializes pull-up resistor on PB3 and sets it into input mode
 */
void initSwitchPB3(){
  /* PB3 is pin #50 on the breadboard */
  PORTB |= (1 << PORTB3); // pull-up resistor initialized
  DDRB &= ~(1 << DDB3); // set DDB3 as the input
}
