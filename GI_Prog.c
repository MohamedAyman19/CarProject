/*
 * GI_Program.c
 *
 * Created: 23-Jul-21 11:13:24 PM
 *  Author: ayman
 */ 
#include "TypeDef.h"
#include "Macros.h"
#include "DIO_Int.h"
#include "GI_Registers.h"
#include "GI_INT.h"

/* */
void GI_vdEnableGI (void)
{
	SET_BIT(SREG_REGISTER, I_BIT);
}


void GI_vdDisableGI (void)
{
	CLR_BIT(SREG_REGISTER, I_BIT);
}
