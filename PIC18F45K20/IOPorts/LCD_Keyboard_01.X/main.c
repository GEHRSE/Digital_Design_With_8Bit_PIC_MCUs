/*******************************************************************************
 * FileName:        main.c
 * ProjectName:     LCD_Keyboard_01
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18F45K20
 * Compiler:        XC8
 * Version:         1.45
 * Author:          Sebasti�n Fernando Puente Reyes
 * e-mail:          sebastian.puente@unillanos.edu.co
 * Date:            Marzo de 2018
 *******************************************************************************
 * REQUERIMIENTO
 * Oscilador: Interno a 16 MHz, Fosc = 16 MHz.
 * Usando la libreria ldc.h imprimir la siguiente informaci�n alfanumerica:
 * 1. Un caracter
 * 2. String de caracteres
 * 3. Dato (int) y (float) usando la funci�n sprintf de la libreria stdio.h
 ******************************************************************************/
/*******************************************************************************
 * Librerias
 ******************************************************************************/
#include <xc.h>
#include "ConfigurationBits.h"
#include <stdint.h>
#include <stdio.h> //Libreria para sprintf
#include "lcd.h" //Libreria para el manejo de la LCD
#include "KeyPad.h" //Libreria para el manejo del Teclado Matricial

/*******************************************************************************
 * Macros
 ******************************************************************************/
#define _XTAL_FREQ 16000000

/*******************************************************************************
 * Prototipos de funciones
 ******************************************************************************/
void SetUp(void);

/*******************************************************************************
 * Variables globales
 ******************************************************************************/
char Mensaje1[] = "DIGITE LA CLAVE:";
char Mensaje2[] = "Clave Digitada:";
char Clave[4] = {'0','0','0','0'};
uint8_t i;

/*******************************************************************************
 * Funci�n Principal
 ******************************************************************************/
void main(void)
{
    SetUp(); //Configuraci�n inicial
    Lcd_Init(); //Se inicializa la LCD
    
    Lcd_Cmd(LCD_CURSOR_OFF); //Apagar cursor
    Lcd_Out(1,0,Mensaje1); //Mensaje1 inicio l�nea 1
    Lcd_Cmd(LCD_SECOND_ROW); //Segunda l�nea
    
    for(i = 0; i <= 3; i++)
    {
        Clave[i] = GetKey(); //Captura tecla
        __delay_ms(300); //Retardo
        Lcd_Chr_CP('*'); //Imprimir *
    }
    
    __delay_ms(800);
    Lcd_Cmd(LCD_CLEAR); //Borrar LCD
    Lcd_Out(1,0,Mensaje2); //Mensaje2 inicio l�nea 1
    Lcd_Out(2,0,Clave); //Mostrar clave inicio l�nea 2
    
    while(1); //Bucle Infinito
}
/*******************************************************************************
 * FUNCTION:    SetUp()
 * INPUTS:      None
 * OUTPUTS:     None
 * DESCRIPTION: Configuraci�n inicial (oscilador, puertos, etc.)
 ******************************************************************************/
void SetUp()
{
    OSCCONbits.IRCF = 0b111; //Oscilador interno a 16 MHz, Fosc = 16 MHz
    return;
}

/*******************************************************************************
 * DISE�O DIGITAL CON MICROCONTROLADORES PIC DE 8 BITS
 * Sebasti�n Puente Reyes, M.Sc.
 * Grupo de Estudio en Hardware Reconfigurable y Sistemas Embebidos - GEHRSE
 * Escuela de Ingenier�a
 * Facultad de Cienc�as B�sicas e Ingenier�a
 * Universidad de los Llanos
 * Villavicencio - Meta, Colombia
 ******************************************************************************/