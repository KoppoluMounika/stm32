#include "stm32l4xx_gpio_driver.h"

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
    {
        if(pGPIOx == GPIOA) RCC->AHB2ENR |= (1 << 0);
        else if(pGPIOx == GPIOB) RCC->AHB2ENR |= (1 << 1);
        else if(pGPIOx == GPIOC) RCC->AHB2ENR |= (1 << 2);
    }
    else
    {
        if(pGPIOx == GPIOA) RCC->AHB2ENR &= ~(1 << 0);
        else if(pGPIOx == GPIOB) RCC->AHB2ENR &= ~(1 << 1);
        else if(pGPIOx == GPIOC) RCC->AHB2ENR &= ~(1 << 2);
    }
}

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pin, uint8_t value)
{
    if(value)
        pGPIOx->ODR |= (1 << pin);
    else
        pGPIOx->ODR &= ~(1 << pin);
}
