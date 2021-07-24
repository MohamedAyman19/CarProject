/*
 * DIO_driver.c
 *
 * Created: 22-Jul-21 4:05:55 PM
 * Author : ayman
 */ 

#define F_CPU 8000000UL
#include "Macros.h"
#include "TypeDef.h"
#include "DIO_Int.h"
#include "Timer_Int.h"
#include "GI_INT.h"
#include "EX_Int.h"
#include "Button_INT.h"
#include "Service.h"

int main(void)
{
	
	Service_vdInit();
	
    while (1) 
    {

		Service_vdupdate();
			
    }
}

