#include "stm32l4_spi_driver.h"

void SPI1_Init(void)
{
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;

    // Configure PA5=SCK, PA6=MISO, PA7=MOSI (Alternate Function 5)
    GPIOA->MODER &= ~((3U << 10) | (3U << 12) | (3U << 14));
    GPIOA->MODER |=  ((2U << 10) | (2U << 12) | (2U << 14));
    GPIOA->AFR[0] |= (5U << 20) | (5U << 24) | (5U << 28);

    // SPI1 Config
    SPI1->CR1 = 0;
    SPI1->CR1 |= (1U << 2);   // Master mode
    SPI1->CR1 |= (3U << 3);   // Baud rate = fPCLK/16
    SPI1->CR1 |= (1U << 6);   // SPI enable
}

uint8_t SPI1_TransmitReceive(uint8_t data)
{
    SPI1->DR = data;                     // Transmit
    while (!(SPI1->SR & (1U << 0)));     // Wait for RXNE flag
    return SPI1->DR;                     // Return received data
}
