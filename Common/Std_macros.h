/*
 * Std_macros.h
 *
 * Created: 11/7/2020 10:51:01 AM
 *  Author: ENG Mostafa
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_

#define REG_SIZE 8

#define SET_BIT(port,bit)			(port|=(1<<bit))
#define SET_REG(reg)                (reg=0xff)

#define CLR_BIT(port,bit)			(port&=~(1<<bit))
#define CLR_REG(reg)                (reg=0x00)      

#define READ_BIT(pin,pin_num)		((pin&(1<<pin_num))>>pin_num)
#define TOG_BIT(port,pin_num)		(port^=(1<<pin_num))

// Rotate
#define ROR(port,num)				((port>>num)|(port<<(REG_SIZE-num)))
#define ROL(port,num)				((port<<num)|(port>>(REG_SIZE-num)))

#endif /* STD_MACROS_H_ */