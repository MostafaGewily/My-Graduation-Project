/*
 * Motor_Driver.c
 *
 * Created: 3/17/2021 4:09:53 AM
 *  Author: ENG Mostafa
 */ 

#include "Motor_Driver.h"

void Driver_vInit(void)
{
	uint8 i ;
	// 4_Pins EN1,2,3,4
	for(i=0;i<4;i++)
	{
		SET_BIT(DDRC,i);
	}
	// Enable A,B
	SET_BIT(DDRD,7);
	
	// Initiate values
	//Timer2_SetDutyCycle(51); // Low Speed
	//SET_BIT(PORTD,7);  //Full Speed
	Driver_vCommand('S');
}

void Driver_vSetSpeed(uint8 Speed)
{
	DutyCycle = Speed*51;
	MOVING_CURSOR(2,0);
	switch(Speed)
	{
		case 0+'0':
		LCD_PRINT("Dutycycle is:0");
		Timer2_SetDutyCycle(DutyCycle);
		// Stop
		CLR_BIT(PORTC,N1);
		CLR_BIT(PORTC,N2);
		CLR_BIT(PORTC,N3);
		CLR_BIT(PORTC,N4);
		break;
		
		case 1+'0':
		LCD_PRINT("Dutycycle is:51");
		Timer2_SetDutyCycle(DutyCycle);
		break;
		
		case 2+'0':
		LCD_PRINT("Dutycycle is:102");
		Timer2_SetDutyCycle(DutyCycle);
		break;
		
		case 3+'0':
		LCD_PRINT("Dutycycle is:153");
		Timer2_SetDutyCycle(DutyCycle);
		break;
		
		case 4+'0':
		LCD_PRINT("Dutycycle is:204");
		Timer2_SetDutyCycle(DutyCycle);
		break;
		
		case 5+'0':
		LCD_PRINT("Dutycycle is:255");
		Timer2_SetDutyCycle(DutyCycle);
		break;
	}
	
}

void Driver_vCommand(uint8 data)
{
	// 4250   90
	// 2125   45
	switch (data)
	{
		// Forward
		case 'F':
		case 'f': 
		SET_BIT(PORTC,N2);
		SET_BIT(PORTC,N4);
		CLR_BIT(PORTC,N1);
		CLR_BIT(PORTC,N3);
		
		SEND_CMD(0x01);
		LCD_PRINT(" Forward");
		break;
		
		// Back
		case 'B':
		case 'b':
		SET_BIT(PORTC,N1);
		SET_BIT(PORTC,N3);
		CLR_BIT(PORTC,N2);
		CLR_BIT(PORTC,N4);
		
		SEND_CMD(0x01);
		LCD_PRINT(" Back");
		break;
		
		// Right
		case 'R':
		case 'r':
		SET_BIT(PORTC,N2);
		SET_BIT(PORTC,N3);
		CLR_BIT(PORTC,N1);
		CLR_BIT(PORTC,N4);
		SEND_CMD(0x01);
		LCD_PRINT(" Right");
		break;
		
		// Left
		case 'L':
		case 'l':
		SET_BIT(PORTC,N1);
		SET_BIT(PORTC,N4);
		CLR_BIT(PORTC,N2);
		CLR_BIT(PORTC,N3);
		SEND_CMD(0x01);
		LCD_PRINT(" Left");
		break;
		
		case 'S':
		case 's':
		// Stop
		CLR_BIT(PORTC,N1);
		CLR_BIT(PORTC,N2);
		CLR_BIT(PORTC,N3);
		CLR_BIT(PORTC,N4);
		
		SEND_CMD(0x01);
		LCD_PRINT(" Stop");
		break;
	}
	
}

