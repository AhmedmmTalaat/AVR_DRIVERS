/*
 * EXTI_Interface.h
 *
 *  Created on: Sep 29, 2023
 *      Author: ahmed
 */

#ifndef INCLUDE_MCAL_EXTI_EXTI_INTERFACE_H_
#define INCLUDE_MCAL_EXTI_EXTI_INTERFACE_H_

typedef enum {
	EXTI0=0,
	EXTI1,
	EXTI2
}EXTI_ID;


typedef enum{
	LOW_LEVEL =0,
	ON_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
}EXTI_SENSE_MODE;

void MEXTI_voidConfig(EXTI_ID A_EXTI_ID , EXTI_SENSE_MODE A_EXTISenseMode);
void MEXTI_voidCallback(EXTI_ID A_EXTI_ID , void(*A_ptrToFunc)(void));
void MEXTI_voidEnable (EXTI_ID A_EXTI_ID);
void MEXTI_voidDisable (EXTI_ID A_EXTI_ID);

#endif /* INCLUDE_MCAL_EXTI_EXTI_INTERFACE_H_ */
