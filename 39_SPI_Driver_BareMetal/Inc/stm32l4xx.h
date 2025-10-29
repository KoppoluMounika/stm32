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

/* ===========================================================
 * SYSCFG (System Configuration Controller)
 * =========================================================== */
#define SYSCFG_BASE (APB2PERIPH_BASE + 0x0000UL)

typedef struct
{
  volatile uint32_t MEMRMP;
  volatile uint32_t CFGR1;
  volatile uint32_t EXTICR[4];   // External interrupt configuration registers
  volatile uint32_t SCSR;
  volatile uint32_t CFGR2;
  volatile uint32_t SWPR;
  volatile uint32_t SKR;
} SYSCFG_TypeDef;

#define SYSCFG ((SYSCFG_TypeDef *) SYSCFG_BASE)

/* SYSCFG Clock Enable Bit in RCC */
#define RCC_APB2ENR_SYSCFGEN   (1U << 0)


/* ===========================================================
 * EXTI (External Interrupt/Event Controller)
 * =========================================================== */
#define EXTI_BASE (0x40010400UL)

typedef struct
{
  volatile uint32_t IMR1;     // Interrupt mask register 1
  volatile uint32_t EMR1;     // Event mask register 1
  volatile uint32_t RTSR1;    // Rising trigger selection register 1
  volatile uint32_t FTSR1;    // Falling trigger selection register 1
  volatile uint32_t SWIER1;   // Software interrupt event register 1
  volatile uint32_t PR1;      // Pending register 1
  uint32_t RESERVED1;
  volatile uint32_t IMR2;
  volatile uint32_t EMR2;
  volatile uint32_t RTSR2;
  volatile uint32_t FTSR2;
  volatile uint32_t SWIER2;
  volatile uint32_t PR2;
} EXTI_TypeDef;

#define EXTI ((EXTI_TypeDef *) EXTI_BASE)


/* ===========================================================
 * NVIC and global interrupt functions
 * =========================================================== */
static inline void __enable_irq(void)
{
  __asm volatile ("cpsie i");
}

static inline void __disable_irq(void)
{
  __asm volatile ("cpsid i");
}

/* NVIC base address (from ARM Cortex-M4) */
#define NVIC_ISER0   (*(volatile uint32_t *)0xE000E100UL)

/* Enable IRQ number (simple version, no priority) */
static inline void NVIC_EnableIRQ(uint32_t IRQn)
{
  NVIC_ISER0 = (1U << (IRQn & 0x1F));
}

/* Common IRQ numbers */
#define EXTI15_10_IRQn 40U
#define USART2_IRQn    38U

/* ===========================================================
 * I2C (Inter-Integrated Circuit)
 * =========================================================== */
#define I2C1_BASE   (APB1PERIPH_BASE + 0x5400UL)
#define I2C2_BASE   (APB1PERIPH_BASE + 0x5800UL)
#define I2C3_BASE   (APB1PERIPH_BASE + 0x5C00UL)
#define I2C4_BASE   (APB1PERIPH_BASE + 0x6000UL)

typedef struct
{
  volatile uint32_t CR1;     /* Control register 1 */
  volatile uint32_t CR2;     /* Control register 2 */
  volatile uint32_t OAR1;    /* Own address register 1 */
  volatile uint32_t OAR2;    /* Own address register 2 */
  volatile uint32_t TIMINGR; /* Timing register */
  volatile uint32_t TIMEOUTR;/* Timeout register */
  volatile uint32_t ISR;     /* Interrupt and status register */
  volatile uint32_t ICR;     /* Interrupt clear register */
  volatile uint32_t PECR;    /* Packet error checking register */
  volatile uint32_t RXDR;    /* Receive data register */
  volatile uint32_t TXDR;    /* Transmit data register */
} I2C_TypeDef;

#define I2C1 ((I2C_TypeDef *) I2C1_BASE)
#define I2C2 ((I2C_TypeDef *) I2C2_BASE)
#define I2C3 ((I2C_TypeDef *) I2C3_BASE)
#define I2C4 ((I2C_TypeDef *) I2C4_BASE)

/* ===== Bit definitions for I2C_CR1 register ===== */
#define I2C_CR1_PE           (1U << 0)
#define I2C_CR1_TXIE         (1U << 1)
#define I2C_CR1_RXIE         (1U << 2)
#define I2C_CR1_ADDRIE       (1U << 3)
#define I2C_CR1_NACKIE       (1U << 4)
#define I2C_CR1_STOPIE       (1U << 5)
#define I2C_CR1_TCIE         (1U << 6)
#define I2C_CR1_ERRIE        (1U << 7)

/* ===== Bit definitions for I2C_CR2 register ===== */
#define I2C_CR2_SADD         (0x3FFU << 0)
#define I2C_CR2_RD_WRN       (1U << 10)
#define I2C_CR2_ADD10        (1U << 11)
#define I2C_CR2_HEAD10R      (1U << 12)
#define I2C_CR2_START        (1U << 13)
#define I2C_CR2_STOP         (1U << 14)
#define I2C_CR2_NACK         (1U << 15)
#define I2C_CR2_NBYTES       (0xFFU << 16)
#define I2C_CR2_RELOAD       (1U << 24)
#define I2C_CR2_AUTOEND      (1U << 25)

/* ===== Bit definitions for I2C_ISR register ===== */
#define I2C_ISR_TXE          (1U << 0)
#define I2C_ISR_TXIS         (1U << 1)
#define I2C_ISR_RXNE         (1U << 2)
#define I2C_ISR_ADDR         (1U << 3)
#define I2C_ISR_NACKF        (1U << 4)
#define I2C_ISR_STOPF        (1U << 5)
#define I2C_ISR_TC           (1U << 6)
#define I2C_ISR_TCR          (1U << 7)
#define I2C_ISR_BERR         (1U << 8)
#define I2C_ISR_ARLO         (1U << 9)
#define I2C_ISR_OVR          (1U << 10)
#define I2C_ISR_PECERR       (1U << 11)
#define I2C_ISR_TIMEOUT      (1U << 12)
#define I2C_ISR_ALERT        (1U << 13)
#define I2C_ISR_BUSY         (1U << 15)

/* ===== Bit definitions for I2C_ICR register ===== */
#define I2C_ICR_ADDRCF       (1U << 3)
#define I2C_ICR_NACKCF       (1U << 4)
#define I2C_ICR_STOPCF       (1U << 5)
#define I2C_ICR_BERRCF       (1U << 8)
#define I2C_ICR_ARLOCF       (1U << 9)
#define I2C_ICR_OVRCF        (1U << 10)
#define I2C_ICR_PECCF        (1U << 11)
#define I2C_ICR_TIMOUTCF     (1U << 12)
#define I2C_ICR_ALERTCF      (1U << 13)

/* ===== RCC I2C Clock Enable bits ===== */
#define RCC_APB1ENR1_I2C1EN  (1U << 21)
#define RCC_APB1ENR1_I2C2EN  (1U << 22)
#define RCC_APB1ENR1_I2C3EN  (1U << 23)
#define RCC_APB1ENR2_I2C4EN  (1U << 1)

/* ===========================================================
 * SPI (Serial Peripheral Interface)
 * =========================================================== */
#define SPI1_BASE   (APB2PERIPH_BASE + 0x3000UL)
#define SPI2_BASE   (APB1PERIPH_BASE + 0x3800UL)
#define SPI3_BASE   (APB1PERIPH_BASE + 0x3C00UL)

/* SPI register structure */
typedef struct
{
  volatile uint32_t CR1;     /* Control register 1,      Address offset: 0x00 */
  volatile uint32_t CR2;     /* Control register 2,      Address offset: 0x04 */
  volatile uint32_t SR;      /* Status register,         Address offset: 0x08 */
  volatile uint32_t DR;      /* Data register,           Address offset: 0x0C */
  volatile uint32_t CRCPR;   /* CRC polynomial register, Address offset: 0x10 */
  volatile uint32_t RXCRCR;  /* RX CRC register,         Address offset: 0x14 */
  volatile uint32_t TXCRCR;  /* TX CRC register,         Address offset: 0x18 */
  volatile uint32_t I2SCFGR; /* I2S configuration reg.,  Address offset: 0x1C */
  volatile uint32_t I2SPR;   /* I2S prescaler register,  Address offset: 0x20 */
} SPI_TypeDef;

/* SPI peripheral instances */
#define SPI1 ((SPI_TypeDef *) SPI1_BASE)
#define SPI2 ((SPI_TypeDef *) SPI2_BASE)
#define SPI3 ((SPI_TypeDef *) SPI3_BASE)

/* ===========================================================
 * RCC bits for SPI clock enable
 * =========================================================== */
#define RCC_APB2ENR_SPI1EN   (1U << 12)
#define RCC_APB1ENR1_SPI2EN  (1U << 14)
#define RCC_APB1ENR1_SPI3EN  (1U << 15)

/* ===========================================================
 * SPI_CR1 bit definitions
 * =========================================================== */
#define SPI_CR1_CPHA_Pos     (0U)
#define SPI_CR1_CPHA_Msk     (1U << SPI_CR1_CPHA_Pos)
#define SPI_CR1_CPOL_Pos     (1U)
#define SPI_CR1_CPOL_Msk     (1U << SPI_CR1_CPOL_Pos)
#define SPI_CR1_MSTR_Pos     (2U)
#define SPI_CR1_MSTR_Msk     (1U << SPI_CR1_MSTR_Pos)
#define SPI_CR1_BR_Pos       (3U)
#define SPI_CR1_BR_Msk       (0x7U << SPI_CR1_BR_Pos)
#define SPI_CR1_SPE_Pos      (6U)
#define SPI_CR1_SPE_Msk      (1U << SPI_CR1_SPE_Pos)
#define SPI_CR1_LSBFIRST_Pos (7U)
#define SPI_CR1_LSBFIRST_Msk (1U << SPI_CR1_LSBFIRST_Pos)
#define SPI_CR1_SSI_Pos      (8U)
#define SPI_CR1_SSI_Msk      (1U << SPI_CR1_SSI_Pos)
#define SPI_CR1_SSM_Pos      (9U)
#define SPI_CR1_SSM_Msk      (1U << SPI_CR1_SSM_Pos)

/* ===========================================================
 * SPI_CR2 bit definitions
 * =========================================================== */
#define SPI_CR2_RXDMAEN      (1U << 0)
#define SPI_CR2_TXDMAEN      (1U << 1)
#define SPI_CR2_SSOE         (1U << 2)
#define SPI_CR2_NSSP         (1U << 3)
#define SPI_CR2_FRF          (1U << 4)
#define SPI_CR2_ERRIE        (1U << 5)
#define SPI_CR2_RXNEIE       (1U << 6)
#define SPI_CR2_TXEIE        (1U << 7)
#define SPI_CR2_DS_Pos       (8U)
#define SPI_CR2_DS_Msk       (0xFU << SPI_CR2_DS_Pos)
#define SPI_CR2_FRXTH        (1U << 12)
#define SPI_CR2_LDMA_RX      (1U << 13)
#define SPI_CR2_LDMA_TX      (1U << 14)

/* ===========================================================
 * SPI_SR bit definitions
 * =========================================================== */
#define SPI_SR_RXNE          (1U << 0)
#define SPI_SR_TXE           (1U << 1)
#define SPI_SR_CHSIDE        (1U << 2)
#define SPI_SR_UDR           (1U << 3)
#define SPI_SR_CRCERR        (1U << 4)
#define SPI_SR_MODF          (1U << 5)
#define SPI_SR_OVR           (1U << 6)
#define SPI_SR_BSY           (1U << 7)
#define SPI_SR_FRE           (1U << 8)
#define SPI_SR_FRLVL_Pos     (9U)
#define SPI_SR_FRLVL_Msk     (3U << SPI_SR_FRLVL_Pos)
#define SPI_SR_FTLVL_Pos     (11U)
#define SPI_SR_FTLVL_Msk     (3U << SPI_SR_FTLVL_Pos)

#endif /* STM32L476XX_H */
