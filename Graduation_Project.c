/*
 * Graduation_Project.c
 *
 * Created: 3/15/2021 5:10:42 PM
 *  Author: ENG Mostafa
 */ 


#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include "util/delay.h"
#include "Std_macros.h"
#include "std_types.h"
#include "Bluetooth.h"
#include "EEPROM.h"
#include "LCD.h"
#include "Servo_Motor.h"
#include "Motor_Driver.h"
#include "IR_Sensor.h"
#include "SpeedMotor.h"

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

volatile uint8 DataReceived = 0;
volatile uint8 RxData = 0;
volatile uint8 Direction = 'S';
volatile uint8 Speed = 5;
volatile uint8 Speed_temp = 'N';
volatile uint8 Start = 'N';
volatile uint8 Test_Ch = 'N';
volatile uint8 Test_No = 3;

int main(void)
{
	/* ******************************* Init Drivers ********************************* */
	HC05_vInit();
	Driver_vInit();
	Servo_vInit();
	SpeedMotor_vInit();
	IRSensor_vInit();
    LCD_INITIALIZE();
	SEND_CMD(0x01);
	_delay_ms(500);
	/* ***************************************************************************** */
	
    /* ********************************* Enable INT ******************************** */
	sei();                           // Enable Global interrupts.
	/* ****************************************************************************** */
	_delay_ms(250);
	HC05_vPrint("Welcome Sir \r");
	LCD_PRINT(" Closed");
	HC05_vPrint("Enter 'O' to Open \r");
	while (Start == 'N')
	{
		if (DataReceived == 1 )
		{
			DataReceived = 0 ;
			if(RxData=='o' || RxData=='O')
			   {
					   Start='Y';   
			   }
		}
	}
	Start='N';
	SEND_CMD(0x01);
	LCD_PRINT(" Open");
	/* ************************ Select Test process *********************** */
	HC05_vPrint("For Test_1, Please Enter 1 \r");
	HC05_vPrint("For Test_2, Please Enter 2 \r");
	HC05_vPrint("For Test_3, Please Enter 3 \r");
	
	while (Test_Ch == 'N')
	{
		if (DataReceived == 1 )
		{
			DataReceived = 0 ;
			Test_No = RxData;
			if (Test_No==1+'0' || Test_No==2+'0' || Test_No==3+'0')
			{
				Test_Ch = 'Y';
				SEND_CMD(0x01);
				LCD_PRINT(" Test Case: ");
				SEND_DATA(Test_No);
				_delay_ms(10000);
			}
			else
			{
				SEND_CMD(0x01);
				LCD_PRINT(" Wrong Entry");
				_delay_ms(5000);
			}
		}
	}
	
	/* *************************** Main start ******************************** */
	
	HC05_vPrint("     Starting to move *Save Trip*        \r");
	HC05_vPrint("Move Forward : F or f \r");
	HC05_vPrint("Move Back    : B or b \r");
	HC05_vPrint("Turn Right   : R or r \r");
	HC05_vPrint("Turn Left    : L or l \r");
	HC05_vPrint("Stop         : S or s \r");
	HC05_vPrint("Set Speed    : C or c \r");
	HC05_vPrint("Get Speed    : G or g \r");
	/* ********************************************************************* */
	
	HC05_vPrint("Command --> \r");
	while (Start == 'N')
	{
		if (DataReceived == 1 )
		{
			DataReceived = 0 ;
			Start='Y';
			Direction=RxData;
			SET_BIT(PORTD,7);
			Timer2_SetDutyCycle(51);
			Driver_vCommand(Direction);				
		}
	}
	
    while(1)
    {
		switch(Test_No)
		{
			/* ************************* Test_1 ****************************** */
			case 1+'0':
			if (  ( READ_BIT(PIND,Detect_Pin) ) == 0  )  // detect object again
			{
				// led on
				SET_BIT(PORTD,Detect_LED);
				// Stop the Car
				Driver_vCommand('s');
				_delay_ms(1000);
				// led off
				CLR_BIT(PORTD,Detect_LED);
			}
			else
			{
				if (DataReceived == 1)
				{
					DataReceived =0;
					Driver_vCommand(RxData);
				}
		   }
			
			break;
       /* ************************** Test_2 ******************************** */			
		  case 2+'0':
		  if (  ( READ_BIT(PIND,Detect_Pin) ) == 0  )  // detect object again
		  {
			  // led on
			  SET_BIT(PORTD,Detect_LED);
			  // Stop the Car
			  Driver_vCommand('s');
			  // Turn Right
			  Driver_vCommand('R');
			  _delay_ms(4250);
			  // Forward
			  Driver_vCommand('F');
			  // led off
			  CLR_BIT(PORTD,Detect_LED);
		  }
		  else if (RxData == 'R' || RxData == 'r' || RxData == 'L' || RxData == 'l')
		  {
			  Driver_vCommand(RxData);
			  _delay_ms(4250);
			  Driver_vCommand('F');
		  }
		  else
		  {
			  Driver_vCommand(RxData);
		  }
		  
		  break;	
   /* ************************* Test_3 ******************************* */
         case  3+'0':
		 
		 if (  ( READ_BIT(PIND,Detect_Pin) ) ==0  )  // detect object again
		 {
			 // Stop the Car
			 Driver_vCommand('s');
			 // led on
			 SET_BIT(PORTD,Detect_LED);
			 // Avoidance
			 IRSensor_vAvoidance();
			 // led off
			 CLR_BIT(PORTD,Detect_LED);
		 }
		 else
		 {
			 if (DataReceived == 1 )
			 {
				 DataReceived = 0 ;
				 if (RxData=='C' || RxData=='c')
				 {
					 // Set Speed
					 SEND_CMD(0x01);
					 LCD_PRINT(" Set Speed(1-5)");
					 HC05_vPrint("Set Speed(1-5) /r");
					 while (Speed_temp == 'N')
					 {
						 if (DataReceived == 1 )
						 {
							 DataReceived = 0 ;
							 Speed = RxData-'0';
							 Speed_temp = 'Y';
							 Driver_vSetSpeed(Speed);
							 _delay_ms(500);
						 }
					 }
					 Speed_temp = 'N';
				 }
				 else if (RxData=='G' || RxData=='g')
				 {
					 // Get Speed
					 SpeedMotor_u8GetSpeed(Speed);
					 _delay_ms(500);
				 }
				 else if (RxData == 'R' || RxData == 'r' || RxData == 'L' || RxData == 'l')
				 {
					 Driver_vCommand(RxData);
					 _delay_ms(4250);
					 Driver_vCommand('F');
				 }
				 else
				 {
					Driver_vCommand(RxData);   
				 }
			 }
		 }		 
		 break;
		 		  
		}        // end of switch .. case		
    }
}


ISR(USART_RXC_vect)
{
    sei();
    RxData = UDR;
    _delay_ms(100);
	DataReceived = 1 ;
}


