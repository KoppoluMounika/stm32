/*
 * stm32l4xx_gpio_driver.h
 *
 *  Created on: Oct 13, 2025
 *      Author: KOPPOLU MOUNIKA
 */

#ifndef STM32L4XX_GPIO_DRIVER_H
#define STM32L4XX_GPIO_DRIVER_H

#include "stm32l4xx.h"

// GPIO pin configuration structure
typedef struct
{
	uint8_t  GPIO_PinNumber;        // @GPIO_PIN_NUM
	uint8_t  GPIO_PinMode;          // @GPIO_PIN_MODES
	uint8_t  GPIO_PinSpeed;         // @GPIO_OUT_SPEED
	uint8_t	 GPIO_PinPuPdControl;   // @GPIO_PUPD
	uint8_t  GPIO_PinOPType;        // @GPIO_OUT_TYPES
	uint8_t  GPIO_PinAltFunMode;
} GPIO_PinConfig_t;

// GPIO handle structure
typedef struct
{
	GPIO_RegDef_t *pGPIOx;          // Base address of GPIO port
	GPIO_PinConfig_t GPIO_PinConfig; // Pin configuration
} GPIO_Handle_t;


//*********** APIs supported by the driver **************

// Peripheral clock setup
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

// Init and Deinit GPIO
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

// Read and Write
uint8_t  GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t GPIO_PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t GPIO_PinNumber, uint32_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint32_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t GPIO_PinNumber);

// IRQ Configuration
void GPIO_IRQ_interrupt_Config(uint8_t IRQNumber, uint8_t EnorDi);
void GPIO_IRQ_priority_Config(uint8_t IRQNumber, uint8_t priority);
void GPIO_IRQHandling(uint8_t GPIO_PinNumber);


// GPIO pin numbers
#define GPIO_PIN_NO_0        0
#define GPIO_PIN_NO_1        1
#define GPIO_PIN_NO_2        2
#define GPIO_PIN_NO_3        3
#define GPIO_PIN_NO_4        4
#define GPIO_PIN_NO_5        5
#define GPIO_PIN_NO_6        6
#define GPIO_PIN_NO_7        7
#define GPIO_PIN_NO_8        8
#define GPIO_PIN_NO_9        9
#define GPIO_PIN_NO_10       10
#define GPIO_PIN_NO_11       11
#define GPIO_PIN_NO_12       12
#define GPIO_PIN_NO_13       13
#define GPIO_PIN_NO_14       14
#define GPIO_PIN_NO_15       15

// GPIO pin modes
#define GPIO_MODE_IN       0
#define GPIO_MODE_OUT      1
#define GPIO_MODE_ALTFN    2
#define GPIO_MODE_ANALOG   3
#define GPIO_MODE_IT_FT    4
#define GPIO_MODE_IT_RT    5
#define GPIO_MODE_IT_RFT   6

// GPIO output types
#define GPIO_OP_TYPE_PP    0
#define GPIO_OP_TYPE_OD    1

// GPIO output speed
#define GPIO_LOW_SPEED     0
#define GPIO_MED_SPEED     1
#define GPIO_HIGH_SPEED    2
#define GPIO_VHIGH_SPEED   3

// GPIO pull-up/pull-down
#define GPIO_NO_PUPD       0
#define GPIO_PIN_PU        1
#define GPIO_PIN_PD        2

#endif

