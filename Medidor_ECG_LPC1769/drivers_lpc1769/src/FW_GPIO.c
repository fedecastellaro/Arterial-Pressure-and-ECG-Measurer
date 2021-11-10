/*
 * FW_GPIO.c
 *
 *  Created on:
 *  	Author:
 */

#include "FW_GPIO.h"

/********************************************************************************
	\fn		void void SetDIR(uint8_t puerto, uint8_t pin, uint8_t dir)
	\brief 	Establece si un determinado PIN de un determinado PUERTO (previamente
			configurado como GPIO) es entrada o salida.
 	\param [in] puerto:		Puerto con el que se va a trabajar.
 	\param [in] pin:		Pin a configurar como entrada o salida.
 	\param [in] dir:		0 = GPIO_ENTRADA, 1 = GPIO_SALIDA.
	\return 	void
*/
void SetDIR(uint8_t puerto, uint8_t pin, uint8_t dir)
{
	registro *p_GPIOx;

	// apunto pGPIOx a la base los registros del puerto correspondiente (GPIOx_BASE)
	if( puerto >= 0 && puerto <= 4 )
	{
		p_GPIOx = GPIO_BASE + puerto * 0x08;
		// con pGPIOx[0] accedo al registro FIOxDIR (ver mapa de memoria)
		if ( dir == 1 )
		{
			p_GPIOx[0] = p_GPIOx[0] | ( dir << pin );
		} else {
			p_GPIOx[0] = p_GPIOx[0] & ( ~ ( 1 << pin ) );
		}
	}
}

/********************************************************************************
	\fn		void SetPIN(uint8_t puerto, uint8_t pin, uint8_t estado)
	\brief 	Establece el ESTADO de un determinado PIN de un determinado PUERTO.
 	\param [in] puerto: 	Puerto con el que se va a trabajar
 	\param [in] pin:		Pin con el que se va a trabajar
 	\param [in] estado:		Valor a establecer en el PIN del PUERTO [0 o 1].
	\return 	void
*/
void SetPIN(uint8_t puerto, uint8_t pin, uint8_t estado)
{
	registro *p_GPIOx;

	// apunto pGPIOx a la base los registros del puerto correspondiente (GPIOx_BASE)
	if( puerto >= 0 && puerto <= 4 )
	{
		p_GPIOx = GPIO_BASE + puerto * 0x08;
		// con pGPIOx[5] accedo al registro FIOxPIN (ver mapa de memoria)
		if( estado == 1 )
		{
			p_GPIOx[5] = p_GPIOx[5] | ( estado << pin );
		} else
		{
			p_GPIOx[5] = p_GPIOx[5] & ( ~ ( 1 << pin ) );
		}
	}

}

/********************************************************************************
	\fn		uint8_t GetPIN(uint8_t puerto, uint8_t pin)
	\brief	Devuelve el ESTADO de un determinado PIN de un determinado PUERTO.
 	\param [in] puerto:		Puerto con el que se va a trabajar
 	\param [in] pin:		Pin a consultar estado
	\return		estado del pin consultado (uint_8)
*/
uint8_t GetPIN(uint8_t puerto, uint8_t pin)
{
	registro *p_GPIOx;
	uint8_t estado = 0;

	// apunto pGPIOx a la base los registros del puerto correspondiente (GPIOx_BASE)
	if( puerto >= 0 && puerto <= 4 )
	{
		p_GPIOx = GPIO_BASE + puerto * 0x08;
		// con pGPIOx[5] accedo al registro FIOxPIN (ver mapa de memoria)
		estado = ( (p_GPIOx[5] >> pin) & 0x01 );
	}

	return estado;
}

