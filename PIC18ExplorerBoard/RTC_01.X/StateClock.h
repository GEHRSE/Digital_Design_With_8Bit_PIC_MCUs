/* 
 * File:   State_Clock.h
 * Author: A16026
 *
 * Created on March 25, 2015, 6:27 PM
 */

#ifndef STATE_CLOCK_H
#define	STATE_CLOCK_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "SystemInitialize.h"

volatile unsigned char hr = 0, min = 0, sec = 0, timeset = 0;

// Enumerations
enum {hour, minute} Time;

// Function prototypes
void Clock(void);


/**
* @FUNCTION     disp_Clock ()
* @INPUTS       None
* @OUTPUTS      None
* @DESCRIPTION  Displays the Clock (hr:min:sec) on LCD and host PC
*/

void disp_Clock (void);

/**
* @FUNCTION     count_Clock ()
* @INPUTS       None
* @OUTPUTS      None
* @DESCRIPTION  Increments the preset time
*/

void count_Clock (void);

/**
* @FUNCTION     set_Clock ()
* @INPUTS       None
* @OUTPUTS      None
* @DESCRIPTION  Manually sets the hours and minutes through RB0 and RA5
*/

void set_Clock (void);

#ifdef	__cplusplus
}
#endif

#endif	/* STATE_CLOCK_H */