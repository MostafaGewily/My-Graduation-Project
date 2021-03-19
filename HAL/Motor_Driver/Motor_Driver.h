/*
 * Motor_Driver.h
 *
 * Created: 3/17/2021 4:10:07 AM
 *  Author: ENG Mostafa
 */ 


#ifndef MOTOR_DRIVER_H_
#define MOTOR_DRIVER_H_

#include <avr/io.h>
#include "util/delay.h"
#include "Std_macros.h"
#include "std_types.h"
#include "LCD.h"
#include "Car_Cfg.h"

#define N1      0
#define N2      1
#define N3      2
#define N4      3
#define ENA     4 
#define ENB     5

#define Forward F
#define Back    B
#define Left    L
#define Right   R
#define Stop    S

void Driver_vInit(void);
void Driver_vCommand(uint8 data);



#endif /* MOTOR_DRIVER_H_ */