/*
 * Timer0.c
 *
 * Created: 5/14/2021 3:32:48 PM
 *  Author: ENG Mostafa
 */ 
#include "Timer0.h"
#include <avr/interrupt.h>


void Timer0_vInit()
{
	// choose CTC Mode
	SET_BIT(TCCR0,WGM01);
	CLR_BIT(TCCR0,WGM00);
	// Select OCR0 , 10 ms
	OCR0 = 152;
	// Enable Global I_bit
	sei() ;
	// Enable OCIE0 for TIMASK Register " Enable INt"
	SET_BIT(TIMSK,OCIE0);
	// choose prescalar 1024
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	
}
