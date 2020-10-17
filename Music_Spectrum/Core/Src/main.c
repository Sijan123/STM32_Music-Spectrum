#define ARM_MATH_CM4

#include "main.h"
#include "arm_math.h"
#include "stdio.h"

#define Samples                     512
#define FFT_Size                Samples / 2

//Global variables
float32_t Input[Samples];                    //Stores ADC Samples
float32_t Output[FFT_Size];                  //Stores magnitude of each bin

//delay : sampling frequency of ADC
void delay1(void);

//spectrum array for 8 rows
char spectrum[8] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0  // F
        };

//Level array for 8 different level of column
char level[9] = { 0x0, 0x1, 0x3, 0x7, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF  // F
        };

/*
 * Initialize ADC for sampling audio signal from Audio Sensor
 * Analog_Pin = PA0
 */
void adcinit(void) {

    GPIO_Config(GPIOA, Analog_Pin, Analog_Mode, No, AF0);
    RCC_APB2_CLKEN(RCC_APB2Peri_ADC1);
    ADC_FirstConversion(ADC1, ADC_CHANNEL0);
    ADC_Start(ADC1);
}

/*
 * Inizialize the GPIO pins
 * SCK_PIN : PA5 (SPI clock)
 * MOSI_PIN : PA7 (SPI dataout)
 * CS_PIN : PB5
 */
void gpioinit(void) {

    RCC_AHB1_CLKEN(RCC_AHB1Peri_GPIOA);
    RCC_AHB1_CLKEN(RCC_AHB1Peri_GPIOB);

    GPIO_Config(GPIOA, SCK_PIN, Alternate_Mode, No, AF_SPI);   //SCK PIN
    GPIO_Config(GPIOA, MOSI_PIN, Alternate_Mode, No, AF_SPI);  //MOSI PIN
    GPIO_Config(GPIOB, CS_PIN, Output_Mode, Pull_Down, AF0);   //CS   PIN
}

/*
 * Initialize the SPI1
 */
void spiinit(void) {

    RCC_APB2_CLKEN(RCC_APB2Peri_SPI1);

    SPI_Config(SPI1, SPI_BaudRate_sysclkby16, SPI_BIDIMode_2Line, SPI_First_MSB,
            SPI_DataFrame_16Bit, SPI_Master, SPI_Trasnmit);
    SPI_Enable(SPI1);
}

/*
 * Main functions begins
 */
int main(void) {

    gpioinit();
    spiinit();
    adcinit();

    //handle of structure for the floating-point CFFT/CIFFT function
    arm_cfft_radix4_instance_f32 S;

    uint8_t map;

    while (1) {

        //Sampling 256 ADC data and store in array Input[i]
        for (uint16_t i = 0; i < Samples; i += 2) {

            delay1();
            ADC_StartConv(ADC1);
            ADC_Done(ADC1);
            Input[(uint16_t) i] = (float32_t) ((float32_t) ADC_GetData(ADC1)
                    - 2200);
            Input[(uint16_t) (i + 1)] = 0;
        }

        //DSP-CFFT
        arm_cfft_radix4_init_f32(&S, FFT_Size, 0, 1);
        arm_cfft_radix4_f32(&S, Input);

        //stores the magnitude value of each bin in Output array
        arm_cmplx_mag_f32(Input, Output, FFT_Size);

        /*
         * display the first 8 Low-frequencies in 8x8 Matrix
         * Map the magnitude value of each frequency to corresponding level
         */
        for (int y = 0; y < 8; y++) {
            map = 0.004 * Output[y + 1] - 0.2;
            spectrum[y] = (level[map]);
        }

        Draw_Spectrum(spectrum);
    }

    return 0;
}

//31khz
void delay1(void) {
    unsigned static volatile long i = 0;
    unsigned static volatile long j = 0;
    for (i = 0; i < 1; i++) {
        for (j = 0; j < 5;) {
            j++;
        }
    }
}

