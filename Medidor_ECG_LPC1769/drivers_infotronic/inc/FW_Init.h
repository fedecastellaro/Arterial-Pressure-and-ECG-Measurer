/*
 * FW_Init.h
 *
 *  Created on:
 *  Author:
 */

#ifndef FW_INIT_H_
#define FW_INIT_H_

#include "Regs_LPC176x.h"
#include "FW_GPIO.h"
#include "FW_PINSEL.h"
#include "FW_UART.h"
#include "FW_ADC.h"
#include "FW_EXTINT.h"
#include "FW_SysTick.h"
#include "FW_Teclado.h"
#include "FW_IO.h"
#include "FW_LCD.h"
#include "KitInfo2.h"

//Funciones de inicialización
void Kit_Init(void);
void PLL_Init(void);

#endif /* FW_INIT_H_ */
