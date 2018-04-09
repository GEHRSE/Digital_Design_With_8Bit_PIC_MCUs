/*******************************************************************************
 * FileName:        main.c
 * ProjectName:     ProgrammedIO_02
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18F45K20
 * Compiler:        XC8
 * Version:         1.45
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
#include <xc.h>
#include "ConfigurationBits.h"

/*******************************************************************************
 * Macros
 ******************************************************************************/
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
    SetUp(); //Realizar configuraciones iniciales

    while(1) //Ciclo infinito
    {
        //El nivel (estado) que entrega el interruptor en RA0 es sacado por la l�nea RA1;
        PORTAbits.RA1 = PORTAbits.RA0;
        
        //Tambien se puede hacer lo anterior usando el macro creado LED
        //LED = PORTAbits.RA0;
    }
    return;
}

/*******************************************************************************
 * FUNCTION:	SetUp()
 * INPUTS:      None
 * OUTPUTS:     None
 * DESCRIPTION: Configuraci�n inicial (oscilador, puertos, etc.)
 ******************************************************************************/
void SetUp(void)
{
    //Configuraci�n frecuencia oscilador interno
    OSCCONbits.IRCF = 0b111;    //Oscilador interno a 16 MHz
    OSCTUNEbits.PLLEN = 1;      //PLL habilitada Fosc = 4 x 16MHz = 64MHz  
    
    //Configuraci�n puertos digitales (Capitulo 10 I/O Ports DataSheet)
    LATA = 0; //Inicializar el PuertoA, tambien es v�lido: PORTA = 0;
    
    /*Habilitaci�n buffer entrada digital para los pines que trabajan como 
     * canales analogicos y digitales.
     * �sta configuraci�n s�lo es necesaria cuando se desee configurar dichos 
     * pines como entradas digitales, ver seccion 10.7 del datasheet
     */
    ANSELbits.ANS0 = 0; //Bufer de entrada digital habilitado para la l�nea RA0
    
    //Configuraci�n sentido puertos I/O
    TRISAbits.TRISA0 = 1;   //L�nea RA0 como entrada
    TRISAbits.TRISA1 = 0;   //L�nea RA1 como salida
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