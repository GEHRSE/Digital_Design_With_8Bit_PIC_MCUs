/*******************************************************************************
 * FileName:        main.c
 * ProjectName:     LCD_02
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
 * Usando la libreria ldc.h imprimir la siguiente informaci�n:
 * 1. L�nea 1 posici�n 0: "Ctos Digitales 2"
 * 2. L�nea 2 posici�n 0: " Ing Electronik "
 * 3. Usar un pulsador para desplazar el texto una posici�n a la derecha
 * 4. Usar un pulsador para desplazar el texto una posici�n a la izquierda 
 * -Ver Descripcion.txt
 ******************************************************************************/

/*******************************************************************************
 * Librerias
 ******************************************************************************/
#include <xc.h> //Lib con informaci�n del MCU
#include <stdio.h> //Libreria para sprintf
#include "ConfigurationBits.h" //Bits de configuraci�n
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
 * Funci�n Principal
 ******************************************************************************/
void main(void)
{
    //--Configutaciones Iniciales
    SetUp();  
    
    Lcd_Init(); //Se inicializa la LCD
    Lcd_Cmd(LCD_CURSOR_OFF); //Se apaga el cursor

    Lcd_Out(1,0,Mensaje1); //Imprimir Mensaje1 en l�nea 1 posici�n 0
    Lcd_Out(2,0,Mensaje2); //Imprimir Mensaje2 en l�nea 2 posici�n 0
    
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
 * FUNCI�N:     SetUp()
 * ENTRADAS:    Ninguna
 * SALIDAS:     Ninguna
 * DESCRIPCI�N: Configuraci�n inicial (oscilador, puertos, etc.)
 ******************************************************************************/
void SetUp(void)
{
    //---A---Configuraci�n Oscilador (Capitulo 2 DataSheet: Oscillator Module)

    //--A.1--Configuraci�n oscilador interno
    OSCCONbits.IRCF = 0b111; //HFINTOSC = 16 MHz, Fosc = 16 MHz

    //---B---Configuraci�n I/O Ports (Capitulo 10 DataSheet: I/O Ports)

    //--B.1--Inicializaci�n I/O Ports
    LATB = 0; //Inicializar PORTB

    //--B.2--Habilitaci�n buffer entrada digital para las lineas digitales/anal�gicas
    //(Seccion 10.7 Datasheet: Port Analog Control)
    //ANSEL  --> ANS7(RE2),ANS6(RE1),ANS5(RE0),ANS4(RA5),ANS3(RA3),ANS2(RA2),ANS1(RA1),ANS0(RA0)
    //ANSELH --> ANS12(RB0),ANS11(RB4),ANS10(RB1),ANS9(RB3),ANS8(RB2)
    //S�lo es necesaria cuando se desee configurar dichos pines como entradas digitales
    ANSELHbits.ANS12 = 0; //Habilitaci�n buffer entrada digital de RB0
    ANSELHbits.ANS10 = 0; //Habilitaci�n buffer entrada digital de RB1

    //--B.3--Sentido I/O Ports
    BotonIZQ_dir = 1; //Entrada para el BotonIZQ
    BotonDER_dir = 1; //Entrada para el BotonDER

    return;
}

/*******************************************************************
* FUNCI�N:      SWdelay()
* ENTRADAS:     Ninguna
* SALIDAS:      None
* DESCRIPCI�N:  Delay after pressing the RB0 and RB1 switch buttons
********************************************************************/
void SWdelay(void)
{
    while(BotonIZQ == Oprimido)
        __delay_ms(1);
    while (BotonDER == Oprimido)
        __delay_ms(1);
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