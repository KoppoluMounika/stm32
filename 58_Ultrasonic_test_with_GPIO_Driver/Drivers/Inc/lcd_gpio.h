/*
 * lcd.h
 *
 *  Created on: Oct 16, 2025
 *      Author: KOPPOLU MOUNIKA
 */

#ifndef LCD_GPIO_H
#define LCD_GPIO_H

#include "stm32l476xx.h"
#include <stdint.h>

#define LCD_PORTA GPIOA
#define LCD_PORTB GPIOB

#define LCD_RS_PIN 8   // PA8
#define LCD_EN_PIN 9   // PA9
#define LCD_D4_PIN 3   // PB3
#define LCD_D5_PIN 2   // PB2
#define LCD_D6_PIN 1   // PB1
#define LCD_D7_PIN 0   // PB0

void LCD_Init(void);
void LCD_SendCommand(uint8_t cmd);
void LCD_SendData(uint8_t data);
void LCD_Clear(void);
void LCD_Print(char *str);

#endif

