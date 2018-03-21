/* 
 * File:   InterruptManager.h
 * Author: Sebastián
 *
 * Created on 6 de marzo de 2016, 11:46 PM
 */

#ifndef INTERRUPTMANAGER_H
#define	INTERRUPTMANAGER_H

#include <xc.h>
#include "SystemInitialize.h"

//Macros
#define GlobalInterruptEnable()         (INTCONbits.GIE = 1)
#define GlobalInterruptDisable()        (INTCONbits.GIE = 0)
#define PeripheralInterruptEnable()     (INTCONbits.PEIE = 1)
#define PeripheralInterruptDisable()    (INTCONbits.PEIE = 0)

#define GlobalInterruptHighPriorityEnable()     (INTCONbits.GIEH = 1)
#define GlobalInterruptHighPriorityDisable()    (INTCONbits.GIEH = 0)
#define GlobalInterruptLowPriorityEnable()      (INTCONbits.GIEL = 1)
#define GlobalInterruptLowPriorityDisable()     (INTCONbits.GIEL = 0)

//Function prototypes
void InterruptInitialize(void);
void interrupt InterruptManager(void);

#endif	/* INTERRUPTMANAGER_H */