/*
 * SSD_Program.c
 *
 *  Created on: Sep 9, 2023
 *      Author: abdelrahmanhossam
 */


// Include LIB
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"
#include <util/delay.h>

// Include DIO
#include "../Include/MCAL/DIO/DIO_Interface.h"

// Include SSD
#include "../Include/HAL/SSD/SSD_Interface.h"
#include "../Include/HAL/SSD/SSD_Private.h"
#include "../Include/HAL/SSD/SSD_Cfg.h"


void HSSD_voidDisplayNumber(DIO_PORT_e A_DIOPort,u8 A_u8NumberValue)
{
	//Input Validation
	if ((A_DIOPort <= DIO_PORTD) && (A_u8NumberValue >= 0) && (A_u8NumberValue <= 9))
	{

		switch (A_u8NumberValue)
		{
		case 0:
			MDIO_voidSetPortValue(A_DIOPort, ZERO);
				break;
		case 1:
			MDIO_voidSetPortValue(A_DIOPort, ONE);
				break;
		case 2:
			MDIO_voidSetPortValue(A_DIOPort, TWO);
				break;
		case 3:
			MDIO_voidSetPortValue(A_DIOPort, THREE);
				break;
		case 4:
			MDIO_voidSetPortValue(A_DIOPort, FOUR);
				break;
		case 5:
			MDIO_voidSetPortValue(A_DIOPort, FIVE);
				break;
		case 6:
			MDIO_voidSetPortValue(A_DIOPort, SIX);
				break;
		case 7:
			MDIO_voidSetPortValue(A_DIOPort, SEVEN);
				break;
		case 8:
			MDIO_voidSetPortValue(A_DIOPort, EIGHT);
				break;
		case 9:
			MDIO_voidSetPortValue(A_DIOPort, NINE);
				break;
		default:
			break;
		}
	}
	else
	{
		MDIO_voidSetPortValue(A_DIOPort,255);
	}
}

void HSSD_voidDisplayNumbersAscending(DIO_PORT_e A_DIOPort, u16 A_u16TimetoWait)
{
	if((A_DIOPort <=DIO_PORTD))
	{
		for(u8 i=0 ; i<=9 ; i++)
		{
			HSSD_voidDisplayNumber(A_DIOPort , i);
			_delay_ms(A_u16TimetoWait);
		}
	}
	else
	{
		//do nth..
	}
}

void HSSD_voidDisplayNumbersDescending(DIO_PORT_e A_DIOPort, u16 A_u16TimetoWait)
{
	if((A_DIOPort <=DIO_PORTD))
	{
		for(u8 i=9 ; i>=0 ; i--)
		{
			HSSD_voidDisplayNumber(A_DIOPort , i);
			_delay_ms(A_u16TimetoWait);
		}
	}
	else
	{
		//do nth..
	}
}

