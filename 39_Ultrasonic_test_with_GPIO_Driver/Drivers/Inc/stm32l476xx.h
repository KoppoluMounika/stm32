#ifndef STM32L476XX_H
#define STM32L476XX_H

#include <stdint.h>

/* Base addresses */
#define PERIPH_BASE       0x40000000UL
#define AHB2PERIPH_BASE   (PERIPH_BASE + 0x08000000UL)
#define GPIOA_BASE        (AHB2PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE        (AHB2PERIPH_BASE + 0x0400UL)
#define RCC_BASE          0x40021000UL

/* GPIO registers */
typedef struct
{
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFR[2];
} GPIO_TypeDef;

/* RCC registers */
typedef struct
{
    volatile uint32_t CR;
    volatile uint32_t ICSCR;
    volatile uint32_t CFGR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CIER;
    volatile uint32_t CIFR;
    volatile uint32_t CICR;
    uint32_t RESERVED1[2];
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    uint32_t RESERVED2[2];
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    uint32_t RESERVED3[2];
} RCC_TypeDef;

/* Peripherals */
#define GPIOA ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef *) GPIOB_BASE)
#define RCC   ((RCC_TypeDef *) RCC_BASE)

/* RCC AHB2ENR bits */
#define RCC_AHB2ENR_GPIOAEN (1UL << 0)
#define RCC_AHB2ENR_GPIOBEN (1UL << 1)

/* SysTick */
typedef struct
{
    volatile uint32_t CTRL;
    volatile uint32_t LOAD;
    volatile uint32_t VAL;
    volatile uint32_t CALIB;
} SysTick_Type;

#define SysTick ((SysTick_Type *)0xE000E010UL)

/* System core clock */
#define SYSTEM_CORE_CLOCK 80000000UL // 80 MHz

#endif
