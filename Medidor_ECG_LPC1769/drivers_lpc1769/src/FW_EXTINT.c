/*
 * FW_EXTINT.c
 *
 *  Created on:
 *      Author:
 */

#include "FW_EXTINT.h"

// flags para notificar a la Aplicación de las Interrupciones Externas
volatile uint32_t EINT0_flag = 0;
volatile uint32_t EINT3_flag = 0;

/********************************************************************************
 	\fn  	void EINT_Init(void)
	\brief 	Inicialización de las Interrupciones Externas
	\return void
 */
void EINT_Init(void)
{
	// P2.13 configurado como EINT3
	SetPINSEL(P2, 13, PINSEL_FUNC1);
	// Limpio flags y seteo valores por defecto de los registros
	EXTINT = 0x00;	// (recomendado en el Manual de Usuario)
	EXTMODE = 0x00;
	EXTPOLAR = 0X00;
	// Configuro el modo de interrupción de EINT3
	EINT_SetMode(EINT3, EXTMODE_FLANCO);
	// Configuro la polaridad para EINT3
	EINT_SetPolarity(EINT3, EXTPOLAR_ACTIVO_BAJO_O_DESCENDENTE);
	// Vuelvo a limpiar los flags luego de configurar modo y polaridad
	EXTINT = 0x0F;	// (recomendado en el Manual de Usuario)
	// Habilito la interrupción de EINT3
	ISER0 |= 0x01 << EINT3_IRQn;
}

/********************************************************************************
 	\fn  	void EINT0_IRQHandler(void)
	\brief 	ISR de la Interrupción Externa 0
	\return void
 */
void EINT0_IRQHandler(void)
{
	EXTINT |= 0x1 << EINT0; // Limpio el flag de la EINT0 escribiendo un UNO.

	EINT0_flag = 1;		// Seteo el flag para dar aviso a la Aplicación.
}

/********************************************************************************
 	\fn  	void EINT3_IRQHandler(void)
	\brief 	ISR de la Interrupción Externa 3
	\return void
 */
void EINT3_IRQHandler(void)
{
	EXTINT |= 0x1 << EINT3; // Limpio el flag de la EINT3 escribiendo un UNO.

	EINT3_flag = 1;		// Seteo el flag para dar aviso a la Aplicación.
}

/********************************************************************************
	\fn  		void EINT_SetMode(void)
	\brief 		Setea el modo para el pin de Interrupción Externa.
	\param[in]	EINTx	 línea de Interrupción Externa:
 				- EINT0: interrupción externa 0
 				- EINT1: interrupción externa 1
 				- EINT2: interrupción externa 2
 				- EINT3: interrupción externa 3
 	 \param[in]	modo 	modo de interrupción:
 				- EXTMODE_NIVEL
 				- EXTMODE_FLANCO
	\return		void
 */
void EINT_SetMode(uint8_t EINTx, uint8_t modo)
{
	if( modo == EXTMODE_FLANCO )
	{
		EXTMODE |= ( 1 << EINTx );
	}
	else if( modo == EXTMODE_NIVEL )
	{
		EXTMODE &= ~( 1 << EINTx );
	}
}

/********************************************************************************
	\fn  		void EINT_SetPolarity(void)
	\brief 		Setea el modo para el pin de Interrupción Externa.
	\param[in]	EINTx	 línea de Interrupción Externa:
 				- EINT0: interrupción externa 0
 				- EINT1: interrupción externa 1
 				- EINT2: interrupción externa 2
 				- EINT3: interrupción externa 3
 	 \param[in]	modo 	polaridad de interrupción:
 				- EXTPOLAR_ACTIVO_BAJO_O_DESCENDENTE
 				- EXTPOLAR_ACTIVO_ALTO_O_ASCENDENTE
	\return		void
 */
void EINT_SetPolarity(uint8_t EINTx, uint8_t polaridad)
{
	if( polaridad == EXTPOLAR_ACTIVO_ALTO_O_ASCENDENTE )
	{
		EXTPOLAR |= ( 1 << EINTx );
	}
	else if( polaridad == EXTPOLAR_ACTIVO_BAJO_O_DESCENDENTE )
	{
		EXTPOLAR &= ~( 1 << EINTx );
	}
}
