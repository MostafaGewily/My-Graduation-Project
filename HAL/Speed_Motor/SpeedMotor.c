/*
 * SpeedMotor.c
 *
 * Created: 3/19/2021 4:58:52 PM
 *  Author: ENG Mostafa
 */ 

#include "Servo_Motor.h"

void SpeedMotor_vInit()
{
	// rpm
	SET_BIT(DDRB,5);
}
uint16 SpeedMotor_u16GetSpeed()
{
	uint8 count;
	uint16 rpm;
}