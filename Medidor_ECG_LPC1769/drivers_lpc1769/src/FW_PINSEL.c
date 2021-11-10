/*
 * FW_PINSEL.c
 *
 *  Created on:
 *      Author:
 */

#include "FW_PINSEL.h"

/********************************************************************************
	\fn  		void SetPINSEL(uint8_t puerto, uint8_t pin, uint8_t func)
	\brief 		Selección de función para un pin (4 modos)
	\param[in] 	puerto	Port a configurar
	\param[in] 	pin		Pin del port a configurar
	\param[in] 	func	Elección de la función para el pin [0 - 3]
				-		PINSEL_GPIO			0
				-		PINSEL_FUNC1		1
				-		PINSEL_FUNC2		2
				-		PINSEL_FUNC3		3
	\return 	void
*/
void SetPINSEL(uint8_t puerto, uint8_t pin, uint8_t func)
{
	uint32_t offset;

	if( puerto >= 0 && puerto <= 4 ) {
		offset = 2 * puerto;
		if ( pin >= 16 ) {
			pin -= 16;
			offset++;
		}
		PINSEL[offset] &= ~ ( 0x03 << ( pin * 2 ) );
		PINSEL[offset] |= ( func << ( pin * 2 ) );
	}
}

/********************************************************************************
	\fn			void SetResistorMode(uint8_t puerto, uint8_t pin, uint8_t modo)
	\brief 		Setup resistor mode for each pin
	\param[in]	puerto	Port a configurar
	\param[in]	pin		Pin del port a configurar
	\param[in] 	modo	Elección del modo
				-		PINMODE_PULLUP 		0
				-		PINMODE_REPEAT 		1
				-		PINMODE_TRISTATE	2
				-		PINMODE_PULLDOWN 	3
	\return 	void
*/
void SetResistorMode(uint8_t puerto, uint8_t pin, uint8_t modo)
{
	uint32_t offset;

	if( puerto >= 0 && puerto <= 4 ) {
		offset = 2 * puerto;
		if ( pin >= 16 ) {
			pin -= 16;
			offset++;
		}
		PINMODE[offset] &= ~ ( 0x03 << ( pin * 2 ) );
		PINMODE[offset] |= ( modo << ( pin * 2 ) );
	}
}

/********************************************************************************
	\fn  		void SetOpenDrainMode(uint8_t puerto, uint8_t pin, uint8_t modo)
	\brief 		Setup Open drain mode for each pin
	\param[in] 	puerto	Port a configurar
	\param[in]	pin		Pin del port a configurar
	\param[in]	modo	Modo Normal(0) o Modo Open-drain(1)
	\return 	void
*/
void SetOpenDrainMode(uint8_t puerto, uint8_t pin, uint8_t modo)
{
	if( puerto >= 0 && puerto <= 4 ) {
		if( modo == PINMODE_OPENDRAIN ) {
			PINMODE_OD[puerto] |= (0x01 << pin);
		} else {
			PINMODE_OD[puerto] &= ~(0x01 << pin);
		}
	}
}
