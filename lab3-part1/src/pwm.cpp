//Authors: Laura Camp, Ryan Nyborg, Megan Lubbers
//NetIDs: lauracamp, rnyborg, meglubbers
//Date: 3/3/2017
//Project Name: lab3-part1
//
// Description:
//----------------------------------------------------------------------//
#include "pwm.h"
#include <Arduino.h>
#include "timer.h"

// Clock is 16 MHz
void initPWM(){
  // Configure Timer 1 to fast PWM, 10 bit
    TCCR1A |= (1 << WGM10 | 1 << WGM11);
    TCCR1B |= (1 << WGM12);
    TCCR1B &= ~(1 << WGM13);
  // set prescalar to 1
    TCCR1B |= (1 << CS10);
    TCCR1B &= ~(1 << CS11 | 1 << CS12);
  // set clear on compare match mode   //noninverting mode
    TCCR1A |= (1 << COM1A1);
    TCCR1A &= ~(1 << COM1A0);
  //set duty cycles
    OCR1AH = 0x00;
    OCR1AL = 0x00;
  // set the pin as output (this must be done last)
    DDRB |= (1 << DDB5); //pin 11 on board
}

void chirp(){
int i = 0x0000;
//iterate from 8k to 666 within 100ms -> drop 73 each 1 Ms interval
for(i=0x1F40; i>= 0x029A; i=i-73){ //high = 16M/24k = 8k, low = 16M/2k = 666
  OCR1AH = i>>8; //top 8 bits of i
  OCR1AL = i & 0x00FF; // bottom 8 bits
  delayMs(1);
  }
}

void stopChirp(){
  OCR1AH = 0x00;
  OCR1AL = 0x00;
}
