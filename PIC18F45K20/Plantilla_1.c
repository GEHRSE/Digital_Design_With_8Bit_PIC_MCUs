/*******************************************************************************
 * FileName:            main.c
 * ProjectName:         Timer0_02
 * Course:              Dise�o Digital con Microcontroladores PIC de 8 bits
 * Topic:               Temporizadores
 * Dependencies:        See INCLUDES section below
 * Processor:           PIC18F45K20
 * Compiler:            XC8, Ver. X.XX
 * Autor:          		Sebasti�n Fernando Puente Reyes
 * e-mail:          	sebastian.puente@unillanos.edu.co
 * Date:            	Octubre de 2017
 *******************************************************************************
 * REQUERIMIENTO
 * Oscilador:
 * 
 * -Ver Descripcion.txt
 ******************************************************************************/

/*******************************************************************************
 * Librerias
 ******************************************************************************/
#include <xc.h> //Lib con informaci�n del MCU
#include <stdint.h> //Lib est�ndar para enteros
#include "ConfigurationBits.h" //Bits de configuraci�n (incluir en el proyecto)

/*******************************************************************************
 * Macros
 ******************************************************************************/
//#define _XTAL_FREQ XX000000 //Macro para __delay_ms(), __delay_us(), etc.

/*******************************************************************************
 * Prototipos de funciones
 ******************************************************************************/
void SetUp(void);

/*******************************************************************************
 * Variables globales
 ******************************************************************************/

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
    	//Tareas a realizar

    }

    return;
}

/*******************************************************************************
 * FUNCI�N:		SetUp()
 * ENTRADAS:	Ninguna
 * SALIDAS:     Ninguna
 * DESCRIPCI�N:	Configuraci�n inicial (oscilador, puertos, etc.)
 ******************************************************************************/
void SetUp(void)
{
    //---A---Configuraci�n Oscilador (Capitulo 2 DataSheet: Oscillator Module)

    //--A.1--Configuraci�n oscilador interno (si es el caso)
    //OSCCONbits.IRCF = 0bXXX; //HFINTOSC = XX MHz, Fosc = XX MHz
    
    //--A.2--Habilitaci�n PLL (si es el caso)
    //OSCTUNEbits.PLLEN = 1; //Fosc = 4 x XX MHz = XX MHz

    //---B---Configuraci�n I/O Ports (Capitulo 10 DataSheet: I/O Ports)

    //--B.1--Inicializaci�n I/O Ports
    //LATA = 0; //Inicializar PORTA (Ejemplo)

    //--B.2--Habilitaci�n buffer entrada digital para las lineas digitales/anal�gicas
    //(Seccion 10.7 Datasheet: Port Analog Control)
    //ANSEL  --> ANS7(RE2),ANS6(RE1),ANS5(RE0),ANS4(RA5),ANS3(RA3),ANS2(RA2),ANS1(RA1),ANS0(RA0)
    //ANSELH --> ANS12(RB0),ANS11(RB4),ANS10(RB1),ANS9(RB3),ANS8(RB2)
    //S�lo es necesaria cuando se desee configurar dichos pines como entradas digitales
    //ANSELbits.ANS0 = 0; //Habilitaci�n buffer entrada digital de RA0 (Ejemplo)

    //--B.3--Sentido I/O Ports
    //TRISAbits.TRISA0 = 1; //L�nea RA0 como entrada (Ejemplo)

    //---C---Otras

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