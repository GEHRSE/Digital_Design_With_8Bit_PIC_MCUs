
#include "StateIntro.h"

extern unsigned char State;

/*******************************************************************
* FUNCTION:     Intro ()
* INPUTS:       None
* OUTPUTS:      None
* DESCRIPTION:  Displays the Introductory Text on LCD and host PC
********************************************************************/
void Intro(void)
{
    // Initialize LCD
    mOPEN_LCD;
    
    // Display Intro text on LCD
    mCURSOR_LINE1;
    LCDPutStr("  MPUs y MCUs  ");
    mCURSOR_LINE2;
    LCDPutStr(" Ing Electronik ");
    
    printf("   MPUs y MCUs  \n\r");
    printf(" Ing Electronik \n\r");

    // Delay before switching to the next display
    IntroDelay();

    // Switch to Voltmeter application
    State++;
}

/*******************************************************************
* FUNCTION:     Intro_delay ()
* INPUTS:       None
* OUTPUTS:      None
* DESCRIPTION:  Delays the display of Introductory Text on LCD
********************************************************************/
void IntroDelay(void)
{
    uint8_t i;
    uint8_t aux = 0;
    uint8_t n = 0;
    
    for (i=0;i<100;i++)
    {
        LEDS = aux;
        if(n == 0)
        {
            aux = 0b10000000 | (aux>>1);
            if(aux == 255) n = 1;
        }
        if(n == 1)
        {
            aux = aux>>1;
            if(aux == 0) n = 0;
        }
        __delay_ms(40);
    }
    LEDS = 0;
}