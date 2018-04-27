/*******************************************************************************
 * FileName:        main.c
 * ProjectName:     ProgrammedIO_01
 * Course:          Diseño Digital con Microcontroladores PIC de 8 bits
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
 * Función Principal
 ******************************************************************************/
void main(void)
{
    //--Configuraciones Iniciales

    //Configuración Oscilador (Capitulo 2 DataSheet: Oscillator Module)
    //Configuración oscilador interno
    OSCCONbits.IRCF = 0b111; //HFINTOSC = 16 MHz, Fosc = 16 MHz

    //Configuración I/O Ports (Capitulo 10 I/O Ports DataSheet)
    LATD = 0; //Inicializar PORTD, tambien es válido: PORTD = 0;
    TRISDbits.RD0 = 0; //Línea RD0 como salida

    //Ciclo Infinito, Tareas que el MCU hace indefinidamente
    while(1)
    {
        //Encender LED conectado en RD0
        PORTDbits.RD0 = 1; //Nivel alto por RD0
    }
}

/*******************************************************************************
 * DISEÑO DIGITAL CON MICROCONTROLADORES PIC DE 8 BITS
 * Sebastian Puente Reyes, M.Sc.
 * Grupo de Estudio en Hardware Reconfigurable y Sistemas Embebidos - GEHRSE
 * Escuela de Ingeniería
 * Facultad de CiencÃ­as Básicas e Ingeniería
 * Universidad de los Llanos
 * Villavicencio - Meta, Colombia
 ******************************************************************************/