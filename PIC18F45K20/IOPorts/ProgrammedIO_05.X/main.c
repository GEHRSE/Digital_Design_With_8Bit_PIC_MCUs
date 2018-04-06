/*******************************************************************************
 * FileName:        main.c
 * ProjectName:     ProgrammedIO_05
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18F45K20
 * Compiler:        XC8
 * Version:         1.45
 * Author:          Sebastián Fernando Puente Reyes
 * e-mail:          sebastian.puente@unillanos.edu.co
 * Date:            Marzo de 2018
 *******************************************************************************
 * REQUERIMIENTO
 * Oscilador: Interno a 16 MHz con PLL, Fosc = 64 MHz.
 * Se captura un número de 4 bits (0-15) por las líneas RB<3:0>.
 * Si el número esta entre 0-9 se visualiza en un display 7 segmentos cátodo
 * común, conectado en el PORTD, de lo contrario no se visualiza nada
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
//Arreglo para el manejo de un display 7 segmentos de cátodo común
//                    0    1    2    3    4    5    6    7    8    9
char Disp7SegCC[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

/*******************************************************************************
 * Función Principal
 ******************************************************************************/
void main(void)
{
    SetUp(); //Llamada función SetUp()

    while(1) //Ciclo infinito
    {
        //Para este caso el display mostrará números del 0 al 9
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
 * DESCRIPTION: Configuración inicial (oscilador, puertos, etc.)
 ******************************************************************************/
void SetUp(void)
{
    //Configuración frecuencia oscilador interno
    OSCCONbits.IRCF = 0b111; //Oscilador interno a 16 MHz
    OSCTUNEbits.PLLEN = 1; //PLL habilitada Fosc = 4 x 16MHz = 64MHz
    
    //Configuración I/O ports
    LATB = 0; //Inicializar PORTB
    LATD = 0; //Inicializar PORTD
    //Buffers de entrada digital habilitados para RB0/RB1/RB2/RB3
    ANSELHbits.ANS12 = 0; //RB0
    ANSELHbits.ANS10 = 0; //RB1 
    ANSELHbits.ANS8 = 0; //RB2
    ANSELHbits.ANS9 = 0; //RB3
    TRISB = 0xFF; //Líneas del PORTB como entradas digitales
    TRISD = 0x00; //Líneas del PORTD como salidas digitales

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