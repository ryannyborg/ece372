// Author:         Ryan Nyborg
// Net ID:         rnyborg
// Date:           13 February 2017
// Assignment:     Lab 1 part 2
//
// Description: This file contains a programmatic overall description of the
// program. It should never contain assignments to special function registers
// for the exception key one-line code such as checking the state of the pin.
//
// Requirements:
//----------------------------------------------------------------------//

#include <avr/io.h>
#include "lcd.h"
#include "timer.h"
#include <Arduino.h>


int main(){

  Serial.begin(9600);
  // Initialze timer, LCD, and write Hello!
  initTimer1();
  initLCD();

  writeString("Arizona");

  // skips down to second line
  writeDataWithUsDelay(0xC, 0); // first bit has to be 1 according to data sheet to set the DD RAM address
  writeDataWithUsDelay(0x0, 2000);

  writeString("Wildcats");

  /*
  * No state machine this time around.
  */
  while(1){

  }

  return 0;
}
