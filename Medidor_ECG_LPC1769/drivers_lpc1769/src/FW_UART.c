/**
 	\file FW_UART.c
 	\brief Driver de la UART (Comunicación Serie)
 	\details
 	\author
 	\date
*/

#include "FW_UART.h"

// Flag de TX en curso
volatile uint8_t UART0_txEnCurso;

void UART0_Init (void)
{
	//1.- Registro PCONP - bit 3 en 1 habilita la UART0
	PCONP |= 0x01 << 3;
	//2.- Registro PCLKSEL0 - bits 6 y 7 en 0 seleccionan que el clk de la UART0 sea 25MHz
	PCLKSEL0 |= (0x01 << 6);
	//3.- Registro U1LCR - trama de 8 bits, 1 bit de stop, paridad par, sin break cond. (DLAB = 1)
	U0LCR = 0x9B;
	//4.- Registros U0DLL (0x40010000) y U0DLM (0x40010004) - 9600 baudios
	U0DLM = 0x00;
	U0DLL = 0x36;
	//5.- Habilito las funciones especiales de los pines TX y RX
	//TX1D : PIN ??	-> 	P0[2]
	SetPINSEL(P0, 2, PINSEL_FUNC1);
	//RX1D : PIN ??	-> 	P0[3]
	SetPINSEL(P0, 3, PINSEL_FUNC1);
	//6.- Registro U1LCR, pongo DLAB(bit7) en 0
	U0LCR &= ~(0x01 << 7);
	//7. Habilito las interrupciones de RX y TX en la UART0 (Registro U0IER)
	U0IER = 0x03;
	//8. Habilito la interrupción de la UART0 en el NVIC (Registro ISER0)
	ISER0 |= (1<<5);
}

void UART0_IRQHandler (void)
{
	uint8_t iir, dato;

	do {
		//Para limpiar los flags de IIR hay que leerlo, una vez que lo leí se resetea.
		iir = U0IIR;
		//THRE (Interrupción por TX)
		if (iir & 0x02) {
			if(!PopTx(&dato))
				U0THR = dato;	// hay un dato en el bufferTx para enviar
			else
				UART0_txEnCurso = 0; // si no hay más datos a enviar, limpio el flag
		}
		//Data Ready (Interrupción por RX)
		if ( iir & 0x04 ) {
			PushRx((uint8_t)U0RBR);	// guardo el dato recibido en el bufferRx
		}
	} while(!(iir & 0x01));	/* me fijo si cuando entré a la ISR había otra
						    int. pendiente de atención: b0=1 (ocurre únicamente
						    si dentro del mismo espacio temporal llegan dos
						    interrupciones a la vez) */
}

void UART0_StartTx(void)
{
	uint8_t dato;

	if(!PopTx(&dato))
		U0THR = dato;	//fuerzo la transmisión del primer dato
}
