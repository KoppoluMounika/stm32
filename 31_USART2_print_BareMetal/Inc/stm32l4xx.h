#ifndef STM32L476XX_H
#define STM32L476XX_H

#include <stdint.h>

/* ===========================================================
 * Core peripheral base
 * =========================================================== */
#define PERIPH_BASE           0x40000000UL

/* Bus peripheral base addresses (STM32L4 series mapping) */
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL) /* not used here but kept */
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x08000000UL) /* 0x4800_0000 - GPIOx live here */
#define APB1PERIPH_BASE       (PERIPH_BASE + 0x00000000UL) /* 0x4000_0000 */
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000UL) /* 0x4001_0000 */

#define RCC_BASE              (0x40021000UL) /* RCC base for many STM32L4 devices */

/* ===========================================================
 * RCC (Reset and Clock Control) - partial
 * =========================================================== */
typedef struct
{
  volatile uint32_t CR;        /* 0x00 */
  volatile uint32_t ICSCR;     /* 0x04 */
  volatile uint32_t CFGR;      /* 0x08 */
  volatile uint32_t PLLCFGR;   /* 0x0C */
  volatile uint32_t PLLSAI1CFGR;/*0x10*/
  volatile uint32_t RESERVED0; /* 0x14 */
  volatile uint32_t CIER;      /* 0x18 */
  volatile uint32_t CIFR;      /* 0x1C */
  volatile uint32_t CICR;      /* 0x20 */
  volatile uint32_t RESERVED1; /* 0x24 */
  volatile uint32_t AHB1RSTR;  /* 0x28 */
  volatile uint32_t AHB2RSTR;  /* 0x2C */
  volatile uint32_t AHB3RSTR;  /* 0x30 */
  volatile uint32_t RESERVED2; /* 0x34 */
  volatile uint32_t APB1RSTR1; /* 0x38 */
  volatile uint32_t APB1RSTR2; /* 0x3C */
  volatile uint32_t APB2RSTR;  /* 0x40 */
  volatile uint32_t RESERVED3; /* 0x44 */
  volatile uint32_t AHB1ENR;   /* 0x48 */
  volatile uint32_t AHB2ENR;   /* 0x4C */
  volatile uint32_t AHB3ENR;   /* 0x50 */
  volatile uint32_t RESERVED4; /* 0x54 */
  volatile uint32_t APB1ENR1;  /* 0x58 */
  volatile uint32_t APB1ENR2;  /* 0x5C */
  volatile uint32_t APB2ENR;   /* 0x60 */
  /* ... more registers exist in real device header ... */
  volatile uint32_t RESERVED5[100]; /* spare to align if you want more */
  volatile uint32_t CCIPR;     /* note: CCIPR is usually at offset 0x88 or similar in real header */
} RCC_TypeDef;

#define RCC   ((RCC_TypeDef *) RCC_BASE)

/* Bit definitions used in your main.c */
#define RCC_CR_HSION      (1U << 0)   /* HSI16 enable bit */
#define RCC_CR_HSIRDY     (1U << 1)   /* HSI16 ready flag */

/* Example AHB2ENR GPIOAEN position (used in your main.c) */
#define RCC_AHB2ENR_GPIOAEN_Pos   (0U)
#define RCC_AHB2ENR_GPIOAEN_Msk   (1U << RCC_AHB2ENR_GPIOAEN_Pos)
#define RCC_AHB2ENR_GPIOAEN       RCC_AHB2ENR_GPIOAEN_Msk

/* ===========================================================
 * GPIO
 * Base addresses for GPIO ports (AHB2)
 * =========================================================== */
#define GPIOA_BASE  (AHB2PERIPH_BASE + 0x0000UL) /* 0x4800_0000 */
#define GPIOB_BASE  (AHB2PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE  (AHB2PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE  (AHB2PERIPH_BASE + 0x0C00UL)
#define GPIOE_BASE  (AHB2PERIPH_BASE + 0x1000UL)
#define GPIOH_BASE  (AHB2PERIPH_BASE + 0x1C00UL)

typedef struct
{
  volatile uint32_t MODER;    /* 0x00 */
  volatile uint32_t OTYPER;   /* 0x04 */
  volatile uint32_t OSPEEDR;  /* 0x08 */
  volatile uint32_t PUPDR;    /* 0x0C */
  volatile uint32_t IDR;      /* 0x10 */
  volatile uint32_t ODR;      /* 0x14 */
  volatile uint32_t BSRR;     /* 0x18 */
  volatile uint32_t LCKR;     /* 0x1C */
  volatile uint32_t AFR[2];   /* 0x20 (AFRL) and 0x24 (AFRH) - use AFR[0]/AFR[1] in code */
  volatile uint32_t BRR;      /* 0x28 - bit reset register (present in L4 variants) */
} GPIO_TypeDef;

#define GPIOA   ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB   ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC   ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD   ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE   ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOH   ((GPIO_TypeDef *) GPIOH_BASE)

/* ===========================================================
 * USART (partial)
 * =========================================================== */
#define USART1_BASE    (APB2PERIPH_BASE + 0x3800UL)
#define USART2_BASE    (APB1PERIPH_BASE + 0x4400UL)
#define USART3_BASE    (APB1PERIPH_BASE + 0x4800UL)
#define UART4_BASE     (APB1PERIPH_BASE + 0x4C00UL)
#define UART5_BASE     (APB1PERIPH_BASE + 0x5000UL)

typedef struct
{
  volatile uint32_t CR1;   /* 0x00 */
  volatile uint32_t CR2;   /* 0x04 */
  volatile uint32_t CR3;   /* 0x08 */
  volatile uint32_t BRR;   /* 0x0C */
  volatile uint32_t GTPR;  /* 0x10 */
  volatile uint32_t RTOR;  /* 0x14 */
  volatile uint32_t RQR;   /* 0x18 */
  volatile uint32_t ISR;   /* 0x1C */
  volatile uint32_t ICR;   /* 0x20 */
  volatile uint32_t RDR;   /* 0x24 */
  volatile uint32_t TDR;   /* 0x28 */
} USART_TypeDef;

#define USART1  ((USART_TypeDef *) USART1_BASE)
#define USART2  ((USART_TypeDef *) USART2_BASE)
#define USART3  ((USART_TypeDef *) USART3_BASE)
#define UART4   ((USART_TypeDef *) UART4_BASE)
#define UART5   ((USART_TypeDef *) UART5_BASE)

/* USART bit masks used in your main.c */
#define USART_CR1_TE   (1U << 3)
#define USART_CR1_UE   (1U << 0)
#define USART_ISR_TXE  (1U << 7)

/* Convenience alias for your main.c */
#define GPIOAEN     RCC_AHB2ENR_GPIOAEN

#endif /* STM32L476XX_H */
