/*******************************************************************************
 * File:   main.c
 * Author: Sebastian Puente R
 * e-mail: sebastian.puente@unillanos.edu.co
 * Universidad de los Llanos
 * Villavicencio-Meta, Colombia
 * Created on 9 de septiembre de 2014, 12:05 AM
 ******************************************************************************
 * DESCRIPCIÓN
 * Para este ejemplo se trabaja con el oscilador interno a 8 MHz.
 * Se conecta un display 7 segmentos de cátodo común
 * Ver la libreria BitsConfiguracion.h
 ******************************************************************************/

////////////////////////////////////////////////////////////////////////////////
//Directivas de preprocesamiento
#include <xc.h>                 //Libreria necesaria para el PIC escogido
#include "BitsConfiguracion.h"  //Libreria con los Bits de Configuración

////////////////////////////////////////////////////////////////////////////////
//Macros            8 MHz

#define _XTAL_FREQ 8000000 //Este macro es necesario para utilizar __delay_us(x), __delay_ms(x)

////////////////////////////////////////////////////////////////////////////////
//Prototipos de funciones
void SetUp();
void delayms(int ms);

////////////////////////////////////////////////////////////////////////////////
//Variables Globales
char Disp7SegCC[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

////////////////////////////////////////////////////////////////////////////////
//Función principal en C
void main()
{
    char aux = 0;
    SetUp();    //Llamado a la función SetUp

    while(1)    //Bucle infinito
    {
        PORTD = Disp7SegCC[aux];
        delayms(1000);
        if(PORTBbits.RB0 == 1)
        {
            aux = aux + 1;
            if(aux > 9)
                aux = 0;
        }
        else if(aux == 0)
        {
            aux = 9;
        }
        else
        {
            aux = aux - 1;
        }
    }
}

//Función SetUp
void SetUp()
{
    //Frecuencia Oscilador Interno
    OSCCONbits.IRCF = 0b111;    //Oscilador interno a 8 MHz
    //Configuración Puertos
    ADCON1bits.PCFG = 0b1111;   //Todos los pines asociados como canales analógicos son configurados como digitales (Pag 266 DataSheet)
    TRISBbits.TRISB0 = 1;       //Línea RB0 como entrada
    TRISD = 0x00;               //Todo el puerto D como salida
}

//Función delayms
void delayms(int ms)
{
    for(int n = 0; n < ms; n++)
    {
        __delay_ms(1);
    }
}
////////////////////////////////////////////////////////////////////////////////