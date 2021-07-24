/*
 * servicec.c
 *
 * Created: 24-Jul-21 3:18:41 PM
 *  Author: ayman
 */ 
#include "Macros.h"
#include "TypeDef.h"
#include "DIO_Int.h"
#include "Timer_Int.h"
#include "GI_INT.h"
#include "EX_Int.h"
#include "Button_INT.h"
#include "Service.h"

sint8_t move=0;
uint8_t mode =INITIAL_MODE;
uint8_t uint8_tStopMoveStatus=0;
void Service_vdInit()
{
	DIO_sint8_tSetPinDirection(BUTTON_CTRLPORT,ButtonG,PIN_INPUT);
	DIO_sint8_tSetPinDirection(BUTTON_CTRLPORT,ButtonM,PIN_INPUT);
	DIO_sint8_tSetPinDirection(BUTTON_CTRLPORT,ButtonL,PIN_INPUT);
	DIO_sint8_tSetPinDirection(BUTTON_CTRLPORT,ButtonR,PIN_INPUT);
	DIO_sint8_tSetPinDirection(PortD,PIN7,PIN_OUTPUT);
	DIO_sint8_tSetPinDirection(PortB,PIN3,PIN_OUTPUT);
	DIO_sint8_tSetPinDirection(PortA,PIN0,PIN_OUTPUT);
	DIO_sint8_tSetPinDirection(PortA,PIN1,PIN_OUTPUT);
	DIO_sint8_tSetPinDirection(PortA,PIN2,PIN_OUTPUT);
	DIO_sint8_tSetPinDirection(PortA,PIN3,PIN_OUTPUT);
	
}
void Service_vdFirstSpeed()
{
	Timer_sint8_tSetTMRValue(OCR0,77);
	Timer_sint8_tCompareOutputMode(TMR0,SET);
	Timer_sint8_tInit(TMR0,FPWM,PRS1024);
	Timer_sint8_tSetTMRValue(OCR2,77);
	Timer_sint8_tCompareOutputMode(TMR2,SET);
	Timer_sint8_tInit(TMR2,FPWM,PRS1024);
	move=1;

		
}
void Service_vdSecondSpeed()
{
	Timer_sint8_tSetTMRValue(OCR0,154);
	Timer_sint8_tCompareOutputMode(TMR0,SET);
	Timer_sint8_tInit(TMR0,FPWM,PRS1024);
	Timer_sint8_tSetTMRValue(OCR2,154);
	Timer_sint8_tCompareOutputMode(TMR2,SET);
	Timer_sint8_tInit(TMR2,FPWM,PRS1024);
	move=1;
}
void Service_vdThirdSpeed()
{
	Timer_sint8_tSetTMRValue(OCR0,230);
	Timer_sint8_tCompareOutputMode(TMR0,SET);
	Timer_sint8_tInit(TMR0,FPWM,PRS1024);
	Timer_sint8_tSetTMRValue(OCR2,230);
	Timer_sint8_tCompareOutputMode(TMR2,SET);
	Timer_sint8_tInit(TMR2,FPWM,PRS1024);
	move=1;
}
void Service_vdBackSpeed()
{
	Timer_sint8_tSetTMRValue(OCR0,77);
	Timer_sint8_tCompareOutputMode(TMR0,SET);
	Timer_sint8_tInit(TMR0,FPWM,PRS1024);
	Timer_sint8_tSetTMRValue(OCR2,77);
	Timer_sint8_tCompareOutputMode(TMR2,SET);
	Timer_sint8_tInit(TMR2,FPWM,PRS1024);
	move=-1;
}
void Service_vdmove()
{
	if (move==1)
	{
		DIO_sint8_tWritePinValue(PortA,0,0);
		DIO_sint8_tWritePinValue(PortA,2,0);
		DIO_sint8_tWritePinValue(PortA,1,1);
		DIO_sint8_tWritePinValue(PortA,3,1);
	}
	else if(move==-1)
	{
		DIO_sint8_tWritePinValue(PortA,1,0);
		DIO_sint8_tWritePinValue(PortA,3,0);
		DIO_sint8_tWritePinValue(PortA,0,1);
		DIO_sint8_tWritePinValue(PortA,2,1);
	}
}
void Service_vdmoveLeft()
{
	Timer_sint8_tSetTMRValue(OCR0,77);
	Timer_sint8_tCompareOutputMode(TMR0,SET);
	Timer_sint8_tInit(TMR0,FPWM,PRS1024);
	Timer_sint8_tSetTMRValue(OCR2,77);
	Timer_sint8_tCompareOutputMode(TMR2,SET);
	Timer_sint8_tInit(TMR2,FPWM,PRS1024);
	DIO_sint8_tWritePinValue(PortA,1,0);
	DIO_sint8_tWritePinValue(PortA,2,0);
	DIO_sint8_tWritePinValue(PortA,3,1);
	DIO_sint8_tWritePinValue(PortA,0,1);
}
void Service_vdmoveRight()
{
	Timer_sint8_tSetTMRValue(OCR0,77);
	Timer_sint8_tCompareOutputMode(TMR0,SET);
	Timer_sint8_tInit(TMR0,FPWM,PRS1024);
	Timer_sint8_tSetTMRValue(OCR2,77);
	Timer_sint8_tCompareOutputMode(TMR2,SET);
	Timer_sint8_tInit(TMR2,FPWM,PRS1024);
	DIO_sint8_tWritePinValue(PortA,3,0);
	DIO_sint8_tWritePinValue(PortA,0,0);
	DIO_sint8_tWritePinValue(PortA,1,1);
	DIO_sint8_tWritePinValue(PortA,2,1);
}
void Service_vdstop()
{
	DIO_sint8_tWritePinValue(PortA,3,0);
	DIO_sint8_tWritePinValue(PortA,0,0);
	DIO_sint8_tWritePinValue(PortA,1,0);
	DIO_sint8_tWritePinValue(PortA,2,0);
}
void Service_vdupdate()
{
	if(uint8_tStopMoveStatus==0)
	{
		switch (mode)
		{
			case INITIAL_MODE :
			if(BUTTON_checkStatus(BUTTON_CTRLPORT,ButtonG)==1)
			{
				mode=FIRSTSPEED_MODE;
				Service_vdFirstSpeed();
				while(BUTTON_checkStatus(BUTTON_CTRLPORT,ButtonG)==1);
			}
			break;
			case FIRSTSPEED_MODE :
			if(BUTTON_checkStatus(BUTTON_CTRLPORT,ButtonG)==1)
			{
				mode=SECONDSPEED_MODE;
				Service_vdSecondSpeed();
				while(BUTTON_checkStatus(BUTTON_CTRLPORT,ButtonG)==1);
			}
			else if(BUTTON_checkStatus(BUTTON_CTRLPORT,ButtonM)==1)
			{
				uint8_tStopMoveStatus=2;
				Service_vdmove();
			}
			break;
					
			case SECONDSPEED_MODE :
			if(BUTTON_checkStatus(BUTTON_CTRLPORT,ButtonG)==1)
			{
				mode=THIRDSPEED_MODE;
				Service_vdThirdSpeed();
				while(BUTTON_checkStatus(BUTTON_CTRLPORT,ButtonG)==1);
			}
			else if(BUTTON_checkStatus(BUTTON_CTRLPORT,ButtonM)==1)
			{
				uint8_tStopMoveStatus=2;
				Service_vdmove();
			}
			break;
					
			case THIRDSPEED_MODE :
			if(BUTTON_checkStatus(BUTTON_CTRLPORT,ButtonG)==1)
			{
				mode=BACKSPEED_MODE;
				Service_vdBackSpeed();
				while(BUTTON_checkStatus(BUTTON_CTRLPORT,ButtonG)==1);
			}
			else if(BUTTON_checkStatus(BUTTON_CTRLPORT,ButtonM)==1)
			{
				uint8_tStopMoveStatus=2;
				Service_vdmove();
			}
			break;
			case BACKSPEED_MODE :
			if(BUTTON_checkStatus(BUTTON_CTRLPORT,ButtonG)==1)
			{
				mode=FIRSTSPEED_MODE;
				Service_vdFirstSpeed();
				while(BUTTON_checkStatus(BUTTON_CTRLPORT,ButtonG)==1);
			}
			else if(BUTTON_checkStatus(BUTTON_CTRLPORT,ButtonM)==1)
			{
				uint8_tStopMoveStatus=2;
				Service_vdmove();
			}
			break;
					
		}
	}
	else if(uint8_tStopMoveStatus==1)
	{
		if(BUTTON_checkStatus(BUTTON_CTRLPORT,ButtonM)==1)
		{
			uint8_tStopMoveStatus=2;
			Service_vdmove();
		}
		else if(BUTTON_checkStatus(BUTTON_CTRLPORT,ButtonL)==1)
		{
			uint8_tStopMoveStatus=4;
			Service_vdmoveLeft();
		}
		else if(BUTTON_checkStatus(BUTTON_CTRLPORT,ButtonR)==1)
		{
			uint8_tStopMoveStatus=3;
			Service_vdmoveRight();
		}
		else if(BUTTON_checkStatus(BUTTON_CTRLPORT,ButtonG)==1)
		{
			uint8_tStopMoveStatus=0;
			while(BUTTON_checkStatus(BUTTON_CTRLPORT,ButtonG)==1);
		}
	}
	else if(uint8_tStopMoveStatus==2)
	{
		if(BUTTON_checkStatus(BUTTON_CTRLPORT,ButtonM)==0)
		{
			uint8_tStopMoveStatus=1;
			Service_vdstop();
		}
				
	}
	else if(uint8_tStopMoveStatus==3)
	{
		if(BUTTON_checkStatus(BUTTON_CTRLPORT,ButtonR)==0)
		{
			uint8_tStopMoveStatus=1;
			Service_vdstop();
		}
	}
	else if(uint8_tStopMoveStatus==4)
	{
		if(BUTTON_checkStatus(BUTTON_CTRLPORT,ButtonL)==0)
		{
			uint8_tStopMoveStatus=1;
			Service_vdstop();
		}
	}
}
