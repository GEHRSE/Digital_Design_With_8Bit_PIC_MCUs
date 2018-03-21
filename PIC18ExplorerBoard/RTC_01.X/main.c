/*
 * File:   main.c
 * Author: Lenovo
 *
 * Created on 27 de marzo de 2017, 12:46 PM
 */
//Frecuencia de Trabajo Fosc = 40 MHz

#include "SystemInitialize.h"
#include "StateIntro.h"
#include "StateClock.h"

// Enumerations
enum {StIntro, StClock} StateMachine;
unsigned char State = StIntro;

/*
                         Main application
 */
void main(void)
{
    SysInitialize();
    
    while(1)
    {
        switch(State)
        {
            case StIntro: Intro();
            break;
            case StClock: Clock();
            break;
        }
    }
}
//------------------------------------------------------------------------------

