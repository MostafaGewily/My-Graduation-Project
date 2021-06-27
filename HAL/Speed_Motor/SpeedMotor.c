/*
 * SpeedMotor.c
 *
 * Created: 3/19/2021 4:58:52 PM
 *  Author: ENG Mostafa
 */ 

#include "SpeedMotor.h"

void SpeedMotor_vInit()
{
	// Initialize Timer0
	// Timer0_vInit();
	// Read-Pin 
	// CLR_BIT(DDRA,0);
}
void SpeedMotor_u8GetSpeed(uint8 count)
{
	SEND_CMD(0x01);
	LCD_PRINT(" Speed: ");
	switch(count)
	{
		case 0:
		LCD_PRINT("0 rpm");
		break;
		
		case 1:
		LCD_PRINT("17 rpm");
		break;
		
		case 2:
		LCD_PRINT("34 rpm");
		break;
		
		case 3:
		LCD_PRINT("51 rpm");
		break;
		
		case 4:
		LCD_PRINT("68 rpm");
		break;
		
		case 5:
		LCD_PRINT("85 rpm");
		break;
	}
	// RPM = (F_CPU*60)/count;
    // return count*17;
}

/*
ISR(TIMER0_COMP_vect)
{
	// every 10ms
}
*/