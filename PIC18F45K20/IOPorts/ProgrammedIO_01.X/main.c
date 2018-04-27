/*******************************************************************************
 * FileName:        main.c
 * ProjectName:     ProgrammedIO_01
 * Course:          Dise�o Digital con Microcontroladores PIC de 8 bits
 * Topic:           I/O Ports
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18F45K20
 * Compiler:        XC8, Ver. 1.45
 * Author:          Sebastian Fernando Puente Reyes
 * e-mail:          sebastian.puente@unillanos.edu.co
 * Date:            Marzo de 2018
 *******************************************************************************
 * REQUERIMIENTO
 * Oscilador: Interno a 16 MHz, Fosc = 16 MHz.
 * Encender un LED conectado en RD0.
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

/*******************************************************************************
 * Prototipos de funciones
 ******************************************************************************/

/*******************************************************************************
 * Variables globales
 ******************************************************************************/

/*******************************************************************************
 * Funci�n Principal
 ******************************************************************************/
void main(void)
{
    //--Configuraciones Iniciales

    //Configuraci�n Oscilador (Capitulo 2 DataSheet: Oscillator Module)
    //Configuraci�n oscilador interno
    OSCCONbits.IRCF = 0b111; //HFINTOSC = 16 MHz, Fosc = 16 MHz

    //Configuraci�n I/O Ports (Capitulo 10 I/O Ports DataSheet)
    LATD = 0; //Inicializar PORTD, tambien es v�lido: PORTD = 0;
    TRISDbits.RD0 = 0; //L�nea RD0 como salida

    //Ciclo Infinito, Tareas que el MCU hace indefinidamente
    while(1)
    {
        //Encender LED conectado en RD0
        PORTDbits.RD0 = 1; //Nivel alto por RD0
    }
}

/*******************************************************************************
 * DISE�O DIGITAL CON MICROCONTROLADORES PIC DE 8 BITS
 * Sebastian Puente Reyes, M.Sc.
 * Grupo de Estudio en Hardware Reconfigurable y Sistemas Embebidos - GEHRSE
 * Escuela de Ingenier�a
 * Facultad de Ciencías B�sicas e Ingenier�a
 * Universidad de los Llanos
 * Villavicencio - Meta, Colombia
 ******************************************************************************/