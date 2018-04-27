/*
 * File:   main.c
 * Author: Lenovo
 *
 * Created on 8 de febrero de 2018, 01:04 PM
 */

#include <xc.h>
#include <stdint.h>
#include "ConfigurationBits.h"
#include "eusart1.h"

//Prototipos de función
void SystemInitialize(void);

//Variables globales
volatile char c;
volatile char d;
static char uartBuffer[8];


char Mensaje[] = "Microcontroladores y Microprocesadores";
char Caracter = 'A';
uint8_t a = 31;
float b = 3.1416;

void main(void)
{
    SystemInitialize();
    
    printf(Mensaje);
    printf("\n\r");
    printf("a=%d, b=%.3f %s",a,b,"\n\r");
    printf("Letra = %c",Caracter);
    printf("oprima comando")
    
    EUSART1_Read_Text(uartBuffer,8);
    
    printf(uartBuffer);
    
    while(1);
    
    return;
}

void SystemInitialize(void)
{
    EUSART1_Initialize();
    return;
}