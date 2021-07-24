/*
 * DIO_Registers.h
 *
 * Created: 22-Jul-21 4:24:37 PM
 *  Author: ayman
 */ 


#ifndef DIO_REGISTERS_H_
#define DIO_REGISTERS_H_


#define PORTA_REGISTER      *((volatile uint8_t*)0x3B)
#define DDRA_REGISTER      *((volatile uint8_t*)0x3A)
#define PINA_REGISTER      *((volatile uint8_t*)0x39)

#define PORTB_REGISTER      *((volatile uint8_t*)0x38)
#define DDRB_REGISTER      *((volatile uint8_t*)0x37)
#define PINB_REGISTER      *((volatile uint8_t*)0x36)

#define PORTC_REGISTER      *((volatile uint8_t*)0x35)
#define DDRC_REGISTER      *((volatile uint8_t*)0x34)
#define PINC_REGISTER      *((volatile uint8_t*)0x33)

#define PORTD_REGISTER      *((volatile uint8_t*)0x32)
#define DDRD_REGISTER      *((volatile uint8_t*)0x31)
#define PIND_REGISTER      *((volatile uint8_t*)0x30)


#endif /* DIO_REGISTERS_H_ */