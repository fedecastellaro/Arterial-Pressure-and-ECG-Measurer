/*
 * FW_PINSEL.h
 *
 *  Created on:
 *      Author:
 */

#ifndef FW_PINSEL_H_
#define FW_PINSEL_H_

#include "Regs_LPC176x.h"

//!< ----------- Valores para PINSEL
#define		PINSEL_GPIO			0
#define		PINSEL_FUNC1		1
#define		PINSEL_FUNC2		2
#define		PINSEL_FUNC3		3

//!< ----------- Estados de PINMODE
//!< 00	Pull Up resistor enable (reset value)		01	Repeater mode enable
//!< 11	Pull Down resistor enable					10	Tri-state mode enable
#define		PINMODE_PULLUP 		0
#define		PINMODE_REPEAT 		1
#define		PINMODE_TRISTATE	2
#define		PINMODE_PULLDOWN 	3

//!< ----------- Estados de PINMODE_OD
//!< 0 Normal (not open drain) mode
//!< 1 Open drain mode
#define		PINMODE_NORMAL		0
#define		PINMODE_OPENDRAIN	1

//Prototipos de funciones
void SetPINSEL(uint8_t puerto, uint8_t pin, uint8_t func);
void SetResistorMode(uint8_t puerto, uint8_t pin, uint8_t modo);
void SetOpenDrainMode(uint8_t puerto, uint8_t pin, uint8_t modo);

#endif /* FW_PINSEL_H_ */
