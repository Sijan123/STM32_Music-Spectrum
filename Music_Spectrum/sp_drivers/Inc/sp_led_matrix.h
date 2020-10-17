#ifndef INC_SP_LED_MATRIX_H_
#define INC_SP_LED_MATRIX_H_

#include <sp_stm32_gpio.h>
#include <sp_stm32_spi.h>
#include "stm32f4xx.h"
#include "stdio.h"
#include "main.h"

#define MAX7219_DECODE_REG      (0x09)
#define MAX7219_DIGIT_REG(pos)  ((pos)+1)
#define MAX7219_INTENSITY_REG   (0x0A)
#define MAX7219_SCANLIMIT_REG   (0x0B)
#define MAX7219_SHUTDOWN_REG    (0X0C)
#define MAX7219_DISPLAYTEST_REG (0x0F)

void Set_Register(int addr, char data);
void Draw_Spectrum(char *data1);

#endif
