// Author:         Laura Camp, Ryan Nyborg, Megan Lubbers
// Net ID:         lauracamp, rnyborg, meglubbers
// Date:           28 March 2017
// Assignment:     Lab 3 Part 2
#include "serial.h"
#include <avr/io.h>

void initSerial0(unsigned int baud_rate){
    UCSR0A |= (1 << U2X0); // doubled the rate
    // enable the interrupts and transmit and recieve
    UCSR0B |= (1 << RXCIE0 | 1 << TXCIE0 | 1 << RXEN0 | 1 << TXEN0);
    UCSR0B &= ~(1 << UCSZ02); // 8-bit selection
    UCSR0B |= (1 << UCSZ00) | (1 << UCSZ01);
    UBRR0L = 207; // baud rate 9600
}
