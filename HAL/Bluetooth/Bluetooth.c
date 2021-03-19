/*
 * Bluetooth.c
 *
 * Created: 11/21/2020 12:52:35 PM
 *  Author: ENG Mostafa
 */ 

#include "Bluetooth.h"

void HC05_vInit()
{
	UART_vInit(BAUD_RATE) ;
}

