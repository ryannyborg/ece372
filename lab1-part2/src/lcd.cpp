// Description: This file implements functions to operate an LCD
//----------------------------------------------------------------------//

#include "lcd.h"
#include "timer.h"
#include <util/delay.h>
#include <Arduino.h>

/* Asserts Logic High on Enable Pin
*/
void enableHigh(){
    // use pin PH6
    PORTH |= (1 << PORTH6);
}

/* Asserts Logic Low on Enable Pin
*/
void enableLow(){
    // use pin PH6
    PORTH &= ~(1 << PORTH6);
}

/* Asserts Logic Low on RS Pin
*/
void rsLow(){
    // use pin PH5
    PORTH &= ~(1 << PORTH5);
}

/* Asserts Logic High on RS Pin
*/
void rsHigh(){
    // use pin PH5
    PORTH |= (1 << PORTH5);
}

/* Initializes Tri-state for LCD pins and calls initialization procedure.
* This function is made so that it's possible to test initLCDPins separately
* from initLCDProcedure which will likely be necessary.
*/
void initLCD(){
  initLCDPins();
  initLCDProcedure();
}

/* Asserts enableHigh, delays, asserts enableLow, then delays again according to
* the specification on the data sheet. This function is meant to be called after
* the data pins have been set at appopriate values. This effectively "sends" the
* bits that are set on the data pins.
*/
void sendCommand(){
    enableHigh(); // enables high
    delayUs(1); // delays for a period of time
    enableLow(); // enables low
    delayUs(1); // delays for a period of time
}

/* Initializes all pins related to the LCD to be outputs
*/
void initLCDPins(){
    DDRA |= (1 << DDA0) | (1 << DDA1) | (1 << DDA2) | (1 << DDA3); // set LCD pins to output
    DDRH |= (1 << DDH5) | (1 << DDH6); // initialized RS and E
    DDRH |= (1 << DDH4); // initialized R/W
}

/* 1. Assert bits to pins connected to DB[7:4] on the LCD screen
*      a. data is an unsigned char which has 8 bits. Therefore, you
*         need assign the bottom 4 bits of "data" to the appropriate bits in
*         PORTA
*  2. This is a "data" signal, meaning RS should be High
*  3. send the command!
*  4. delay the provided number in MICROseconds.
*/
void writeDataWithUsDelay(unsigned char data, unsigned int delay){
    rsLow();
    // ASSERT BITS HERE.
    PORTA = (PORTA & 0xF0) | (data & 0x0F);
    sendCommand();
    delayUs(delay);
}

/* Similar to writeDataWithUsDelay except that now all eight bits of command are
* sent.
* 1. Assert bits to pins connected to DB[7:4] on the LCD screen
*       a. unlike writeDataWithUsDelay, you need to send the TOP four bits of
*          "command" first. These should be assigned to appropriate bits in PORTA
* 2. This is a command signal, meaning RS should be Low
* 3. send the command!
* 4. Now set the lower four bits of command to appropriate bits in PORTA
* 5. Send the command!
* 6. delay the provided number in MICROseconds.
*/
void writeCommandWithUsDelay(unsigned char command, unsigned int delay){

    rsHigh();
    // ASSERT BITS TO TOP HERE
    PORTA = (PORTA & 0xF0)|(command >> 4);
    sendCommand();

    // ASSERT BITS TO BOTTOM HERE
    PORTA = (PORTA & 0xF0) | (command & 0x0F);

    sendCommand();
    delayUs(delay);
}

/* Writes a character to the LCD screen. This is done by giving a character
* such as 'G' to writeCommandWithUsDelay and delaying according to the datasheet.
*/
void writeCharacter(unsigned char character){
    writeCommandWithUsDelay(character, 46);
}

/* Writes a provided string such as "Hello!" to the LCD screen. You should
* remember that a c string always ends with the '\0' character
*/
void writeString(const char *string){
    unsigned int i = 0;
    while(i < strlen(string)){
      writeCharacter(string[i]);
      i++;
    }
}

/* This is the procedure outline on the LCD datasheet page 4 out of 9.
* This should be the last function you write as it largely depends on all other
* functions working.
*/
void initLCDProcedure(){
  // Delay 15 milliseconds
  delayUs(15000);
  // Write 0b0011 to DB[7:4] and delay 4100 microseconds
  writeDataWithUsDelay(0x3, 4300);
  // Write 0b0011 to DB[7:4] and delay 100 microseconds
  writeDataWithUsDelay(0x3, 100);

  // The data sheet does not make this clear, but at this point you are issuing
  // commands in two sets of four bits. You must delay after each command
  // (which is the second set of four bits) an amount specified on page 3 of
  // the data sheet.
  // write 0b0011 to DB[7:4] and no delay
  writeDataWithUsDelay(0x3, 0);

  // write 0b0010 to DB[7:4] and delay.
  writeDataWithUsDelay(0x2, 46);

  // Function set in the command table
  writeDataWithUsDelay(0x2, 0);
  writeDataWithUsDelay(0x8, 46);


  // Display off in the command table
  writeDataWithUsDelay(0x0, 0);
  writeDataWithUsDelay(0x8, 46);

  // Clear display in the command table. Remember the delay is longer!!!
  writeDataWithUsDelay(0x0, 0);
  writeDataWithUsDelay(0x1, 2000);

  // Entry Mode Set in the command table.
  writeDataWithUsDelay(0x0, 0);
  writeDataWithUsDelay(0x6, 46);

  // Display ON/OFF Control in the command table. (Yes, this is not specified),
  // in the data sheet, but you have to do it to get this to work. Yay datasheets!)
  writeDataWithUsDelay(0x0, 0);
  writeDataWithUsDelay(0xC, 46);

}
