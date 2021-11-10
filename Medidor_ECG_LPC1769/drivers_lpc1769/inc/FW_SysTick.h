/*
 * FW_Timertick.h
 *
 *  Created on:
 *      Author:
 */

#ifndef FW_SYSTICK_H_
#define FW_SYSTICK_H_

#include "Regs_LPC176x.h"
#include "FW_LCD.h"
#include "FW_Teclado.h"
#include "FW_ADC.h"

extern volatile uint8_t flag_updateValorLCD;

void SysTick_Init(uint32_t useg);

//Defines
#define TICKS_CENTESIMAS  	4
#define TICKS_DECIMAS		10
#define TICKS_SEGUNDOS		10

#endif /* FW_SYSTICK_H_ */

