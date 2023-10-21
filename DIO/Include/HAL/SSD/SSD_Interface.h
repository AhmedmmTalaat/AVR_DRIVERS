/*
 * SSD_Interface.h
 *
 *  Created on: Sep 9, 2023
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_HAL_SSD_SSD_INTERFACE_H_
#define INCLUDE_HAL_SSD_SSD_INTERFACE_H_

#define ZERO	0b11000000
#define ONE		0b11111001
#define TWO		0b10100100
#define THREE	0b10110000
#define FOUR	0b10011001
#define FIVE	0b10010010
#define SIX		0b10000010
#define SEVEN	0b11111000
#define EIGHT   0b10000000
#define NINE	0b10010000

void HSSD_voidDisplayNumber(DIO_PORT_e A_DIOPort,u8 A_u8NumberValue);
void HSSD_voidDisplayNumbersAscending(DIO_PORT_e A_DIOPort, u16 A_u16TimetoWait);
void HSSD_voidDisplayNumbersDescending(DIO_PORT_e A_DIOPort, u16 A_u16TimetoWait);



#endif /* INCLUDE_HAL_SSD_SSD_INTERFACE_H_ */
