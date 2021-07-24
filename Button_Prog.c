/*
 * Button_Prog.c
 *
 * Created: 24-Jul-21 3:26:52 PM
 *  Author: ayman
 */ 
#include "TypeDef.h"
#include "Macros.h"
#include "DIO_Int.h"
#include "Button_INT.h"


sint8_t BUTTON_checkStatus(uint8_t Port,uint8_t ButtonNum)
{
	if((Port<=PortD)&&(ButtonNum<=PIN7))
	{
		if(DIO_sint8_t_tGetPinValue(Port,ButtonNum)==PIN_HIGH)
		{
			//for(uint32_t i=0;i<72000;i++); ///                           for debouncing
			if(DIO_sint8_t_tGetPinValue(Port,ButtonNum)==PIN_HIGH)
			{
				return 1;
			}

		}
		return 0;
		
	}

	return  ButtonError;
}