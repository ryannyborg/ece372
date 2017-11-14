// Author:         Laura Camp, Ryan Nyborg, Megan Lubbers
// Net ID:         lauracamp, rnyborg, meglubbers
// Date:           28 March 2017
// Assignment:     Lab 3 Part 2
//
// Description: This file contains a programmatic overall description of the
#include <avr/interrupt.h>
#include <avr/io.h>
#include "i2c.h"
#include "serial.h"

int main(){
  initSerial0();
  sei();
  initI2CSlave();

  while(1){
  }
  return 0;
}
ISR(TWI_vect){
  if(TWSR == TW_SR_SLA_ACK){
    TWDR = 0x50;
  }
  TWCR |= (1<< TWINT);
}

ISR(USART0_RX_vect){
}
ISR(USART0_TX_vect){
}
