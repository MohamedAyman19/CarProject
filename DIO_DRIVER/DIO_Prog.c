/*
 * DIO_Prog.c
 *
 * Created: 22-Jul-21 4:27:14 PM
 *  Author: ayman
 */ 
#include "Macros.h"
#include "TypeDef.h"
#include "DIO_Registers.h"
#include "DIO_Int.h"

sint8_t DIO_sint8_tSetPortDirection(uint8_t PortID, uint8_t PortDirection)
{
	//checking if the port number is outside the range
	if(PortID >=0 || PortID <= 3 )
	{
		switch (PortID)
		{
			case PortA:
			DDRA_REGISTER=PortDirection;
			return 1;
			break;
			case PortB:
			DDRB_REGISTER=PortDirection;
			return 1;
			break;
			case PortC:
			DDRC_REGISTER=PortDirection;
			return 1;
			break;
			case PortD:
			DDRD_REGISTER=PortDirection;
			return 1;
			break;
		}
	}
	return PARAMETER_ERROR;
}

sint8_t DIO_sint8_tSetPinDirection(uint8_t PortID,uint8_t PinNumber, uint8_t PinDirection)
{
	if ((PortID >= 0 || PortID <= 3) && (PinNumber >= 0 || PinNumber <= 7))
	{
		if(PinDirection==PIN_OUTPUT)
		{
			switch (PortID)
			{
				case PortA:
				SET_BIT(DDRA_REGISTER,PinNumber);
				return 1;
				break;
				case PortB:
				SET_BIT(DDRB_REGISTER,PinNumber);
				return 1;
				break;
				case PortC:
				SET_BIT(DDRC_REGISTER,PinNumber);
				return 1;
				break;
				case PortD:
				SET_BIT(DDRD_REGISTER,PinNumber);
				return 1;
				break;
				default:
				return PARAMETER_ERROR;
				break;
			}
		}
		else if(PinDirection==PIN_INPUT)
		{
			switch (PortID)
			{
				case PortA:
				CLR_BIT(DDRA_REGISTER,PinNumber);
				return 1;
				break;
				case PortB:
				CLR_BIT(DDRB_REGISTER,PinNumber);
				return 1;
				break;
				case PortC:
				CLR_BIT(DDRC_REGISTER,PinNumber);
				return 1;
				break;
				case PortD:
				CLR_BIT(DDRD_REGISTER,PinNumber);
				return 1;
				break;
				default:
				return PARAMETER_ERROR;
				break;
			}
		}
	}
	return PARAMETER_ERROR;
	
}

sint8_t DIO_sint8_tWritePortValue(uint8_t PortID, uint8_t PortValue)
{
	if(PortID >=0 || PortID <= 3 )
	{
		switch (PortID)
		{
			case PortA:
			PORTA_REGISTER=PortValue;
			return 1;
			break;
			case PortB:
			PORTB_REGISTER=PortValue;
			return 1;
			break;
			case PortC:
			PORTC_REGISTER=PortValue;
			return 1;
			break;
			case PortD:
			PORTD_REGISTER=PortValue;
			return 1;
			break;
			default:
			return PARAMETER_ERROR;
			break;
		}
	}
	
	return PARAMETER_ERROR;
}

sint8_t DIO_sint8_tWritePinValue(uint8_t PortID,uint8_t PinNumber, uint8_t PinValue)
{
	if ((PortID >= 0 || PortID <= 3) && (PinNumber >= 0 || PinNumber <= 7))
	{
		if(PinValue==PIN_HIGH)
		{
			switch (PortID)
			{
				case PortA:
				SET_BIT(PORTA_REGISTER,PinNumber);
				return 1;
				break;
				case PortB:
				SET_BIT(PORTB_REGISTER,PinNumber);
				return 1;
				break;
				case PortC:
				SET_BIT(PORTC_REGISTER,PinNumber);
				return 1;
				break;
				case PortD:
				SET_BIT(PORTD_REGISTER,PinNumber);
				return 1;
				break;
				default:
				return PARAMETER_ERROR;
				break;
			}
		}
		else if(PinValue==PIN_LOW)
		{
			switch (PortID)
			{
				case PortA:
				CLR_BIT(PORTA_REGISTER,PinNumber);
				return 1;
				break;
				case PortB:
				CLR_BIT(PORTB_REGISTER,PinNumber);
				return 1;
				break;
				case PortC:
				CLR_BIT(PORTC_REGISTER,PinNumber);
				return 1;
				break;
				case PortD:
				CLR_BIT(PORTD_REGISTER,PinNumber);
				return 1;
				break;
				default:
				return PARAMETER_ERROR;
				break;
			}
		}

	}	
	
	return PARAMETER_ERROR;
}

sint8_t DIO_sint8_t_tGetPinValue(uint8_t PortID, uint8_t PinNumber)
{
	if ((PortID >= 0 || PortID <= 3) && (PinNumber >= 0 || PinNumber <= 7))
	{
		switch (PortID)
		{
			case PortA:
			return GET_BIT(PINA_REGISTER,PinNumber);
			break;
			case PortB:
			return GET_BIT(PINB_REGISTER,PinNumber);
			break;
			case PortC:
			return GET_BIT(PINC_REGISTER,PinNumber);
			break;
			case PortD:
			return GET_BIT(PIND_REGISTER,PinNumber);
			break;
			default:
			return PARAMETER_ERROR;
			break;
		}
	}
	return PARAMETER_ERROR;
}

sint8_t DIO_sint8_tTogglePin(uint8_t PortID,uint8_t PinNumber)
{
	if ((PortID >= 0 || PortID <= 3) && (PinNumber >= 0 || PinNumber <= 7))
	{

		switch (PortID)
		{
			case PortA:
			TOG_BIT(PORTA_REGISTER,PinNumber);
			return 1;
			break;
			case PortB:
			TOG_BIT(PORTB_REGISTER,PinNumber);
			return 1;
			break;
			case PortC:
			TOG_BIT(PORTC_REGISTER,PinNumber);
			return 1;
			break;
			case PortD:
			TOG_BIT(PORTD_REGISTER,PinNumber);
			return 1;
			break;
			default:
			return PARAMETER_ERROR;
			break;
		}
	}
	
	return PARAMETER_ERROR;
	
}


sint8_t DIO_sint8_tEnPullUpRes(uint8_t PortID,uint8_t PinNumber)
{
	if ((PortID >= 0 || PortID <= 3) && (PinNumber >= 0 || PinNumber <= 7))
	{

		switch (PortID)
		{
			case PortA:
			SET_BIT(PORTA_REGISTER,PinNumber);
			return 1;
			break;
			case PortB:
			SET_BIT(PORTB_REGISTER,PinNumber);
			return 1;
			break;
			case PortC:
			SET_BIT(PORTC_REGISTER,PinNumber);
			return 1;
			break;
			case PortD:
			SET_BIT(PORTD_REGISTER,PinNumber);
			return 1;
			break;
			default:
			return PARAMETER_ERROR;
			return 1;
			break;
		}
	}	
	return PARAMETER_ERROR;
}

sint8_t DIO_sint8_tGetPortValue(uint8_t PortID, uint8_t PinNumber)
{
	if ((PortID >= 0 || PortID <= 3) && (PinNumber >= 0 || PinNumber <= 7))
	{
		switch (PortID)
		{
			case PortA:
			return GET_BIT(PORTA_REGISTER,PinNumber);
			break;
			case PortB:
			return GET_BIT(PORTB_REGISTER,PinNumber);
			break;
			case PortC:
			return GET_BIT(PORTC_REGISTER,PinNumber);
			break;
			case PortD:
			return GET_BIT(PORTD_REGISTER,PinNumber);
			break;
			default:
			return PARAMETER_ERROR;
			break;
		}
	}
	return PARAMETER_ERROR;	
}