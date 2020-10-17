
#ifndef INC_SP_STM32_GPIO_H_
#define INC_SP_STM32_GPIO_H_

#include "stm32f4xx.h"
#include "stdio.h"

#define GPIO_PIN_0                 ((uint16_t)0x0001)  /* Pin 0 selected    */
#define GPIO_PIN_1                 ((uint16_t)0x0002)  /* Pin 1 selected    */
#define GPIO_PIN_2                 ((uint16_t)0x0004)  /* Pin 2 selected    */
#define GPIO_PIN_3                 ((uint16_t)0x0008)  /* Pin 3 selected    */
#define GPIO_PIN_4                 ((uint16_t)0x0010)  /* Pin 4 selected    */
#define GPIO_PIN_5                 ((uint16_t)0x0020)  /* Pin 5 selected    */
#define GPIO_PIN_6                 ((uint16_t)0x0040)  /* Pin 6 selected    */
#define GPIO_PIN_7                 ((uint16_t)0x0080)  /* Pin 7 selected    */
#define GPIO_PIN_8                 ((uint16_t)0x0100)  /* Pin 8 selected    */
#define GPIO_PIN_9                 ((uint16_t)0x0200)  /* Pin 9 selected    */
#define GPIO_PIN_10                ((uint16_t)0x0400)  /* Pin 10 selected   */
#define GPIO_PIN_11                ((uint16_t)0x0800)  /* Pin 11 selected   */
#define GPIO_PIN_12                ((uint16_t)0x1000)  /* Pin 12 selected   */
#define GPIO_PIN_13                ((uint16_t)0x2000)  /* Pin 13 selected   */
#define GPIO_PIN_14                ((uint16_t)0x4000)  /* Pin 14 selected   */
#define GPIO_PIN_15                ((uint16_t)0x8000)  /* Pin 15 selected   */
#define GPIO_PIN_All               ((uint16_t)0xFFFF)  /* All pins selected */

#define HIGH 1
#define LOW  0

typedef enum {
    Input_Mode = 0x00,
    Output_Mode = 0x01,
    Alternate_Mode = 0x02,
    Analog_Mode = 0x03

} GPIO_ModeTypeDef;

typedef enum {
    No = 0x00, Pull_Up = 0x01, Pull_Down = 0x02

} GPIO_PUPDTypeDef;

typedef enum {
    No_AF = 0x00,
    AF0 = 0x00,
    AF_TIM1_TIM2 = 0x01,
    AF_TIM3_TIM5 = 0x02,
    AF_TIM8_TIM11 = 0x03,
    AF_I2C = 0x04,
    AF_SPI = 0x05,
    AF_SPI2 = 0x06,
    AF_SPI_USART = 0x07,
    AF_SPI2_USART = 0x08,
    AF_CAN_TIM12 = 0x09

} GPIO_AFTypeDef;

void GPIO_Config(GPIO_TypeDef *GPIOx, int pinnum, GPIO_ModeTypeDef mode,
        GPIO_PUPDTypeDef pupd, GPIO_AFTypeDef alternatefunction);
void GPIO_Write(GPIO_TypeDef *GPIOx, int pinnum, uint16_t state);
uint8_t GPIO_Read(GPIO_TypeDef *GPIOx, int pinnum);
void GPIO_Toggle(GPIO_TypeDef *GPIOx, int pinnum);
void RESET_GPIO(GPIO_TypeDef *GPIOx);

#endif
