/*
 * AP_Controlador.c
 *
 *  Created on:
 *      Author:
 */

#include "AP_Controlador.h"

uint8_t flag_IniciarMedicion = 0;
uint8_t flag_DetenerMedicion = 0;
volatile uint32_t LCD_delay2 = 5;



void Controlador(void)
{
	static uint32_t estado_medidor = MEDIDOR_RESET;
	static char msg_LCD[2*LARGO_RENGLON];

	// MdE: medición del ADC y transmisión de datos
	switch (estado_medidor) {
		case MEDIDOR_RESET:
			LCD_DisplayMsg(" Medidor de ECG ", LCD_RENGLON_1, 0);
			LCD_DisplayMsg(" Prueba Sampling", LCD_RENGLON_2, 0);
			estado_medidor = MEDIDOR_INACTIVO;
			break;

		case MEDIDOR_INACTIVO:
			if (flag_IniciarMedicion == 1)
			{
			flag_IniciarMedicion = 0;
			LCD_DisplayMsg("                 ", LCD_RENGLON_1, 0);
			LCD_DisplayMsg("                 ", LCD_RENGLON_2, 0);

			LCD_DisplayMsg(" KEY_2 -> PAUSE  ", LCD_RENGLON_2, 0);
			LCD_DisplayMsg(" KEY_1 -> START  ", LCD_RENGLON_1, 0);
			flag_IniciarMedicion = 0;

			estado_medidor = WAITING_KEY;

			}
			break;

			// chequeo si llegó un comando para iniciar la medición
		case WAITING_KEY:
				if (bufferTeclado5x1 == KEY_1)
				{
				ADC_BurstEnable();
				LCD_DisplayMsg(" > MIDIENDO      ", LCD_RENGLON_1, 0);
				IO_LED_Set(IO_LED_STICK, ON);
				estado_medidor = MEDIDOR_ACTIVO;
				}
			break;

		case MEDIDOR_ACTIVO:
			// si hay un dato disponible, lo envío por el puerto serie
			if (ADC_dato_disponible) {
				ADC_dato_disponible = 0;
				// transmito la trama con un nuevo dato
				PushTx('$');
				PushTx((char)((ADC_valor>>8) & 0xFF));
				PushTx((char)(ADC_valor & 0xFF));
				//PushTx('#');
			}
			// chequeo si llegó un comando para detener la medición
			else if (flag_DetenerMedicion == 1 || bufferTeclado5x1 == KEY_2) {
				flag_DetenerMedicion = 0;
				ADC_BurstDisable();
				IO_LED_Set(IO_LED_STICK, OFF);

				flag_IniciarMedicion = 1;
				estado_medidor = MEDIDOR_INACTIVO;
			}
			// actualizo el valor mostrado en el LCD
			else if (flag_updateValorLCD) {
				flag_updateValorLCD  = 0;
				sprintf(msg_LCD, "valorADC=%04d   ", ADC_valor);
				LCD_DisplayMsg(msg_LCD, LCD_RENGLON_2, 0);
			}
			break;

		default:
			estado_medidor = MEDIDOR_INACTIVO;
			break;
	}
}

void RX_Mensajes(void)
{
	uint8_t dato;
	static uint8_t index_msg_rx = 0;
	static char msg_rx[MAX_TRAMA_RX] = {0};
	static uint32_t estado_rx = ESPERANDO_TRAMA;

	// Chequeo si llegó un msje...
	if (!PopRx(&dato)) {
		// MdE: Análisis de la trama recibida
		switch (estado_rx) {
			case ESPERANDO_TRAMA: 	// Espero el caracter de inicio de la trama ('$')
				if ((char)dato == '$') {
					index_msg_rx = 0;
					estado_rx = RECIBIENDO_TRAMA;
				}
				break;
			case RECIBIENDO_TRAMA:	// Recibo y almaceno la trama completa
				// Chequeo si llegó el final de la trama ('#')
				if ((char)dato != '#') {
					msg_rx[index_msg_rx] = (char)dato;
					index_msg_rx++;
					if (index_msg_rx > MAX_TRAMA_RX)
						estado_rx = ESPERANDO_TRAMA;
				} else {
					// msg_rx[0]: 'M' (comando medición ADC)
					// msg_rx[1]: '0' detener, '1' iniciar
					if ((msg_rx[0]) == 'M' || (msg_rx[0]) == 'm') {
						if((msg_rx[1]) == '0') {
							flag_DetenerMedicion = 1;
						}
						else if ((msg_rx[1]) == '1')
								flag_IniciarMedicion = 1;

					}
					estado_rx = ESPERANDO_TRAMA;
				}
				break;


			default:
				estado_rx = ESPERANDO_TRAMA;
				break;
		}
	}
}
