/*******************************************************************************
 * FileName:        main.c
 * ProjectName:     ProgrammedIO_04 
 * Course:          Dise�o Digital con Microcontroladores PIC de 8 bits
 * Topic:           I/O Ports - Unconditional Programmed I/O
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18F45K20
 * Compiler:        XC8, Ver. 1.45
 * Author:          Sebasti�n Fernando Puente Reyes
 * e-mail:          sebastian.puente@unillanos.edu.co
 * Date:            Abril de 2018
 *******************************************************************************
 * REQUERIMIENTO
 * Oscilador: Interno a 8 MHz, Fosc = 32 MHz (Habilitar PLL)
 * Realizar un contador binario de 8 bits, 0 - 255, que se visualize a trav�s
 * de las 8 l�neas del Puerto A. El incremento debe ser cada 300 mseg.
 * -Ver Descripci�n.txt
 ******************************************************************************/

/*******************************************************************************
 * Librerias
 ******************************************************************************/
#include <xc.h> //Lib con informaci�n del MCU
#include <stdint.h> //Lib est�ndar para enteros
#include "ConfigurationBits.h" //Bits de configuraci�n

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
 * Funci�n Principal
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
            //Llevar los 8 bits de u8_Contador a las 8 l�neas del PORTA
            PORTA = u8_Contador; 
            __delay_ms(300);
        }
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

    //--A.1--Configuraci�n oscilador interno
    OSCCONbits.IRCF = 0b110; //HFINTOSC = 8 MHz, Fosc = 8 MHz

    //--A.2--Habilitaci�n PLL
    OSCTUNEbits.PLLEN = 1; //Fosc = 4 x 8 MHz = 32 MHz

    //---B---Configuraci�n I/O Ports (Capitulo 10 DataSheet: I/O Ports)

    //--B.1--Inicializaci�n I/O Ports
    LATA = 0; //Inicializar PORTA

    //--B.2--Sentido I/O Ports
    TRISA = 0x00; //Todas las l�neas del PORTA como salidas
    
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