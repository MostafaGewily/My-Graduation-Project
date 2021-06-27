/*
 * Servo_Motor.c
 *
 * Created: 3/17/2021 2:32:33 AM
 *  Author: ENG Mostafa
 */ 

#include "Servo_Motor.h"

void Servo_vInit()
{
	Timer1_Init();
	Servo_vForward();
}

void Servo_vTurnRight()
{
   Timer1_setDutyCycle(97);  //90 degree correct	
}

void Servo_vTurnLeft()
{
	Timer1_setDutyCycle(535);   //-90 degree 
}

void Servo_vForward()
{
	Timer1_setDutyCycle(374);  // 0 degree or (316,374)
}
