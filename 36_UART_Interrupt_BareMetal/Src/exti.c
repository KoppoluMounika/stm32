#include "stm32l4xx.h"
#include "exti.h"

#define GPIOCEN (1U<<2)

void pc13_exti_init(void)
{
    // Disable global interrupts
    __disable_irq();

    // 1. Enable clock for GPIOC
    RCC->AHB2ENR |= GPIOCEN;

    // 2. Set PC13 as input
    GPIOC->MODER &= ~(3U << 26);  // PC13 → Input mode (00)

    // 3. Enable clock access to SYSCFG
    RCC->APB2ENR |= (1U << 0);

    // 4. Select Port C for EXTI13
    SYSCFG->EXTICR[3] &= ~(0xFU << 4);
    SYSCFG->EXTICR[3] |=  (0x2U << 4); // Port C is 0b0010

    // 5. Unmask EXTI13
    EXTI->IMR1 |= (1U << 13);

    // 6. Falling edge trigger (button pressed = LOW)
    EXTI->FTSR1 |= (1U << 13);

    // 7. Enable interrupt in NVIC
    NVIC_EnableIRQ(EXTI15_10_IRQn);

    // Re-enable interrupts
    __enable_irq();
}
