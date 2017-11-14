// Author:         Ryan Nyborg
// Net ID:         rnyborg
// Date:           6 February 2017
// Assignment:     Lab 1 part 1
//
// Description: This file contains a programmatic overall description of the
// program. It should never contain assignments to special function registers
// for the exception key one-line code such as checking the state of the pin.
//
// Requirements:
//----------------------------------------------------------------------//
#include <Arduino.h>
#include <avr/io.h>
#include "led.h"
#include "switch.h"
#include "timer.h"

#define NORMAL_SPEED 1
#define DOUBLE_SPEED 2

/*
 * Define a set of states that can be used in the state machine using an enum
 */

 typedef enum stateType_enum{
    waitPress, dbPress, waitRelease, dbRelease
 } stateType;

 volatile stateType state = waitPress;

 volatile int counter = 0;
 volatile int multiplier = NORMAL_SPEED;

int main(){

  Serial.begin(9600);
  initSwitchPB3();
  initTimer1();
  initLED();
  sei(); // enable global interrupts

  /*
  * Implement a state machine in the while loop which achieves the assignment
  * requirements.
  */
  delayMs(100/multiplier);
  while(1){
    /* After 100 ms, increment the binary number represented by the LEDs
    */
    //delay
    delayMs(100/multiplier);
    counter++;
    //turn on the led
    turnOnLEDWithChar(counter);

    switch(state){
      case waitPress:
        break;
      case dbPress:
        // Serial.println("dbPress!");
        state = waitRelease;
        break;
      case waitRelease:
        // Serial.println("waitRelease");
        break;
      case dbRelease:
        // Serial.println("dbRelease!");
        Serial.println(multiplier);
        if(multiplier == NORMAL_SPEED){
          multiplier = DOUBLE_SPEED;
        }
        else if (multiplier == DOUBLE_SPEED){
          multiplier = NORMAL_SPEED;
        }
        state = waitPress;
        break;
      }
  }

  return 0;
}

/* Implement an Pin Change Interrupt which handles the switch being
* pressed and released. When the switch is pressed an released, the LEDs
* change at twice the original rate. If the LEDs are already changing at twice
* the original rate, it goes back to the original rate.
*/

ISR(PCINT0_vect){
  // Serial.println("switch HIT!");
  if (state == waitPress){
    state = dbPress;
  }
  else if (state == waitRelease){
    state = dbRelease;
  }
}
