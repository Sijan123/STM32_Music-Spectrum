/*
 * sp_stm32_adc.h
 *
 *  Created on: Oct 16, 2020
 *      Author: sijan
 */

#ifndef INC_SP_STM32_ADC_H_
#define INC_SP_STM32_ADC_H_

#include "stm32f4xx.h"
#include "stdio.h"

#define ADC_Start(HAND) (HAND->CR2 |= 1)

typedef enum {
    ADC_CHANNEL0 = 0x00,
    ADC_CHANNEL1 = 0x01,
    ADC_CHANNEL2 = 0x02,
    ADC_CHANNEL3 = 0x03,
    ADC_CHANNEL4 = 0x04,
    ADC_CHANNEL5 = 0x05

} ADC_CHANNELSELTypeDef;

#define ADC_FirstConversion(HAND, ADCCHANNEL) (HAND->SQR3 = ADCCHANNEL)

//#define ADC_GetData(HAND) ({uint16_t val;val = ADC1->DR; val;})
#define ADC_GetData(HAND) (HAND->DR)
#define ADC_StartConv(HAND) (HAND->CR2 |= 1 << (30))

void ADC_Done(ADC_TypeDef *ADCx);

#endif /* INC_SP_STM32_ADC_H_ */
