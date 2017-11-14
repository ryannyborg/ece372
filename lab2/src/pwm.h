// Author:
// Net ID:
// Date:
// Assignment:
//
// Description:
//----------------------------------------------------------------------//

#ifndef PWM_H
#define PWM_H
#include <avr/io.h>

typedef enum motorStateType_enum{
   forward, reverse, idle
 } motorStateType;


void initPWM();
void setMotor1Forward();
void setMotor1Reverse();
void setMotor1Off();
void setMotor2Off();

#endif
