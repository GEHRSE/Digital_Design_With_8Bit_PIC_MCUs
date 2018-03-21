/*******************************************************************************
 * FileName:        main.c
 * ProjectName:     IOPorts_01
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18F45K20
 * Compiler:        XC8
 * Version:         1.45
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
 * Función Principal
 ******************************************************************************/
void main(void)
{
    //Config. frecuencia oscilador interno
    OSCCONbits.IRCF = 0b111;    //Oscilador interno a 16 MHz, Fosc = 16Mhz

    //Config. puertos I/O
    LATD = 0;			//Iniciar PORTD
    TRISDbits.RD0 = 0;	//RD0 como salida digital

    while(1)
    {
        //Encender LED conectado en RD0
        PORTDbits.RD0 = 1;  //Nivel alto por RD0
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