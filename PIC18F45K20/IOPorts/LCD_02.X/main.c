/*******************************************************************************
 * FileName:        main.c
 * ProjectName:     LCD_02
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18F45K20
 * Compiler:        XC8
 * Version:         1.45
 * Author:          Sebastián Fernando Puente Reyes
 * e-mail:          sebastian.puente@unillanos.edu.co
 * Date:            Marzo de 2018
 *******************************************************************************
 * REQUERIMIENTO
 * Oscilador: Interno a 16 MHz, Fosc = 16 MHz.
 * Usando la libreria ldc.h imprimir la siguiente información alfanumerica:
 * 1. Un caracter
 * 2. String de caracteres
 * 3. Dato (int) y (float) usando la función sprintf de la libreria stdio.h
 ******************************************************************************/
/*******************************************************************************
 * Librerias
 ******************************************************************************/
#include <xc.h>
#include <stdio.h> //Libreria para sprintf
#include "ConfigurationBits.h"
#include "lcd.h" //Libreria para el manejo de una LCD 16x2

/*******************************************************************************
 * Macros
 ******************************************************************************/
#define _XTAL_FREQ  16000000

//Definiciones para los botones IZQ Y DER
#define IZQ_dir     TRISBbits.TRISB1
#define IZQ         PORTBbits.RB1
#define DER_dir     TRISBbits.TRISB0
#define DER         PORTBbits.RB0
#define Oprimido    1

/*******************************************************************************
 * Prototipos de funciones
 ******************************************************************************/
void SetUp(void);
void SWdelay(void);

/*******************************************************************************
 * Variables globales
 ******************************************************************************/
char Mensaje1[] = "Ctos Digitales 2";
char Mensaje2[] = "  Taller No. 2  ";

/*******************************************************************************
 * Función Principal
 ******************************************************************************/
void main(void)
{
    SetUp(); //Configuración inicial    
    Lcd_Init(); //Se inicializa la LCD
    Lcd_Cmd(LCD_CURSOR_OFF); //Se apaga el cursor

    Lcd_Out(1,0,Mensaje1);
    Lcd_Out(2,0,Mensaje2);
    
    while(1) //Bucle Infinito
    {
        if (IZQ == Oprimido) //Condición si RB1 es oprimido
        {
            SWdelay();
            Lcd_Cmd(LCD_SHIFT_LEFT);
        }
        if (DER == Oprimido) //Condición si RB0 es oprimido
        {
            SWdelay();
            Lcd_Cmd(LCD_SHIFT_RIGHT);
        }
    }
}
/*******************************************************************************
 * FUNCTION:	SetUp()
 * INPUTS:      None
 * OUTPUTS:     None
 * DESCRIPTION: Configuración inicial (oscilador, puertos, etc.)
 ******************************************************************************/
void SetUp(void)
{
    OSCCONbits.IRCF = 0b111; //Oscilador interno a 16 MHz, Fosc = 16 MHz

    //Config I/O ports
    ANSELHbits.ANS12 = 0; //Buffer de entrada digital de RB0 habilitado
    ANSELHbits.ANS10 = 0; //Buffer de entrada digital de RB1 habilitado
    LATB = 0;
    IZQ_dir = 1;
    DER_dir = 1;

    return;
}

/*******************************************************************
* FUNCTION:     SWdelay ()
* INPUTS:       None
* OUTPUTS:      None
* DESCRIPTION:  Delay after pressing the RB0 and RB1 switch buttons
********************************************************************/
void SWdelay(void)
{
    while(IZQ == Oprimido)
        __delay_ms(1);
    while (DER == Oprimido)
        __delay_ms(1);
}

/*******************************************************************************
 * DISEÑO DIGITAL CON MICROCONTROLADORES PIC DE 8 BITS
 * Sebastián Puente Reyes, M.Sc.
 * Grupo de Estudio en Hardware Reconfigurable y Sistemas Embebidos - GEHRSE
 * Escuela de Ingeniería
 * Facultad de Ciencías Básicas e Ingeniería
 * Universidad de los Llanos
 * Villavicencio - Meta, Colombia
 ******************************************************************************/