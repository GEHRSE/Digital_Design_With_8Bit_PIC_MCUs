#include <xc.h>
#include "tmr1.h"

// *****************************************************************************
// void TMR1Initialize(void)
// Configuración inicial para el Timer1
// -----------------------------------------------------------------------------
void TMR1Initialize(void)
{
    /* TMR1ON (T1CON<0>): TICONTimer1 On bit
     * 1 = Enables Timer1
     * 0 = Stops Timer1 (default)
     */
    T1CONbits.TMR1ON = 0;
    
    /* TMR1CS (T1CON<1>): Timer1 Clock Source Select Bit
     * 1 = External clock from pin RC0/T1OS0/T13CKI (on the rising edge)
     * 0 = Internal clock (Fosc/4) (default)
     */
    T1CONbits.TMR1CS = 1;
    
    /* T1OSCEN (T1CON<3>): Timer1 Oscillator Enable bit
     * 1 = Timer1 oscillator is enabled
     * 0 = Timer1 oscillator is shut off (default)
     */
    T1CONbits.T1OSCEN = 1;
    
    /* T1CKPS<1:0> (T1CON<5:4>): Timer1 Input Clock Prescale Select bits
     * 11 = 1:8 Prescale value
     * 10 = 1:4 Prescale value
     * 01 = 1:2 Prescale value
     * 00 = 1:1 Prescale value (default)
     */
    T1CONbits.T1CKPS = T1PS_1;
    
    /* TMR1IF (PIR1<0>): TMR1 Overflow Interrupt Flag bit
     * 1 = TMR1 register overflowed (must be cleared in software)
     * 0 = TMR1 register did not overflow
     */
    PIR1bits.TMR1IF = 0;
    
    /* TMR1IE (PIE1<0>): TMR1 Overflow Interrupt Enable bit
     * 1 = Enable the TMR1 overflow interrupt
     * 0 = Disable the TMR1 overflow interrupt (default)
     */
    PIE1bits.TMR1IE = 1;
    
    //Valor Timer1 para un desbordamiento de 1seg (32768)
    TMR1H = 0x80; //Cargamos la parte alta
    TMR1L = 0x00; //Cargamos la parte baja del valor a cargar en el Timer0
    
    TMR1Start(); //Start Timer1

    return;
}

// *****************************************************************************
// void TMR1Start(void)
// Habilitación del Timer1
// -----------------------------------------------------------------------------
void TMR1Start(void)
{
    T1CONbits.TMR1ON = 1; //Habilitación del Timer1

    return;
}

// *****************************************************************************
// void TMR1Stop(void)
// Deshabilitación del Timer1
// -----------------------------------------------------------------------------
void TMR1Stop(void)
{
    T1CONbits.TMR1ON = 0; //Stop Timer1

    return;
}

//******************************************************************************
// uint16_t TMR1Read(void)
// Lectura al valor actual del registro TMR1
// -----------------------------------------------------------------------------
uint16_t TMR1Read(void)
{
    uint16_t ReadVal;
    uint8_t ReadValHigh;
    uint8_t ReadValLow;
    
    ReadValLow = TMR1L;
    ReadValHigh = TMR1H;
    
    ReadVal = ((uint16_t)ReadValHigh << 8) | ReadValLow;

    return ReadVal;
}

//******************************************************************************
// void TMR1Write(uint16_t ValTMR1)
// Establecer valor al registro TMR1
// -----------------------------------------------------------------------------
void TMR1Write(uint16_t ValTMR1)
{
    if (T1CONbits.T1SYNC == 1)
    {
        // Stop the Timer by writing to TMRxON bit
        T1CONbits.TMR1ON = 0;

        // Write to the Timer1 register
        TMR1H = (ValTMR1 >> 8);
        TMR1L = (uint8_t) ValTMR1;

        // Start the Timer after writing to the register
        T1CONbits.TMR1ON =1;
    }
    else
    {
        // Write to the Timer1 register
        TMR1H = (ValTMR1 >> 8);
        TMR1L = (uint8_t) ValTMR1;
    }

    return;
}

//******************************************************************************
// void TMR1InterruptRoutine(void)
// Subrutina para la atención de la interrupción por desbordamiento de TMR1
// -----------------------------------------------------------------------------
void TMR1InterruptRoutine(void)
{
    // Clear the TMR1 interrupt flag
    PIR1bits.TMR1IF = 0;
    
    // Write to the Timer1 register
    TMR1H = 0x80;
    TMR1L = 0x00;

    // Add your TMR1 interrupt custom code
    Timer1Flag = 1;

    return;
}

// *****************************************************************************
// Sebastián F. Puente Reyes
// Septiembre 2016
// Universidad de los Llanos
// -----------------------------------------------------------------------------