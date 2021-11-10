/**
 	\file PR_Serie.c
 	\brief Funciones de Comunicación Serie
 	\details
 	\author
 	\date
*/

#include "PR_Serie.h"

// Buffer de Transmisión
uint8_t bufferTx[TXBUFFER_SIZE];
// Buffer de Recepción
uint8_t bufferRx[RXBUFFER_SIZE];

// Índices de Transmisión
uint8_t index_tx_in, index_tx_out;
// Índices de Recepción
uint8_t index_rx_in, index_rx_out;
// Flags de estado de los buffers
uint8_t tx_buffer_full = 0, tx_buffer_empty = 1;
uint8_t rx_buffer_full = 0, rx_buffer_empty = 1;

uint8_t PushTx(uint8_t dato)
{
	if(tx_buffer_full)
		return 1;	//buffer lleno

	bufferTx[index_tx_in] = dato;
	index_tx_in++;
	index_tx_in %= TXBUFFER_SIZE;
	tx_buffer_empty = 0;	//si agrego un dato el buffer ya no está vacío

	if(index_tx_in == index_tx_out)
		tx_buffer_full = 1;	//se llenó el buffer

	if (UART0_txEnCurso == 0) {
		UART0_txEnCurso = 1;		//si no había una TX en curso,
		UART0_StartTx();	//fuerzo el inicio de la TX
	}

	return 0;	//dato agregado al buffer
}

uint8_t PopTx(uint8_t *dato)
{
	if(tx_buffer_empty)
		return 1;	//buffer vacío

	*dato = (uint8_t) bufferTx[index_tx_out];
	index_tx_out++;
	index_tx_out %= TXBUFFER_SIZE;
	tx_buffer_full = 0;	//si saco un dato, el buffer ya no está lleno

	if(index_tx_out == index_tx_in)
		tx_buffer_empty = 1;	//se vació el buffer

	return 0;	//dato retirado del buffer
}

uint8_t PushRx(uint8_t dato)
{
	if(rx_buffer_full)
		return 1;	//buffer lleno

	bufferRx[index_rx_in] = dato;
	index_rx_in ++;
	index_rx_in %= RXBUFFER_SIZE;
	rx_buffer_empty = 0;	//si agrego un dato, el buffer ya no está vacío

	if(index_rx_in == index_rx_out)
		rx_buffer_full = 1;	//se llenó el buffer

	return 0;	//dato agregado al buffer
}

uint8_t PopRx(uint8_t *dato)
{
	if(rx_buffer_empty)
		return 1;	//buffer vacío

	*dato = (uint8_t) bufferRx[index_rx_out];
	index_rx_out++;
	index_rx_out %= RXBUFFER_SIZE;
	rx_buffer_full = 0;	//si saco un dato, el buffer ya no está lleno

	if(index_rx_out == index_rx_in)
		rx_buffer_empty = 1;	//se vació el buffer

	return 0;	//dato retirado del buffer
}

void EnviarString(const char *str)
{
	uint32_t i;

	for(i = 0; str[i] != '\0'; i++)
		PushTx(str[i]);
}
