/*
 * LCD.h
 *
 * Created: 11/7/2020 10:42:50 AM
 *  Author: ENG Mostafa
 */ 

#ifndef LCD_H_
#define LCD_H_

#include <avr/io.h>
#include "Std_macros.h"
#include "std_types.h"
#include <util/delay.h>
#define F_CPU 16000000UL

#define RS 1
#define RW 2
#define EN 3

void SEND_FALLING_EDGE(void);
void SEND_CMD(uint8 cmd);
void LCD_INITIALIZE(void);
void MOVING_CURSOR(uint8 row ,uint8 col);
void LCD_PRINT(char *data);
void SEND_DATA(uint8 cmd);

#endif /* LCD_H_ */