/*******************************************************************************
 * FileName:        main.c
 * ProjectName:     ProgrammedIO_04 
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18F45K20
 * Compiler:        XC8
 * Version:         1.45
 * Author:          Sebastián Fernando Puente Reyes
 * e-mail:          sebastian.puente@unillanos.edu.co
 * Date:            Abril de 2018
 *******************************************************************************
 * REQUERIMIENTO
 * Oscilador: Interno a 8 MHz, Fosc = 32 MHz (Habilitar PLL)
 * Realizar un contador binario de 8 bits, 0 - 255, que se visualize a través
 * de las 8 líneas del Puerto A. El incremento debe ser cada 300 mseg.
 * -Ver Descripción.txt
 ******************************************************************************/

/*******************************************************************************
 * Librerias
 ******************************************************************************/
#include <xc.h>
#include "ConfigurationBits.h"
#include <stdint.h>

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
uint8_t u8_Contador = 0;

/*******************************************************************************
 * Función Principal
 ******************************************************************************/
void main(void)
{
    uint8_t u8_i;

    SetUp(); //Llamado función SetUp()

    while(1) //Ciclo infinito
    {
        for(u8_i = 0; u8_i < 256; u8_i++)
        {
            u8_Contador = u8_i;
            //Llevar los 8 bits de u8_Contador a las 8 líneas del PORTA
            PORTA = u8_Contador; 
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
    //Configuración frecuencia oscilador interno
    OSCCONbits.IRCF = 0b110; //HFINTOSC = 8 MHz
    OSCTUNEbits.PLLEN = 1; //PLL habilitada, Fosc = 4 x 8MHz = 32MHz 
    
    //Configuración puertos digitales
    LATA = 0; //Inicializar PORTA
    TRISA = 0x00; //Todas las líneas del PORTA como salidas digitales
    
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