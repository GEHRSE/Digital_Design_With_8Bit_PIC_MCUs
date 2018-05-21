/*******************************************************************************
 * FileName:        main.c
 * ProjectName:     ProgrammedIO_03 
 * Course:          Diseño Digital con Microcontroladores PIC de 8 bits
 * Topic:           I/O Ports - Unconditional Programmed I/O
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18F45K20
 * Compiler:        XC8, Ver. 1.45
 * Author:          Sebastián Fernando Puente Reyes
 * e-mail:          sebastian.puente@unillanos.edu.co
 * Date:            Marzo de 2018
 *******************************************************************************
 * REQUERIMIENTO
 * Oscilador: Interno a 16 MHz, Fosc = 16 MHz.
 * Generar una señal cuadrada por la línea RE0 con un periodo (T) de 2 seg y
 * un ciclo de trabajo del 50%. Es decir, la señal se mantiene en estado ALTO
 * por 1 seg(0.5*2) y luego pasa a estado BAJO por 1 seg(0.5*2).
 * -Ver Descripcion.txt
 ******************************************************************************/

/*******************************************************************************
 * Librerias
 ******************************************************************************/
#include <xc.h> //Lib con información del MCU
#include "ConfigurationBits.h" //Bits de configuración

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
    //--Configutaciones Iniciales
    SetUp();

    //--Ciclo Infinito, Tareas que el MCU hace indefinidamente
    while(1)
    {
        LED = !LED; //Se complementa la variable LED
        PORTEbits.RE0 = LED; //El valor de la variable LED se muestra por la línea RE0
        __delay_ms(1000);    //Función para temporizaciones en ms, se pide un retardo de 1000 ms = 1seg
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

    //--A.1--Configuración oscilador interno (si es el caso)
    OSCCONbits.IRCF = 0b111; //HFINTOSC = 16 MHz, Fosc = 16 MHz

    //---B---Configuración I/O Ports (Capitulo 10 DataSheet: I/O Ports)

    //--B.1--Inicialización I/O Ports
    LATE = 0; //Inicializar PORTE

    //--B.2--Sentido I/O Ports
    TRISEbits.TRISE0 = 0; //Línea RE0 como salida
    
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