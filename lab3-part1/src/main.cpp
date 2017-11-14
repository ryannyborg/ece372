//Authors: Laura Camp, Ryan Nyborg, Megan Lubbers
//NetIDs: lauracamp, rnyborg, meglubbers
//Date: 3/3/2017
//Project Name: lab3-part1
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
#include "pwm.h"
#include "adc.h"
#include "switch.h"

typedef enum stateType_enum{
  waitPress, chirpState, chirpDone, dbPress, waitRelease, dbRelease
} stateType;
volatile stateType state = waitPress;


#define X_MOVEMENT 1000
#define Y_MOVEMENT 1000
#define Z_MOVEMENT 400

#define ADC_X 0
#define ADC_Y 1
#define ADC_Z 2

volatile unsigned int adc_val = 0;
volatile unsigned int adc1_val = 0;
volatile unsigned int adc2_val = 0;
volatile unsigned int adc_state = 0;
volatile unsigned int adc_flag = 0;


int main(){

  Serial.begin(9600);
  sei(); // enable global interrupts

  // initialize here
initTimer1();
initADC0();
initPWM();
initSwitchPB3();


  while(1){
    switch(state){
      case waitPress:
        if(adc_flag == 1){
          state = chirpState;
        }
      break;
      case chirpState:
        Serial.println("chirppppppppppppppppppppppp");
        chirp();
      break;
      case chirpDone:
      break;
      case dbPress:
      state = waitRelease;
      break;
      case waitRelease:
      break;
      case dbRelease:
        Serial.println("dbRelease");
        stopChirp();
        adc_flag = 0;
        initADC0();
        state = waitPress;
      break;
          }
  }
  return 0;
}

ISR(ADC_vect){

if(adc_state == ADC_X){
  ADMUX &= ~(1 << MUX0 |1 << MUX1);
  adc_val = ADCL;
  adc_val = adc_val | (ADCH << 8);
  Serial.print(" x:");
  Serial.print(3*adc_val);
  adc_state = ADC_Y;
}
else if(adc_state == ADC_Y){
  ADMUX &= ~(1 << MUX1);
  ADMUX |= (1 << MUX0);
  adc1_val = ADCL;
  adc1_val = adc1_val + (ADCH << 8);
  Serial.print(" y:");
  Serial.print(3*adc1_val);
  adc_state = ADC_Z;
}
else if(adc_state == ADC_Z){
  ADMUX &= ~(1 << MUX0);
  ADMUX |= (1 << MUX1);
  adc2_val = ADCL;
  adc2_val = adc2_val + (ADCH << 8);
  Serial.print(" z:");
  Serial.println(adc2_val);
 if(adc2_val > Z_MOVEMENT){
   ADCSRA |= (1 << ADEN);
  }
 else if(adc2_val < Z_MOVEMENT){
      adc_flag = 1;
     ADCSRA &= ~(1 << ADEN);
   }
  adc_state = ADC_X;
  }
 }

ISR(PCINT0_vect){
Serial.println("pin change");
  if(state == chirpState){
    state = dbPress;
  }
  else if(state == waitRelease){
    state = dbRelease;
  }
}
