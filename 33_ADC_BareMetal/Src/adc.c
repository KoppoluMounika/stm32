#include "adc.h"

#define GPIOAEN     (1U << 0)
#define ADC1EN      (1U << 13)

void pa1_adc1_init(void)
{
    /************** Configure PA1 as analog ****************/
    RCC->AHB2ENR |= GPIOAEN;            // Enable GPIOA clock
    GPIOA->MODER |= (3U << 2);          // Analog mode for PA1
    GPIOA->ASCR  |= (1U << 1);          // Connect analog switch

    /************** Enable ADC1 clock ****************/
    RCC->AHB2ENR |= ADC1EN;

    /************** Exit deep power-down mode ****************/
    ADC1->CR &= ~ADC_CR_DEEPPWD;        // Disable deep power down
    ADC1->CR |=  ADC_CR_ADVREGEN;       // Enable voltage regulator
    for (volatile uint32_t i = 0; i < 1000; i++); // wait a bit

    /************** Calibrate ADC ****************/
    ADC1->CR &= ~ADC_CR_ADEN;           // Make sure ADC is disabled
    ADC1->CR |= ADC_CR_ADCAL;           // Start calibration
    while (ADC1->CR & ADC_CR_ADCAL);    // Wait for calibration to finish

    /************** Enable ADC ****************/
    ADC1->ISR |= ADC_ISR_ADRDY;         // Clear ready flag
    ADC1->CR |= ADC_CR_ADEN;            // Enable ADC
    while (!(ADC1->ISR & ADC_ISR_ADRDY));

    /************** Configure ADC channel 6 (PA1) ****************/
    ADC1->SQR1 &= ~ADC_SQR1_L;          // 1 conversion
    ADC1->SQR1 &= ~ADC_SQR1_SQ1;
    ADC1->SQR1 |= (6U << 0);            // SQ1 = channel 6

    /************** Sampling time ****************/
    ADC1->SMPR1 &= ~(7U << 18);
    ADC1->SMPR1 |=  (2U << 18);         // 12.5 ADC cycles

    /************** Enable continuous conversion mode ****************/
    ADC1->CFGR |= ADC_CFGR_CONT;
}

void adc_start(void)
{
    ADC1->CR |= ADC_CR_ADSTART;
}

uint32_t adc_read(void)
{
    while (!(ADC1->ISR & ADC_ISR_EOC)); // Wait for end of conversion
    return ADC1->DR;
}
