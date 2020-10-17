
#ifndef INC_SP_STM32_SPI_H_
#define INC_SP_STM32_SPI_H_

#include <sp_stm32_gpio.h>
#include "stm32f4xx.h"
#include "stdio.h"
#include "main.h"

//Bit masking enum
typedef enum {
    BIT_SEL_0 = 1 << (0),
    BIT_SEL_1 = 1 << (1),
    BIT_SEL_2 = 1 << (2),
    BIT_SEL_3 = 1 << (3),
    BIT_SEL_4 = 1 << (4),
    BIT_SEL_5 = 1 << (5),
    BIT_SEL_6 = 1 << (6),
    BIT_SEL_7 = 1 << (7),
    BIT_SEL_8 = 1 << (8),
    BIT_SEL_9 = 1 << (9),
    BIT_SEL_10 = 1 << (10),
    BIT_SEL_11 = 1 << (11),
    BIT_SEL_12 = 1 << (12),
    BIT_SEL_13 = 1 << (13),
    BIT_SEL_14 = 1 << (14),
    BIT_SEL_15 = 1 << (15),
    BIT_SEL_16 = 1 << (16),
    BIT_SEL_17 = 1 << (17),
    BIT_SEL_18 = 1 << (18),
    BIT_SEL_19 = 1 << (19),
    BIT_SEL_20 = 1 << (20),
    BIT_SEL_21 = 1 << (21),
    BIT_SEL_22 = 1 << (22),
    BIT_SEL_23 = 1 << (23),
    BIT_SEL_24 = 1 << (24),
    BIT_SEL_25 = 1 << (25),
    BIT_SEL_26 = 1 << (26),
    BIT_SEL_27 = 1 << (27),
    BIT_SEL_28 = 1 << (28),
    BIT_SEL_29 = 1 << (29),
    BIT_SEL_30 = 1 << (30),
    BIT_SEL_31 = 1 << (31)

} MASK_BitSELTypeDef;

typedef enum {
    SPI_DataFrame_8Bit = 0x00, SPI_DataFrame_16Bit = 0x01

} SPI_DataFrameTypeDef;

typedef enum {
    SPI_First_MSB = 0x00, SPI_First_LSB = 0x01

} SPI_FirstTypeDef;

typedef enum {
    SPI_BIDIMode_2Line = 0x00, SPI_BIDIMode_1Line = 0x01

} SPI_BIDIModeTypeDef;

typedef enum {
    SPI_Slave = 0x00, SPI_Master = 0x01

} SPI_MasterTypeDef;

typedef enum {
    SPI_Receive = 0x00, SPI_Trasnmit = 0x01

} SPI_BIDIOETypeDef;

typedef enum {
    SPI_BaudRate_sysclkby2 = 0x0000,
    SPI_BaudRate_sysclkby4 = 0x0001,
    SPI_BaudRate_sysclkby8 = 0x0002,
    SPI_BaudRate_sysclkby16 = 0x0003,
    SPI_BaudRate_sysclkby32 = 0x0004,
    SPI_BaudRate_sysclkby64 = 0x0005

} SPI_BaudRateTypeDef;

void SPI_TxBufferEmpty(SPI_TypeDef *spix);
void SPI_NotBusy(SPI_TypeDef *spix);
void SPI_Senddata(SPI_TypeDef *spix, uint16_t data);
void SPI_Enable(SPI_TypeDef *spix);
void SPI_Config(SPI_TypeDef *spix, SPI_BaudRateTypeDef baudratepslcr,
        SPI_BIDIModeTypeDef bidimode, SPI_FirstTypeDef firstmsblsb,
        SPI_DataFrameTypeDef dataframe, SPI_MasterTypeDef masterslave,
        SPI_BIDIOETypeDef receivetransmit);

#endif
