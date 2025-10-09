#ifndef STM32L4_GPIO_DRIVER_H
#define STM32L4_GPIO_DRIVER_H

#include "stm32l4xx.h"  // CMSIS header

// Simple GPIO functions
void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t Pin, uint8_t Value);
void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t Pin);

#endif
