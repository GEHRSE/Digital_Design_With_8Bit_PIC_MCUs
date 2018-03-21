
#include "StateClock.h"

extern unsigned char State;

/*******************************************************************
* FUNCTION:     Clock ()
* INPUTS:       None
* OUTPUTS:      None
* DESCRIPTION:  Displays the Clock text and Now/Next options
*               on LCD and host PC
********************************************************************/

void Clock(void)
{
    // Display Clock text and Now/Next options on LCD
    mCURSOR_LINE1;
    LCDPutStr("     Clock      ");
    mCURSOR_LINE2;
    LCDPutStr("RB0=Now RA5=Next");

    // Send Clock text and Now/Next options to host PC serial terminal
    printf("     Clock      \n\r");
    printf("RB0=Now RA5=Next\n\r");

    while (State == 1)
    {
        if (select == pressed)              // Condition if RB0 is pressed
        {
            SWdelay();
            count_Clock ();                 // Display incrementing clock
        }
        if (scroll == pressed)              // Condition if RA5 is pressed
        {
            SWdelay();
            State = 0;                      // Switch to Voltmeter application
        }
    }
}

/*******************************************************************
* FUNCTION:     disp_Clock ()
* INPUTS:       None
* OUTPUTS:      None
* DESCRIPTION:  Displays the Clock (hr:min:sec) on LCD and host PC
********************************************************************/

void disp_Clock (void)
{
    // Display clock on LCD Line 1
    mCURSOR_LINE1;
    LCDPutChar(hr/10+'0');
    LCDPutChar(hr%10+'0');
    LCDPutChar(':');
    LCDPutChar(min/10+'0');
    LCDPutChar(min%10+'0');
    LCDPutChar(':');
    LCDPutChar(sec/10+'0');
    LCDPutChar(sec%10+'0');
    LCDPutStr("        ");

    // Send hour, minute and second values to host PC serial terminal
    printf("%02d:", hr);
    printf("%02d:", min);
    printf("%02d \t", sec);
}

/*******************************************************************
* FUNCTION:     count_Clock ()
* INPUTS:       None
* OUTPUTS:      None
* DESCRIPTION:  Increments the preset time
********************************************************************/

void count_Clock (void)
{ 
    while (State == 1)
    {
        if(Timer1Flag == 1)              // Condition if Timer1 flags
        {
            sec++;                      // Increment seconds
            if (sec > 59)               // Condition if seconds is greater than 59
            {
                sec = 0;                // Set seconds to 0
                min++;                  // Increment minutes
            }
            if (min > 59)               // Condtion if minutes is greater than 59
            {
                min = 0;                // Set minutes to 0
                hr++;                   // Increment hours
            }
            if (hr > 12 && min == 0 && sec == 0)    //Condition if clock reaches (13:00:00)
            {
                hr = 1;                     // Set hour to 1
            }
            disp_Clock();                   // Display clock
            Timer1Flag = 0;                  // Clear Timer1 flag

            mCURSOR_LINE2;
            LCDPutStr("RB0=Menu RA5=Set");  // Display Menu/Set on LCD Line 2
            printf("RB0=Menu RA5=Set\r"); // Send Menu/Set to host PC serial terminal
        }
        if(scroll == pressed)               // Condition if RB0 is pressed
            {
                SWdelay();
                timeset = 1;
                set_Clock();                // Manual setting of hours and minutes
            }
        if(select == pressed)
            {
                SWdelay();
                //sec = 0;                    // Reset clock to 00:00:00
                //min = 0;
                //hr = 0;
                State = 0;                  // Switch to Voltmeter application
            }
    }
}

/*******************************************************************
* FUNCTION:     set_Clock ()
* INPUTS:       None
* OUTPUTS:      None
* DESCRIPTION:  Manually sets the hours and minutes through RB0 and RA5
********************************************************************/

void set_Clock (void)
{
    Time = hour;                        // Set hours value
    while (timeset == 1)
    {
        mCURSOR_LINE2;
        LCDPutStr("RB0= ++ RA5= -->");  // Display Inc/Next on LCD Line 2
        printf("RB0= ++ RA5= -->\r"); // Send Inc/Next to host PC serial terminal

        switch (Time)
        {
            case hour:      disp_Clock ();              // Display Clock on LCD and host PC
                            if(select == pressed)       // Condition if RB0 is pressed
                            {
                                SWdelay();
                                hr++;                   // Increment hour
                                if (hr > 12)            // Condition if hour is greater than 12
                                    hr = 0;             // Set hour to 0
                            }
                            else if(scroll == pressed)  // Condition if RA5 is pressed
                            {
                                SWdelay();
                                Time = minute;          // Set minute value
                            }
                            break;
            case minute:    disp_Clock ();              // Display Clock on LCD and host PC
                            if(select == pressed)       // Condition if RB0 is pressed
                            {
                                SWdelay();
                                min++;                  // Increment minute
                                if (min > 59)           // Condition if minute is greater than 59
                                    min = 0;            // Set minute to 0
                            }
                            else if (scroll == pressed) // Condition if RA5 is pressed
                            {
                                SWdelay();
                                timeset = 0;            // Start clock incrementing from set value
                            }
                            break;
        }
    }
}