#include "stm32l4xx.h"
#include "uart.h"
#include "adc.h"
#include <stdio.h>

int main(void)
{
    uint32_t val;

    USART2_tx_rx_init();
    printf("UART OK\r\n");

    pa1_adc1_init();
    printf("ADC Initialized\r\n");

    while (1)
    {
        adc_start();
        val = adc_read();
        printf("ADC Value: %lu\r\n", val);

        for (volatile int i = 0; i < 200000; i++);  // small delay
    }
}
