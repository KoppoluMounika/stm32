#ifndef ADC_H_
#define ADC_H_

#include "stm32l4xx.h"
#include <stdint.h>

void pa1_adc1_init(void);
void adc_start(void);
uint32_t adc_read(void);

#endif
