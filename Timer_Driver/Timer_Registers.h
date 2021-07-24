/*
 * Timer_Register.h
 *
 * Created: 23-Jul-21 6:52:31 PM
 *  Author: ayman
 */ 


#ifndef TIMER_REGISTERS_H_
#define TIMER_REGISTERS_H_

#define TCCR0_REGISTER  *( ( volatile uint8_t* ) 0x53 )
#define TCNT0_REGISTER *( ( volatile uint8_t* ) 0x52 )
#define OCR0_REGISTER   *( ( volatile uint8_t* ) 0x5c )
#define TIMSK_REGISTER  *( ( volatile uint8_t* ) 0x59 )
#define TIFR_REGISTER   *( ( volatile uint8_t* ) 0x58 )
#define TCNT1H_REGISTER *( ( volatile uint8_t* ) 0x4d )
#define TCNT1L_REGISTER *( ( volatile uint8_t* ) 0x4c )
#define TCNT1_REGISTER  *( ( volatile uint16_t* ) 0x4c )
#define TCCR1A_REGISTER *( ( volatile uint8_t* ) 0x4f )
#define TCCR1B_REGISTER *( ( volatile uint8_t* ) 0x4e )
#define OCR1A_REGISTER  *( ( volatile uint16_t* ) 0x4a )
#define OCR1AH_REGISTER *( ( volatile uint8_t* ) 0x4b )
#define OCR1AL_REGISTER *( ( volatile uint8_t* ) 0x4a )
#define OCR1B_REGISTER  *( ( volatile uint16_t* ) 0x48 )
#define OCR1BH_REGISTER *( ( volatile uint8_t* ) 0x49 )
#define OCR1BL_REGISTER *( ( volatile uint8_t* ) 0x48 )
#define ICR1_REGISTER   *( ( volatile uint16_t* ) 0x46 )
#define ICR1H_REGISTER  *( ( volatile uint8_t* ) 0x47 )
#define ICR1L_REGISTER  *( ( volatile uint8_t* ) 0x46 )
#define TCCR2_REGISTER  *( ( volatile uint8_t* ) 0x45 )
#define TCNT2_REGISTER  *( ( volatile uint8_t* ) 0x44 )
#define OCR2_REGISTER   *( ( volatile uint8_t* ) 0x43 )



#endif /* TIMER_REGISTERS_H_ */