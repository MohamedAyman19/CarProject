/*
 * EX_Int.h
 *
 * Created: 23-Jul-21 11:35:49 PM
 *  Author: ayman
 */ 


#ifndef EX_INT_H_
#define EX_INT_H_

#define EX_INT0 0
#define EX_INT1 1
#define EX_INT2 2

#define EX_SENSE_FALLING_EDGE    0
#define EX_SENSE_RAISING_EDGE    1
#define EX_SENSE_LOW_LEVEL       2
#define EX_SENSE_LOGIACL_CHANGE  3
#define EX_ERROR                -1
#define EX_VALID                 1  

sint8_t EX_sint8_tDisable(uint8_t CopyInterrupt);
sint8_t EX_sint8_tConfigInterrupt(uint8_t CopyInterrupt , uint8_t CopyControlSense);
void EX_vdSetCallBackTMR2(void (*CopyFuncPtr)(void));
void EX_vdSetCallBackTMR1(void (*CopyFuncPtr)(void));
void EX_vdSetCallBackTMR0(void (*CopyFuncPtr)(void));

void __vector_5 (void) __attribute__((signal));
void __vector_9 (void) __attribute__((signal));
void __vector_11 (void) __attribute__((signal));



#endif /* EX_INT_H_ */