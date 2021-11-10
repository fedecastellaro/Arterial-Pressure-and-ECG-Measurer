/**
 	\file PR_LCD.c
 	\brief Funciones para manejar un LCD (de dos líneas)
 	\details
 	\author
 	\date
*/

#include "PR_LCD.h"

void LCD_DisplayMsg(char * msg, uint8_t r, uint8_t pos)
{
	uint8_t i;

	switch (r) {
		case LCD_RENGLON_1:
			LCD_Push((pos|0x80), LCD_CONTROL);
			break;
		case LCD_RENGLON_2:
			LCD_Push((pos|0xC0), LCD_CONTROL);
			break;
	}
	for(i = 0; msg[i] != '\0'; i++)
		LCD_Push(msg[i], LCD_DATA);
}
