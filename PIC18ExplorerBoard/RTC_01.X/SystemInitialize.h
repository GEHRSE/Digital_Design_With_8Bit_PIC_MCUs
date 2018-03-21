/* 
 * File:   SystemInitialize.h
 * Author: Lenovo
 *
 * Created on 4 de abril de 2017, 11:20 PM
 */

#ifndef SYSTEMINITIALIZE_H
#define	SYSTEMINITIALIZE_H

#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include "BitsConfig.h"
#include "InterruptManager.h"
#include "tmr1.h"
#include "BBSPI_LCD.h"
#include "eusart1.h"

#define _XTAL_FREQ 40000000

// Definitions for select and scroll buttons
#define scroll_dir  TRISAbits.TRISA5
#define scroll      PORTAbits.RA5
#define select_dir  TRISBbits.TRISB0
#define select      PORTBbits.RB0
#define pressed     0

#define LEDS_DIR    TRISD
#define LEDS        PORTD  

// Function prototypes
void SysInitialize(void);
void PortInitialize(void);
void SWdelay(void);

#endif	/* SYSTEMINITIALIZE_H */

