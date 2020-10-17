/*
 * stm32_timer.h
 *
 *  Created on: Oct 9, 2020
 *      Author: sijan
 */

#ifndef INC_SP_STM32_TIMER_H_
#define INC_SP_STM32_TIMER_H_

#include "stm32f4xx.h"
#include "stdio.h"

#define TIMER_START(HAND) (HAND->CR1 |= 1<<(0))

typedef enum {
    TIMER_OCM_FROZEN = 000 << (4),
    TIMER_OCM_SETCHANNEL = 001 << (4),
    TIMER_OCM_PWMMODE = 0x6 << (4)
} Timer_OCMTypeDef;

#define TIMER_OCM(HAND, Mode) (HAND->CCMR1 |= Mode)

#define TIMER_CCER(HAND, Channel) (HAND->CCER |= Channel)
#define Timer_Prescalar(HAND,Value) (HAND->PSC = Value)
#define Timer_ARR(HAND,Value) (HAND->ARR = Value)
#define Timer_CCR1(HAND,Value) (HAND->CCR1 = Value)

#endif /* INC_SP_STM32_TIMER_H_ */
