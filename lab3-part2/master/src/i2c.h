// Author:         Laura Camp, Ryan Nyborg, Megan Lubbers
// Net ID:         lauracamp, rnyborg, meglubbers
// Date:           28 March 2017
// Assignment:     Lab 3 Part 2
//
// Description:
//----------------------------------------------------------------------//

#ifndef I2C_H
#define I2C_H

#define TW_START 0x08
#define TW_REP_START 0x10
#define TW_MR_SLA_ACK 0x40
#define TW_MR_DATA_NACK 0x58
#define TW_READ 1
#define TW_WRITE 0
#define TW_MT_SLA_ACK 0x18
#define TW_MT_DATA_ACK 0x20
#define TW_MR_SLA_NACK 0x48
#define TW_MR_DATA_ACK 0x50

void initI2CMaster();
int startI2C();
void repeatedStart();
void findValue();
unsigned char stopI2C();
void readSlave(unsigned char slave_address, unsigned char register_addr);
void readDataI2C(unsigned char i2c_address, unsigned char data_to_send);
void resetI2C();


#endif
