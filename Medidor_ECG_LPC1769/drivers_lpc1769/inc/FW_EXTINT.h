/*
 * FW_EXTINT.h
 *
 *  Created on:
 *      Author:
 */

#ifndef INC_FW_EXTINT_H_
#define INC_FW_EXTINT_H_

#include "Regs_LPC176x.h"
#include "FW_PINSEL.h"

//flags para notificar a la Aplicación de las Interrupciones Externas
extern volatile uint32_t EINT0_flag;
extern volatile uint32_t EINT3_flag;

//Prototipos de funciones
void EINT_Init(void);
void EINT_SetMode(uint8_t EXTINTx, uint8_t modo);
void EINT_SetPolarity(uint8_t EINTx, uint8_t polaridad);

//Defines
#define		EINT0		0
#define		EINT1		1
#define		EINT2		2
#define		EINT3		3

#define 	EXTMODE_NIVEL		0
#define 	EXTMODE_FLANCO		1

#define 	EXTPOLAR_ACTIVO_BAJO_O_DESCENDENTE		0
#define 	EXTPOLAR_ACTIVO_ALTO_O_ASCENDENTE		1

#endif /* INC_FW_EXTINT_H_ */
