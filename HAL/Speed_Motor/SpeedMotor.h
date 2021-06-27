/*
 * SpeedMotor.h
 *
 * Created: 3/19/2021 4:58:35 PM
 *  Author: ENG Mostafa
 */ 


#ifndef SPEEDMOTOR_H_
#define SPEEDMOTOR_H_

#include <avr/io.h>
#include "Std_macros.h"
#include "std_types.h"
#include "LCD.h"

void SpeedMotor_vInit(void);
void SpeedMotor_u8GetSpeed(uint8 count);




#endif /* SPEEDMOTOR_H_ */