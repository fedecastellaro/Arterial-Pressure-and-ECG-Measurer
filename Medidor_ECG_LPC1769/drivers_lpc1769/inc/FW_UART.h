/*
 * FW_UART.h
 *
 *  Created on:
 *      Author:
 */

#ifndef FW_UART_H_
#define FW_UART_H_

#include "Regs_LPC176x.h"
#include "FW_PINSEL.h"
#include "PR_Serie.h"

extern volatile uint8_t UART0_txEnCurso;

void UART0_Init(void);
void UART0_StartTx(void);

#define UART0_START_TX()	(PopTx((uint8_t*)&U0THR))

#endif /* FW_UART_H_ */
