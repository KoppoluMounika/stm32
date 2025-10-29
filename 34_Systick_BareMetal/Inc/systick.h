#ifndef SYSTICK_H_
#define SYSTICK_H_

#include <stdint.h>

void systick_init(void);
void systick_delay_ms(uint32_t delay);

#endif
