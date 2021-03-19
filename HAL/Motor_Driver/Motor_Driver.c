/*
 * Motor_Driver.c
 *
 * Created: 3/17/2021 4:09:53 AM
 *  Author: ENG Mostafa
 */ 

#include "Motor_Driver.h"

#ifdef Car_Manual

void Driver_vInit(void)
{
	uint8 i ;
	for(i=0;i<6;i++)
	{
		SET_BIT(DDRC,i);
	}
}

void Driver_vCommand(uint8 data)
{
	switch (data)
	{
		// Forward
		case 'F':
		case 'f': 
		SET_BIT(PORTC,N2);
		SET_BIT(PORTC,N4);
		CLR_BIT(PORTC,N1);
		CLR_BIT(PORTC,N3);
		
		LCD_vCleanScreen();
		LCD_vPrintData("Forward");
		
		break;
		
		// Back
		case 'B':
		case 'b':
		SET_BIT(PORTC,N1);
		SET_BIT(PORTC,N3);
		CLR_BIT(PORTC,N2);
		CLR_BIT(PORTC,N4);
		
		LCD_vCleanScreen();
		LCD_vPrintData("Back");
		break;
		
		// Right
		case 'R':
		case 'r':
		SET_BIT(PORTC,N2);
		SET_BIT(PORTC,N3);
		CLR_BIT(PORTC,N1);
		CLR_BIT(PORTC,N4);
		
		LCD_vCleanScreen();
		LCD_vPrintData("Right");
		break;
		
		// Left
		case 'L':
		case 'l':
		SET_BIT(PORTC,N1);
		SET_BIT(PORTC,N4);
		CLR_BIT(PORTC,N2);
		CLR_BIT(PORTC,N3);
		
		LCD_vCleanScreen();
		LCD_vPrintData("Left");
		break;
		
		case 'S':
		case 's':
		// Stop
		CLR_BIT(PORTC,N1);
		CLR_BIT(PORTC,N2);
		CLR_BIT(PORTC,N3);
		CLR_BIT(PORTC,N4);
		
		LCD_vCleanScreen();
		LCD_vPrintData("Stop");
		break;
	}
}

#else


#endif