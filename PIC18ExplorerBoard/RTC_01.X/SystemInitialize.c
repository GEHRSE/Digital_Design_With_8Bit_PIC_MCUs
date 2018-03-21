
#include "SystemInitialize.h"

void SysInitialize(void)
{
    PortInitialize();
    InterruptInitialize();
    TMR1Initialize();
    EUSART1_Initialize();
    return;
}

void PortInitialize(void)
{
    LATA = 0;
    scroll_dir = 1;
    LATB = 0;
    select_dir = 1;
    LEDS_DIR = 0;
    LEDS = 0x00;
    
    ADCON1bits.PCFG = 0b1111;
    
    return;
}

/*******************************************************************
* FUNCTION:     SWdelay ()
* INPUTS:       None
* OUTPUTS:      None
* DESCRIPTION:  Delay after pressing the RB0 and RB5 switch buttons
********************************************************************/
void SWdelay (void)
{
    while(scroll == pressed)
    {
        __delay_ms(1);
        LEDS = 0x0F;
    }
    while (select == pressed)
    {
        __delay_ms(1);
        LEDS = 0xF0;
    }
}