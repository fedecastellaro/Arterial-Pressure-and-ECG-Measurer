/*
 * FW_Teclado.c
 *
 *  Created on:
 *  	Author:
 */

#include "FW_Teclado.h"

// Buffer de Teclado 5x1
volatile uint8_t bufferTeclado5x1 = NO_KEY;

void Teclado5x1_Driver(void)
{
	uint8_t codigoActual;

	codigoActual = Teclado5x1_HW();		// Barrido del Teclado (HW)
	Teclado5x1_SW(codigoActual);		// Rutina Antirebote (SW)
}

void Teclado5x1_SW(uint8_t codigoActual)
{
	static uint8_t codigoAnterior = NO_KEY;
	static uint8_t estado = ESPERANDO_TECLA;
	static uint8_t contTeclaEstable = 0;

	switch (estado) {
		case ESPERANDO_TECLA:
			if (codigoActual != NO_KEY) {
				codigoAnterior = codigoActual;
				contTeclaEstable = 0;
				estado = VALIDAR_TECLA;
			}
			break;
		case VALIDAR_TECLA:
			if (codigoActual != codigoAnterior) {
				estado = ESPERANDO_TECLA;
			} else {
				contTeclaEstable++;
				if (contTeclaEstable == CANT_PARA_VALIDAR) {
					bufferTeclado5x1 = codigoActual;
					estado = TECLA_PRESIONADA;
				}
			}
			break;
		case TECLA_PRESIONADA:
			if (codigoActual != codigoAnterior) {
				estado = ESPERANDO_TECLA;
			}
			break;
		default:
			estado = ESPERANDO_TECLA;
			break;
	}
}

uint8_t Teclado5x1_HW(void)
{
	// los pulsadores son ACTIVO BAJO

	if (GetPIN(SW1_TECL5x1) == 0)
		return KEY_1;
	if (GetPIN(SW2_TECL5x1) == 0)
		return KEY_2;
	if (GetPIN(SW3_TECL5x1) == 0)
		return KEY_3;
	if (GetPIN(SW4_TECL5x1) == 0)
		return KEY_4;
	if (GetPIN(SW5_TECL5x1) == 0)
		return KEY_5;

	return NO_KEY ;
}

void Teclado5x1_Init(void)
{
	SetPINSEL(SW1_TECL5x1, PINSEL_GPIO);
	SetPINSEL(SW2_TECL5x1, PINSEL_GPIO);
	SetPINSEL(SW3_TECL5x1, PINSEL_GPIO);
	SetPINSEL(SW4_TECL5x1, PINSEL_GPIO);
	SetPINSEL(SW5_TECL5x1, PINSEL_GPIO);

	SetDIR(SW1_TECL5x1, GPIO_ENTRADA);
	SetDIR(SW2_TECL5x1, GPIO_ENTRADA);
	SetDIR(SW3_TECL5x1, GPIO_ENTRADA);
	SetDIR(SW4_TECL5x1, GPIO_ENTRADA);
	SetDIR(SW5_TECL5x1, GPIO_ENTRADA);

	SetResistorMode(SW1_TECL5x1, PINMODE_PULLUP);
	SetResistorMode(SW2_TECL5x1, PINMODE_PULLUP);
	SetResistorMode(SW3_TECL5x1, PINMODE_PULLUP);
	SetResistorMode(SW4_TECL5x1, PINMODE_PULLUP);
	SetResistorMode(SW5_TECL5x1, PINMODE_PULLUP);
}
