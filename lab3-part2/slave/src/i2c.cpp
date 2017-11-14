// Author:         Laura Camp, Ryan Nyborg, Megan Lubbers
// Net ID:         lauracamp, rnyborg, meglubbers
// Date:           28 March 2017
// Assignment:     Lab 3 Part 2
//
// Description:
//----------------------------------------------------------------------//

#include <Arduino.h>
#include <avr/io.h>
#include "i2c.h"

void initI2CSlave(){
  TWCR &= ~(1 << TWINT);
  TWCR = (1 << TWEN) | (1<<TWEA) | (1<<TWIE); // enabled TWI
  TWAR = 0x55 << 1; // sets the slaves address
}
