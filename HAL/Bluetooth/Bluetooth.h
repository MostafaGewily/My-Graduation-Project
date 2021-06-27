/*
 * Bluetooth.h
 *
 * Created: 11/21/2020 12:52:19 PM
 *  Author: ENG Mostafa
 */ 


#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include "Std_macros.h"
#include "std_types.h"
#include "UART.h"

#define  BAUD_RATE 9600
void HC05_vInit(void);
uint8 HC05_u8Receive(void);
void HC05_vSend(uint8 data) ;
void HC05_vPrint(char *str);

#endif /* BLUETOOTH_H_ */