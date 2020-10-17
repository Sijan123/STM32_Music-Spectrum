/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include <sp_stm32_gpio.h>
#include <sp_stm32_clock.h>
#include <sp_stm32_spi.h>
#include <sp_led_matrix.h>
#include "sp_stm32_adc.h"


void Error_Handler(void);


#define SCK_PIN 5
#define MOSI_PIN 7
#define CS_PIN 5
#define Analog_Pin 0



#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */


