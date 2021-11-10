/*
 * FW_Teclado.h
 *
 *  Created on:
 *      Author:
 */

#ifndef FW_TECLADO_H_
#define FW_TECLADO_H_

#include "Regs_LPC176x.h"
#include "FW_GPIO.h"
#include "FW_PINSEL.h"
#include "KitInfo2.h"

#define	ESPERANDO_TECLA			1
#define	VALIDAR_TECLA			2
#define	TECLA_PRESIONADA		3

#define CANT_PARA_VALIDAR		3

#define	NO_KEY		0xFF

#define KEY_1		1
#define KEY_2		2
#define KEY_3		3
#define KEY_4		4
#define KEY_5		5

// Buffer de Teclado 5x1
extern volatile uint8_t bufferTeclado5x1;

void Teclado5x1_Driver(void);
void Teclado5x1_SW(uint8_t codigoActual);
uint8_t Teclado5x1_HW(void);

#endif /* FW_TECLADO_H_ */

