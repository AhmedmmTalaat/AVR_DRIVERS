/*
 * KEYPAD_Program.c
 *
 *  Created on: Mar 10, 2023
 *      Author: Abdalrhman Mohammed
 */
/****************************************/
/*        Library Diertives             */
/****************************************/
#include"../include/LIB/STD_Types.h"
#include"../include/LIB/BIT_Math.h"
#include<util/delay.h>

/****************************************/
/*        DIO Diertives                 */
/****************************************/
#include"../include/MCAL/DIO/DIO_Interface.h"

/***************************************/
/*        KEYPAD Diertives             */
/***************************************/
#include"../include/HAL/KEYPAD/KEYPAD_Interface.h"
#include"../include/HAL/KEYPAD/KEYPAD_Private.h"
#include"../include/HAL/KEYPAD/KEYPAD_Configuration.h"

#define F_CPU  8000000UL

/* KeyWord Static Here Make No One Can Use This Two Arrays Out This File */
u8 static Global_u8SArrOfRows[ROW_NUMBER] = KEYPAD_ROWS;
u8 static Global_u8SArrOfCols[COL_NUMBER] = KEYPAD_COLS;

u8 HKEYPAD_u8GetPressedKey(void)
{
	u8 Local_u8KeyValue = KEYPAD_NO_BUTTON_PRESSED;
	u8 Local_u8RowCounter , Local_u8ColCounter , Local_u8PinValue , Local_u8Flag = FLAG_DOWN ;
	while(Local_u8Flag==FLAG_DOWN)
	{
		for(Local_u8RowCounter = 0 ; Local_u8RowCounter <ROW_NUMBER ; Local_u8RowCounter++)
		{
			MDIO_voidSetPinValue(KEYPAD_PORT , Global_u8SArrOfRows[Local_u8RowCounter],DIO_RESET);
			for (Local_u8ColCounter = 0 ;Local_u8ColCounter< COL_NUMBER ; Local_u8ColCounter++)
			{
				Local_u8PinValue = MDIO_GetPinValue(KEYPAD_PORT,Global_u8SArrOfCols[Local_u8ColCounter]);
				if(Local_u8PinValue == KEY_PRESSED )
				{
					/*   To Avoid DEBOUNCING EFFECT    */
					_delay_ms(KEYPAD_DEBOUNCING_DELAY_MS);
					Local_u8PinValue = MDIO_GetPinValue(KEYPAD_PORT,Global_u8SArrOfCols[Local_u8ColCounter]);
					while(Local_u8PinValue == KEY_PRESSED)
					{
						Local_u8PinValue = MDIO_GetPinValue(KEYPAD_PORT,Global_u8SArrOfCols[Local_u8ColCounter]);
					}
					Local_u8KeyValue = Global_u8ArrOfKeyPadValues[Local_u8RowCounter][Local_u8ColCounter];
					Local_u8Flag =FLAG_UP;
					/* To Break COLUMS FOR LOOP */
					break;
				}
			}/* END OF COLUMS LOOP */
			/*   Make The Row = 1 Again */
			MDIO_voidSetPinValue(KEYPAD_PORT , Global_u8SArrOfRows[Local_u8RowCounter],DIO_SET);
			if(Local_u8Flag == FLAG_UP)
			{
				break;
			}
			}/* END OF ROWS LOOP */
	}
	return Local_u8KeyValue;
}
