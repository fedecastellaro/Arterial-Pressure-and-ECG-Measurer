/**
 	\file FW_SysTick.c
 	\brief Driver del SysTick
 	\details
 	\author
 	\date
*/

#include "FW_SysTick.h"

volatile uint8_t flag_updateValorLCD = 0;

void SysTick_Init(uint32_t useg)
{
	uint32_t value;

	// N = t / (1/fclk) = t * fclk
	// si fclk = 100MHz -->  N = t (en us) * 100
	// Para temporizaciones repetitivas se debe cargar N-1
	value = useg * 100 - 1;
	STRELOAD = value;
	//Hago que se dispare la interrupción al habilitar
	STCURR = 0;
	//Habilito el SysTick
	STCTRL = 0x00000007;
}

void SysTick_Handler(void)
{
	static uint32_t ticks_10ms = TICKS_CENTESIMAS;
	static uint32_t	ticks_100ms = TICKS_DECIMAS;
	static uint32_t ticks_1seg = TICKS_SEGUNDOS;

	Teclado5x1_Driver();
	// rutina de control y actualización del LCD
	LCD_Driver();
	// variable temporizada para inicializar el LCD
	if (LCD_delay)
		LCD_delay--;

	if (ADC_delay != 0)
		ADC_delay--;


	// control de las temporizaciones
	ticks_10ms--;
	if(!ticks_10ms) {
		// cada 10ms
		ticks_10ms = TICKS_CENTESIMAS;
		ticks_100ms--;
		if(!ticks_100ms) {
			// cada 100ms
			flag_updateValorLCD = 1;

			ticks_100ms = TICKS_DECIMAS;
			ticks_1seg--;
			if(!ticks_1seg) {
				// cada 1seg


				ticks_1seg = TICKS_SEGUNDOS;
				// seteo el flag para avisar a la aplicación

			}
		}
	}
}

