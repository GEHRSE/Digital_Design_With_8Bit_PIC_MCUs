/*
 * File:   main.c
 * Author: Lenovo
 *
 * Created on 17 de mayo de 2018, 12:55 PM
 */


#include <xc.h>
#include <stdint.h>

uint8_t dato = 0;

uint8_t EEPROMRead(uint16_t address);
void EEPROMWrite(uint16_t address, uint8_t dato);

void main(void)
{
    ADCON1bits.PCFG = 0b1111;
    EEPROMWrite(0x051,0x17);
    dato = EEPROMRead(0x051);
}

uint8_t EEPROMRead(uint16_t address)
{
    EEADRH = (uint8_t)(address>>8);
    EEADR = (uint8_t)address;
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS = 0;
    EECON1bits.RD = 1;
    return EEDATA;
}

void EEPROMWrite(uint16_t address, uint8_t dato)
{
    EEADRH = (uint8_t)(address>>8);
    EEADR = (uint8_t)address;
    EEDATA = dato;
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS = 0;
    EECON1bits.WREN = 1;
    
    INTCONbits.GIE = 0;
    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR = 1;
    INTCONbits.GIE = 1;
    EECON1bits.WREN = 0;    
}