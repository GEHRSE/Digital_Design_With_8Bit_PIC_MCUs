
#include "InterruptManager.h"

void InterruptInitialize(void)
{
    /* IPEN (RCON<7>): Interrupt Priority Enable bit
     * 1 = Enable priority levels on interrupts
     * 0 = Disable priority levels on interrupts (default)
     */
    RCONbits.IPEN = 0; //Sistema de prioridad de interrupciones deshabilitado
    
    /* TMR0IE (INTCON<5>): TMR0 Overflow Interrupt Enable bit
     * 1 = Enable the TMR0 overflow interrupt
     * 0 = Disable the TMR0 overflow interrupt (default)
     */
    //INTCONbits.TMR0IE = 1;
    
    /* TMR1IE (PIE1<0>): TMR1 Overflow Interrupt Enable bit
     * 1 = Enable the TMR1 overflow interrupt
     * 0 = Disable the TMR1 overflow interrupt (default)
     */
    PIE1bits.TMR1IE = 1;
    
    PeripheralInterruptEnable();
    GlobalInterruptEnable();
}

void interrupt InterruptManager()
{
    if(PIR1bits.TMR1IF == 1)
    {
        //TMR1ISR
        TMR1InterruptRoutine();
    }
}