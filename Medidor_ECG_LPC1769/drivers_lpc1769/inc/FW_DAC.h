/*
 * FW_DAC.h
 *
 *  Created on:
 *      Author:
 */

#ifndef FW_DAC_H_
#define FW_DAC_H_

#include "Regs_LPC176x.h"
#include "FW_PINSEL.h"

void DAC_Init(void);
void DAC_SetValue(uint16_t valor);

#endif /* FW_DAC_H_ */
