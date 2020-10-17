/*
 * stm32_uart.c
 *
 *  Created on: 7 Oct 2020
 *      Author: sijan pahari
 */

#include <sp_stm32_uart.h>

void USART_Config(USART_TypeDef *USARTx, USART_ConfigTypedef huartx) {

    USARTx->CR1 |= (uint32_t) huartx.Mode | huartx.Oversampling_Mode
            | huartx.Parity_Control | huartx.Parity_Selection;
    USARTx->BRR = huartx.Baudrate;
}

void USART_Enable(USART_TypeDef *USARTx) {
    USARTx->CR1 |= 1 << (13);
}

void USART_SendChar(USART_TypeDef *USARTx, char data) {
    while (!(USARTx->SR & 1 << (6)))
        ;
    USARTx->DR = data;
}

void USART_SendString(USART_TypeDef *USARTx, char *string) {

    while (*string) {
        USART_SendChar(USARTx, *string);
        string++;
    }
}
