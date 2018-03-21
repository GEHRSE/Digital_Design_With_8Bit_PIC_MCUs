/*
 * File:   main.c
 * Author: Lenovo
 *
 * Created on 15 de marzo de 2018, 11:28 AM
 */

// C-code for the master SPI PIC18F45K20 device:

#include <xc.h>

void SPI_out(unsigned char);

void main (void)
{
    unsigned char output;
    
    OSCCONbits.IRCF = 0b111;
    
    TRISCbits.TRISC5 = 0; // Configure SDO as output
    TRISCbits.TRISC3 =0; // Configure SCK as output
    
    ANSELHbits.ANS12 = 0;
    ANSELHbits.ANS10 = 0;
    ANSELHbits.ANS8 = 0;
    ANSELHbits.ANS9 = 0;
    
    ANSELH |= (0b11101000);
    
    SSPSTAT= 0x40; // Transmission occurs on high to low clock
    //SSPSTATbits.CKE = 1;
    
    SSPCON1 = 0x20; // Enable serial functions and set as master device
    
//    SSPCON1bits.SSPM = 0b0000; //SPI Master mode, clock = FOSC/4
//    SSPCON1bits.CKP = 0; //Idle state for clock is a low level
//    /*Enables serial port and configures SCK, SDO, SDI and SS as serial port pins.
//     * When enabled, the SDA and SCL pins must be configured as inputs.
//     */
//    SSPCON1bits.SSPEN = 1;
    
    while(1)
    {
        output = PORTB; // Move switch value to output
        SPI_out(output); // Send variable ?output? to SPI_out
    }
}

void SPI_out(unsigned char SPI_data)
{
    SSPBUF = SPI_data; // Place switch value into the serial buffer
    while (SSPSTATbits.BF == 0); // Wait for transmission to finish
}