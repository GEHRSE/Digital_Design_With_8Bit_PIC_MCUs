/*
 * File:   main.c
 * Author: Lenovo
 *
 * Created on 15 de marzo de 2018, 01:08 PM
 */


#include <xc.h>
#include "ConfigurationBits.h"

void main (void)
{
    OSCCONbits.IRCF = 0b111;
    
    TRISCbits.TRISC4 = 1; // Configure SDI as input
    TRISCbits.TRISC3 =1; // Configure SCK as input
    TRISD=0x00; // ConfigurePORTD as output for LEDs
    SSPSTAT= 0x40; // Transmission occurs on high to low clock
    SSPCON1 = 0x25; // Enable serial functions and disable the slave device
    
    while(1)
    {
        while(SSPSTATbits.BF == 0); // Wait for transmission to finish
        PORTD=SSPBUF; // Move serial buffer to PORTD
    }
}