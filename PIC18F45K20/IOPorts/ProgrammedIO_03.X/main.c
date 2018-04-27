/*******************************************************************************
 * FileName:        main.c
 * ProjectName:     ProgrammedIO_03 
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18F45K20
 * Compiler:        XC8
 * Version:         1.45
 * Author:          Sebastián Fernando Puente Reyes
 * e-mail:          sebastian.puente@unillanos.edu.co
 * Date:            Marzo de 2018
 *******************************************************************************
 * REQUERIMIENTO
 * Oscilador: Interno a 16 MHz, Fosc = 16 MHz.
 * Generar una señal cuadrada por la línea RE0 con un periodo (T) de 2 seg y
 * un ciclo de trabajo del 50%. Es decir, la señal se mantiene en estado ALTO
 * por 1 seg(0.5*2) y luego pasa a estado BAJO por 1 seg(0.5*2).
 ******************************************************************************/

/*******************************************************************************
 * Librerias
 ******************************************************************************/
#include <xc.h>
#include "ConfigurationBits.h"

/*******************************************************************************
 * Macros
 ******************************************************************************/
#define _XTAL_FREQ 16000000 //Macro necesario para __delay_us(x), __delay_ms(x)

/*******************************************************************************
 * Prototipos de funciones
 ******************************************************************************/
void SetUp(void);

/*******************************************************************************
 * Variables globales
 ******************************************************************************/
bit LED = 0; //Variable tipo bit

/*******************************************************************************
 * Función Principal
 ******************************************************************************/
void main(void)
{
    SetUp(); //Llamado a la función SetUp

    while(1) //Bucle infinito
    {
        LED = !LED; //Se complementa la variable LED
        PORTEbits.RE0 = LED; //El valor de la variable LED se muestra por la línea RE0
        __delay_ms(1000);    //Función para temporizaciones en ms, se pide un retardo de 1000 ms = 1seg
    }
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
    OSCCONbits.IRCF = 0b111; //Fosc = 16 MHz
    
    //Configuración puertos digitales
    LATE = 0; //Inicializar PORTE
    TRISEbits.TRISE0 = 0; //Línea RE0 como salida digital
    
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