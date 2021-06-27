/*
 * Timer2.c
 *
 * Created: 6/3/2021 2:08:21 PM
 *  Author: ENG Mostafa
 */

#include "Timer2.h"

void Timer2_Init()
{
	TCCR2|=(1<<COM21);        //Clear on Compare
	TCCR2|=(1<<WGM20)|(1<<CS22)|(1<<CS21)|(1<<CS20); //NON Inverted PWM, PRESCALER=1024 

	DDRD|=(1<<PD7);   //PWM Pins as Output
}

void Timer2_SetDutyCycle(short DutyCycle)
{
	OCR2 = (DutyCycle/100.0)*0xff;
    _delay_ms(500);	
} 
