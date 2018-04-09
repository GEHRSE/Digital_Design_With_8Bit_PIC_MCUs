/*******************************************************************************
 * FileName:        main.c
 * ProjectName:     ProgrammedIO_02
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18F45K20
 * Compiler:        XC8
 * Version:         1.45
 * Author:          Sebastián Fernando Puente Reyes
 * e-mail:          sebastian.puente@unillanos.edu.co
 * Date:            Abril de 2018
 *******************************************************************************
 * REQUERIMIENTO
 * Oscilador: Interno a 16 MHz PLL habilitada, Fosc = (4x16)MHz = 64 MHz.
 * Requerimiento: Encender un led, conectado en RA1, a través de un interruptor
 * conectado en la línea RA0 en logica positiva ("0" abierto, "1" cerrado).
 * El LED se deberá encender cuando el interruptor sea cerrado y apagarse en el
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
void SetUp(void); //Configuración inicial

/*******************************************************************************
 * Variables globales
 ******************************************************************************/

/*******************************************************************************
 * Función Principal
 ******************************************************************************/
void main(void)
{
    SetUp(); //Realizar configuraciones iniciales

    while(1) //Ciclo infinito
    {
        //El nivel (estado) que entrega el interruptor en RA0 es sacado por la línea RA1;
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
 * DESCRIPTION: Configuración inicial (oscilador, puertos, etc.)
 ******************************************************************************/
void SetUp(void)
{
    //Configuración frecuencia oscilador interno
    OSCCONbits.IRCF = 0b111;    //Oscilador interno a 16 MHz
    OSCTUNEbits.PLLEN = 1;      //PLL habilitada Fosc = 4 x 16MHz = 64MHz  
    
    //Configuración puertos digitales (Capitulo 10 I/O Ports DataSheet)
    LATA = 0; //Inicializar el PuertoA, tambien es válido: PORTA = 0;
    
    /*Habilitación buffer entrada digital para los pines que trabajan como 
     * canales analogicos y digitales.
     * Ésta configuración sólo es necesaria cuando se desee configurar dichos 
     * pines como entradas digitales, ver seccion 10.7 del datasheet
     */
    ANSELbits.ANS0 = 0; //Bufer de entrada digital habilitado para la línea RA0
    
    //Configuración sentido puertos I/O
    TRISAbits.TRISA0 = 1;   //Línea RA0 como entrada
    TRISAbits.TRISA1 = 0;   //Línea RA1 como salida
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