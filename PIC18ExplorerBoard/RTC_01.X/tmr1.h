/* 
 * File:   tmr1.h
 * Author: Sebastián
 *
 * Created on 9 de marzo de 2016, 05:27 PM
 */

#ifndef TMR1_H
#define	TMR1_H

#include <stdint.h>

uint8_t Timer1Flag;

//Macros para los valores de pre-escalar del Timer1

#define T1PS_1 0b00
#define T1PS_2 0b01
#define T1PS_4 0b10
#define T1PS_8 0b11

//Prototipos de funciones

void TMR1Initialize(void); //Configuración inicial del Timer0
void TMR1Start(void); //Start Timer0
void TMR1Stop(void); //Stop Timer0
uint16_t TMR1Read(void); //Lectura del valor del Timer0
void TMR1Write(uint16_t ValTMR1); //Escribir un valor al registro del Timer0
void TMR1InterruptRoutine(void); //Rutina para la interrupción del Timer0

#endif	/* TMR1_H */

