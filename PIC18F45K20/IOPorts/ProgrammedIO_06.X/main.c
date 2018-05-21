/*******************************************************************************
 * FileName:        main.c
 * ProjectName:     ProgrammedIO_06
 * Course:          Dise�o Digital con Microcontroladores PIC de 8 bits
 * Topic:           I/O Ports - Conditional Programmed I/O
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18F45K20
 * Compiler:        XC8, Ver. 1.45
 * Author:          Sebasti�n Fernando Puente Reyes
 * e-mail:          sebastian.puente@unillanos.edu.co
 * Date:            Marzo de 2018
 *******************************************************************************
 * REQUERIMIENTO
 * Oscilador: Interno a 16 MHz con PLL, Fosc = 64 MHz.
 * Se captura un n�mero de 4 bits (0-15) por las l�neas RB<3:0>.
 * Si el n�mero esta entre 0-9 se visualiza en un display 7 segmentos c�todo
 * com�n, conectado en el PORTD, de lo contrario no se visualiza nada
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
//#define _XTAL_FREQ XX000000 //Macro necesario para __delay_ms(), etc

/*******************************************************************************
 * Prototipos de funciones
 ******************************************************************************/
void SetUp(void);

/*******************************************************************************
 * Variables globales
 ******************************************************************************/
//Arreglo para el manejo de un display 7 segmentos de c�todo com�n
//                       0    1    2    3    4    5    6    7    8    9
uint8_t Disp7SegCC[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

/*******************************************************************************
 * Funci�n Principal
 ******************************************************************************/
void main(void)
{
    //--Configutaciones Iniciales
    SetUp();

    //--Ciclo Infinito, Tareas que el MCU hace indefinidamente
    while(1)
    {
        //Para este caso el display mostrar� n�meros del 0 al 9
        if(PORTB < 10)
        {
            PORTD = Disp7SegCC[PORTB];
        }
        else //para >= 10 no se muestra nada en el display
        {
            PORTD = 0x00; //se apagan todos los segmentos del display
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
    
    //--A.2--Habilitaci�n PLL
    OSCTUNEbits.PLLEN = 1; //Fosc = 4 x 16 MHz = 64 MHz

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
    ANSELHbits.ANS10 = 0; //RB1 
    ANSELHbits.ANS8 = 0; //RB2
    ANSELHbits.ANS9 = 0; //RB3

    //--B.3--Sentido I/O Ports
    TRISB = 0xFF; //L�neas del PORTB como entradas
    TRISD = 0x00; //L�neas del PORTD como salidas

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