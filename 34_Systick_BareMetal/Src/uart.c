#include "stm32l4xx.h"
#include "uart.h"

#define UART_BAUDRATE 115200
#define SYS_FREQ 4000000UL  // 4 MHz default HSI clock

static uint16_t compute_uart_bd(uint32_t periph_clk, uint32_t baudrate);

void USART2_tx_init(void)
{
    /********** Configure GPIO for UART2 TX (PA2) **********/
    RCC->AHB2ENR |= (1U << 0);       // Enable GPIOA clock

    GPIOA->MODER &= ~(3U << 4);      // Clear mode bits for PA2
    GPIOA->MODER |=  (2U << 4);      // Alternate function mode

    GPIOA->AFR[0] &= ~(0xF << 8);
    GPIOA->AFR[0] |=  (7U << 8);     // AF7 = USART2_TX

    /********** Configure USART2 **********/
    RCC->APB1ENR1 |= (1U << 17);     // Enable USART2 clock

    USART2->BRR = compute_uart_bd(SYS_FREQ, UART_BAUDRATE);  // Set baud rate
    USART2->CR1 = (1U << 3);         // Enable TX (TE)
    USART2->CR1 |= (1U << 0);        // Enable USART2 (UE)
}

static uint16_t compute_uart_bd(uint32_t periph_clk, uint32_t baudrate)
{
    return (periph_clk + (baudrate / 2U)) / baudrate;
}

//int __io_putchar(int ch)
//{
//    while (!(USART2->ISR & (1U << 7))) {}  // Wait until TXE is set
//    USART2->TDR = (ch & 0xFF);
//    return ch;
//}
