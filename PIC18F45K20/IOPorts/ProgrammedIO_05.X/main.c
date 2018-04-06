/*******************************************************************************
 * FileName:        main.c
 * ProjectName:     ProgrammedIO_05
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18F45K20
 * Compiler:        XC8
 * Version:         1.45
 * Author:          Sebasti�n Fernando Puente Reyes
 * e-mail:          sebastian.puente@unillanos.edu.co
 * Date:            Marzo de 2018
 *******************************************************************************
 * REQUERIMIENTO
 * Oscilador: Interno a 16 MHz con PLL, Fosc = 64 MHz.
 * Se captura un n�mero de 4 bits (0-15) por las l�neas RB<3:0>.
 * Si el n�mero esta entre 0-9 se visualiza en un display 7 segmentos c�todo
 * com�n, conectado en el PORTD, de lo contrario no se visualiza nada
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
void SetUp(void);

/*******************************************************************************
 * Variables globales
 ******************************************************************************/
//Arreglo para el manejo de un display 7 segmentos de c�todo com�n
//                    0    1    2    3    4    5    6    7    8    9
char Disp7SegCC[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

/*******************************************************************************
 * Funci�n Principal
 ******************************************************************************/
void main(void)
{
    SetUp(); //Llamada funci�n SetUp()

    while(1) //Ciclo infinito
    {
        //Para este caso el display mostrar� n�meros del 0 al 9
        if(PORTB < 10)
        {
            PORTD = Disp7SegCC[PORTB];
        }
        else //para >= 10 no se muestra nada en el display
        {
            PORTD = 0x00; //se apagan todos los segmentos del display
        }
    }
}

/*******************************************************************************
 * FUNCTION:	SetUp()
 * INPUTS:      None
 * OUTPUTS:     None
 * DESCRIPTION: Configuraci�n inicial (oscilador, puertos, etc.)
 ******************************************************************************/
void SetUp(void)
{
    //Configuraci�n frecuencia oscilador interno
    OSCCONbits.IRCF = 0b111; //Oscilador interno a 16 MHz
    OSCTUNEbits.PLLEN = 1; //PLL habilitada Fosc = 4 x 16MHz = 64MHz
    
    //Configuraci�n I/O ports
    LATB = 0; //Inicializar PORTB
    LATD = 0; //Inicializar PORTD
    //Buffers de entrada digital habilitados para RB0/RB1/RB2/RB3
    ANSELHbits.ANS12 = 0; //RB0
    ANSELHbits.ANS10 = 0; //RB1 
    ANSELHbits.ANS8 = 0; //RB2
    ANSELHbits.ANS9 = 0; //RB3
    TRISB = 0xFF; //L�neas del PORTB como entradas digitales
    TRISD = 0x00; //L�neas del PORTD como salidas digitales

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