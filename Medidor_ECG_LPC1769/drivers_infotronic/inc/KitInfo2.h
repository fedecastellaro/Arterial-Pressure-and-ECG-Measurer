/*
 * KitInfo2.h
 *
 *  Created on:
 *  Author:
 */

#ifndef KITINFO2_H_
#define KITINFO2_H_

#include "Regs_LPC176x.h"

//Led Stick
#define		LED_STICK	P0,22

//Relays:
#define		RELAY1		P2,0
#define		RELAY2		P0,23
#define		RELAY3		P0,21
#define		RELAY4		P0,27

//Leds RGB:
#define		RGB_G		P2,2
#define		RGB_R		P2,3
#define		RGB_B		P2,1

//Buzzer:
#define		BUZZER		P0,28
#define		BUZZER_ON	0
#define		BUZZER_OFF	1

//Teclas (Teclado 5x1)
#define		SW1_TECL5x1		P2,10
#define		SW2_TECL5x1		P0,18
#define		SW3_TECL5x1		P0,11
#define		SW4_TECL5x1		P2,13
#define		SW5_TECL5x1		P1,26

//LCD:
#define		LCD_D4		P0,5	//P2,5
#define		LCD_D5		P0,10	//P2,6
#define		LCD_D6		P2,4	//P2,7
#define		LCD_D7		P2,5	//P2,8
#define		LCD_RS		P2,6	//P2,0
#define		LCD_E		P0,4	//P2,1

//Pines de Expansión:
#define 	EXPANSION0		P2,7
#define 	EXPANSION1		P1,29
#define 	EXPANSION2		P4,28
#define 	EXPANSION3		P1,23
#define 	EXPANSION4		P1,20
#define 	EXPANSION5		P0,19
#define 	EXPANSION6		P3,26
#define 	EXPANSION7		P1,25
#define 	EXPANSION8		P1,22
#define 	EXPANSION9		P1,19
#define 	EXPANSION10		P0,20
#define 	EXPANSION11		P3,25
#define 	EXPANSION12		P1,27
#define 	EXPANSION13		P1,24
#define 	EXPANSION14		P1,21
#define 	EXPANSION15		P1,18
#define 	EXPANSION16		P1,31
#define 	EXPANSION17		P0,24
#define 	EXPANSION18		P0,25
#define 	EXPANSION19		P0,17
#define 	EXPANSION20		P1,31
#define 	EXPANSION21		P0,22
#define 	EXPANSION22		P0,15
#define 	EXPANSION23		P0,16
#define 	EXPANSION24		P2,8
#define 	EXPANSION25		P2,12
#define 	EXPANSION26		P1,31
#define 	EXPANSION27		P1,31

#endif /* KITINFO2_H_ */
