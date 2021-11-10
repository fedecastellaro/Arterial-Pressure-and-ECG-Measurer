/*
 * FW_ADC.h
 *
 *  Created on:
 *      Author:
 */

#ifndef FW_ADC_H_
#define FW_ADC_H_

#include "Regs_LPC176x.h"
#include "FW_PINSEL.h"

#define CANT_MUESTRAS_PROMEDIO	8
#define WINDOW_SIZE  150

extern volatile uint32_t ADC_valor;
extern volatile uint8_t ADC_dato_disponible;
extern volatile uint32_t ADC_delay;


void ADC_Init(void);
void ADC_BurstEnable(void);
void ADC_BurstDisable(void);

#endif /* FW_ADC_H_ */
