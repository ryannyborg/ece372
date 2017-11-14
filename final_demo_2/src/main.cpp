// Author: Laura Camp, Ryan Nyborg, Megan Lubbers
// Net ID: lauracamp, rnyborg, meglubbers
// Date:  4/9/17
// Assignment: Project Demonstration #1
//
// Description: This file contains a programmatic overall description of the
// program. It should never contain assignments to special function registers
// for the exception key one-line code such as checking the state of the pin.
//
// Requirements:
//----------------------------------------------------------------------//

#include <Arduino.h>
#include <avr/io.h>
#include "timer.h"
#include "adc.h"
#include "pwm.h"

volatile unsigned int adc_val = 0;
volatile unsigned int adc1_val = 0;
volatile unsigned int adc_state = 0;


#define ADC_TEMP 0 //temperature adc
#define ADC_MOISTURE 1 //soil moisture adc
#define TEMP_THRESHOLD 730 //adc value to begin fan
#define MOISTURE_THRESHOLD 400 //adc value to begin watering


int main(){
  Serial.begin(9600);
  sei(); // enable global interrupt

  // initialize here
  initTimer1();
  initADC0();
  initPWM();

  while(1){
    // temp sensor
      ADMUX &= ~(1 << MUX0 |1 << MUX1);
      adc_val = ADCL;
      adc_val = adc_val | (ADCH << 8);
      Serial.print(" temp:");
      Serial.print(4*adc_val);
      Serial.println("");
     if(4*adc_val > TEMP_THRESHOLD){
       fanOn(adc_val*4);
       Serial.print(" FAN ");
     }
     else if(4*adc_val < TEMP_THRESHOLD){
       fanOff();
     }


    //  // soil moisture
    //  ADMUX &= ~(1 << MUX1);
    //  ADMUX |= (1 << MUX0);
    //  adc1_val = ADCL;
    //  adc1_val = adc1_val + (ADCH << 8);
    //  Serial.print(" moisture:");
    //  Serial.print(adc1_val);
    //  Serial.println("");
    //  adc_state = ADC_TEMP;
    //  if(adc1_val < MOISTURE_THRESHOLD){
    //    waterOn();
    //    fanOff();
    //    Serial.println(" WATER ");
    //  }
    //  else if(adc1_val > MOISTURE_THRESHOLD){
    //    waterOff();
    //    Serial.println(" ");
    //  }


    ADCSRA |= (1 << ADIF);

}

  return 0;
}

ISR(ADC_vect){
  // if(adc_state == ADC_TEMP){ //reading temp
  //    ADMUX &= ~(1 << MUX0 |1 << MUX1);
  //    adc_val = ADCL;
  //    adc_val = adc_val | (ADCH << 8);
  //    Serial.print(" temp:");
  //    Serial.print(4*adc_val);
  //   //
  //   if(4*adc_val > TEMP_THRESHOLD){
  //     fanOn(adc_val*4);
  //     Serial.print(" FAN ");
  //   }
  //   else if(4*adc_val < TEMP_THRESHOLD){
  //     fanOff();
  //   }
  //   adc_state = ADC_MOISTURE;
  //
  // }

//   else if(adc_state == ADC_MOISTURE){ //reading moisture
//     ADMUX &= ~(1 << MUX1);
//     ADMUX |= (1 << MUX0);
//     adc1_val = ADCL;
//     adc1_val = adc1_val + (ADCH << 8);
//     Serial.print(" moisture:");
//     Serial.print(adc1_val);
//     adc_state = ADC_TEMP;
//     if(adc1_val < MOISTURE_THRESHOLD){
//       waterOn();
//       fanOff();
//       Serial.println(" WATER ");
//     }
//     else if(adc1_val > MOISTURE_THRESHOLD){
//       waterOff();
//       Serial.println(" ");
//     }
// }

}