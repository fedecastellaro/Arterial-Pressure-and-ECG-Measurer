/*
 * FW_GPIO.h
 *
 *  Created on:
 *  	Author:
 */

#ifndef FW_GPIO_H_
#define FW_GPIO_H_

#include "Regs_LPC176x.h"

#define	OFF		0
#define	ON		1
#define FALSE	0
#define TRUE	1
#define BAJO	0
#define ALTO	1

//!< ----------- Dirección en FIODIR
#define 	GPIO_ENTRADA		0
#define 	GPIO_SALIDA			1

//Prototipos de funciones
void SetDIR(uint8_t puerto, uint8_t pin, uint8_t dir);
void SetPIN(uint8_t puerto, uint8_t pin, uint8_t estado);
uint8_t GetPIN(uint8_t puerto, uint8_t pin);

#endif /* FW_GPIO_H_ */
