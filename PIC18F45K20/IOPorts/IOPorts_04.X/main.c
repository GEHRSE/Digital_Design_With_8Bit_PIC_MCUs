/*******************************************************************************
 * FileName:        main.c
 * ProjectName:     IOPorts_04 
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18F45K20
 * Compiler:        XC8
 * Version:         1.45
 * Author:          Sebastián Fernando Puente Reyes
 * e-mail:          sebastian.puente@unillanos.edu.co
 * Date:            Marzo de 2017
 *******************************************************************************
 * REQUERIMIENTO
 * Oscilador: Fosc = 32 MHz (Interno a 8 MHz x 4PLL)
 * Realizar un contador binario de 8 bits, 0 - 255, que se visualize a través
 * de las 8 líneas del Puerto A. El incremento debe ser cada 300 mseg.
 * -Ver Descripción.txt
 ******************************************************************************/

/*******************************************************************************
 * Librerias
 ******************************************************************************/
#include <xc.h>
#include "ConfigurationBits.h"

/*******************************************************************************
 * Macros
 ******************************************************************************/
#define _XTAL_FREQ 32000000 //Macro necesario para __delay_ms()

/*******************************************************************************
 * Prototipos de funciones
 ******************************************************************************/
void SetUp(void);

/*******************************************************************************
 * Variables globales
 ******************************************************************************/
unsigned char Contador = 0;

/*******************************************************************************
 * Función Principal
 ******************************************************************************/
void main(void)
{
    unsigned char i;

    SetUp(); //Llamado a la función SetUp()

    while(1) //Ciclo infinito
    {
        for( i = 0; i < 256; i++)
        {
            Contador = i;
            PORTA = Contador;
            __delay_ms(300);
        }
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
    //Frecuencia oscilador interno con PLL habilitada
    OSCCONbits.IRCF = 0b110;    //HFINTOSC = 8 MHz
    OSCTUNEbits.PLLEN = 1;      //PLL habilitada Fosc = 4 x 8MHz = 32MHz 
    
    //Configuración puertos digitales
    LATA = 0;
    TRISA = 0x00; //Todas las líneas del puerto A como salidas digitales
    
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