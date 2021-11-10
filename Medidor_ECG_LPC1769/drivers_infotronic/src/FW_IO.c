/*
 * FW_IO.c
 *
 *  Created on:
 *      Author:
 */

#include "FW_IO.h"

void IO_Init(void)
{
	// LED STICK
	SetPINSEL(LED_STICK, PINSEL_GPIO);
	SetDIR(LED_STICK, GPIO_SALIDA);
	SetPIN(LED_STICK, OFF);
	//LEDs RGB
	SetPINSEL(RGB_R, PINSEL_GPIO);
	SetPINSEL(RGB_G, PINSEL_GPIO);
	SetPINSEL(RGB_B, PINSEL_GPIO);
	SetDIR(RGB_R, GPIO_SALIDA);
	SetDIR(RGB_G, GPIO_SALIDA);
	SetDIR(RGB_B, GPIO_SALIDA);
	SetPIN(RGB_R, OFF);
	SetPIN(RGB_G, OFF);
	SetPIN(RGB_B, OFF);
}

void IO_LED_Set(uint8_t led, uint8_t estado)
{
	switch (led) {
		case IO_LED_STICK:
			SetPIN(LED_STICK, estado);
			break;
		case IO_RGB_R:
			SetPIN(RGB_R, estado);
			break;
		case IO_RGB_G:
			SetPIN(RGB_G, estado);
			break;
		case IO_RGB_B:
			SetPIN(RGB_B, estado);
			break;
		default:
			break;
	}
}

void IO_LED_Toggle(uint8_t led)
{
	switch (led) {
		case IO_LED_STICK:
			SetPIN(LED_STICK, !GetPIN(LED_STICK));
			break;
		case IO_RGB_R:
			SetPIN(RGB_R, !GetPIN(RGB_R));
			break;
		case IO_RGB_G:
			SetPIN(RGB_G, !GetPIN(RGB_G));
			break;
		case IO_RGB_B:
			SetPIN(RGB_B, !GetPIN(RGB_B));
			break;
		default:
			break;
	}

}

uint8_t IO_LED_GetStatus(uint8_t led)
{
	uint8_t estado = 0;

	switch (led) {
		case IO_LED_STICK:
			estado = GetPIN(LED_STICK);
			break;
		case IO_RGB_R:
			estado = GetPIN(RGB_R);
			break;
		case IO_RGB_G:
			estado = GetPIN(RGB_G);
			break;
		case IO_RGB_B:
			estado = GetPIN(RGB_B);
			break;
		default:
			break;
	}

	return estado;
}
