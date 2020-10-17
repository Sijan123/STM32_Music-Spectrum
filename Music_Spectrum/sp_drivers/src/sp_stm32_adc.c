/*
 * sp_stm32_adc.c
 *
 *  Created on: Oct 16, 2020
 *      Author: sijan
 *
 */

#include "sp_stm32_adc.h"

void ADC_Done(ADC_TypeDef *ADCx) {
    while (!(ADCx->SR & 1 << (1)))
        ;
}
