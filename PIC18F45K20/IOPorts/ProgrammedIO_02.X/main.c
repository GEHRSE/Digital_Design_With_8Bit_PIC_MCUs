/*******************************************************************************
 * FileName:        main.c
 * ProjectName:     ProgrammedIO_02
 * Course:          Dise�o Digital con Microcontroladores PIC de 8 bits
 * Topic:           I/O Ports
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18F45K20
 * Compiler:        XC8, Ver. 1.45
 * Author:          Sebasti�n Fernando Puente Reyes
 * e-mail:          sebastian.puente@unillanos.edu.co
 * Date:            Abril de 2018
 *******************************************************************************
 * REQUERIMIENTO
 * Oscilador: Interno a 16 MHz PLL habilitada, Fosc = (4x16)MHz = 64 MHz.
 * Requerimiento: Encender un led, conectado en RA1, a trav�s de un interruptor
 * conectado en la l�nea RA0 en logica positiva ("0" abierto, "1" cerrado).
 * El LED se deber� encender cuando el interruptor sea cerrado y apagarse en el
 * caso contrario.
 * -Ver Descripcion.txt
 ******************************************************************************/

/*******************************************************************************
 * Librerias
 ******************************************************************************/
#include <xc.h> //Lib con informaci�n del MCU
#include "ConfigurationBits.h" //Bits de configuraci�n

/*******************************************************************************
 * Macros
 ******************************************************************************/
//#define _XTAL_FREQ XX000000 //Macro necesario para __delay_ms()
#define LED PORTAbits.RA1

/*******************************************************************************
 * Prototipos de funciones
 ******************************************************************************/
void SetUp(void); //Configuraci�n inicial

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
        //El nivel (estado) que entrega el interruptor en RA0 es sacado por la l�nea RA1;
        PORTAbits.RA1 = PORTAbits.RA0;
        
        //Tambien se puede hacer lo anterior usando el macro creado LED
        //LED = PORTAbits.RA0;
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

    //--A.1--Configuraci�n oscilador interno (si es el caso)
    OSCCONbits.IRCF = 0b111; //HFINTOSC = 16 MHz, Fosc = 16 MHz
    
    //--A.2--Habilitaci�n PLL (si es el caso)
    OSCTUNEbits.PLLEN = 1; //Fosc = 4 x 16 MHz = 64 MHz
    
    //---B---Configuraci�n I/O Ports (Capitulo 10 DataSheet: I/O Ports)

    //--B.1--Inicializaci�n I/O Ports
    LATA = 0; //Inicializar PORTA, tambien es v�lido: PORTA = 0;
    
    //--B.2--Habilitaci�n buffer entrada digital para las lineas digitales/anal�gicas
    //(Seccion 10.7 Datasheet: Port Analog Control)
    //ANSEL  --> ANS7(RE2),ANS6(RE1),ANS5(RE0),ANS4(RA5),ANS3(RA3),ANS2(RA2),ANS1(RA1),ANS0(RA0)
    //ANSELH --> ANS12(RB0),ANS11(RB4),ANS10(RB1),ANS9(RB3),ANS8(RB2)
    //S�lo es necesaria cuando se desee configurar dichos pines como entradas digitales
    ANSELbits.ANS0 = 0; //Habilitaci�n buffer entrada digital de RA0

    //--B.2--Sentido I/O Ports
    TRISAbits.TRISA0 = 1; //L�nea RA0 como entrada
    TRISAbits.TRISA1 = 0; //L�nea RA1 como salida
    
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