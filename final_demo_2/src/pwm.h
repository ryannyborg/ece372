// Author: Laura Camp, Ryan Nyborg, Megan Lubbers
// Net ID: lauracamp, rnyborg, meglubbers
// Date:  4/9/2017
// Assignment: Project Demonstration #1
//
// Description:
//----------------------------------------------------------------------//

#ifndef PWM_H
#define PWM_H
#include <avr/io.h>



void initPWM();
void fanOn(unsigned int adc_val);
void fanOff();
void waterOn();
void waterOff();

#endif