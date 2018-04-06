/*******************************************************************************
 * FileName:        main.c
 * ProjectName:     LCD_01 
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
#include "lcd.h" //Libreria para el manejo de una LCD 16x2
#include <stdio.h> //Libreria para sprintf

/*******************************************************************************
 * Prototipos de funciones
 ******************************************************************************/
void SetUp(void);

/*******************************************************************************
 * Variables globales
 ******************************************************************************/
char TextoLCD[16];
char Mensaje[] = "Digitales II";
char Caracter = 'A';
int a = 31;
float b = 3.1416;

/*******************************************************************************
 * Funci�n Principal
 ******************************************************************************/
void main(void)
{
    SetUp(); //Configuraci�n inicial
    
    Lcd_Init(); //Se inicializa la LCD
    Lcd_Cmd(LCD_CURSOR_OFF); //Se apaga el cursor

    //Imprimir un caracter y un string de caracteres
    Lcd_Out(1,0,Mensaje); //Imprimir un string en la l�nea 1 desde la posici�n 0
    Lcd_Cmd(LCD_MOVE_CURSOR_RIGHT); //Se desplaza a la derecha el cursor
    Lcd_Chr_CP(Caracter); //Imprimir caracter en la posici�n actual del cursor

    //Uso de sprintf para imprimir variables n�mericas
    sprintf(TextoLCD, "a=%d,b=%.3f",a,b);
    Lcd_Out(2,0,TextoLCD); //Imprimir el resultado de sprintf en la l�nea 2
    
    while(1); //Bucle Infinito
}
/*******************************************************************************
 * FUNCTION:	SetUp()
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