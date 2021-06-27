/*
 * Timer1.h
 *
 * Created: 2/8/2021 11:37:21 PM
 *  Author: ENG Mostafa
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_


#include <avr/io.h>
#include <util/delay.h>
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

void Timer1_Init(void);

void Timer1_setDutyCycle(short DutyCycle);

void Wait(void);

#endif /* TIMER1_H_ */