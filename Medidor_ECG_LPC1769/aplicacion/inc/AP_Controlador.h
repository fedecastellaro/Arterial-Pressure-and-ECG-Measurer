/*
 * AP_Controlador.h
 *
 *  Created on:
 *      Author:
 */

#ifndef INC_AP_CONTROLADOR_H_
#define INC_AP_CONTROLADOR_H_

#include "stdio.h"
#include "FW_ADC.h"
#include "FW_SysTick.h"
#include "FW_IO.h"
#include "PR_Serie.h"
#include "PR_LCD.h"
#include "FW_Teclado.h"

#define ESPERANDO_TRAMA		0
#define RECIBIENDO_TRAMA	1

#define MEDIDOR_RESET		0
#define	MEDIDOR_INACTIVO	1
#define	MEDIDOR_ACTIVO		2
#define WAITING_KEY			3

#define MAX_TRAMA_RX	8

void Controlador(void);
void RX_Mensajes(void);

#endif /* INC_AP_CONTROLADOR_H_ */
