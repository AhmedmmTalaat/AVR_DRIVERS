/*
 * HSTP_Program.c
 *
 *  Created on: Sep 23, 2023
 *      Author: ahmed
 */

// Include LIB
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"
#include <util/delay.h>

// Include DIO
#include "../Include/MCAL/DIO/DIO_Interface.h"

//Include Stepper Header Files
#include "../Include/HAL/STEPPER/HSTP_Interface.h"
#include "../Include/HAL/STEPPER/HSTP_Private.h"
#include "../Include/HAL/STEPPER/HSTP_Cfg.h"

void HSTP_voidRotate(u16 A_Angle)
{
	/*
	 *  	360-->2048
	 * 		X	-->??
	 */
	u32 Local_u32LoopCounterLimit;
	Local_u32LoopCounterLimit= (A_Angle * STEP_CLC)/FULL_ROT;
	Local_u32LoopCounterLimit/=4;
	for(u32 Local_Loop = 0 ; Local_Loop<=Local_u32LoopCounterLimit ; Local_Loop++)
	{
		MDIO_voidSetPinValue(HSTP_Port,BLUE,DIO_RESET);
		MDIO_voidSetPinValue(HSTP_Port,PINK,DIO_SET);
		MDIO_voidSetPinValue(HSTP_Port,YELLOW,DIO_SET);
		MDIO_voidSetPinValue(HSTP_Port,ORANGE,DIO_SET);
		_delay_ms(10);
		MDIO_voidSetPinValue(HSTP_Port,BLUE,DIO_SET);
		MDIO_voidSetPinValue(HSTP_Port,PINK,DIO_RESET);
		MDIO_voidSetPinValue(HSTP_Port,YELLOW,DIO_SET);
		MDIO_voidSetPinValue(HSTP_Port,ORANGE,DIO_SET);
		_delay_ms(10);
		MDIO_voidSetPinValue(HSTP_Port,BLUE,DIO_SET);
		MDIO_voidSetPinValue(HSTP_Port,PINK,DIO_SET);
		MDIO_voidSetPinValue(HSTP_Port,ORANGE,DIO_RESET);
		MDIO_voidSetPinValue(HSTP_Port,YELLOW,DIO_SET);
		_delay_ms(10);
		MDIO_voidSetPinValue(HSTP_Port,BLUE,DIO_SET);
		MDIO_voidSetPinValue(HSTP_Port,PINK,DIO_SET);
		MDIO_voidSetPinValue(HSTP_Port,ORANGE,DIO_SET);
		MDIO_voidSetPinValue(HSTP_Port,YELLOW,DIO_RESET);
		_delay_ms(10);
	}
}
