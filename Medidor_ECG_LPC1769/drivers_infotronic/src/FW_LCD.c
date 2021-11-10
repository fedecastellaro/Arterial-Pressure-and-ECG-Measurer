/**
 	\file FW_LCD.c
 	\brief Drivers del LCD
 	\details Validos para LCD manjados por 4 bits
 	\author Pablo Irrera Condines
 	\date 2013.08.05
*/

#include "FW_LCD.h"

volatile uint8_t buffer_LCD[LCD_BUFFER_SIZE];
volatile uint32_t indexIn_LCD;
volatile uint32_t indexOut_LCD;
volatile uint32_t LCD_delay;


void LCD_Init(void)
{
	SetPINSEL(P0, 5, PINSEL_GPIO);	//LCD_D4
	SetPINSEL(P0, 10, PINSEL_GPIO);	//LCD_D5
	SetPINSEL(P2, 4, PINSEL_GPIO);	//LCD_D6
	SetPINSEL(P2, 5, PINSEL_GPIO);	//LCD_D7
	SetPINSEL(P2, 6, PINSEL_GPIO);	//LCD_RS
	SetPINSEL(P0, 4, PINSEL_GPIO);	//LCD_E

	SetDIR(LCD_D4, GPIO_SALIDA);
	SetDIR(LCD_D5, GPIO_SALIDA);
	SetDIR(LCD_D6, GPIO_SALIDA);
	SetDIR(LCD_D7, GPIO_SALIDA);
	SetDIR(LCD_RS, GPIO_SALIDA);
	SetDIR(LCD_E, GPIO_SALIDA);

	SetPIN(LCD_D4, OFF);
	SetPIN(LCD_D5, OFF);
	SetPIN(LCD_D6, OFF);
	SetPIN(LCD_D7, OFF);
	SetPIN(LCD_E, OFF);
	SetPIN(LCD_RS, OFF);

	LCD_Config();
}

void LCD_Config(void)
{
	uint8_t i;

	SetPIN(LCD_E, OFF);
	LCD_delay = 10;			// Demora inicial
	while(LCD_delay);

	for(i = 0; i < 3; i++) {
		SetPIN(LCD_D4, ON);			// Configuración en 8 bits
		SetPIN(LCD_D5, ON);
		SetPIN(LCD_D6, OFF);
		SetPIN(LCD_D7, OFF);
		SetPIN(LCD_RS, OFF);
		SetPIN(LCD_E, ON);
		SetPIN(LCD_E, OFF);
		LCD_delay = 2;
		while(LCD_delay);
	}

	// Configuracion en 4 bits
	SetPIN(LCD_D4,OFF);
	SetPIN(LCD_D5,ON);
	SetPIN(LCD_D6,OFF);
	SetPIN(LCD_D7,OFF);

	SetPIN(LCD_RS,OFF);
	SetPIN(LCD_E,ON);
	SetPIN(LCD_E,OFF);

	LCD_delay = 1;	// Demora inicial
	while (LCD_delay);

	// A partir de aca el LCD pasa a 4 bits !!!
	LCD_Push(0x28, LCD_CONTROL);	// DL = 0: 4 bits de datos
								// N = 1 : 2 lineas
								// F = 0 : 5x7 puntos

	LCD_Push(0x08, LCD_CONTROL);	// D = 0 : display OFF
								// C = 0 : Cursor OFF
								// B = 0 : Blink OFF

	LCD_Push(0x01, LCD_CONTROL);	// clear display

	LCD_Push(0x06, LCD_CONTROL);	// I/D = 1 : Incrementa puntero
								// S = 0 : NO Shift Display

	// Activo el LCD y listo para usar !
	LCD_Push(0x0C, LCD_CONTROL);	// D = 1 : display ON
								// C = 0 : Cursor OFF
								// B = 0 : Blink OFF
}

uint8_t LCD_Push(uint8_t dato, uint8_t control)
{

	buffer_LCD[indexIn_LCD] = (dato >> 4) & 0x0F;
	if(control == LCD_CONTROL)
		buffer_LCD[indexIn_LCD] |= 0x80;

	indexIn_LCD++;
	indexIn_LCD %= LCD_BUFFER_SIZE;

	buffer_LCD[indexIn_LCD] = dato & 0x0F;
	if(control == LCD_CONTROL)
		buffer_LCD[indexIn_LCD] |= 0x80;

	indexIn_LCD++;
	indexIn_LCD %= LCD_BUFFER_SIZE;

	return 0;
}

int LCD_Pop (void)
{
	char dato;

	if(indexIn_LCD == indexOut_LCD)
		return -1;

	dato = buffer_LCD[indexOut_LCD];
	indexOut_LCD++;
	indexOut_LCD %= LCD_BUFFER_SIZE;

	return dato;
}

void LCD_Driver(void)
{
	int data;
	static uint8_t estadoEnable = 0;

	if(estadoEnable == 0) {
		if((data = LCD_Pop ()) == -1)
			return;

		SetPIN(LCD_D7, (((uint8_t)data) >> 3) & 0x01);
		SetPIN(LCD_D6, (((uint8_t)data) >> 2) & 0x01);
		SetPIN(LCD_D5, (((uint8_t)data) >> 1) & 0x01);
		SetPIN(LCD_D4, (((uint8_t)data) >> 0) & 0x01);

		if(((uint8_t)data) & 0x80)
			SetPIN(LCD_RS, OFF);
		else
			SetPIN(LCD_RS, ON);

		SetPIN(LCD_E, ON);
		estadoEnable = 1;
	} else if(estadoEnable == 1) {
		SetPIN(LCD_E, OFF);
		estadoEnable = 0;
	}
}
