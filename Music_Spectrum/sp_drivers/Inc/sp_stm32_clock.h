/*
 * sp_stm32_clock.h
 *
 *  Created on: Oct 16, 2020
 *      Author: sijan
 */

#include "stm32f4xx.h"
#include "stdio.h"

typedef enum {
    RCC_AHB1Peri_GPIOA = 1 << (0),
    RCC_AHB1Peri_GPIOB = 1 << (1),
    RCC_AHB1Peri_GPIOC = 1 << (2),
    RCC_AHB1Peri_GPIOD = 1 << (3),
    RCC_AHB1Peri_GPIOE = 1 << (4),
    RCC_AHB1Peri_GPIOF = 1 << (5),
    RCC_AHB1Peri_GPIOG = 1 << (6),
    RCC_AHB1Peri_GPIOH = 1 << (7),
    RCC_AHB1Peri_CRC = 1 << (12),
    RCC_AHB1Peri_DMA1 = 1 << (21),
    RCC_AHB1Peri_DMA2 = 1 << (22)

} RCC_AHB1PeriTypeDef;

typedef enum {
    RCC_APB1Peri_TIM2 = 1 << (0),
    RCC_APB1Peri_TIM3 = 1 << (1),
    RCC_APB1Peri_TIM4 = 1 << (2),
    RCC_APB1Peri_TIM5 = 1 << (3),
    RCC_APB1Peri_TIM6 = 1 << (4),
    RCC_APB1Peri_TIM7 = 1 << (5),
    RCC_APB1Peri_SPI2 = 1 << (14),
    RCC_APB1Peri_SPI3 = 1 << (15),
    RCC_APB1Peri_USART2 = 1 << (17),
    RCC_APB1Peri_USART3 = 1 << (18),
    RCC_APB1Peri_I2C1 = 1 << (21),
    RCC_APB1Peri_I2C2 = 1 << (22),
    RCC_APB1Peri_I2C3 = 1 << (23),
    RCC_APB1Peri_CAN1 = 1 << (25),
    RCC_APB1Peri_CAN2 = 1 << (26)

} RCC_APB1PeriTypeDef;

typedef enum {
    RCC_APB2Peri_TIM1 = 1 << (0),
    RCC_APB2Peri_TIM8 = 1 << (1),
    RCC_APB2Peri_UASRT1 = 1 << (4),
    RCC_APB2Peri_USART6 = 1 << (5),
    RCC_APB2Peri_ADC1 = 1 << (8),
    RCC_APB2Peri_ADC2 = 1 << (9),
    RCC_APB2Peri_ADC3 = 1 << (10),
    RCC_APB2Peri_SPI1 = 1 << (12),
    RCC_APB2Peri_SPI4 = 1 << (13),
    RCC_APB2Peri_SYSCFG = 1 << (14),
    RCC_APB2Peri_TIM9 = 1 << (16),
    RCC_APB2Peri_TIM10 = 1 << (17)

} RCC_APB2PeriTypeDef;

#define RCC_AHB1_CLKEN(peripheral) (RCC->AHB1ENR |= peripheral)
#define RCC_APB1_CLKEN(peripheral) (RCC->APB1ENR |= peripheral)
#define RCC_APB2_CLKEN(peripheral) (RCC->APB2ENR |= peripheral)

