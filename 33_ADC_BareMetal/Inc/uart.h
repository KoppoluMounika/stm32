#ifndef UART_H_
#define UART_H_

#include "stm32l4xx.h"

void USART2_tx_rx_init(void);
void uart2_write(int ch);

#endif
