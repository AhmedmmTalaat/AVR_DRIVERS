/*
 * app.c
 *
 *  Created on: Sep 1, 2023
 *      Author: abdelrahmanhossam
 */


#include <util/delay.h>
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/TIMERS/TIMERS_Interface.h"
#include "../Include/MCAL/WDT/WDT_Interface.h"
#include "../Include/HAL/LED/LED_Interface.h"
#define F_CPU 8000000UL

// Timer 0 --> 8-bit, Prescaler --> 8, F_CPU --> 8 MHZ
//void Timer0_OVF ()
//{
//	static u16 counter =0 ;
//	counter++;
//	if (counter == 3907)
//	{
//		MTIMER0_voidSetPreloadValue(192);
//		HLED_voidToggleLED(DIO_PORTC, PIN0);
//		HLED_voidToggleLED(DIO_PORTC, PIN1);
//		HLED_voidToggleLED(DIO_PORTC, PIN2);
//		counter = 0;
//	}
//}
//
//void Timer0_CTC ()
//{
//	static u16 counter =0 ;
//	counter++;
//	if (counter == 5000)
//	{
//		HLED_voidToggleLED(DIO_PORTC, PIN0);
//		HLED_voidToggleLED(DIO_PORTC, PIN1);
//		HLED_voidToggleLED(DIO_PORTC, PIN2);
//		counter = 0;
//	}
//}
//
//// OVF Mode
//int main ()
//{
//	MDIO_voidInit();
//	MTIMER0_voidSetOVFCallback(Timer0_OVF);
//	MTIMER0_voidInit();
//	MTIMER0_voidSetPreloadValue(192);
//	MGI_voidEnable();
//
//	while (1)
//	{
//
//	}
//}


// CTC Mode
//int main ()
//{
//	MDIO_voidInit();
//	MTIMER0_voidSetOVFCallback(Timer0_CTC);
//	MTIMER0_voidInit();
//	MGI_voidEnable();
//
//	while (1)
//	{
//
//	}
//}



// Fast PWM
//int main ()
//{
//	MDIO_voidInit();
//	MTIMER0_voidInit();
//
//	while(1)
//	{
//		for (u16 i=0; i<255; i+=10)
//		{
//			MTIMER0_voidSetOCR0Value(i);
//			_delay_ms(200);
//		}
//	}
//}


// Servo
//int main ()
//{
//	MDIO_voidInit();
//	MTIMER1_voidInit();
//
//	while(1)
//	{
//	}
//}



// WDT
//int main ()
//{
//	MDIO_voidInit();
//	_delay_ms(2);
//	HLED_voidTurnOn(DIO_PORTA,PIN0);
//	WDT_voidEnable();
//	while(1)
//	{
//
//	}
//}

