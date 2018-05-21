/*******************************************************************************
 * FileName:        main.c
 * ProjectName:     ProgrammedIO_03 
 * Course:          Dise�o Digital con Microcontroladores PIC de 8 bits
 * Topic:           I/O Ports - Unconditional Programmed I/O
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18F45K20
 * Compiler:        XC8, Ver. 1.45
 * Author:          Sebasti�n Fernando Puente Reyes
 * e-mail:          sebastian.puente@unillanos.edu.co
 * Date:            Marzo de 2018
 *******************************************************************************
 * REQUERIMIENTO
 * Oscilador: Interno a 16 MHz, Fosc = 16 MHz.
 * Generar una se�al cuadrada por la l�nea RE0 con un periodo (T) de 2 seg y
 * un ciclo de trabajo del 50%. Es decir, la se�al se mantiene en estado ALTO
 * por 1 seg(0.5*2) y luego pasa a estado BAJO por 1 seg(0.5*2).
 * -Ver Descripcion.txt
 ******************************************************************************/

/*******************************************************************************
 * Librerias
 ******************************************************************************/
#include <xc.h> //Lib con informaci�n del MCU
#include "ConfigurationBits.h" //Bits de configuraci�n

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
 * Funci�n Principal
 ******************************************************************************/
void main(void)
{
    //--Configutaciones Iniciales
    SetUp();

    //--Ciclo Infinito, Tareas que el MCU hace indefinidamente
    while(1)
    {
        LED = !LED; //Se complementa la variable LED
        PORTEbits.RE0 = LED; //El valor de la variable LED se muestra por la l�nea RE0
        __delay_ms(1000);    //Funci�n para temporizaciones en ms, se pide un retardo de 1000 ms = 1seg
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

    //--A.1--Configuraci�n oscilador interno (si es el caso)
    OSCCONbits.IRCF = 0b111; //HFINTOSC = 16 MHz, Fosc = 16 MHz

    //---B---Configuraci�n I/O Ports (Capitulo 10 DataSheet: I/O Ports)

    //--B.1--Inicializaci�n I/O Ports
    LATE = 0; //Inicializar PORTE

    //--B.2--Sentido I/O Ports
    TRISEbits.TRISE0 = 0; //L�nea RE0 como salida
    
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