/*
 * IR_Sensor.h
 *
 * Created: 6/3/2021 3:54:04 PM
 *  Author: ENG Mostafa
 */ 


#ifndef IR_SENSOR_H_
#define IR_SENSOR_H_

#include <avr/io.h>
#include "Std_macros.h"
#include "std_types.h"
#include "Motor_Driver.h"
#include "Servo_Motor.h"
#include "LCD.h"

/* DDRD */
#define Detect_Pin 2
#define Detect_LED 3


void IRSensor_vInit(void);
void IRSensor_vAvoidance();

#endif /* IR_SENSOR_H_ */