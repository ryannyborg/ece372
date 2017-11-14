#include "adc.h"
#include <avr/io.h>

//10 bit ADC

void initADC0(){
  //set AVCC as positive reference
  ADMUX |= (1 << REFS0);
  //disable ADC0 pin digital input
  DIDR0 |= (1 << ADC0D);
  //turns on the ADC, enables auto trigger, etc.
  ADCSRA |= (1 << ADEN | 1 << ADSC | 1 << ADATE | 1 << ADIE);
}
