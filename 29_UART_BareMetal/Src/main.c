#include "stm32l4xx.h"
#include <stdint.h>

#define GPIOAEN      (1U << 0)
#define USART2EN     (1U << 17)

#define SYS_FREQ     16000000U
#define APB1_CLK     SYS_FREQ
#define UART_BAUDRATE 115200U

#define CR1_TE       (1U << 3)
#define CR1_UE       (1U << 0)
#define ISR_TXE      (1U << 7)

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate);
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate);
void uart2_write(int ch);
void USART2_tx_init(void);

int main(void)
{
    USART2_tx_init();

    while (1)
    {
        uart2_write('S');
        for (volatile int i = 0; i < 1000000; i++); // simple delay
    }
}

void USART2_tx_init(void)
{
    /*********** Configure UART2 GPIO pins ***********/
    // Enable GPIOA clock
    RCC->AHB2ENR |= GPIOAEN;

    // Set PA2 to Alternate Function (AF7 = USART2_TX)
    GPIOA->MODER &= ~(3U << 4);   // clear bits 5:4
    GPIOA->MODER |=  (2U << 4);   // set mode 10 (AF)
    GPIOA->AFRL  &= ~(0xF << 8);  // clear bits 11:8
    GPIOA->AFRL  |=  (7U << 8);   // AF7 = 0111

    /************* Configure UART2 module *************/
    // Enable USART2 clock
    RCC->APB1ENR1 |= USART2EN;

    // Configure baud rate
    uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);

    // Enable transmitter
    USART2->CR1 = CR1_TE;

    // Enable USART
    USART2->CR1 |= CR1_UE;
}

void uart2_write(int ch)
{
    // Wait until TXE flag is set
    while (!(USART2->ISR & ISR_TXE));

    // Write data to transmit register
    USART2->TDR = (ch & 0xFF);
}

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate)
{
    USARTx->BRR = compute_uart_bd(PeriphClk, BaudRate);
}

static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate)
{
    return ((PeriphClk + (BaudRate / 2U)) / BaudRate);
}
