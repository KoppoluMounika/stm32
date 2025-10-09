#include "stm32l4_gpio_driver.h"

void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t Pin, uint8_t Value)
{
    if(Value)
        GPIOx->ODR |= Pin;
    else
        GPIOx->ODR &= ~Pin;
}

void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t Pin)
{
    GPIOx->ODR ^= Pin;
}
