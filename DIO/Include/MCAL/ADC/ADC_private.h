/*
 * ADC_private.h
 *
 *  Created on: Oct 6, 2023
 *      Author: ahmed
 */

#ifndef INCLUDE_MCAL_ADC_ADC_PRIVATE_H_
#define INCLUDE_MCAL_ADC_ADC_PRIVATE_H_

#define ADMUX 		(*(volatile u8 *)0x27)
#define ADCSRA		(*(volatile u8 *)0x26)
#define ADCL		(*(volatile u8 *)0x24)
#define ADCH		(*(volatile u8 *)0x25)
#define ADCLH		(*(volatile u16 *)0x24)
#define SFIOR		(*(volatile u8 *)0x50)

#define ADC_CHANNEL_MASK 0b11100000

#endif /* INCLUDE_MCAL_ADC_ADC_PRIVATE_H_ */
