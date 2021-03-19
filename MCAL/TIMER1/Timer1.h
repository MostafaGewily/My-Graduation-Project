/*
 * Timer1.h
 *
 * Created: 2/8/2021 11:37:21 PM
 *  Author: ENG Mostafa
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

void Timer1_Init(void);

void setDutyCycle(short DutyCycle);

void Wait(void);

#endif /* TIMER1_H_ */