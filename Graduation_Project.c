/*
 * Graduation_Project.c
 *
 * Created: 3/15/2021 5:10:42 PM
 *  Author: ENG Mostafa
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include "util/delay.h"
#include "Std_macros.h"
#include "std_types.h"


#ifndef F_CPU 
#define F_CPU 16000000UL
#endif


#include "Bluetooth.h"
#include "UART.h"
#include "Motor_Driver.h"

volatile uint8 DataReceived_Flag = 0;
volatile uint8 RxData = 0;

int main(void)
{
	sei();
	UART_vInit(BAUD_RATE);
	HC05_vInit();
	Driver_vInit();
	LCD_vInit();
	LCD_vCleanScreen();
	LCD_vPrintData("HELLO");
	
    while(1)
    {
        //TODO:: Please write your application code
		if (DataReceived_Flag == 1 )
		{
			DataReceived_Flag = 0 ;
			Driver_vCommand(RxData);
		} 
    }
}

ISR(USART_RXC_vect)
{
	DataReceived_Flag = 1 ;
	RxData = UART_u8Receive(); // '2'
}