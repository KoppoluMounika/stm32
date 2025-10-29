#include "stm32l4xx.h"

#define GPIOAEN     (1U<<0)
#define GPIOCEN     (1U<<2)
#define PIN5        (1U<<5)
#define PIN13       (1U<<13)

void pc13_exti_init(void);
void EXTI15_10_IRQHandler(void);

int main(void)
{
    pc13_exti_init();

    // Enable GPIOA clock for LED
    RCC->AHB2ENR |= GPIOAEN;

    // Set PA5 as output
    GPIOA->MODER &= ~(3U << (5 * 2));
    GPIOA->MODER |=  (1U << (5 * 2));

    while(1)
    {
        // Idle loop — wait for interrupt
    }
}

void pc13_exti_init(void)
{
    // Enable clock access to GPIOC and SYSCFG
    RCC->AHB2ENR |= GPIOCEN;
    RCC->APB2ENR |= (1U << 0);   // SYSCFG clock enable

    // Set PC13 as input
    GPIOC->MODER &= ~(3U << (13 * 2));

    // Map EXTI13 line to PC13
    SYSCFG->EXTICR[3] &= ~(0xFU << 4);  // Clear EXTI13 bits
    SYSCFG->EXTICR[3] |=  (2U  << 4);   // Set to port C (0010)

    // Unmask EXTI13
    EXTI->IMR1 |= PIN13;

    // Falling edge trigger (button press = logic 0)
    EXTI->FTSR1 |= PIN13;

    // Enable interrupt in NVIC
    NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI15_10_IRQHandler(void)
{
    // Check if EXTI13 triggered
    if (EXTI->PR1 & PIN13)
    {
        // Clear pending bit
        EXTI->PR1 |= PIN13;

        // Toggle LED
        GPIOA->ODR ^= PIN5;
    }
}
