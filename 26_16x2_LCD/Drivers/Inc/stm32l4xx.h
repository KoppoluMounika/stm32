#ifndef STM32L4XX_H
#define STM32L4XX_H

#include <stdint.h>

#define __IO volatile

// GPIO register structure
typedef struct
{
    __IO uint32_t MODER;
    __IO uint32_t OTYPER;
    __IO uint32_t OSPEEDR;
    __IO uint32_t PUPDR;
    __IO uint32_t IDR;
    __IO uint32_t ODR;
    __IO uint32_t BSRR;
    __IO uint32_t LCKR;
    __IO uint32_t AFR[2];
} GPIO_RegDef_t;

// RCC register structure
typedef struct
{
    __IO uint32_t CR;
    __IO uint32_t ICSCR;
    __IO uint32_t CFGR;
    __IO uint32_t PLLCFGR;
    __IO uint32_t PLLSAI1CFGR;
    __IO uint32_t CIER;
    __IO uint32_t CIFR;
    __IO uint32_t CICR;
    __IO uint32_t AHB1RSTR;
    __IO uint32_t AHB2RSTR;
    __IO uint32_t AHB3RSTR;
    uint32_t RESERVED0;
    __IO uint32_t APB1RSTR1;
    __IO uint32_t APB1RSTR2;
    __IO uint32_t APB2RSTR;
    uint32_t RESERVED1[2];
    __IO uint32_t AHB1ENR;
    __IO uint32_t AHB2ENR;
    __IO uint32_t AHB3ENR;
    uint32_t RESERVED2;
    __IO uint32_t APB1ENR1;
    __IO uint32_t APB1ENR2;
    __IO uint32_t APB2ENR;
} RCC_RegDef_t;

// Base addresses
#define GPIOA ((GPIO_RegDef_t *)0x48000000U)
#define GPIOB ((GPIO_RegDef_t *)0x48000400U)
#define GPIOC ((GPIO_RegDef_t *)0x48000800U)

#define RCC ((RCC_RegDef_t *)0x40021000U)

// Enable/Disable macros
#define ENABLE  1
#define DISABLE 0

#endif
