// Author: Laura Camp, Ryan Nyborg, Megan Lubbers
// Net ID: lauracamp, rnyborg, meglubbers
// Date: 28 March 2017
// Assignment: Lab 3 Part 2
//
// Description:
//----------------------------------------------------------------------//

#include <avr/io.h>
#include <Arduino.h>
#include "i2c.h"

void initI2CMaster(){
  TWBR = 0x0F; // set the TWI frequency to something
  TWCR |= (1 << TWEN); // enabled TWI
}

int startI2C(){
  // send a start condition
  TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN); // send start condition
  // after sent, the TWINT Flag is set to HIGH
  while (!(TWCR & (1 << TWINT))); // wait while flag is low
  if((TWSR & 0xF8) != TW_START){
    return 0;
  }
  return 1;
}

void repeatedStart(){
  //data byte transmitted and acknowledgement is received
  // send repeated start to switch to MR mode
  TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
  while(!(TWCR & (1 << TWINT))); // wait until done

  if (TWSR != TW_REP_START){
  }
}

void readSlave(unsigned char slave_address, unsigned char register_addr){
  // start with a write to the slave
  TWDR = (slave_address << 1) | 1; // put slave address in data register
  TWCR = (1 << TWINT) | (1 << TWEN); // send address to the slave

  while (!(TWCR & (1 << TWINT))); // wait until sent
  // check TWSR
  if((TWSR == TW_START) || (TWSR == 0x10)){
    repeatedStart();
  }
  if(TWSR != TW_MR_SLA_ACK){
  }
}

void findValue(){
  // SLA+R transmitted, acknowledge received
  // get value from register on the slave
  TWCR = (1 << TWINT) | (1 << TWEN);
  while(!(TWCR & (1 << TWINT))); // wait until done
  if (TWSR != TW_MR_DATA_NACK){
  }
}

unsigned char stopI2C(){
  // data byte received, Nack has been returned
  // send stop bit
  TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);

  return TWDR;
}

void resetI2C(){
  TWCR = 0;
}
