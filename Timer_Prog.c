/*
 * Timer_Prog.c
 *
 * Created: 23-Jul-21 6:53:38 PM
 *  Author: ayman
 */ 
#include "Macros.h"
#include "TypeDef.h"
#include "DIO_Int.h"
#include "Timer_Registers.h"
#include "Timer_Int.h"

sint8_t Timer_sint8_tInit(uint8_t timer,uint8_t mode,uint32_t prescaler)
{
	if(timer <= TMR2 && mode <= 17)
	{
		switch (timer)
		{
			case TMR0:
			switch (mode)
			{
				case NORMAL:
				CLR_BIT(TCCR0_REGISTER,PIN3);
				CLR_BIT(TCCR0_REGISTER,PIN6);
				break;
				case PWM:
				CLR_BIT(TCCR0_REGISTER,PIN3);
				SET_BIT(TCCR0_REGISTER,PIN6);
				break;
				case CTC:
				SET_BIT(TCCR0_REGISTER,PIN3);
				CLR_BIT(TCCR0_REGISTER,PIN6);
				break;
				case FPWM:
				SET_BIT(TCCR0_REGISTER,PIN3);
				SET_BIT(TCCR0_REGISTER,PIN6);
				break;
				default:
				return TIMERERROR;
				break;
			}

			switch (prescaler)
			{
				case PRS1:
				SET_BIT(TCCR0_REGISTER,PIN0);
				CLR_BIT(TCCR0_REGISTER,PIN1);
				CLR_BIT(TCCR0_REGISTER,PIN2);
				break;
				case PRS8:
				CLR_BIT(TCCR0_REGISTER,PIN0);
				SET_BIT(TCCR0_REGISTER,PIN1);
				CLR_BIT(TCCR0_REGISTER,PIN2);
				return TIMERVALID;
				break;
				case PRS64:
				CLR_BIT(TCCR0_REGISTER,PIN0);
				SET_BIT(TCCR0_REGISTER,PIN1);
				SET_BIT(TCCR0_REGISTER,PIN2);
				return TIMERVALID;
				break;
				case PRS256:
				CLR_BIT(TCCR0_REGISTER,PIN0);
				CLR_BIT(TCCR0_REGISTER,PIN1);
				SET_BIT(TCCR0_REGISTER,PIN2);
				return TIMERVALID;
				break;
				case PRS1024:
				SET_BIT(TCCR0_REGISTER,PIN0);
				CLR_BIT(TCCR0_REGISTER,PIN1);
				SET_BIT(TCCR0_REGISTER,PIN2);
				return TIMERVALID;
				break;
				case PRESOFF: /// stop timer
				CLR_BIT(TCCR0_REGISTER,PIN0);
				CLR_BIT(TCCR0_REGISTER,PIN1);
				CLR_BIT(TCCR0_REGISTER,PIN2);
				return TIMERVALID;
				break;
				default:
				return TIMERERROR;
				break;
			}

			break;

			case TMR1:
			switch (mode)
			{
				case NORMAL:
				CLR_BIT(TCCR1A_REGISTER,PIN0);
				CLR_BIT(TCCR1A_REGISTER,PIN1);
				CLR_BIT(TCCR1B_REGISTER,PIN3);
				CLR_BIT(TCCR1B_REGISTER,PIN4);
				break;
				case PWMPH8:
				SET_BIT(TCCR1A_REGISTER,PIN0);
				CLR_BIT(TCCR1A_REGISTER,PIN1);
				CLR_BIT(TCCR1B_REGISTER,PIN3);
				CLR_BIT(TCCR1B_REGISTER,PIN4);
				break;
				case PWMPH9:
				CLR_BIT(TCCR1A_REGISTER,PIN0);
				SET_BIT(TCCR1A_REGISTER,PIN1);
				CLR_BIT(TCCR1B_REGISTER,PIN3);
				CLR_BIT(TCCR1B_REGISTER,PIN4);
				break;
				case CTCOCR:
				SET_BIT(TCCR1A_REGISTER,PIN0);
				SET_BIT(TCCR1A_REGISTER,PIN1);
				CLR_BIT(TCCR1B_REGISTER,PIN3);
				CLR_BIT(TCCR1B_REGISTER,PIN4);
				break;
				case FPWM8:
				CLR_BIT(TCCR1A_REGISTER,PIN0);
				CLR_BIT(TCCR1A_REGISTER,PIN1);
				SET_BIT(TCCR1B_REGISTER,PIN3);
				CLR_BIT(TCCR1B_REGISTER,PIN4);
				break;
				case FPWM9:
				SET_BIT(TCCR1A_REGISTER,PIN0);
				CLR_BIT(TCCR1A_REGISTER,PIN1);
				SET_BIT(TCCR1B_REGISTER,PIN3);
				CLR_BIT(TCCR1B_REGISTER,PIN4);
				break;
				case FPWM10:
				CLR_BIT(TCCR1A_REGISTER,PIN0);
				SET_BIT(TCCR1A_REGISTER,PIN1);
				SET_BIT(TCCR1B_REGISTER,PIN3);
				CLR_BIT(TCCR1B_REGISTER,PIN4);
				break;
				case PWMPHFRICR:
				SET_BIT(TCCR1A_REGISTER,PIN0);
				SET_BIT(TCCR1A_REGISTER,PIN1);
				SET_BIT(TCCR1B_REGISTER,PIN3);
				CLR_BIT(TCCR1B_REGISTER,PIN4);
				break;
				case PWMPHFROCR:
				CLR_BIT(TCCR1A_REGISTER,PIN0);
				CLR_BIT(TCCR1A_REGISTER,PIN1);
				CLR_BIT(TCCR1B_REGISTER,PIN3);
				SET_BIT(TCCR1B_REGISTER,PIN4);
				break;
				case PWMPHICR:
				SET_BIT(TCCR1A_REGISTER,PIN0);
				CLR_BIT(TCCR1A_REGISTER,PIN1);
				CLR_BIT(TCCR1B_REGISTER,PIN3);
				SET_BIT(TCCR1B_REGISTER,PIN4);
				break;
				case PWMPHOCR:
				SET_BIT(TCCR1A_REGISTER,PIN0);
				SET_BIT(TCCR1A_REGISTER,PIN1);
				CLR_BIT(TCCR1B_REGISTER,PIN3);
				SET_BIT(TCCR1B_REGISTER,PIN4);
				break;
				case CTCICR:
				CLR_BIT(TCCR1A_REGISTER,PIN0);
				CLR_BIT(TCCR1A_REGISTER,PIN1);
				SET_BIT(TCCR1B_REGISTER,PIN3);
				SET_BIT(TCCR1B_REGISTER,PIN4);
				break;
				case FPWMICR:
				CLR_BIT(TCCR1A_REGISTER,PIN0);
				SET_BIT(TCCR1A_REGISTER,PIN1);
				SET_BIT(TCCR1B_REGISTER,PIN3);
				SET_BIT(TCCR1B_REGISTER,PIN4);
				break;
				case FPWMOCR:
				SET_BIT(TCCR1A_REGISTER,PIN0);
				SET_BIT(TCCR1A_REGISTER,PIN1);
				SET_BIT(TCCR1B_REGISTER,PIN3);
				SET_BIT(TCCR1B_REGISTER,PIN4);
				break;
			}
			switch (prescaler)
			{
				case PRS1:
				SET_BIT(TCCR1B_REGISTER,PIN0);
				CLR_BIT(TCCR1B_REGISTER,PIN1);
				CLR_BIT(TCCR1B_REGISTER,PIN2);
				return TIMERVALID;
				break;
				case PRS8:
				CLR_BIT(TCCR1B_REGISTER,PIN0);
				SET_BIT(TCCR1B_REGISTER,PIN1);
				CLR_BIT(TCCR1B_REGISTER,PIN2);
				return TIMERVALID;
				break;
				case PRS64:
				SET_BIT(TCCR1B_REGISTER,PIN0);
				SET_BIT(TCCR1B_REGISTER,PIN1);
				CLR_BIT(TCCR1B_REGISTER,PIN2);
				return TIMERVALID;
				break;
				case PRS256:
				CLR_BIT(TCCR1B_REGISTER,PIN0);
				CLR_BIT(TCCR1B_REGISTER,PIN1);
				SET_BIT(TCCR1B_REGISTER,PIN2);
				return TIMERVALID;
				break;
				case PRS1024:
				SET_BIT(TCCR1B_REGISTER,PIN0);
				CLR_BIT(TCCR1B_REGISTER,PIN1);
				SET_BIT(TCCR1B_REGISTER,PIN2);
				return TIMERVALID;
				break;
				case PRESOFF: /// stop timer
				CLR_BIT(TCCR1B_REGISTER,PIN0);
				CLR_BIT(TCCR1B_REGISTER,PIN1);
				CLR_BIT(TCCR1B_REGISTER,PIN2);
				return TIMERVALID;
				break;
				default:
				return TIMERERROR;

				break;
			}
			break;
			case TMR2:
			switch (mode)
			{
				case NORMAL:
				CLR_BIT(TCCR2_REGISTER,3);
				CLR_BIT(TCCR2_REGISTER,6);
				break;
				case PWM:
				CLR_BIT(TCCR2_REGISTER,3);
				SET_BIT(TCCR2_REGISTER,6);
				break;
				case CTC:
				SET_BIT(TCCR2_REGISTER,3);
				CLR_BIT(TCCR2_REGISTER,6);
				break;
				case FPWM:
				SET_BIT(TCCR2_REGISTER,3);
				SET_BIT(TCCR2_REGISTER,6);
				break;
			}

			switch (prescaler)
			{
				case PRS8:
				CLR_BIT(TCCR2_REGISTER,0);
				SET_BIT(TCCR2_REGISTER,1);
				CLR_BIT(TCCR2_REGISTER,2);
				return TIMERVALID;
				break;
				case PRS32:
				SET_BIT(TCCR2_REGISTER,0);
				SET_BIT(TCCR2_REGISTER,1);
				CLR_BIT(TCCR2_REGISTER,2);
				return TIMERVALID;
				break;
				case PRS64:
				CLR_BIT(TCCR2_REGISTER,0);
				CLR_BIT(TCCR2_REGISTER,1);
				SET_BIT(TCCR2_REGISTER,2);
				return TIMERVALID;
				break;
				case PRS128:
				SET_BIT(TCCR2_REGISTER,0);
				CLR_BIT(TCCR2_REGISTER,1);
				SET_BIT(TCCR2_REGISTER,2);
				return TIMERVALID;
				break;
				case PRS256:
				CLR_BIT(TCCR2_REGISTER,0);
				SET_BIT(TCCR2_REGISTER,1);
				SET_BIT(TCCR2_REGISTER,2);
				return TIMERVALID;
				break;
				case PRS1024:
				SET_BIT(TCCR2_REGISTER,0);
				SET_BIT(TCCR2_REGISTER,1);
				SET_BIT(TCCR2_REGISTER,2);
				return TIMERVALID;
				break;
				case PRESOFF: /// stop timer
				CLR_BIT(TCCR2_REGISTER,0);
				CLR_BIT(TCCR2_REGISTER,1);
				CLR_BIT(TCCR2_REGISTER,2);
				return TIMERVALID;
				break;
				default:
				return TIMERERROR;
				break;
			}
			break;

		}
	}
	return TIMERERROR;
}

sint8_t Timer_sint8_tSetTMRValue(uint8_t timer,uint16_t TMRValue)
{
	switch(timer)
	{
		case TMR0:
		TCNT0_REGISTER=TMRValue;
		return TIMERVALID;
		break;
		case TMR1:
		TCNT1_REGISTER=TMRValue;
		return TIMERVALID;
		break;
		case TMR2:
		TCNT2_REGISTER=TMRValue;
		return TIMERVALID;
		break;
		case TMR1H:
		TCNT1H_REGISTER=TMRValue;
		return TIMERVALID;
		break;
		case TMR1L:
		TCNT1L_REGISTER=TMRValue;
		return TIMERVALID;
		break;
		case OCR1A:
		OCR1A_REGISTER=TMRValue;
		return TIMERVALID;
		break;
		case OCR1AH:
		OCR1AH_REGISTER=TMRValue;
		return TIMERVALID;
		break;
		case OCR1AL:
		OCR1AL_REGISTER=TMRValue;
		return TIMERVALID;
		break;
		case OCR1B:
		OCR1B_REGISTER=TMRValue;
		return TIMERVALID;
		break;
		case OCR1BH:
		OCR1BH_REGISTER=TMRValue;
		return TIMERVALID;
		break;
		case OCR1BL:
		OCR1BL_REGISTER=TMRValue;
		return TIMERVALID;
		break;
		case ICR1:
		ICR1_REGISTER=TMRValue;
		return TIMERVALID;
		break;
		case ICR1H:
		ICR1H_REGISTER=TMRValue;
		return TIMERVALID;
		break;
		case ICR1L:
		ICR1L_REGISTER=TMRValue;
		return TIMERVALID;
		break;
		case OCR2:
		OCR2_REGISTER=TMRValue;
		return TIMERVALID;
		break;
		case OCR0:
		OCR0_REGISTER=TMRValue;
		return TIMERVALID;
		break;
		default:
		return TIMERERROR;
		break;
	}
	return TIMERERROR;
}
sint8_t Timer_sint8_tInterruptEnable(uint8_t timer,uint8_t type)
{
	switch (timer)
	{
		case TMR0:
		switch(type)
		{
			case TOIE:
			SET_BIT(TIMSK_REGISTER,PIN0);
			return TIMERVALID;
			break;

			case OSCIE:
			SET_BIT(TIMSK_REGISTER,PIN1);
			return TIMERVALID;
			break;
		}
		break;
		case TMR1:
		switch(type)
		{
			case TOIE:
			SET_BIT(TIMSK_REGISTER,PIN2);
			return TIMERVALID;
			break;

			case OSCIEB:
			SET_BIT(TIMSK_REGISTER,PIN3);
			return TIMERVALID;
			break;
			case OSCIEA:
			SET_BIT(TIMSK_REGISTER,PIN4);
			return TIMERVALID;
			break;

			case TICIE:
			SET_BIT(TIMSK_REGISTER,PIN5);
			return TIMERVALID;
			break;
		}
		break;
		case TMR2:
		switch(type)
		{
			case TOIE:
			SET_BIT(TIMSK_REGISTER,PIN6);
			return TIMERVALID;
			break;

			case OSCIE:
			SET_BIT(TIMSK_REGISTER,PIN7);
			return TIMERVALID;
			break;
		}
		break;
	}
	return TIMERERROR;	
}
sint8_t Timer_sint8_tInterruptDisable(uint8_t timer,uint8_t type)
{
	switch (timer)
	{
		case TMR0:
		switch(type)
		{
			case TOIE:
			CLR_BIT(TIMSK_REGISTER,PIN0);
			return TIMERVALID;
			break;

			case OSCIE:
			CLR_BIT(TIMSK_REGISTER,PIN1);
			return TIMERVALID;
			break;
		}
		break;
		case TMR1:
		switch(type)
		{
			case TOIE:
			CLR_BIT(TIMSK_REGISTER,PIN2);
			return TIMERVALID;
			break;

			case OSCIEB:
			CLR_BIT(TIMSK_REGISTER,PIN3);
			return TIMERVALID;
			break;
			case OSCIEA:
			CLR_BIT(TIMSK_REGISTER,PIN4);
			return TIMERVALID;
			break;
			case TICIE:
			CLR_BIT(TIMSK_REGISTER,PIN5);
			return TIMERVALID;
			break;
		}
		break;
		case TMR2:
		switch(type)
		{
			case TOIE:
			CLR_BIT(TIMSK_REGISTER,PIN6);
			return TIMERVALID;
			break;
			case OSCIE:
			CLR_BIT(TIMSK_REGISTER,PIN7);
			return TIMERVALID;
			break;
		}
		break;

	}
	return TIMERERROR;
}
sint8_t Timer_sint8_tCompareOutputMode(uint8_t timer,uint8_t mode)
{
	switch(timer)
	{
		case TMR0:
		switch(mode)
		{
			case NORMALOPERATION:
			CLR_BIT(TCCR0_REGISTER,PIN4);
			CLR_BIT(TCCR0_REGISTER,PIN5);
			return TIMERVALID;
			break;
			case TOGGLE:
			SET_BIT(TCCR0_REGISTER,PIN4);
			CLR_BIT(TCCR0_REGISTER,PIN5);
			return TIMERVALID;
			break;
			case CLEAR:
			CLR_BIT(TCCR0_REGISTER,PIN4);
			SET_BIT(TCCR0_REGISTER,PIN5);
			return TIMERVALID;
			break;
			case SET:
			SET_BIT(TCCR0_REGISTER,PIN4);
			SET_BIT(TCCR0_REGISTER,PIN5);
			return TIMERVALID;
			break;
		}
		break;

		case TMR1A:
		switch(mode)
		{
			case NORMALOPERATION:
			CLR_BIT(TCCR1A_REGISTER,PIN6);
			CLR_BIT(TCCR1A_REGISTER,PIN7);
			return TIMERVALID;
			break;
			case TOGGLE:
			SET_BIT(TCCR1A_REGISTER,PIN6);
			CLR_BIT(TCCR1A_REGISTER,PIN7);
			return TIMERVALID;
			break;
			case CLEAR:
			CLR_BIT(TCCR1A_REGISTER,PIN6);
			SET_BIT(TCCR1A_REGISTER,PIN7);
			return TIMERVALID;
			break;
			case SET:
			SET_BIT(TCCR1A_REGISTER,PIN6);
			SET_BIT(TCCR1A_REGISTER,PIN7);
			return TIMERVALID;
			break;
		}
		break;
		case TMR1B:
		switch(mode)
		{
			case NORMALOPERATION:
			CLR_BIT(TCCR1A_REGISTER,PIN4);
			CLR_BIT(TCCR1A_REGISTER,PIN5);
			return TIMERVALID;
			break;
			case TOGGLE:
			SET_BIT(TCCR1A_REGISTER,PIN4);
			CLR_BIT(TCCR1A_REGISTER,PIN5);
			return TIMERVALID;
			break;
			case CLEAR:
			CLR_BIT(TCCR1A_REGISTER,PIN4);
			SET_BIT(TCCR1A_REGISTER,PIN5);
			return TIMERVALID;
			break;
			case SET:
			SET_BIT(TCCR1A_REGISTER,PIN4);
			SET_BIT(TCCR1A_REGISTER,PIN5);
			return TIMERVALID;
			break;
		}
		break;
		case TMR2:
		switch(mode)
		{
			case NORMALOPERATION:
			CLR_BIT(TCCR2_REGISTER,PIN4);
			CLR_BIT(TCCR2_REGISTER,PIN5);
			return TIMERVALID;
			break;
			case TOGGLE:
			SET_BIT(TCCR2_REGISTER,PIN4);
			CLR_BIT(TCCR2_REGISTER,PIN5);
			return TIMERVALID;
			break;
			case CLEAR:
			CLR_BIT(TCCR2_REGISTER,PIN4);
			SET_BIT(TCCR2_REGISTER,PIN5);
			return TIMERVALID;
			break;
			case SET:
			SET_BIT(TCCR2_REGISTER,PIN4);
			SET_BIT(TCCR2_REGISTER,PIN5);
			return TIMERVALID;
			break;
		}
		break;
	}	
	return TIMERERROR;
}
sint32_t Timer_sint32_tTMRValue(uint8_t timer)
{
	switch(timer)
	{
		case TMR0:
		return TCNT0_REGISTER;
		break;
		case TMR1:
		return TCNT1_REGISTER;
		break;
		case TMR2:
		return TCNT2_REGISTER;
		break;
		case TMR1H:
		return TCNT1H_REGISTER;
		break;
		case TMR1L:
		return TCNT1L_REGISTER;
		break;

	}
	return TIMERERROR;	
}

sint8_t Timer_sint8_tStop(uint8_t timer)
{
	if(timer <= TMR2)
	{
		switch (timer)
		{
			case TMR0:
			CLR_BIT(TCCR0_REGISTER,PIN0);
			CLR_BIT(TCCR0_REGISTER,PIN1);
			CLR_BIT(TCCR0_REGISTER,PIN2);
			return TIMERVALID;
			break;
			case TMR1:
			CLR_BIT(TCCR1B_REGISTER,PIN0);
			CLR_BIT(TCCR1B_REGISTER,PIN1);
			CLR_BIT(TCCR1B_REGISTER,PIN2);
			return TIMERVALID;
			break;
			case TMR2:
			CLR_BIT(TCCR2_REGISTER,0);
			CLR_BIT(TCCR2_REGISTER,1);
			CLR_BIT(TCCR2_REGISTER,2);
			return TIMERVALID;
			break;
		}
	}
		return TIMERERROR;
			
}