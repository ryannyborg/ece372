// Description: This file implements turnOnLED and initLED to control
// the LEDs.
//----------------------------------------------------------------------//


#include <avr/io.h>
#include <util/delay.h>
#include "led.h"

/*
 * Initializes pins B6, B5, and B4 to be in output mode using the DDR register
 * and bit operations. Other bits in DDRB must not be affected by this
 * assignment.
 */
void initLED(){
  /* PB6 is pin #25; PB5 is pin #24; PB4 is pin #23 */
  DDRB |= (1 << DDB4); // sets the output to pin PB4 WHITE LED
  DDRB |= (1 << DDB5); // sets the output to pin PB5 RED LED
  DDRB |= (1 << DDB6); // sets the output to pin PB6 GREEN LED
}

/*
 * Turns on a specified LED and turns off other LEDS using PORTB registers
 * and bit operations. This function should also not affect other bits in
 * PORTB while turning on an off LEDs. You can choose which number corresponsds
 * to which LED, but this mapping should be matching the testLED function.
 */
void turnOnLED(int led){
  if(led == 0){
    PORTB &= ~(1 << PB5); // turn off red
    PORTB &= ~(1 << PB6); // turn off white
    PORTB |= (1 << PB4); // turn green on
  }

  if (led == 1){
    PORTB &= ~(1 << PB4); // turn off green
    PORTB &= ~(1 << PB6); // turn off white
    PORTB |= (1 << PB5); // turn red on
  }

  if(led == 2){
    PORTB &= ~(1 << PB4); // turn off green
    PORTB &= ~(1 << PB5); // turn off red
    PORTB |= (1 << PB6); // turn white on
  }
}

/*
 * Tests initLEDs and turnOnLED by turning on each LED in succession.
 */
void testLED(){
  turnOnLED(0);
  _delay_ms(250.0);
  turnOnLED(1);
  _delay_ms(250.0);
  turnOnLED(2);
  _delay_ms(250.0);
}
