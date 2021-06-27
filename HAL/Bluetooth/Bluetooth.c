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
uint8 HC05_u8Receive()
{
	return UART_u8Receive();
}
void HC05_vSend(uint8 data)
{
	UART_vSend(data) ;
}
void HC05_vPrint(char *str)
{
	while(*str)
	{
		HC05_vSend(*str++) ;
	}
}