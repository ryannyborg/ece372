// Author:         Laura Camp, Ryan Nyborg, Megan Lubbers
// Net ID:         lauracamp, rnyborg, meglubbers
// Date:           28 March 2017
// Assignment:     Lab 3 Part 2
//
// Description: This file contains a programmatic overall description of the
// program. It should never contain assignments to special function registers
// for the exception key one-line code such as checking the state of the pin.
//
// Requirements:
//----------------------------------------------------------------------//

#include <Arduino.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "serial.h"
#include "i2c.h"

typedef enum stateType_enum{
  start, rep_start, slave_read, find_val, stop
} stateType;

volatile unsigned char recv_val = 0;
volatile stateType state = start;

/* the goal of this is to set the master as a receiver

1.) START condition is sent (set TWEN, TWINT, TWSTA to 1)
2.) TWINT Flag is set by hardware (status code will be 0x08)
3.) Transmit SLA+R (write SLA+R to TWDR)
4.) TWINT bit should be cleared (write it to one; update
TWCR register to have TWINT and TWEN equal to 1; rest are zero
5.) After SLA+R has been transmitted and acknowledgement
has been received, we can have status codes 0x38, 0x40, or 0x48
6.) Read data from TWDR Register when TWINT Flag is HIGH
7.) After the last byte, send NACK to slave.
8.) Generate repeated START condition by setting TWINT, TWSTA, TWEN
to 1 and TWSTO to 0 (code is 0x10 for repeated start)
9.) Repeat again?

*/

volatile int value = 0;
volatile unsigned char slave_address = 0x55;
volatile unsigned char register_addr = 0xAA;
volatile unsigned char letter = 'A';


int main(){
  initSerial0(9600);
  initI2CMaster();
  sei();


  resetI2C();

  while(1){
    if(startI2C() == 1){
      readSlave(slave_address, register_addr);
      findValue();
      letter = stopI2C();

       // clear flag
       UCSR0A |= (1 << UDRE0);
       while ( !( UCSR0A & (1<<UDRE0)) );

       UDR0 = letter; // data from slave
    }
  }
    return 0;
}

ISR(USART0_RX_vect){
}

ISR(USART0_TX_vect){
}
