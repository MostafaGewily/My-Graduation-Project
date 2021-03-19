/*
 * IR_Sensor.c
 *
 * Created: 3/19/2021 4:12:16 PM
 *  Author: ENG Mostafa
 */ 

#include "IR_Sensor.h"

void IR_vInit()
{
	// Echo -- Tr. -- Output
	SET_BIT(DDRB,6);
	// Trig -- Rec. -- Input
	SET_BIT(DDRB,7);
}
void IR_vAvoidance(void);