#ifndef STM32L4_GPIO_H
#define STM32L4_GPIO_H

#include <stdint.h>

// Base addresses
#define PERIPH_BASEADDR      0x40000000UL
#define AHB2_BASEADDR        0x48000000UL

#define GPIOA_BASEADDR       0x48000000U
#define RCC_BASEADDR         0x40021000U

// RCC registers
#define RCC_AHB2ENR          (*(volatile uint32_t*)(RCC_BASEADDR + 0x4C))

// GPIO registers offsets
#define MODER_OFFSET         0x00UL
#define ODR_OFFSET           0x14UL

// GPIOA registers
#define GPIOA_MODER          (*(volatile uint32_t*)(GPIOA_BASEADDR + MODER_OFFSET))
#define GPIOA_ODR            (*(volatile uint32_t*)(GPIOA_BASEADDR + ODR_OFFSET))

// Macros
#define GPIOAEN              (1U<<0)
#define LED_PIN              (1U<<5)

// Function prototypes
void GPIOA_Init(void);
void LED_On(void);
void LED_Off(void);
void LED_Toggle(void);
void delay(volatile uint32_t count);

#endif
