/*******************************************************************************
 * FileName:        main.c
 * ProjectName:     LCD_Keyboard_01
 * Course:          Dise�o Digital con Microcontroladores PIC de 8 bits
 * Topic:           I/O Ports
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18F45K20
 * Compiler:        XC8, Ver. 1.45
 * Author:          Sebasti�n Fernando Puente Reyes
 * e-mail:          sebastian.puente@unillanos.edu.co
 * Date:            Marzo de 2018
 *******************************************************************************
 * REQUERIMIENTO
 * Oscilador: Interno a 16 MHz, Fosc = 16 MHz.
 * Usando la libreria KeyPad.h  y ldc.h capturar y/o imprimir:
 * 1. Inicio l�nea 1: Imprimir "DIGITE LA CLAVE:"
 * 2. Inicio l�nea 2: Imprimir "*" cada vez que se captura una tecla
 * 3. Se deben capturar 4 d�gitos
 * 4. Borrar LCD e imprimir los 4 d�gitos capturados
 * -Ver Descripcion.txt
 ******************************************************************************/

/*******************************************************************************
 * Librerias
 ******************************************************************************/
#include <xc.h> //Lib con informaci�n del MCU
#include <stdint.h> //Lib est�ndar para enteros
#include <stdio.h> //Libreria para sprintf
#include "ConfigurationBits.h" //Bits de configuraci�n
#include "lcd.h" //Libreria LCD
#include "KeyPad.h" //Libreria para el manejo del Teclado Matricial

/*******************************************************************************
 * Macros
 ******************************************************************************/
#define _XTAL_FREQ 16000000 //Macro para __delay_ms(), __delay_us(), etc.

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
uint8_t u8_i;

/*******************************************************************************
 * Funci�n Principal
 ******************************************************************************/
void main(void)
{
    //--Configutaciones Iniciales
    SetUp();
    Lcd_Init(); //Se inicializa la LCD
    
    Lcd_Cmd(LCD_CURSOR_OFF); //Apagar cursor
    Lcd_Out(1,0,Mensaje1); //Mensaje1 inicio l�nea 1
    Lcd_Cmd(LCD_SECOND_ROW); //Segunda l�nea
    
    //Capturar 4 digitos desde el teclado
    for(u8_i = 0; u8_i <= 3; u8_i++)
    {
        Clave[u8_i] = GetKey(); //Captura tecla
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
 * FUNCI�N:     SetUp()
 * ENTRADAS:    Ninguna
 * SALIDAS:     Ninguna
 * DESCRIPCI�N: Configuraci�n inicial (oscilador, puertos, etc.)
 ******************************************************************************/
void SetUp(void)
{
    //---A---Configuraci�n Oscilador (Capitulo 2 DataSheet: Oscillator Module)

    //--A.1--Configuraci�n oscilador interno (si es el caso)
    OSCCONbits.IRCF = 0b111; //HFINTOSC = 16 MHz, Fosc = 16 MHz

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