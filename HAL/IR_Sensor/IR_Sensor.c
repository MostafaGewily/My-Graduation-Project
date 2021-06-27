/*
 * IR_Sensor.c
 *
 * Created: 6/3/2021 3:53:42 PM
 *  Author: ENG Mostafa
 */ 

#include "IR_Sensor.h"

void IRSensor_vInit()
{
  // IR_Sensor -- 2 -- Rec. -- Input
  CLR_BIT(DDRD,Detect_Pin);
  // LED -- 3 -- Tr. -- Output
  SET_BIT(DDRD,Detect_LED);
  
 SET_BIT(PORTD,Detect_Pin);
}

void IRSensor_vAvoidance()
{
	SEND_CMD(0x01);
	LCD_PRINT(" Detect obj-F");
	_delay_ms(1000);
	// turn Servo motor right
	Servo_vTurnRight();
	if ( ! ( READ_BIT(PIND,Detect_Pin) )  )  // detect object again
	{
		SEND_CMD(0x01);
		LCD_PRINT(" Detect obj-R ");
		_delay_ms(1000);
		// turn servo motor left
		Servo_vTurnLeft();
		if ( ! ( READ_BIT(PIND,Detect_Pin) )  )  // detect object again
		{
			SEND_CMD(0x01);
			LCD_PRINT(" Detect obj-L ");
			_delay_ms(1000);
			// make the servo & IR-Sensor look ahead
			Servo_vForward();
		
			SEND_CMD(0x01);
			LCD_PRINT(" Stop");
		}
		else
		{
			SEND_CMD(0x01);
			LCD_PRINT(" Safe-L");
			_delay_ms(1000);
			// led off
			CLR_BIT(PORTD,Detect_LED);
			// make the servo & IR-Sensor look ahead
			Servo_vForward();
			// turn left
			Driver_vCommand('l');
			_delay_ms(2125);
			Driver_vCommand('s');
			// Forward
			Driver_vCommand('F');
			_delay_ms(2000);
			Driver_vCommand('s');
			// then right
			Driver_vCommand('r');
			_delay_ms(4250);
			Driver_vCommand('s');
			// turn left
			Driver_vCommand('l');
			_delay_ms(2125);
			Driver_vCommand('s');
			// then forward
			Driver_vCommand('F');
		}
	}
	else
	{
		SEND_CMD(0x01);
		LCD_PRINT(" Safe-R");
		_delay_ms(1000);
		// led off
		CLR_BIT(PORTD,Detect_LED);
		// make the servo & IR-Sensor look ahead
		Servo_vForward();
		// turn Right
		Driver_vCommand('r');
		_delay_ms(2125);
		Driver_vCommand('s');
		// Forward
		Driver_vCommand('F');
		_delay_ms(2000);
		Driver_vCommand('s');
		// then left
		Driver_vCommand('l');
		_delay_ms(4250);
		Driver_vCommand('s');
		// turn Right
		Driver_vCommand('r');
		_delay_ms(2125);
		Driver_vCommand('s');
		// then forward
		Driver_vCommand('F');
	}
}



