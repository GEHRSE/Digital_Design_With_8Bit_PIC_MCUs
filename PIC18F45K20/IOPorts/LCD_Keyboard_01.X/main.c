/*******************************************************************************
 * FileName:        main.c
 * ProjectName:     LCD_Keyboard_01
 * Course:          Diseño Digital con Microcontroladores PIC de 8 bits
 * Topic:           I/O Ports
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18F45K20
 * Compiler:        XC8, Ver. 1.45
 * Author:          Sebastián Fernando Puente Reyes
 * e-mail:          sebastian.puente@unillanos.edu.co
 * Date:            Marzo de 2018
 *******************************************************************************
 * REQUERIMIENTO
 * Oscilador: Interno a 16 MHz, Fosc = 16 MHz.
 * Usando la libreria KeyPad.h  y ldc.h capturar y/o imprimir:
 * 1. Inicio línea 1: Imprimir "DIGITE LA CLAVE:"
 * 2. Inicio línea 2: Imprimir "*" cada vez que se captura una tecla
 * 3. Se deben capturar 4 dígitos
 * 4. Borrar LCD e imprimir los 4 dígitos capturados
 * -Ver Descripcion.txt
 ******************************************************************************/

/*******************************************************************************
 * Librerias
 ******************************************************************************/
#include <xc.h> //Lib con información del MCU
#include <stdint.h> //Lib estándar para enteros
#include <stdio.h> //Libreria para sprintf
#include "ConfigurationBits.h" //Bits de configuración
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
 * Función Principal
 ******************************************************************************/
void main(void)
{
    //--Configutaciones Iniciales
    SetUp();
    Lcd_Init(); //Se inicializa la LCD
    
    Lcd_Cmd(LCD_CURSOR_OFF); //Apagar cursor
    Lcd_Out(1,0,Mensaje1); //Mensaje1 inicio línea 1
    Lcd_Cmd(LCD_SECOND_ROW); //Segunda línea
    
    //Capturar 4 digitos desde el teclado
    for(u8_i = 0; u8_i <= 3; u8_i++)
    {
        Clave[u8_i] = GetKey(); //Captura tecla
        __delay_ms(300); //Retardo
        Lcd_Chr_CP('*'); //Imprimir *
    }
    
    __delay_ms(800);
    Lcd_Cmd(LCD_CLEAR); //Borrar LCD
    Lcd_Out(1,0,Mensaje2); //Mensaje2 inicio línea 1
    Lcd_Out(2,0,Clave); //Mostrar clave inicio línea 2
    
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

    //--A.1--Configuración oscilador interno (si es el caso)
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