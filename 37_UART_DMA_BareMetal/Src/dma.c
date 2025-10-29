/*
 * dma.c
 *
 *  Created on: Oct 29, 2025
 *      Author: KOPPOLU MOUNIKA
 */

#include "stm32l4xx.h"
#include "dma.h"

#define DMA1EN      (1U << 0)
#define CHSEL_USART2_TX (0x4U << 25)  // Channel 4 for USART2_TX on DMA1 CH7

void dma1_ch7_init(uint32_t src, uint32_t dst, uint32_t len)
{
    // Enable DMA1 clock
    RCC->AHB1ENR |= DMA1EN;

    // Disable DMA before config
    DMA1_Channel7->CCR &= ~DMA_CCR_EN;

    // Set memory and peripheral addresses
    DMA1_Channel7->CMAR = src;
    DMA1_Channel7->CPAR = dst;
    DMA1_Channel7->CNDTR = len;

    // Configure: memory increment, direction (mem-to-periph), TC interrupt
    DMA1_Channel7->CCR = DMA_CCR_MINC | DMA_CCR_DIR | DMA_CCR_TCIE;

    // Select USART2_TX channel (Channel 7 → Request 2 in DMAMUX)
    DMA1_CSELR->CSELR |= (4U << 24);  // Map CH7 to USART2_TX

    // Enable interrupt in NVIC
    NVIC_EnableIRQ(DMA1_Channel7_IRQn);

    // Enable DMA channel
    DMA1_Channel7->CCR |= DMA_CCR_EN;
}

