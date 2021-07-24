/*
 * EXT_Registers.h
 *
 * Created: 23-Jul-21 11:39:58 PM
 *  Author: ayman
 */ 


#ifndef EXT_REGISTERS_H_
#define EXT_REGISTERS_H_


#define GICR   *((volatile uint8_t *)0x5B)
#define MCUCR  *((volatile uint8_t *)0x55)
#define MCUCSR *((volatile uint8_t *)0x54)
#define GIFR   *((volatile uint8_t *)0x5A)


#endif /* EXT_REGISTERS_H_ */