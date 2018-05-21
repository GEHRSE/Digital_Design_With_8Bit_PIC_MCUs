/*******************************************************************************
 * FileName:        main.c
 * ProjectName:     ProgrammedIO_05
 * Course:          Dise�o Digital con Microcontroladores PIC de 8 bits
 * Topic:           I/O Ports - Conditional Programmed I/O
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18F45K20
 * Compiler:        XC8, Ver. 1.45
 * Author:          Sebasti�n Fernando Puente Reyes
 * e-mail:          sebastian.puente@unillanos.edu.co
 * Date:            Mayo de 2018
 *******************************************************************************
 * REQUERIMIENTO
 * Oscilador: Interno a 16 MHz, Fosc = 16 MHz.
 * -Ver Descripcion.txt
 ******************************************************************************/

/*******************************************************************************
 * Librerias
 ******************************************************************************/
#include <xc.h> //Lib con informaci�n del MCU
#include <stdint.h> //Lib est�ndar para enteros
#include "ConfigurationBits.h" //Bits de configuraci�n

/*******************************************************************************
 * Macros
 ******************************************************************************/
#define _XTAL_FREQ 16000000 //Macro necesario para __delay_ms(), etc

#define Pulsador PORTBbits.RB0
#define Oprimido 1

/*******************************************************************************
 * Prototipos de funciones
 ******************************************************************************/
void SetUp(void);
void DelayMseg(uint16_t u16_n);

/*******************************************************************************
 * Variables globales
 ******************************************************************************/
//Arreglo para el manejo del dado formado por 7 LEDS
//                 0    1    2    3    4    5    6
uint8_t Dado[] = {0x00,0x08,0x22,0x2A,0x55,0x5D,0x77};
//RD7-RD6-RD5-RD4-RD3-RD2-RD1-RD0
// -   D8  D7  D6  D5  D4  D3  D2 
// Disposici�n LEDS D2:D8 para el dado
//     D2    D6
//     D3 D5 D7
//     D4    D8

/*******************************************************************************
 * Funci�n Principal
 ******************************************************************************/
void main(void)
{
    //Variables locales
    uint8_t u8_j = 1;
    
    //--Configutaciones Iniciales
    SetUp();

    //--Ciclo Infinito, Tareas que el MCU hace indefinidamente
    while(1)
    {
        //Para este caso el display mostrar� n�meros del 0 al 9
        if(Pulsador == Oprimido)
        {
            while(Pulsador == Oprimido)
            {
                __delay_ms(1);
            }
            PORTD = Dado[u8_j];
            DelayMseg(3000);
            PORTD = 0x00;
            u8_j = 0;
        }
        u8_j++;
        if(u8_j == 7)u8_j = 1;
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
    LATD = 0; //Inicializar PORTD

    //--B.2--Habilitaci�n buffer entrada digital para las lineas digitales/anal�gicas
    //(Seccion 10.7 Datasheet: Port Analog Control)
    //ANSEL  --> ANS7(RE2),ANS6(RE1),ANS5(RE0),ANS4(RA5),ANS3(RA3),ANS2(RA2),ANS1(RA1),ANS0(RA0)
    //ANSELH --> ANS12(RB0),ANS11(RB4),ANS10(RB1),ANS9(RB3),ANS8(RB2)
    //S�lo es necesaria cuando se desee configurar dichos pines como entradas digitales
    ANSELHbits.ANS12 = 0; //RB0

    //--B.3--Sentido I/O Ports
    TRISBbits.TRISB0; //L�nea RB0 como entrada
    TRISD = 0x00; //L�neas del PORTD como salidas

    return;
}

/*******************************************************************************
 * FUNCI�N:     DelayMseg()
 * ENTRADAS:    n: milisegundos deseados
 * SALIDAS:     Ninguna
 * DESCRIPCI�N: Retardo de n milisegundos
 ******************************************************************************/
void DelayMseg(uint16_t u16_n) //n -> milisegundos
{
    uint16_t u16_i;
    for (u16_i=0; u16_i < u16_n; u16_i++)
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