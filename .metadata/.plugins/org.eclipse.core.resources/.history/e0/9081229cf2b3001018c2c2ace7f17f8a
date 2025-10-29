#ifndef STM32L476XX_H
#define STM32L476XX_H

#include <stdint.h>

/* ===========================================================
 * Core peripheral base
 * =========================================================== */
#define PERIPH_BASE           0x40000000UL

/* Bus peripheral base addresses */
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x08000000UL)
#define APB1PERIPH_BASE       (PERIPH_BASE + 0x00000000UL)
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000UL)

#define RCC_BASE              (0x40021000UL) /* RCC base */

/* ===========================================================
 * RCC (Reset and Clock Control)
 * =========================================================== */
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
  volatile uint32_t RESERVED5[100];
  volatile uint32_t CCIPR;
} RCC_TypeDef;

#define RCC   ((RCC_TypeDef *) RCC_BASE)

/* RCC bit definitions */
#define RCC_CR_HSION      (1U << 0)
#define RCC_CR_HSIRDY     (1U << 1)
#define RCC_AHB2ENR_GPIOAEN   (1U << 0)
#define RCC_AHB2ENR_ADCEN     (1U << 13)
#define RCC_APB1ENR1_USART2EN (1U << 17)

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
  volatile uint32_t AFR[2];
  volatile uint32_t BRR;
  volatile uint32_t ASCR;  /* Analog switch control (used by ADC input pins) */
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

/* USART bit definitions */
#define USART_CR1_UE     (1U << 0)
#define USART_CR1_TE     (1U << 3)
#define USART_CR1_RE     (1U << 2)
#define USART_ISR_TXE    (1U << 7)
#define USART_ISR_RXNE   (1U << 5)

/* ===========================================================
 * ADC (partial)
 * =========================================================== */
#define ADC1_BASE  (AHB2PERIPH_BASE + 0x0800UL)

typedef struct
{
  volatile uint32_t ISR;      /* 0x00 */
  volatile uint32_t IER;      /* 0x04 */
  volatile uint32_t CR;       /* 0x08 */
  volatile uint32_t CFGR;     /* 0x0C */
  volatile uint32_t RESERVED1;
  volatile uint32_t SMPR1;    /* 0x14 */
  volatile uint32_t SMPR2;    /* 0x18 */
  volatile uint32_t RESERVED2[2];
  volatile uint32_t TR1;      /* 0x20 */
  volatile uint32_t RESERVED3[24];
  volatile uint32_t SQR1;     /* 0x30 */
  volatile uint32_t SQR2;
  volatile uint32_t SQR3;
  volatile uint32_t SQR4;
  volatile uint32_t DR;       /* 0x40 */
} ADC_TypeDef;

#define ADC1 ((ADC_TypeDef *) ADC1_BASE)

/* ADC bit definitions */
#define ADC_CR_ADEN         (1U << 0)
#define ADC_CR_ADDIS        (1U << 1)
#define ADC_CR_ADSTART      (1U << 2)
#define ADC_CR_ADCAL        (1U << 31)
#define ADC_CR_ADVREGEN     (1U << 28)
#define ADC_CR_DEEPPWD      (1U << 29)
#define ADC_CR_ADCALDIF     (1U << 30)

#define ADC_ISR_ADRDY       (1U << 0)
#define ADC_ISR_EOC         (1U << 2)

#define ADC_CFGR_CONT       (1U << 13)
#define ADC_CFGR_ALIGN      (1U << 5)
#define ADC_CFGR_RES        (3U << 3)

#define ADC_SQR1_L          (0xFU << 0)
#define ADC_SQR1_SQ1_Pos    (6U)
#define ADC_SQR1_SQ1        (0x1FU << 6)

#endif /* STM32L476XX_H */
