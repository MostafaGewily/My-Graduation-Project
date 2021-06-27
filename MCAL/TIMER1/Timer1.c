/*
 * Timer1.c
 *
 * Created: 2/8/2021 11:37:08 PM
 *  Author: ENG Mostafa
 */ 

#include "Timer1.h"

void Timer1_Init()
{
	
//FOR TIMER1
TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);        //NON Inverted PWM

TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10); //PRESCALER=64 MODE 14(FAST PWM)

ICR1=4999;  //fPWM=50Hz

DDRD|=(1<<4)|(1<<5);   //PWM Pins as Output

}

void Timer1_setDutyCycle(short DutyCycle)
{
	OCR1A = DutyCycle;
	_delay_ms(15000);
}

/*
void Wait()
{
	char i;
	for(i=0;i<50;i++)
	{
		_delay_loop_2(0);
		_delay_loop_2(0);
		_delay_loop_2(0);
	}
}
*/