/*
 * Timer2.h
 *
 * Created: 6/3/2021 2:08:10 PM
 *  Author: ENG Mostafa
 */ 


#ifndef TIMER2_H_
#define TIMER2_H_

#include <avr/io.h>
#include <util/delay.h>
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

void Timer2_Init(void);

void Timer2_SetDutyCycle(short DutyCycle);


#endif /* TIMER2_H_ */