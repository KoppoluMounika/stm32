#ifndef STM32L4XX_GPIO_DRIVER_H
#define STM32L4XX_GPIO_DRIVER_H

#include "stm32l4xx.h"

// GPIO peripheral clock control
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

// GPIO write function
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pin, uint8_t value);

#endif
