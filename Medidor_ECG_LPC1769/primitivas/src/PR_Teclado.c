/*
 * PR_Teclado.c
 *
 *  Created on:
 *      Author:
 */

#include "PR_Teclado.h"

char Teclado5x1_GetKey(void)
{
	uint8_t aux = NO_KEY;

	if (bufferTeclado5x1 != NO_KEY)
	{
		aux = bufferTeclado5x1;
		bufferTeclado5x1 = NO_KEY;
	}
	return aux;
}
