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
  volatile uint32_t RESERVED5[100];
  volatile uint32_t CCIPR;
} RCC_TypeDef;

#define RCC   ((RCC_TypeDef *) RCC_BASE)

/* RCC bit definitions */
#define RCC_CR_HSION          (1U << 0)
#define RCC_CR_HSIRDY         (1U << 1)

#define RCC_AHB2ENR_GPIOAEN   (1U << 0)
#define RCC_AHB2ENR_ADCEN     (1U << 13)
#define RCC_APB1ENR1_USART2EN (1U << 17)

/* ===========================================================
 * RCC CFGR bit definitions (for system clock selection)
 * =========================================================== */
#define RCC_CFGR_SW_Pos         (0U)
#define RCC_CFGR_SW_Msk         (0x3U << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW             RCC_CFGR_SW_Msk
#define RCC_CFGR_SW_MSI         (0x0U << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW_HSI         (0x1U << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW_HSE         (0x2U << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW_PLL         (0x3U << RCC_CFGR_SW_Pos)

#define RCC_CFGR_SWS_Pos        (2U)
#define RCC_CFGR_SWS_Msk        (0x3U << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS            RCC_CFGR_SWS_Msk
#define RCC_CFGR_SWS_MSI        (0x0U << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS_HSI        (0x1U << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS_HSE        (0x2U << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS_PLL        (0x3U << RCC_CFGR_SWS_Pos)

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
  volatile uint32_t ASCR;  /* Analog switch control */
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

#define USART_CR1_UE     (1U << 0)
#define USART_CR1_TE     (1U << 3)
#define USART_CR1_RE     (1U << 2)
#define USART_ISR_TXE    (1U << 7)
#define USART_ISR_RXNE   (1U << 5)

/* ===========================================================
 * ADC
 * =========================================================== */
#define ADC1_BASE  (AHB2PERIPH_BASE + 0x0800UL)

typedef struct
{
  volatile uint32_t ISR;
  volatile uint32_t IER;
  volatile uint32_t CR;
  volatile uint32_t CFGR;
  volatile uint32_t RESERVED1;
  volatile uint32_t SMPR1;
  volatile uint32_t SMPR2;
  volatile uint32_t RESERVED2[2];
  volatile uint32_t TR1;
  volatile uint32_t RESERVED3[24];
  volatile uint32_t SQR1;
  volatile uint32_t SQR2;
  volatile uint32_t SQR3;
  volatile uint32_t SQR4;
  volatile uint32_t DR;
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

/* ===========================================================
 * SysTick
 * =========================================================== */
typedef struct
{
  volatile uint32_t CTRL;
  volatile uint32_t LOAD;
  volatile uint32_t VAL;
  volatile uint32_t CALIB;
} SysTick_Type;

#define SysTick_BASE        (0xE000E010UL)
#define SysTick             ((SysTick_Type *) SysTick_BASE)

/* SysTick bit definitions */
#define SYSTICK_CTRL_ENABLE     (1U << 0)
#define SYSTICK_CTRL_TICKINT    (1U << 1)
#define SYSTICK_CTRL_CLKSOURCE  (1U << 2)
#define SYSTICK_CTRL_COUNTFLAG  (1U << 16)

/* ===========================================================
 * TIMERS (TIM2–TIM7)
 * =========================================================== */
#define TIM2_BASE   (APB1PERIPH_BASE + 0x0000UL)
#define TIM3_BASE   (APB1PERIPH_BASE + 0x0400UL)
#define TIM4_BASE   (APB1PERIPH_BASE + 0x0800UL)
#define TIM5_BASE   (APB1PERIPH_BASE + 0x0C00UL)
#define TIM6_BASE   (APB1PERIPH_BASE + 0x1000UL)
#define TIM7_BASE   (APB1PERIPH_BASE + 0x1400UL)

/* TIM register structure */
typedef struct
{
  volatile uint32_t CR1;       // Control register 1
  volatile uint32_t CR2;       // Control register 2
  volatile uint32_t SMCR;      // Slave mode control register
  volatile uint32_t DIER;      // DMA/Interrupt enable register
  volatile uint32_t SR;        // Status register
  volatile uint32_t EGR;       // Event generation register
  volatile uint32_t CCMR1;     // Capture/Compare mode register 1
  volatile uint32_t CCMR2;     // Capture/Compare mode register 2
  volatile uint32_t CCER;      // Capture/Compare enable register
  volatile uint32_t CNT;       // Counter
  volatile uint32_t PSC;       // Prescaler
  volatile uint32_t ARR;       // Auto-reload register
  volatile uint32_t RESERVED1;
  volatile uint32_t CCR1;      // Capture/Compare register 1
  volatile uint32_t CCR2;
  volatile uint32_t CCR3;
  volatile uint32_t CCR4;
  volatile uint32_t RESERVED2;
  volatile uint32_t DCR;       // DMA control register
  volatile uint32_t DMAR;      // DMA address for full transfer
} TIM_TypeDef;

/* Timer pointers */
#define TIM2   ((TIM_TypeDef *) TIM2_BASE)
#define TIM3   ((TIM_TypeDef *) TIM3_BASE)
#define TIM4   ((TIM_TypeDef *) TIM4_BASE)
#define TIM5   ((TIM_TypeDef *) TIM5_BASE)
#define TIM6   ((TIM_TypeDef *) TIM6_BASE)
#define TIM7   ((TIM_TypeDef *) TIM7_BASE)

/* Timer bit definitions */
#define TIM_CR1_CEN     (1U << 0)    // Counter enable
#define TIM_SR_UIF      (1U << 0)    // Update interrupt flag
#define TIM_DIER_UIE    (1U << 0)    // Update interrupt enable
#define TIM_EGR_UG      (1U << 0)    // Update generation


#endif /* STM32L476XX_H */
