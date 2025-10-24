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
  volatile uint32_t CR;
  volatile uint32_t ICSCR;
  volatile uint32_t CFGR;
  volatile uint32_t PLLCFGR;
  volatile uint32_t PLLSAI1CFGR;
  volatile uint32_t RESERVED0;
  volatile uint32_t CIER;
  volatile uint32_t CIFR;
  volatile uint32_t CICR;
  volatile uint32_t RESERVED1;
  volatile uint32_t AHB1RSTR;
  volatile uint32_t AHB2RSTR;
  volatile uint32_t AHB3RSTR;
  volatile uint32_t RESERVED2;
  volatile uint32_t APB1RSTR1;
  volatile uint32_t APB1RSTR2;
  volatile uint32_t APB2RSTR;
  volatile uint32_t RESERVED3;
  volatile uint32_t AHB1ENR;
  volatile uint32_t AHB2ENR;
  volatile uint32_t AHB3ENR;
  volatile uint32_t RESERVED4;
  volatile uint32_t APB1ENR1;
  volatile uint32_t APB1ENR2;
  volatile uint32_t APB2ENR;
} RCC_TypeDef;

#define RCC   ((RCC_TypeDef *) RCC_BASE)

/* ===========================================================
 * GPIO
 * =========================================================== */
#define GPIOA_BASE  (AHB2PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE  (AHB2PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE  (AHB2PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE  (AHB2PERIPH_BASE + 0x0C00UL)
#define GPIOE_BASE  (AHB2PERIPH_BASE + 0x1000UL)
#define GPIOH_BASE  (AHB2PERIPH_BASE + 0x1C00UL)

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
  volatile uint32_t AFRL;
  volatile uint32_t AFRH;
  volatile uint32_t BRR;
} GPIO_TypeDef;

#define GPIOA   ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB   ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC   ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD   ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE   ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOH   ((GPIO_TypeDef *) GPIOH_BASE)

/* ===========================================================
 * USART
 * =========================================================== */
#define USART1_BASE    (APB2PERIPH_BASE + 0x3800UL)
#define USART2_BASE    (APB1PERIPH_BASE + 0x4400UL)
#define USART3_BASE    (APB1PERIPH_BASE + 0x4800UL)
#define UART4_BASE     (APB1PERIPH_BASE + 0x4C00UL)
#define UART5_BASE     (APB1PERIPH_BASE + 0x5000UL)

typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t CR3;
  volatile uint32_t BRR;
  volatile uint32_t GTPR;
  volatile uint32_t RTOR;
  volatile uint32_t RQR;
  volatile uint32_t ISR;
  volatile uint32_t ICR;
  volatile uint32_t RDR;
  volatile uint32_t TDR;
} USART_TypeDef;

#define USART1  ((USART_TypeDef *) USART1_BASE)
#define USART2  ((USART_TypeDef *) USART2_BASE)
#define USART3  ((USART_TypeDef *) USART3_BASE)
#define UART4   ((USART_TypeDef *) UART4_BASE)
#define UART5   ((USART_TypeDef *) UART5_BASE)

/* ===========================================================
 * Bit definitions (example subset)
 * =========================================================== */
#define RCC_AHB2ENR_GPIOAEN_Pos   (0U)
#define RCC_AHB2ENR_GPIOAEN_Msk   (1U << RCC_AHB2ENR_GPIOAEN_Pos)
#define RCC_AHB2ENR_GPIOAEN       RCC_AHB2ENR_GPIOAEN_Msk

#endif /* STM32L476XX_H */
