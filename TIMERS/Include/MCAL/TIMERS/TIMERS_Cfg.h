/*
 * TIMERS_Cfg.h
 *
 *  Created on: Apr 30, 2023
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_MCAL_TIMERS_TIMERS_CFG_H_
#define INCLUDE_MCAL_TIMERS_TIMERS_CFG_H_

#define TIMER0_MODE FAST_PWM_MODE

#define CTC_MODE_VALUE      200
#define FAST_PWM_MODE_VALUE 99

#define OC0_FAST_PWM_MODE OC0_NONINVERTING_MODE

/*
 * 0b000 No clock source (Timer/Counter stopped).
 * 0b001 clkI/O/(No prescaling)
 * 0b010 clkI/O/8 (From prescaler)
 * 0b011 clkI/O/64 (From prescaler)
 * 0b100 clkI/O/256 (From prescaler)
 * 0b101 clkI/O/1024 (From prescaler)
 * 0b110 External clock source on T0 pin. Clock on falling edge.
 * 0b111 External clock source on T0 pin. Clock on rising edge.
 */
#define TIMER0_CLK_CFG 0b010
#endif /* INCLUDE_MCAL_TIMERS_TIMERS_CFG_H_ */
