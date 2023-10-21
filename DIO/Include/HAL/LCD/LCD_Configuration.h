/*
 * LCD_Configuration.h
 *
 *  Created on: Mar 8, 2023
 *      Author: Abdalrhman Mohammed
 */

#ifndef INCLUDE_HAL_LCD_LCD_CONFIGURATION_H_
#define INCLUDE_HAL_LCD_LCD_CONFIGURATION_H_

#define LCD_DATA_PORT      DIO_PORTC
#define LCD_CONTROL_PORT   DIO_PORTA

#define LCD_RS_PIN   PIN0
#define LCD_RW_PIN   PIN1
#define LCD_E_PIN    PIN2

/* Options : 0 --> 1Line                 */
/*           1 --> 2Lines                */
#define NUM_OF_LINES    1

/* Options : 0 --> 5*7                   */
/*           1 --> 5*10                  */
#define CHARACTER_FONT  0

/* Options : 0 ---> Display Off          */
/*           1 ---> Display ON           */
#define DISPLAY_ON      1

/* Options : 0 ---> Cursor OFF           */
/*           1 ---> Cursor ON            */
#define CURSOR_DISPLAY  0

/* Options : 0 ---> Cursor Blink Not Display */
/*           1 ---> Curosr Blink Display     */
#define CURSOR_BLINK    0

/* Options : 0 ---> From Rigth To Left  */
/*           1 ---> From Left To Right  */
#define DATA_DIRECTION  1

/* Options : 0 ---> FIXED               */
/*           1 ---> MOVING              */
#define DATA_SHIFT      0


#endif /* INCLUDE_HAL_LCD_LCD_CONFIGURATION_H_ */
