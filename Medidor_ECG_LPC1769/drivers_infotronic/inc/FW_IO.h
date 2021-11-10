/*
 * FW_IO.h
 *
 *  Created on:
 *      Author:
 */

#ifndef INC_FW_IO_H_
#define INC_FW_IO_H_

#include "Regs_LPC176x.h"
#include "FW_GPIO.h"
#include "FW_PINSEL.h"
#include "KitInfo2.h"

#define 	IO_LED_STICK	0
#define 	IO_RGB_R		1
#define 	IO_RGB_G		2
#define 	IO_RGB_B		3

void IO_Init(void);
void IO_LED_Set(uint8_t led, uint8_t estado);
void IO_LED_Toggle(uint8_t led);
uint8_t IO_LED_GetStatus(uint8_t led);

#endif /* INC_FW_IO_H_ */
