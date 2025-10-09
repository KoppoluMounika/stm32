#include <Inc/stm32l4_gpio.h>
// Initialize PA5 as output
void GPIOA_Init(void)
{
    // Enable GPIOA clock
    RCC_AHB2ENR |= GPIOAEN;

    // Set PA5 as output (MODER5[1:0] = 01)
    GPIOA_MODER &= ~(1U << 11);  // Clear bit 11
    GPIOA_MODER |=  (1U << 10);  // Set bit 10
}

// Turn on LED
void LED_On(void)
{
    GPIOA_ODR |= LED_PIN;
}

// Turn off LED
void LED_Off(void)
{
    GPIOA_ODR &= ~LED_PIN;
}

// Toggle LED
void LED_Toggle(void)
{
    GPIOA_ODR ^= LED_PIN;
}

// Simple delay function
void delay(volatile uint32_t count)
{
    while(count--);
}
