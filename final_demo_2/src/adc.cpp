// Author: Laura Camp, Ryan Nyborg, Megan Lubbers
// Net ID: lauracamp, rnyborg, meglubbers
// Date:  4/9/2017
// Assignment: Project Demonstration #1
//
// Description:
//----------------------------------------------------------------------//

#include "adc.h"
#include <avr/io.h>

//10 bit ADC

void initADC0(){
  //set AVCC as positive reference
  ADMUX |= (1 << REFS0);
  //disable ADC0 pin digital input
  DIDR0 |= (1 << ADC0D);
  DIDR0 |= (1 << ADC1D);
  //turns on the ADC, enables auto trigger, etc.
  ADCSRA |= (1 << ADEN | 1 << ADSC | 1 << ADATE | 1 << ADIE);
  ADCSRA |= (1<<ADPS0 |1<<ADPS1);
}
