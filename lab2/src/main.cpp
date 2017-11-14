// Author:         Laura Camp
// Net ID:         lauracamp
// Date:           20 February 2017
// Assignment:     Lab 2
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
#include "switch.h"

volatile unsigned int adc_val = 0;

typedef enum stateType_enum{
  waitPress, dbPress, waitRelease, dbRelease
} stateType;
volatile stateType state = waitPress;


volatile unsigned int motorState = 0;

int main(){
  Serial.begin(9600);
  sei(); // enable global interrupt

  // initialize here
  initTimer1();
  initADC0();
  initPWM();
  initSwitchPB3();


  while(1){
    switch(state){
      case waitPress:
          break;
        case dbPress:
            state = waitRelease;
          break;
        case waitRelease:
          break;
        case dbRelease:
        Serial.println("dbrelease");

          if (motorState == 2){ //Reverse
            Serial.println("reverse");
            setMotor1Reverse();
            motorState = 0;
            state = waitPress;
            break;
          }
          else if (motorState == 1){ //Forward
            Serial.println("forward");
            setMotor1Forward();
            motorState = 2;
            state = waitPress;
            break;
          }
          else if (motorState == 0){ //Idle
            Serial.println("idle");
            setMotor1Off();
            motorState = 1;
            state = waitPress;
            break;
          }
    break;
  }
}
  return 0;
}

ISR(ADC_vect){
  //Serial.print("value: ");
  adc_val = ADCL;
  adc_val = adc_val + (ADCH << 8);
if(adc_val > 800){ //all the way up m1 on, m2 off
  setMotor2Off();
}
if(adc_val < 400){ //all the way down m1 off, m2 on
  setMotor1Off();
}
else { //both m1 and m2 on, set to current motor state
  if (motorState == 2){
    setMotor1Reverse();
  }
  else if (motorState == 1){
  setMotor1Forward();
  }
  else if (motorState == 0){
    setMotor1Off();
    setMotor2Off();
  }
}
//  Serial.println(adc_val);
}
ISR(PCINT0_vect){
Serial.println("pin change");
  if(state == waitPress){
    state = dbPress;
  }
  else if(state == waitRelease){
    state = dbRelease;
  }
}


// switch(status){
//   case idle:
//   setMotor1Off();
//   status = forward;
//   break;
//   case forward:
//   setMotor1Forward();
//   status = reverse;
//   break;
//   case reverse:
//   setMotor1Reverse();
//   status = idle;
//   break;
//  }
