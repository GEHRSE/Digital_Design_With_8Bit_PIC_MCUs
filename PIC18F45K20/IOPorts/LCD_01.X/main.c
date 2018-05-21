/*******************************************************************************
 * FileName:        main.c
 * ProjectName:     LCD_01
 * Course:			Diseño Digital con Microcontroladores PIC de 8 bits
 * Topic:			I/O Ports
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18F45K20
 * Compiler:		XC8, Ver. 1.45
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
#include <xc.h> //Lib con información del MCU
#include <stdint.h> //Lib estándar para enteros
#include <stdio.h> //Libreria para sprintf
#include "ConfigurationBits.h" //Bits de configuración
#include "lcd.h" //Libreria LCD

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
uint16_t u16_a = 31;
float b = 3.1416;

/*******************************************************************************
 * Función Principal
 ******************************************************************************/
void main(void)
{
    SetUp(); //Configuración inicial
    
    Lcd_Init(); //Se inicializa la LCD
    Lcd_Cmd(LCD_CURSOR_OFF); //Se apaga el cursor

    //Imprimir un caracter y un string de caracteres
    Lcd_Out(1,0,Mensaje); //Imprimir un string en la línea 1 desde la posición 0
    Lcd_Cmd(LCD_MOVE_CURSOR_RIGHT); //Se desplaza a la derecha el cursor
    Lcd_Chr_CP(Caracter); //Imprimir caracter en la posición actual del cursor

    //Uso de sprintf para imprimir variables númericas
    sprintf(TextoLCD,"a=%d,b=%.3f",u16_a,b);
    Lcd_Out(2,0,TextoLCD); //Imprimir el resultado de sprintf en la línea 2
    
    while(1); //Bucle Infinito
}

/*******************************************************************************
 * FUNCIÓN:     SetUp()
 * ENTRADAS:    Ninguna
 * SALIDAS:     Ninguna
 * DESCRIPCIÓN: Configuración inicial (oscilador, puertos, etc.)
 ******************************************************************************/
void SetUp(void)
{
    //---A---Configuración Oscilador (Capitulo 2 DataSheet: Oscillator Module)

    //--A.1--Configuración oscilador interno
    OSCCONbits.IRCF = 0b111; //HFINTOSC = 16 MHz, Fosc = 16 MHz

    return;
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