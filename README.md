# STM32_Music-Spectrum
FFT application in STM32 uC for Audio Signal

Audio Signal from sensor Iduino 1485297 is sampled in realtime with STM32 Nucleo-F446RE board and Fourier Transformation is performed using CMSIS-DSP library. The magnitude of first 8-bins is then displayed in a 8x8 Led matrix.  

main.c : Music_Spectrum/Core/Src/

Drivers : Music_Spectrum/sp_drivers/

Demo : [https://www.youtube.com/watch?v=csIgAfBhKa0].

![Alt Text](https://github.com/Sijan123/STM32_Music-Spectrum/blob/master/Files/20200904_155343_1.gif)
