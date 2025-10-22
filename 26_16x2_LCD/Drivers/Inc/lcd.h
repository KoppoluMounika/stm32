#ifndef LCD_H
#define LCD_H

#include "stm32l4xx_gpio_driver.h"

// LCD Pins (adjust according to your wiring)
#define RS_PIN  0   // PB0
#define EN_PIN  1   // PB1
#define D4_PIN  2   // PB2
#define D5_PIN  3   // PB3
#define D6_PIN  4   // PB4
#define D7_PIN  5   // PB5
#define LCD_GPIO_PORT GPIOB

void LCD_Init(void);
void LCD_Command(uint8_t cmd);
void LCD_SendChar(char data);
void LCD_SendString(char *str);
void LCD_EnablePulse(void);

#endif
