#include <sp_stm32_gpio.h>

void RESET_GPIO(GPIO_TypeDef *GPIOx) {
    GPIOx->MODER = 0x00;
}

void GPIO_Config(GPIO_TypeDef *GPIOx, int pinnum, GPIO_ModeTypeDef mode,
        GPIO_PUPDTypeDef pupd, GPIO_AFTypeDef alternatefunction) {
    GPIOx->MODER |= mode << (2 * pinnum);
    GPIOx->PUPDR |= pupd << (2 * pinnum);

    if (mode == Alternate_Mode) {
        GPIOx->AFR[pinnum >> 3] |= alternatefunction << ((pinnum % 8) * 4);

    }
}

void GPIO_Write(GPIO_TypeDef *GPIOx, int pinnum, uint16_t state) {
    if (state == 1) {
        GPIOx->ODR |= 1 << (pinnum);
    } else {
        GPIOx->ODR &= ~(1 << (pinnum));
    }
}

void GPIO_Toggle(GPIO_TypeDef *GPIOx, int pinnum) {
    GPIOx->ODR ^= 1 << (pinnum);
}

uint8_t GPIO_Read(GPIO_TypeDef *GPIOx, int pinnum) {
    if (GPIOx->IDR & 1 << (pinnum)) {
        return 1;
    } else {
        return 0;
    }

}
