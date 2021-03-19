/*
 * Servo_Motor.c
 *
 * Created: 3/17/2021 2:32:33 AM
 *  Author: ENG Mostafa
 */ 

#include "Servo_Motor.h"

void Servo_vInit()
{
	SET_BIT(PORTB,4);
}

void Servo_vTurnRight()
{
   setDutyCycle(535);  //90 degree
   Wait();	
}

void Servo_vTurnLeft()
{
	setDutyCycle(97);   //-90 degree
	Wait();
}

void Servo_vForward()
{
	setDutyCycle(374);  // 0 degree
	Wait();
}
