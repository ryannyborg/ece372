// Author:         Ryan Nyborg
// Net ID:         rnyborg
// Date:           25 January 2017
// Assignment:     Lab 0 part 2
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

#define BUTTON_PUSHED 1


/*
 * Define a set of states that can be used in the state machine using an enum
 */

 typedef enum stateType_enum{
    led_off, led_on
 } stateType;

 stateType state = led_off;

 int led_selector = 0;

int main(){

Serial.begin(9600);
initSwitchPB3();
initLED();

  /*
  * Implement a state machine in the while loop which achieves the assignment
  * requirements.
  */
  while(1){

    switch(state){
      case led_off:
        //Serial.println("In state: led_off.");
        Serial.println(led_selector);
        if((PINB & (BUTTON_PUSHED << PINB3))){
          Serial.println("Pin pressed.");
          state = led_on;
        }
        break;
      case led_on:
        //Serial.println("In state: led_on.");
        turnOnLED(led_selector);
        if(!(PINB & (BUTTON_PUSHED << PINB3))){
          Serial.println("Pin released.");
          led_selector += 1; // LED count iterator
           // LED mod 3 to always keep number between 0-2
          led_selector = led_selector % 3;
          state = led_off;
        }
        break;
    }


  }

  return 0;
}
