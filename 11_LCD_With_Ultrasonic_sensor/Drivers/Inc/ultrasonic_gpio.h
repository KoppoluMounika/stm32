/*
 * ultrasonic.h
 *
 *  Created on: Oct 16, 2025
 *      Author: KOPPOLU MOUNIKA
 */

#ifndef ULTRASONIC_GPIO_H
#define ULTRASONIC_GPIO_H

#include "stm32l476xx.h"

#define TRIG_PORT GPIOB
#define ECHO_PORT GPIOB
#define TRIG_PIN 5
#define ECHO_PIN 4

void Ultrasonic_Init(void);
uint32_t Ultrasonic_Read(void);

#endif

