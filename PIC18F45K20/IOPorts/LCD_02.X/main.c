/*******************************************************************************
 * FileName:        main.c
 * ProjectName:     LCD_02
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
 * Usando la libreria ldc.h imprimir la siguiente información:
 * 1. Línea 1 posición 0: "Ctos Digitales 2"
 * 2. Línea 2 posición 0: " Ing Electronik "
 * 3. Usar un pulsador para desplazar el texto una posición a la derecha
 * 4. Usar un pulsador para desplazar el texto una posición a la izquierda 
 * -Ver Descripcion.txt
 ******************************************************************************/

/*******************************************************************************
 * Librerias
 ******************************************************************************/
#include <xc.h> //Lib con información del MCU
#include <stdio.h> //Libreria para sprintf
#include "ConfigurationBits.h" //Bits de configuración
#include "lcd.h" //Libreria LCD

/*******************************************************************************
 * Macros
 ******************************************************************************/
#define _XTAL_FREQ  16000000 //Macro necesario para __delay_ms(), etc.

//Definiciones para los botones IZQ Y DER
#define BotonIZQ_dir     TRISBbits.TRISB1
#define BotonIZQ         PORTBbits.RB1
#define BotonDER_dir     TRISBbits.TRISB0
#define BotonDER         PORTBbits.RB0
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
char Mensaje2[] = " Ing Electronik ";

/*******************************************************************************
 * Función Principal
 ******************************************************************************/
void main(void)
{
    //--Configutaciones Iniciales
    SetUp();  
    
    Lcd_Init(); //Se inicializa la LCD
    Lcd_Cmd(LCD_CURSOR_OFF); //Se apaga el cursor

    Lcd_Out(1,0,Mensaje1); //Imprimir Mensaje1 en línea 1 posición 0
    Lcd_Out(2,0,Mensaje2); //Imprimir Mensaje2 en línea 2 posición 0
    
    //--Ciclo Infinito, Tareas que el MCU hace indefinidamente
    while(1)
    {
        if (BotonIZQ == Oprimido) //Si RB1 es oprimido
        {
            SWdelay();
            Lcd_Cmd(LCD_SHIFT_LEFT);
        }
        if (BotonDER == Oprimido) //Si RB0 es oprimido
        {
            SWdelay();
            Lcd_Cmd(LCD_SHIFT_RIGHT);
        }
    }

    return;
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

    //---B---Configuración I/O Ports (Capitulo 10 DataSheet: I/O Ports)

    //--B.1--Inicialización I/O Ports
    LATB = 0; //Inicializar PORTB

    //--B.2--Habilitación buffer entrada digital para las lineas digitales/analógicas
    //(Seccion 10.7 Datasheet: Port Analog Control)
    //ANSEL  --> ANS7(RE2),ANS6(RE1),ANS5(RE0),ANS4(RA5),ANS3(RA3),ANS2(RA2),ANS1(RA1),ANS0(RA0)
    //ANSELH --> ANS12(RB0),ANS11(RB4),ANS10(RB1),ANS9(RB3),ANS8(RB2)
    //Sólo es necesaria cuando se desee configurar dichos pines como entradas digitales
    ANSELHbits.ANS12 = 0; //Habilitación buffer entrada digital de RB0
    ANSELHbits.ANS10 = 0; //Habilitación buffer entrada digital de RB1

    //--B.3--Sentido I/O Ports
    BotonIZQ_dir = 1; //Entrada para el BotonIZQ
    BotonDER_dir = 1; //Entrada para el BotonDER

    return;
}

/*******************************************************************
* FUNCIÓN:      SWdelay()
* ENTRADAS:     Ninguna
* SALIDAS:      None
* DESCRIPCIÓN:  Delay after pressing the RB0 and RB1 switch buttons
********************************************************************/
void SWdelay(void)
{
    while(BotonIZQ == Oprimido)
        __delay_ms(1);
    while (BotonDER == Oprimido)
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