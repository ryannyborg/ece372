// Author: Laura Camp, Ryan Nyborg, Megan Lubbers
// Net ID: lauracamp, rnyborg, meglubbers
// Date:  4/9/2017
// Assignment: Project Demonstration #1
//
// Description:
//----------------------------------------------------------------------//
#include "pwm.h"
#include <Arduino.h>

// Clock is 16 MHz
void initPWM(){
  // Configure Timer 1 to fast PWM, 10 bit
    TCCR1A |= (1 << WGM10 | 1 << WGM11);
    TCCR1B |= (1 << WGM12);
    TCCR1B &= ~(1 << WGM13);

  // Configure Timer 3 to fast PWM, 10 bit
    TCCR3A |= (1 << WGM10 | 1 << WGM11);
    TCCR3B |= (1 << WGM12);
    TCCR3B &= ~(1 << WGM13);

  // set prescalar to 1
    TCCR1B |= (1 << CS10);
    TCCR1B &= ~(1 << CS11 | 1 << CS12);
    TCCR3B |= (1 << CS10);
    TCCR3B &= ~(1 << CS11 | 1 << CS12);

  // set clear on compare match mode   //noninverting mode
    TCCR1A |= (1 << COM1A1 | 1 << COM1B1);
    TCCR1A &= ~(1 << COM1A0 | 1 << COM1B0);
    TCCR3A |= (1 << COM1A1 | 1 << COM1B1);
    TCCR3A &= ~(1 << COM1A0 | 1 << COM1B0);

  //set duty cycles
    OCR1AH = 0x00;
    OCR1AL = 0x00;

  // set the pin as output (this must be done last)
    DDRB |= (1 << DDB5); //pin 11 on board
}

void fanOn(unsigned int adc_val){
  OCR1AH = (adc_val >> 8); //top 8 bits of adc
  OCR1AL = adc_val & 0x00FF; //lower 8 bits of adc
}
void fanOff(){
  OCR1AH = 0x00;
  OCR1AL = 0x00;
}
