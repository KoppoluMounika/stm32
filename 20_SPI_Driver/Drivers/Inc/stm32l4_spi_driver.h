#ifndef STM32L4_SPI_DRIVER_H
#define STM32L4_SPI_DRIVER_H

#include <stdint.h>

#define PERIPH_BASE           (0x40000000UL)
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000UL)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x08000000UL)

#define GPIOA_BASE            (AHB2PERIPH_BASE + 0x0000UL)
#define RCC_BASE              (0x40021000UL)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x3000UL)

typedef struct {
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

typedef struct {
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SR;
    volatile uint32_t DR;
    volatile uint32_t CRCPR;
    volatile uint32_t RXCRCR;
    volatile uint32_t TXCRCR;
    volatile uint32_t I2SCFGR;
    volatile uint32_t I2SPR;
} SPI_TypeDef;

typedef struct {
    volatile uint32_t CR;
    volatile uint32_t ICSCR;
    volatile uint32_t CFGR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t PLLSAI1CFGR;
    volatile uint32_t CIER;
    volatile uint32_t CIFR;
    volatile uint32_t CICR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    volatile uint32_t AHB3RSTR;
    uint32_t RESERVED0;
    volatile uint32_t APB1RSTR1;
    volatile uint32_t APB1RSTR2;
    volatile uint32_t APB2RSTR;
    uint32_t RESERVED1[2];
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    volatile uint32_t AHB3ENR;
    uint32_t RESERVED2;
    volatile uint32_t APB1ENR1;
    volatile uint32_t APB1ENR2;
    volatile uint32_t APB2ENR;
} RCC_TypeDef;

#define GPIOA    ((GPIO_TypeDef *) GPIOA_BASE)
#define RCC      ((RCC_TypeDef *) RCC_BASE)
#define SPI1     ((SPI_TypeDef *) SPI1_BASE)

#define RCC_AHB2ENR_GPIOAEN    (1U << 0)
#define RCC_APB2ENR_SPI1EN     (1U << 12)

void SPI1_Init(void);
uint8_t SPI1_TransmitReceive(uint8_t data);

#endif
