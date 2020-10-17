#include <sp_led_matrix.h>

/*
 * Move the data in corresponding Register
 * MSB 8 bit Register Address and LSB 8 bit Data
 *
 */
void Set_Register(int addr, char data) {
    SPI_TxBufferEmpty(SPI1);
    GPIO_Write(GPIOB, CS_PIN, LOW);
    SPI_Senddata(SPI1, addr << (8) | data);
    SPI_NotBusy(SPI1);
    GPIO_Write(GPIOB, CS_PIN, HIGH);
}

void Draw_Spectrum(char *data1) {

    Set_Register(MAX7219_SHUTDOWN_REG, 0x0);

    //Display all rows (Digits)
    Set_Register(MAX7219_SCANLIMIT_REG, 7);

    //Set corresponding level for corresponding Row (Digits)
    for (int i = 7; i >= 0; i--) {
        Set_Register(MAX7219_DIGIT_REG(i), *data1);
        data1++;
    }

    Set_Register(MAX7219_SHUTDOWN_REG, 0x1);
}
