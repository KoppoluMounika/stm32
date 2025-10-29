#include "stm32l4xx.h"
#include "systick.h"
#include "timer.h"

#define GPIOAEN   (1U << 0)
#define GPIOBEN   (1U << 1)
#define LED_PIN   (1U << 5)   // Onboard LED is on PA5

int main(void)
{
    /* 1. Enable clock for GPIOA (where LED is connected) */
    RCC->AHB2ENR |= GPIOAEN;

    /* 2. Set PA5 as output */
    GPIOA->MODER &= ~(3U << (5 * 2));   // Clear mode bits for pin 5
    GPIOA->MODER |=  (1U << (5 * 2));   // Set as general purpose output

    /* 3. Initialize timer to 1Hz */
    tim2_1hz_init();

    while (1)
    {
        /* Wait until the update interrupt flag (UIF) is set */
        while (!(TIM2->SR & SR_UIF));

        /* Clear UIF flag */
        TIM2->SR &= ~SR_UIF;

        /* Toggle LED */
        GPIOA->ODR ^= LED_PIN;

        /* Optional delay for visual smoothness */
        systickDelayMs(100);
    }
}
