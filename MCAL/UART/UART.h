/*
 * UART.h
 *
 * Created: 11/21/2020 10:46:53 AM
 *  Author: ENG Mostafa
 */ 


#ifndef UART_H_
#define UART_H_

#include "Std_macros.h"
#include "std_types.h"

void UART_vInit(uint32 baud);
void UART_vSend(uint8 val);
uint8 UART_u8Receive(void);

#endif

/*
HC05_vInit();
sei();
while(1)
{
	if (DataReceived == 1 )
	{
		DataReceived = 0 ;
		HC05_vSend(RxData+1) ; // '3'
	}
	//TODO:: Please write your application code
}

*/