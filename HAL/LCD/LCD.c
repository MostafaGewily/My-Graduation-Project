/*
 * LCD.c
 *
 * Created: 11/7/2020 10:42:34 AM
 *  Author: ENG Mostafa
 */ 
#include "LCD.h"

void SEND_FALLING_EDGE(void){
	SET_BIT(PORTA,EN);
	_delay_ms(5);
	CLR_BIT(PORTA,EN);
	_delay_ms(5);
}
void SEND_CMD(uint8 cmd){
	PORTA&=0x0f;      // #define LSB 0x0f
	PORTA|=(cmd&0xf0);//send last 4 digits, #define MSB 0xf0
	CLR_BIT(PORTA,RS);
	SEND_FALLING_EDGE();
	PORTA&=0x0f;
	PORTA|=(cmd<<4);//send first 4 digits
	CLR_BIT(PORTA,RS);
	SEND_FALLING_EDGE();
}
void SEND_DATA(uint8 cmd){
	PORTA&=0x0f;
	PORTA|=(cmd&0xf0);//send last 4 digits
	SET_BIT(PORTA,RS);
	SEND_FALLING_EDGE();
	PORTA&=0x0f;
	PORTA|=(cmd<<4);//send first 4 digits
	SET_BIT(PORTA,RS);
	SEND_FALLING_EDGE();
}
void LCD_INITIALIZE(void){
	
	// SET RS,RW,EN '1'
	SET_BIT(DDRA,RS);
	SET_BIT(DDRA,RW);
	SET_BIT(DDRA,EN);
	//4-MSBBins_PORTA OUTPUT
	SET_BIT(DDRA,4);
	SET_BIT(DDRA,5);
	SET_BIT(DDRA,6);
	SET_BIT(DDRA,7);
	// RW clear to be write
	CLR_BIT(PORTA,RW);
	//Commands
	// Initialization
	SEND_CMD(0x33);
	_delay_ms(1);
	SEND_CMD(0x32);
    _delay_ms(1);
	SEND_CMD(0x28);
	_delay_ms(1);
	// Clear screen
	SEND_CMD(0x01);
	// Blink Cursor
	SEND_CMD(0x0f);
	_delay_ms(20);
}
void MOVING_CURSOR(uint8 row ,uint8 col){
	uint8 temp;
	if(row==0){
		temp=0x80+col;
	}
	else{
		temp=0xc0+col;
	}
	SEND_CMD(temp);
}
void LCD_PRINT(char *cmd){
	for(int i=0;i<16;i++)
	{
		if(cmd[i]=='\0'){
			break;
		}
		SEND_DATA(cmd[i]);
	}
}

