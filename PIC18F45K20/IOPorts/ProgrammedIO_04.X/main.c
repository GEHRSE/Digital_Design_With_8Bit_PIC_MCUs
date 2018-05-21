/*******************************************************************************
 * FileName:        main.c
 * ProjectName:     ProgrammedIO_04 
 * Course:          Diseño Digital con Microcontroladores PIC de 8 bits
 * Topic:           I/O Ports - Unconditional Programmed I/O
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18F45K20
 * Compiler:        XC8, Ver. 1.45
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
#include <xc.h> //Lib con información del MCU
#include <stdint.h> //Lib estándar para enteros
#include "ConfigurationBits.h" //Bits de configuración

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
    uint16_t u16_i;

    //--Configutaciones Iniciales
    SetUp();

    //--Ciclo Infinito, Tareas que el MCU hace indefinidamente
    while(1)
    {
        for(u16_i = 0; u16_i < 256; u16_i++)
        {
            u8_Contador = (uint8_t)u16_i;
            //Llevar los 8 bits de u8_Contador a las 8 líneas del PORTA
            PORTA = u8_Contador; 
            __delay_ms(300);
        }
    }
    
    return;
}

/*******************************************************************************
 * FUNCIÓN:     SetUp()
 * ENTRADAS:    Ninguna
 * SALIDAS:     Ninguna
 * DESCRIPCIÓN: Configuración inicial (oscilador, puertos, etc.)
 ******************************************************************************/
void SetUp(void)
{
    //---A---Configuración Oscilador (Capitulo 2 DataSheet: Oscillator Module)

    //--A.1--Configuración oscilador interno
    OSCCONbits.IRCF = 0b110; //HFINTOSC = 8 MHz, Fosc = 8 MHz

    //--A.2--Habilitación PLL
    OSCTUNEbits.PLLEN = 1; //Fosc = 4 x 8 MHz = 32 MHz

    //---B---Configuración I/O Ports (Capitulo 10 DataSheet: I/O Ports)

    //--B.1--Inicialización I/O Ports
    LATA = 0; //Inicializar PORTA

    //--B.2--Sentido I/O Ports
    TRISA = 0x00; //Todas las líneas del PORTA como salidas
    
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