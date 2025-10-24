#ifndef STM32L476XX_H
#define STM32L476XX_H

#include <stdint.h>

/* ===========================================================
 * Base addresses for peripheral buses
 * =========================================================== */
#define PERIPH_BASE           0x40000000UL
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x08000000UL)
#define APB1PERIPH_BASE       (PERIPH_BASE + 0x00000000UL)
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000UL)

/* ===========================================================
 * RCC (Reset and Clock Control)
 * Base address: 0x40021000
 * =========================================================== */
#define RCC_BASE              (0x40021000UL)

typedef struct
{
  volatile uint32_t CR;            /*!< RCC clock control register,                   Address offset: 0x00 */
  volatile uint32_t ICSCR;         /*!< Internal clock sources calibration register,  Address offset: 0x04 */
  volatile uint32_t CFGR;          /*!< RCC clock configuration register,             Address offset: 0x08 */
  volatile uint32_t PLLCFGR;       /*!< RCC PLL configuration register,               Address offset: 0x0C */
  volatile uint32_t PLLSAI1CFGR;   /*!< RCC PLLSAI1 configuration register,           Address offset: 0x10 */
  volatile uint32_t RESERVED0;     /*!< Reserved,                                     Address offset: 0x14 */
  volatile uint32_t CIER;          /*!< RCC clock interrupt enable register,          Address offset: 0x18 */
  volatile uint32_t CIFR;          /*!< RCC clock interrupt flag register,            Address offset: 0x1C */
  volatile uint32_t CICR;          /*!< RCC clock interrupt clear register,           Address offset: 0x20 */
  volatile uint32_t RESERVED1;     /*!< Reserved,                                     Address offset: 0x24 */
  volatile uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,           Address offset: 0x28 */
  volatile uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,           Address offset: 0x2C */
  volatile uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,           Address offset: 0x30 */
  volatile uint32_t RESERVED2;     /*!< Reserved,                                     Address offset: 0x34 */
  volatile uint32_t APB1RSTR1;     /*!< RCC APB1 peripheral reset register 1,         Address offset: 0x38 */
  volatile uint32_t APB1RSTR2;     /*!< RCC APB1 peripheral reset register 2,         Address offset: 0x3C */
  volatile uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,           Address offset: 0x40 */
  volatile uint32_t RESERVED3;     /*!< Reserved,                                     Address offset: 0x44 */
  volatile uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock enable register,    Address offset: 0x48 */
  volatile uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock enable register,    Address offset: 0x4C */
  volatile uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock enable register,    Address offset: 0x50 */
  volatile uint32_t RESERVED4;     /*!< Reserved,                                     Address offset: 0x54 */
  volatile uint32_t APB1ENR1;      /*!< RCC APB1 peripheral clock enable register 1,  Address offset: 0x58 */
  volatile uint32_t APB1ENR2;      /*!< RCC APB1 peripheral clock enable register 2,  Address offset: 0x5C */
  volatile uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,    Address offset: 0x60 */
} RCC_TypeDef;

#define RCC   ((RCC_TypeDef *) RCC_BASE)

/* ===========================================================
 * GPIO
 * Base addresses (from RM0351)
 * =========================================================== */
#define GPIOA_BASE            (AHB2PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE            (AHB2PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE            (AHB2PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE            (AHB2PERIPH_BASE + 0x0C00UL)
#define GPIOE_BASE            (AHB2PERIPH_BASE + 0x1000UL)
#define GPIOH_BASE            (AHB2PERIPH_BASE + 0x1C00UL)

/* GPIO register structure */
typedef struct
{
  volatile uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00 */
  volatile uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04 */
  volatile uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08 */
  volatile uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C */
  volatile uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10 */
  volatile uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14 */
  volatile uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18 */
  volatile uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C */
  volatile uint32_t AFRL;     /*!< GPIO alternate function low register,  Address offset: 0x20 */
  volatile uint32_t AFRH;     /*!< GPIO alternate function high register, Address offset: 0x24 */
  volatile uint32_t BRR;      /*!< GPIO port bit reset register,          Address offset: 0x28 */
} GPIO_TypeDef;

/* Peripheral definitions */
#define GPIOA   ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB   ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC   ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD   ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE   ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOH   ((GPIO_TypeDef *) GPIOH_BASE)

/* ===========================================================
 * Bit definitions
 * =========================================================== */
#define RCC_AHB2ENR_GPIOAEN_Pos   (0U)
#define RCC_AHB2ENR_GPIOAEN_Msk   (1U << RCC_AHB2ENR_GPIOAEN_Pos)
#define RCC_AHB2ENR_GPIOAEN       RCC_AHB2ENR_GPIOAEN_Msk

#define RCC_AHB2ENR_GPIOBEN_Pos   (1U)
#define RCC_AHB2ENR_GPIOBEN_Msk   (1U << RCC_AHB2ENR_GPIOBEN_Pos)
#define RCC_AHB2ENR_GPIOBEN       RCC_AHB2ENR_GPIOBEN_Msk

#define RCC_AHB2ENR_GPIOCEN_Pos   (2U)
#define RCC_AHB2ENR_GPIOCEN_Msk   (1U << RCC_AHB2ENR_GPIOCEN_Pos)
#define RCC_AHB2ENR_GPIOCEN       RCC_AHB2ENR_GPIOCEN_Msk

#endif /* STM32L476XX_H */
