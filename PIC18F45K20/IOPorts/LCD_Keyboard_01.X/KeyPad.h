/* 
 * File:   KeyPad.h
 * Author: Sebastian Puente R
 *
 * Created on 27 de octubre de 2014, 11:42 PM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

#include <xc.h>

#define NumRows 4
#define NumCols 4
#define _XTAL_FREQ 16000000

/******************************************************************************/
/*Prototipos de función*/
void KeyPadSetup(void);
char GetCol(char ColValue);
char GetKey(void);
/******************************************************************************/
/*Variables globales*/
char Keys[NumRows][NumCols] = { {'1','2','3','A'},
                                {'4','5','6','B'},
                                {'7','8','9','C'},
                                {'*','0','#','D'}
                              };
/*'1' = 0x31, '2' = 0x32, '3' = 0x33, 'A' = 0x41
 *'4' = 0x34, '5' = 0x35, '6' = 0x36, 'B' = 0x42
 *'7' = 0x37, '8' = 0x38, '9' = 0x39, 'C' = 0x43
 *'*' = 0x2A, '0' = 0x30, '#' = 0x23, 'D' = 0x44*/
/******************************************************************************/
/*Función GetKey*/
char GetKey(void)
{
    KeyPadSetup();
    char Row = 0;
    char Col = 0; //Col tendrá el número de la columna donde se digitó una tecla
    char AnsCol = 0; //Valor actual de las 4 columnas
    char Cont = 0;

    /*Se activa, con un cero, cada una de las filas. Ej. fila 1 -> 1110*/
    for(Row = 0; Row < NumRows; Row++)
    {
        PORTB = ~(1 << Row);
        __delay_ms(10);  
        AnsCol = PORTB >> 4; //Valor actual de las columnas

        /*Si no se oprime ninguna tecla para cada una de las filas, se debe
         * volver a explorar de nuevo cada una de las filas (es decir, el ciclo
         * for se reinicia)*/
        if(AnsCol == 0x0F)
        {
            Cont += 1;
            if(Cont == NumCols)
            {
                /*Row en 255 ya que cuando se continue con el for Row valdrá 0*/
                Row = 255; Cont = 0;
            }
            continue;
        }
        else
        {
            break;
        }
    }
    Col = GetCol(AnsCol);
    return Keys[Row][Col];
}
/******************************************************************************/
/*Función Setup*/
void KeyPadSetup()
{
    LATB = 0;
    PORTB = 0;
    //ADCON1bits.PCFG = 0b1111;
    //Para los PIC18 que manejen los registros ANSEL y ANSELH en vez de los bits PCFG
    ANSELHbits.ANS11 = 0; //Digital input buffer of RB4 is enabled
    TRISB = 0xF0;
}
/******************************************************************************/
/*Función Obtener Columna*/
char GetCol(char ColValue)
{
    char Col;

    switch(ColValue)
    {
        case 0b00001110:
            Col = 0; break;
        case 0b00001101:
            Col = 1; break;
        case 0b00001011:
            Col = 2; break;
        case 0b00000111:
            Col = 3; break;
        default:
            break;
    }
    return Col;
}

#endif	/* KEYPAD_H */
/******************************************************************************/
/*Sebastián F. Puente Reyes, M.Sc.
 Universidad de los Llanos
 Villavicencio, Meta, Colombia
 Octubre de 2014*/
/******************************************************************************/