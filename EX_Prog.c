/*
 * EXT_Prog.c
 *
 * Created: 23-Jul-21 11:42:30 PM
 *  Author: ayman
 */ 

#include <stdlib.h>
#include "TypeDef.h"
#include "Macros.h"
#include "DIO_Int.h"
#include "EX_Int.h"
#include "EX_Registers.h"

void (*CallBackPtrTMR2)(void)=NULL; 
void (*CallBackPtrTMR1)(void)=NULL; 
void (*CallBackPtrTMR0)(void)=NULL; 

sint8_t EX_sint8_tDisable(uint8_t CopyInterrupt)
{
	if(CopyInterrupt <= EX_INT2)
	{
		switch (CopyInterrupt)
		{
			case EX_INT0:
			CLR_BIT(GICR,6);
			return EX_VALID;
			break;
			case EX_INT1:
			CLR_BIT(GICR,7);
			return EX_VALID;
			break;
			case EX_INT2:
			CLR_BIT(GICR,5);
			return EX_VALID;
			break;
			default:
			return EX_ERROR;
			break;
		}
	}
	return EX_ERROR;	
}
sint8_t EX_sint8_tConfigInterrupt(uint8_t CopyInterrupt , uint8_t CopyControlSense)
{
	if(CopyInterrupt <= EX_INT2 && CopyControlSense <= EX_SENSE_LOGIACL_CHANGE)
	{
		switch (CopyInterrupt)
		{
			case EX_INT0:
			SET_BIT(GICR,6);
			switch (CopyControlSense)
			{
				case EX_SENSE_FALLING_EDGE:
				CLR_BIT(MCUCR,0);
				SET_BIT(MCUCR,1);
				return EX_VALID;
				break;
				case EX_SENSE_RAISING_EDGE:
				SET_BIT(MCUCR,0);
				SET_BIT(MCUCR,1);
				return EX_VALID;
				break;
				case EX_SENSE_LOW_LEVEL:
				CLR_BIT(MCUCR,0);
				CLR_BIT(MCUCR,1);
				return EX_VALID;
				break;
				case EX_SENSE_LOGIACL_CHANGE:
				SET_BIT(MCUCR,0);
				CLR_BIT(MCUCR,1);
				return EX_VALID;
				break;
			}
			break;
			case EX_INT1:
			SET_BIT(GICR,7);
			switch (CopyControlSense)
			{
				case EX_SENSE_FALLING_EDGE:
				CLR_BIT(MCUCR,2);
				SET_BIT(MCUCR,3);
				return EX_VALID;
				break;
				case EX_SENSE_RAISING_EDGE:
				SET_BIT(MCUCR,2);
				SET_BIT(MCUCR,3);
				return EX_VALID;
				break;
				case EX_SENSE_LOW_LEVEL:
				CLR_BIT(MCUCR,2);
				CLR_BIT(MCUCR,3);
				return EX_VALID;
				break;
				case EX_SENSE_LOGIACL_CHANGE:
				SET_BIT(MCUCR,2);
				CLR_BIT(MCUCR,3);
				return EX_VALID;
				break;
			}
			break;
			case EX_INT2:
			SET_BIT(GICR,5);
			switch (CopyControlSense)
			{
				case EX_SENSE_FALLING_EDGE:
				CLR_BIT(MCUCSR,6);
				return EX_VALID;
				break;
				case EX_SENSE_RAISING_EDGE:
				SET_BIT(MCUCSR,6);
				return EX_VALID;
				break;
			}
			break;
		}
	}
	return EX_ERROR;
}
void EX_vdSetCallBackTMR2(void (*CopyFuncPtr)(void))
{
	CallBackPtrTMR2=CopyFuncPtr;
}
void EX_vdSetCallBackTMR1(void (*CopyFuncPtr)(void))
{
	CallBackPtrTMR1=CopyFuncPtr;
}
void EX_vdSetCallBackTMR0(void (*CopyFuncPtr)(void))
{
	CallBackPtrTMR0=CopyFuncPtr;
}
void __vector_5 (void)
{
	if(CallBackPtrTMR2!=NULL)
	{
		CallBackPtrTMR2();
	}
}


void __vector_9 (void)
{
	if(CallBackPtrTMR1!=NULL)
	{
		CallBackPtrTMR1();
	}
}
void __vector_11 (void)
{
	if(CallBackPtrTMR0!=NULL)
	{
		CallBackPtrTMR0();
	}
}