/*
 * FW_lcd.h
 *
 *  Created on:
 *      Author:
 */

#ifndef FW_LCD_H_
#define FW_LCD_H_

#include "Regs_LPC176x.h"
#include "FW_GPIO.h"
#include "FW_PINSEL.h"
#include "KitInfo2.h"

#define LCD_BUFFER_SIZE	160

#define LARGO_RENGLON	16

#define 	LCD_RENGLON_1		0
#define 	LCD_RENGLON_2		1
#define		LCD_CONTROL		1
#define		LCD_DATA		0

void LCD_Init(void);
void LCD_Config(void);
uint8_t LCD_Push(uint8_t dato, uint8_t control);
int LCD_Pop(void);
void LCD_Driver(void);

extern volatile uint32_t LCD_delay;
extern volatile uint32_t LCD_delay2;

#endif /* FW_LCD_H_ */
