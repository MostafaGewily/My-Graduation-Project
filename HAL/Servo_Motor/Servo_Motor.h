/*
 * Servo_Motor.h
 *
 * Created: 3/17/2021 2:32:50 AM
 *  Author: ENG Mostafa
 */ 


#ifndef SERVO_MOTOR_H_
#define SERVO_MOTOR_H_

#include <avr/io.h>
#include "std_types.h"
#include "Std_macros.h"

void Servo_vInit(void);
void Servo_vTurnRight(void);
void Servo_vTurnLeft(void);
void Servo_vForward(void);


#endif /* SERVO_MOTOR_H_ */