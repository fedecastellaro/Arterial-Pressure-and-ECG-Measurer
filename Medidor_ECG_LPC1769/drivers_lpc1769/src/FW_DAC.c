/**
 	\file FW_DAC.c
 	\brief Driver del DAC (Conversor Digital/Analógico)
 	\details
 	\author
 	\date
*/

#include "FW_DAC.h"

void DAC_Init(void)
{
	//1.- Selecciono el clock del DAC como 25MHz:
	PCLKSEL0 &= ~(0x03<<22);
	//2.- Configuro los pines del DAC
	//DAC : P0[26]->PINSEL1: 20:21
	SetPINSEL(P0, 26, PINSEL_FUNC2);
	//Pongo una R de pull down en el pin:
	PINMODE1 |= 0x3 << 20;
	//3.- Configuro el DAC:
	DACCNTVAL = 0x000000FA; //CNTVAL = 250 => 25MHz/250 = 10kHz
	DACCTRL = 0x00000006; 	//DBLBUF_ENA = 1, CNT_ENA = 1
}

void DAC_SetValue(uint16_t valor)
{
	DACR = ((valor & 0x03FF)<<6) | (1<<16);
}
