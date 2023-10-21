/*
 * LCD_Program.c
 *
 *  Created on: Mar 8, 2023
 *      Author: Abdalrhman Mohammed
 */
/****************************************/
/*        Library Diertives             */
/****************************************/
#include<util/delay.h>
#include"../include/LIB/STD_Types.h"
#include"../include/LIB/BIT_Math.h"

/****************************************/
/*        DIO Diertives                 */
/****************************************/
#include"../include/MCAL/DIO/DIO_Interface.h"
/****************************************/
/*        LCD Diertives                 */
/****************************************/
#include"../include/HAL/LCD/LCD_Interface.h"
#include"../include/HAL/LCD/LCD_Private.h"
#include"../include/HAL/LCD/LCD_Configuration.h"

#define F_CPU   8000000UL

void HLCD_voidSendData(u8 A_u8Data)
{
	/*   RS >>>>> 1    R/W >>>>>> 0 */
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_SET);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_RESET);
	/*   Send Data To LCD          */
	MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Data);
	/*   Set Pulse To Enable (E) To Read Data With 2ms Delay */
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_SET);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_RESET);

}

void HLCD_voidSendCommond(u8 A_u8Commond)
{
	/*   RS >>>> 0    R/W  >>>>> 0  */
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_RESET);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_RESET);
	/*   TO Send Commond To LCD     */
	MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Commond);
	/*   Set Pulse To Enalbe (E) PIN To Read Commond With 2ms Delay*/
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_SET);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_RESET);
}
void HLCD_void8BitInit(void)
{
	/*     Wait For More Than  30ms To Let Vcc raise to 4.5V   */
	_delay_ms(35);
	/*                       Function Set                      */
	HLCD_voidSendCommond(FUNCTION_SET);
	/*                 Wait For More Than  39MS                */
	_delay_us(40);
	/*                 Display ON/OFF Control                  */
	HLCD_voidSendCommond(DISPLAY_ON_OFF_CONTROL);
	/*                 Wait for More Than  39MS                */
	_delay_us(40);
	/*                 Display Clear Commonc                   */
	HLCD_voidSendCommond(DISPLAY_CLEAR);
	/*                 Wait for More Than 1.35ms               */
	_delay_ms(2);
	/*                    Entry  Set Mode                      */
	HLCD_voidSendCommond(ENTRY_SET_MODE);
	/*                         END                             */
}

void HLCD_voidClearDisplay(void)
{
	/*                 Display Clear Commonc                  */
	HLCD_voidSendCommond(DISPLAY_CLEAR);
	/*                 Wait for More Than 1.35ms               */
	_delay_ms(2);
}

void HLCD_voidSendString(u8 *A_Pu8String)
{
	while(*A_Pu8String != '\0')
	{
		HLCD_voidSendData(*A_Pu8String++);
	}
}

void HLCD_voidDisplayNumber(u32 A_u32Number)
{
	u32 Local_u32Number = 1;
	if (A_u32Number == 0)
	{
		HLCD_voidSendData('0');
	}
	while(A_u32Number != 0)
	{
		Local_u32Number = ((Local_u32Number * 10) + (A_u32Number % 10));
		A_u32Number = A_u32Number/10;
	}
	while(Local_u32Number != 1)
	{
		HLCD_voidSendData((Local_u32Number % 10) + 48 );
		Local_u32Number = Local_u32Number / 10;
	}
}

void HLCD_voidGoToPos(u8 A_u8RowNum , u8 A_u8ColNum)
{
	switch(A_u8RowNum)
	{
		case LCD_ROW_ONE:
			HLCD_voidSendCommond(LCD_ROW1_ADDRESS + A_u8ColNum);
			break;
		case LCD_ROW_TWO:
			HLCD_voidSendCommond(LCD_ROW2_ADDRESS + A_u8ColNum);
			break;
		default :
			break;
	}
	_delay_ms(1);
}

void HLCD_voidSendSpecialCharacter(u8 *A_Pu8CharArr ,u8 A_u8PatternNum,u8 A_u8RowNum, u8 A_u8ColNum)
{
	u8 Local_u8CGRAMAddress , Local_u8Counter;
	/* Calculate CGRAM Address = Pattern Num * 8 */
	Local_u8CGRAMAddress = A_u8PatternNum * 8 ;
	SET_BIT(Local_u8CGRAMAddress,6);
	/* Send Command To CGRAM Address    */
	HLCD_voidSendCommond(Local_u8CGRAMAddress);

	for (Local_u8Counter = 0; Local_u8Counter < 8 ; Local_u8Counter++)
	{
		/* Send Byte From Array OF Character   */
		HLCD_voidSendData(A_Pu8CharArr[Local_u8Counter]);
	}
	/*   Make The Special Character to Go To Position   */
	HLCD_voidGoToPos(A_u8RowNum,A_u8ColNum);
	/* Display Pattern From CGRAM   */
	HLCD_voidSendData(A_u8PatternNum);
}
