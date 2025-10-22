#include <stdio.h>
#include "stm32l476xx.h"
#include "stm32l4xx_hal.h"
#include "adc.h"

void GPIO_Init(void);
void TIM2_Init(void);
void USART2_Init(void);
void USART2_SendString(char *str);

volatile uint32_t uiMilliSec = 0;

int main(void)
{
	uint32_t uiAdcVal = 0;
	uint8_t ucTxBuff[100] = {0};
    GPIO_Init();     // LED setup
    //TIM2_Init();     // Timer for interrupt
    USART2_Init();   // UART2 setup
    adc_init_start();

    while(1)
    {
        // Main loop empty — LED blink and UART happen in ISR
    	uiAdcVal = adc_read();

    	sprintf((char*)ucTxBuff, "ADC Value is %ld \n",uiAdcVal);


    	USART2_SendString((char*)ucTxBuff);

    	//HAL_Delay(5);

    }
}

// -------- GPIO: LED on PA5 --------
void GPIO_Init(void)
{
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;   // Enable GPIOA clock
    GPIOA->MODER &= ~(3UL << (5 * 2));     // Clear mode bits
    GPIOA->MODER |=  (1UL << (5 * 2));     // Set PA5 as output
}

// -------- UART2: PA2 (TX), PA3 (RX) --------
void USART2_Init(void)
{
    RCC->APB1ENR1 |= RCC_APB1ENR1_USART2EN;   // Enable UART2 clock
    RCC->AHB2ENR  |= RCC_AHB2ENR_GPIOAEN;     // Enable GPIOA clock

    // Set PA2, PA3 to alternate function mode
    GPIOA->MODER &= ~((3UL << (2*2)) | (3UL << (3*2)));
    GPIOA->MODER |=  ((2UL << (2*2)) | (2UL << (3*2)));

    // Select AF7 (USART2)
    GPIOA->AFR[0] &= ~((0xF << (2*4)) | (0xF << (3*4)));
    GPIOA->AFR[0] |=  ((7UL << (2*4)) | (7UL << (3*4)));

    // Configure USART2
    USART2->BRR = 4000000 / 9600;     // Assuming 8MHz clock, Baud = 9600
    USART2->CR1 = USART_CR1_TE;       // Transmitter enable
    USART2->CR1 |= USART_CR1_UE;      // USART enable
}

// -------- Send a string via UART2 --------
void USART2_SendString(char *str)
{
    while(*str)
    {
        while(!(USART2->ISR & USART_ISR_TXE)); // Wait for TX empty
        USART2->TDR = *str++;
    }
}

// -------- TIM2 Interrupt setup --------
void TIM2_Init(void)
{
    RCC->APB1ENR1 |= RCC_APB1ENR1_TIM2EN;      // Enable clock for TIM2

    TIM2->PSC = 7999;     // Prescaler (8 MHz / 8000 = 1 kHz -> 1ms tick)
    TIM2->ARR = 1000;     // Auto-reload = 1000ms = 1 second interrupt
    TIM2->DIER |= TIM_DIER_UIE; // Enable update interrupt
    TIM2->CR1 |= TIM_CR1_CEN;   // Start timer

    NVIC_EnableIRQ(TIM2_IRQn);  // Enable TIM2 interrupt
}

// -------- TIM2 ISR: Blink LED + Send UART --------
void TIM2_IRQHandler(void)
{
    if (TIM2->SR & TIM_SR_UIF)
    {
        TIM2->SR &= ~TIM_SR_UIF;   // Clear interrupt flag
        GPIOA->ODR ^= (1 << 5);    // Toggle LED
        USART2_SendString("hello world\r\n");
    }
}
