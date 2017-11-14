// Author:         Ryan Nyborg
// Net ID:         rnyborg
// Date:           23 Jan 2017
// Assignment:     Lab 0 part 1
//
// Description: This file contains a programmatic overall description of the
// program. It should never contain assignments to special function registers
// for the exception key one-line code such as checking the state of the pin.
//
// Requirements: Implement initLED and turnOnLED according to the requirements
// described in the .cpp files.
//----------------------------------------------------------------------//

#include <avr/io.h>
#include <Arduino.h>
#include "led.h"

int main(){

  Serial.begin(9600);
  
  initLED();

  while(1){
    testLED();
  }

  return 0;
}
