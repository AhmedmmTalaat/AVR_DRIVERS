/*
 * LCD_Interface.h
 *
 *  Created on: Mar 8, 2023
 *      Author: Abdalrhman Mohammed
 */

#ifndef INCLUDE_HAL_LCD_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_LCD_INTERFACE_H_

/*  Function To Send Data To LCD  */
void HLCD_voidSendData(u8 A_u8Data);

/*  Function To Send Commond To LCD  */
void HLCD_voidSendCommond(u8 A_u8Commond);

/* 8 BIT INTILAZATION Function  */
void HLCD_void8BitInit(void);

/*  Function To Clear The LCD   */
void HLCD_voidClearDisplay(void);

/*  Function To Send String     */
void HLCD_voidSendString(u8 *A_Pu8String);

/*  Function To Send Numbers    */
void HLCD_voidDisplayNumber(u32 A_u32Number);

/*  Function to go to Position  */
void HLCD_voidGoToPos(u8 A_u8RowNum , u8 A_u8ColNum);

/*  Function To Display Special Character  */
void HLCD_voidSendSpecialCharacter(u8 *A_Pu8CharArr,u8 A_u8PatternNum,u8 A_u8RowNum,u8 A_u8ColNum);





#endif /* INCLUDE_HAL_LCD_LCD_INTERFACE_H_ */
