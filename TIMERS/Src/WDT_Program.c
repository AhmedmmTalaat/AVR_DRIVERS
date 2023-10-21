/*
 * WDT_Program.c
 *
 *  Created on: Oct 20, 2023
 *      Author: ahmed
 */


// Include LIB
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

// Include DIO
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/WDT/WDT_Interface.h"
#include "../Include/MCAL/WDT/WDT_private.h"
#include "../Include/MCAL/WDT/WDT_Cfg.h"

void WDT_voidEnable()
{
	WDTCR = 0b00001111;
}

void WDT_voidDisable()
{
	WDTCR |=((1<<3) | (1<<4));
	WDTCR= 0x00;
}
