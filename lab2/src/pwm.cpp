// Author:
// Net ID:
// Date:
// Assignment:
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
    OCR1BH = 0x00;
    OCR1BL = 0x00;
    OCR3AH = 0x00;
    OCR3AL = 0x00;
    OCR3BH = 0x00;
    OCR3BL = 0x00;
    
  // set the pin as output (this must be done last)
    DDRB |= (1 << DDB5); //pin 11 on board
    DDRB |= (1 << DDB6); //pin 12 on board

    DDRE |= (1 << DDE3); // pin 5 on board
    DDRE |= (1 << DDE4); // pin 2 on board
}

void setMotor1Forward(){
  OCR1AH = 0x00; //Motor 1 Forward
  OCR1AL = 0x00;
  OCR1BH = 0x03;
  OCR1BL = 0x00;

  OCR3AH = 0x03; //Motor 2 Reverse
  OCR3AL = 0x00;
  OCR3BH = 0x00;
  OCR3BL = 0x00;
}
void setMotor1Reverse(){
  OCR1AH = 0x03; //Motor 1 Reverse
  OCR1AL = 0x00;
  OCR1BH = 0x00;
  OCR1BL = 0x00;

  OCR3AH = 0x00; //Motor 2 Forward
  OCR3AL = 0x00;
  OCR3BH = 0x03;
  OCR3BL = 0x00;
}
void setMotor1Off(){
  OCR1AH = 0x00;
  OCR1AL = 0x00;
  OCR1BH = 0x00;
  OCR1BL = 0x00;
}
void setMotor2Off(){
  OCR3AH = 0x00;
  OCR3AL = 0x00;
  OCR3BH = 0x00;
  OCR3BL = 0x00;
}



// void switchPWM(){
//
//   volatile motorStateType state = idle;
//   switch(state){
//     case idle:
//     Serial.println("idle");
//     OCR1AH = 0x00;
//     OCR1AL = 0x00;
//     OCR3AH = 0x00;
//     OCR3AL = 0x00;
//     state = forward;
//         break;
//     case forward:
//     OCR1AH = 0x00;
//     OCR1AL = 0x00;
//     OCR3AH = 0x03;
//     OCR3AL = 0x00;
//     Serial.println("forward");
//     state = reverse;
//         break;
//     case reverse:
//     Serial.println("reverse");
//     OCR1AH = 0x03;
//     OCR1AL = 0x00;
//     OCR3AH = 0x00;
//     OCR3AL = 0x00;
//     state = idle;
//         break;
// }
// }
