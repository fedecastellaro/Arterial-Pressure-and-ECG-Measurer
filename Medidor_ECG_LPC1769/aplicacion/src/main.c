/*
===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include <cr_section_macros.h>
#include "FW_Init.h"
#include "AP_Controlador.h"

int main(void)
{
	Kit_Init();

    while(1) {
    	RX_Mensajes();
    	Controlador();
    }

    return 0 ;
}
