/*******************************************************************************
 * FileName:            main.c
 * ProjectName:         Timer0_02
 * Course:              Diseño Digital con Microcontroladores PIC de 8 bits
 * Topic:               Temporizadores
 * Dependencies:        See INCLUDES section below
 * Processor:           PIC18F45K20
 * Compiler:            XC8, Ver. X.XX
 * Autor:          		Sebastián Fernando Puente Reyes
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
#include <xc.h> //Lib con información del MCU
#include <stdint.h> //Lib estándar para enteros
#include "ConfigurationBits.h" //Bits de configuración (incluir en el proyecto)

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
 * Función Principal
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
 * FUNCIÓN:		SetUp()
 * ENTRADAS:	Ninguna
 * SALIDAS:     Ninguna
 * DESCRIPCIÓN:	Configuración inicial (oscilador, puertos, etc.)
 ******************************************************************************/
void SetUp(void)
{
    //---A---Configuración Oscilador (Capitulo 2 DataSheet: Oscillator Module)

    //--A.1--Configuración oscilador interno (si es el caso)
    //OSCCONbits.IRCF = 0bXXX; //HFINTOSC = XX MHz, Fosc = XX MHz
    
    //--A.2--Habilitación PLL (si es el caso)
    //OSCTUNEbits.PLLEN = 1; //Fosc = 4 x XX MHz = XX MHz

    //---B---Configuración I/O Ports (Capitulo 10 DataSheet: I/O Ports)

    //--B.1--Inicialización I/O Ports
    //LATA = 0; //Inicializar PORTA (Ejemplo)

    //--B.2--Habilitación buffer entrada digital para las lineas digitales/analógicas
    //(Seccion 10.7 Datasheet: Port Analog Control)
    //ANSEL  --> ANS7(RE2),ANS6(RE1),ANS5(RE0),ANS4(RA5),ANS3(RA3),ANS2(RA2),ANS1(RA1),ANS0(RA0)
    //ANSELH --> ANS12(RB0),ANS11(RB4),ANS10(RB1),ANS9(RB3),ANS8(RB2)
    //Sólo es necesaria cuando se desee configurar dichos pines como entradas digitales
    //ANSELbits.ANS0 = 0; //Habilitación buffer entrada digital de RA0 (Ejemplo)

    //--B.3--Sentido I/O Ports
    //TRISAbits.TRISA0 = 1; //Línea RA0 como entrada (Ejemplo)

    //---C---Otras

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