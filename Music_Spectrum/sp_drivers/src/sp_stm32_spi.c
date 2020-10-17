#include <sp_stm32_spi.h>

void SPI_Config(SPI_TypeDef *spix, SPI_BaudRateTypeDef baudratepslcr,
        SPI_BIDIModeTypeDef bidimode, SPI_FirstTypeDef firstmsblsb,
        SPI_DataFrameTypeDef dataframe, SPI_MasterTypeDef masterslave,
        SPI_BIDIOETypeDef receivetransmit) {

    spix->CR1 |= baudratepslcr << (3) | firstmsblsb << (7) | dataframe << (11)
            | bidimode << (15) | masterslave << (2) | receivetransmit << (14)
            | 1 << (8) | 1 << (9);
}

void SPI_Enable(SPI_TypeDef *spix) {
    spix->CR1 |= 1 << (6);

}

void SPI_TxBufferEmpty(SPI_TypeDef *spix) {
    while (!(SPI1->SR & 1 << (1)))
        ;

}

void SPI_NotBusy(SPI_TypeDef *spix) {
    while ((SPI1->SR & 1 << (7)))
        ;

}

void SPI_Senddata(SPI_TypeDef *spix, uint16_t data) {
    spix->DR = data;
}

