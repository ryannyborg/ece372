//Authors: Laura Camp, Ryan Nyborg, Megan Lubbers
//NetIDs: lauracamp, rnyborg, meglubbers
//Date: 3/3/2017
//Project Name: lab3-part1
//
// Description:
//----------------------------------------------------------------------//

#include "switch.h"
#include <avr/io.h>
void initSwitchPB3(){
  // Initializes pull-up resistor on PB3 and sets it into input mode
  PORTB |= (1 << PORTB3);
  DDRB &= ~(1 << DDB3);
  // enable pin-change interrupts
  // enable interrupts on PB3

  PCICR |= (1 << PCIE0); //enables PCINT for PCINT[7:0]
  PCMSK0 |= (1 << PCINT3 ); // enables PCINT for PCINT3
}
