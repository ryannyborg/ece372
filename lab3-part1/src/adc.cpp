//Authors: Laura Camp, Ryan Nyborg, Megan Lubbers
//NetIDs: lauracamp, rnyborg, meglubbers
//Date: 3/3/2017
//Project Name: lab3-part1
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
  DIDR0 |= (1 << ADC2D);
  //turns on the ADC, enables auto trigger, etc.
  ADCSRA |= (1 << ADEN | 1 << ADSC | 1 << ADATE | 1 << ADIE);
  ADCSRA |= (1<<ADPS0 |1<<ADPS1 |1<<ADPS2);

  //
}
