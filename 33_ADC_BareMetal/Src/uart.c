#include "stm32l4xx.h"
#include "uart.h"

#define GPIOAEN   (1U << 0)
#define USART2EN  (1U << 17)

#define CR1_TE    (1U << 3)
#define CR1_RE    (1U << 2)
#define CR1_UE    (1U << 0)
#define SR_TXE    (1U << 7)
#define SR_RXNE   (1U << 5)

void USART2_tx_rx_init(void)
{
    RCC->AHB2ENR |= GPIOAEN;      // Enable GPIOA
    GPIOA->MODER &= ~((3U << 4) | (3U << 6));  // Clear mode
    GPIOA->MODER |=  (2U << 4) | (2U << 6);    // AF mode for PA2/PA3
    GPIOA->AFR[0] |=  (7U << 8) | (7U << 12);  // AF7 = USART2
    GPIOA->OSPEEDR |= (3U << 4) | (3U << 6);   // High speed

    RCC->APB1ENR1 |= USART2EN;    // Enable USART2 clock

    USART2->BRR = 0x22B;          // 115200 baud @16MHz
    USART2->CR1 = CR1_TE | CR1_RE; // Enable TX, RX
    USART2->CR1 |= CR1_UE;        // Enable USART
}
