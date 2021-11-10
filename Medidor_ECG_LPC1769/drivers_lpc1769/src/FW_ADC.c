/**
 	\file FW_ADC.c
 	\brief Driver del conversor A/D
 	\details
 	\author
 	\date
*/

#include "FW_ADC.h"

volatile uint32_t ADC_valor;
volatile uint8_t ADC_dato_disponible;
volatile uint32_t ADC_delay = 1;

void ADC_Init(void)
{
	//1.- Activo la alimentación del dispositivo desde el registro PCONP
	PCONP |= 1<<12;
	//2.- Selecciono el clock del ADC como 25MHz, PCLK_ADC = 100 Mhz / 4 = 25MHz
	PCLKSEL0 &= ~(0x03<<24);
	//3.- Y el divisor como 255 -> clk_ADC = 25MHz/256 = 98kHz
	// NOTA: PCLK_ADC0 is divided by (this value plus one) to produce the clock for the A/D converter)
	AD0CR = 0x3F00;
	//4.- Configuro los pines del ADC0
	//ADC0.5 (pote) : P1[31]->PINSEL3: 30:31
	SetPINSEL(P1, 31, PINSEL_FUNC3);
	//5.- Activo interrupción del canal 5
	AD0INTEN = 0x00000020;
	//6.- Selecciono que voy a tomar muestras del canal AD0.5
	AD0CR |= 0x00000020;
	//7.- Activo el ADC (PDN = 1)
	AD0CR |= 1<<21;
	//8.- Como vamos a trabajar en modo BURTS, pongo los bits de START = 000
	AD0CR &= ~(0x0F<<24);
	// NOTA: El BURTS no lo activo ahora, lo hago desde la aplicación.
	//AD0CR |= 1<<16;
	//9.- Habilito interrupción en el NVIC
	ISER0 |= (1<<22);
}

void ADC_BurstEnable(void)
{
	//Activo el Burst, empieza a convertir.
	AD0CR |= 1<<16;
}

void ADC_BurstDisable(void)
{
	//Deshabilito el Burst, detiene la conversión.
	AD0CR &= ~(0x01 << 16);
}

void ADC_IRQHandler(void)
{
	uint32_t adc_data_reg = 0;
	static uint32_t 	circularBuffer[WINDOW_SIZE]  = {0};   //circular buffer
	static uint32_t		*circularBufferAccessor 	= circularBuffer; //actual value
	static uint32_t		sum 						= 0;
	//const  uint32_t 	*circularBufferStart		= &circularBuffer[0]; // constant pointer -> start buff
	static const  uint32_t 	*circularBufferEnd			= &circularBuffer[WINDOW_SIZE]; // constant pointer -> end buff

	// leo el registro de resultado del canal 5
	adc_data_reg = AD0DR5;
	// chequeo bit DONE == 1 -> hay un resultado disponible
	if ((adc_data_reg >> 31) == 0x01)
	{
		sum -= *circularBufferAccessor;
		// obtengo los 12 bits del valor medido y los acumulo para promediar
		sum += (adc_data_reg >> 4) & 0xFFF;

		*circularBufferAccessor = (adc_data_reg >> 4) & 0xFFF;
		circularBufferAccessor++;

		if (circularBufferAccessor == circularBufferEnd )
			circularBufferAccessor = circularBuffer;

		if (ADC_delay == 0)
		{

		ADC_delay = 1;
		ADC_valor = ( sum / WINDOW_SIZE ) ;
		ADC_dato_disponible = 1;

		}
	}
}

