/*
 * Timer_Interface.h
 *
 * Created: 23-Jul-21 6:51:52 PM
 *  Author: ayman
 */ 


#ifndef TIMER_INT_H_
#define TIMER_INT_H_

sint8_t Timer_sint8_tInit(uint8_t timer,uint8_t mode,uint32_t prescaller);
sint8_t Timer_sint8_tSetTMRValue(uint8_t timer,uint16_t TMRValue);
sint8_t Timer_sint8_tInterruptEnable(uint8_t timer,uint8_t type);
sint8_t Timer_sint8_tInterruptDisable(uint8_t timer,uint8_t type);
sint8_t Timer_sint8_tCompareOutputMode(uint8_t timer,uint8_t mode);
sint32_t Timer_sint32_tTMRValue(uint8_t timer);
sint8_t Timer_sint8_tStop(uint8_t timer);
//modes
#define NORMAL 		 0
#define PWM   		 1
#define CTC  		 2
#define FPWM  		 3
#define PWMPH8  	 4
#define PWMPH9  	 5
#define PWMPH10  	 6
#define CTCOCR  	 7
#define CTCICR   	 8
#define FPWM8    	 9
#define FPWM9   	 10
#define FPWM10   	 11
#define PWMPHFRICR   12
#define PWMPHFROCR   13
#define PWMPHICR   	 14
#define PWMPHOCR   	 15
#define FPWMICR   	 16
#define FPWMOCR   	 17
//timers and registers
#define TMR0     		  0
#define TMR1    	      1
#define TMR2     		  2
#define TMR1A      		  3
#define TMR1B      		  4
#define TMR1H      		  5    //for TCNTH register
#define TMR1L      		  6    //for TCNTL register
#define OCR1A   	      7
#define OCR1AH    		  8
#define OCR1AL   		  9
#define OCR1B    		 10
#define OCR1BH   		 11
#define OCR1BL    		 12
#define ICR1      		 13
#define ICR1H     		 14
#define ICR1L     		 15
#define OCR2	         16
#define OCR0			 17


//prescalers
#define PRS1	   0
#define PRS8       1
#define PRS32      2
#define PRS64      3
#define PRS128     4
#define PRS256     5
#define PRS1024    6
#define PRESOFF    7
//interrupts
#define TOIE       0
#define OSCIE      1
#define OSCIEA     2
#define OSCIEB     3
#define TICIE      4
//compare output modes
#define NORMALOPERATION  0
#define TOGGLE           1
#define CLEAR            2
#define SET              3
#define TIMERERROR       -1
#define TIMERVALID        1



#endif /* TIMER_INTERFACE_H_ */