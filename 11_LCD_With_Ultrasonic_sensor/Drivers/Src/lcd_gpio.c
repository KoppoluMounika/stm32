/*
 * lcd.c
 *
 *  Created on: Oct 16, 2025
 *      Author: KOPPOLU MOUNIKA
 */


#include "lcd_gpio.h"
#include <string.h>
#include "stm32l476xx.h"

// ---- lcd_gpio.c ----
void delay_ms(uint32_t ms)
{
    for (uint32_t i = 0; i < ms * 4000; i++)
        __asm volatile ("nop");
}


static void GPIO_WritePin(GPIO_TypeDef *port, uint8_t pin, uint8_t value) {
    if(value)
        port->ODR |= (1 << pin);
    else
        port->ODR &= ~(1 << pin);
}

static void LCD_Send4Bits(uint8_t data) {
    GPIO_WritePin(LCD_PORTB, LCD_D4_PIN, (data >> 0) & 1);
    GPIO_WritePin(LCD_PORTB, LCD_D5_PIN, (data >> 1) & 1);
    GPIO_WritePin(LCD_PORTB, LCD_D6_PIN, (data >> 2) & 1);
    GPIO_WritePin(LCD_PORTB, LCD_D7_PIN, (data >> 3) & 1);

    GPIO_WritePin(LCD_PORTA, LCD_EN_PIN, 1);
    delay_ms(1);
    GPIO_WritePin(LCD_PORTA, LCD_EN_PIN, 0);
    delay_ms(1);
}

void LCD_SendCommand(uint8_t cmd) {
    GPIO_WritePin(LCD_PORTA, LCD_RS_PIN, 0);
    LCD_Send4Bits(cmd >> 4);
    LCD_Send4Bits(cmd & 0x0F);
    delay_ms(2);
}

void LCD_SendData(uint8_t data) {
    GPIO_WritePin(LCD_PORTA, LCD_RS_PIN, 1);
    LCD_Send4Bits(data >> 4);
    LCD_Send4Bits(data & 0x0F);
    delay_ms(2);
}

void LCD_Init(void) {
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN | RCC_AHB2ENR_GPIOBEN;

    // PA8, PA9 output
    LCD_PORTA->MODER &= ~((3 << (2 * LCD_RS_PIN)) | (3 << (2 * LCD_EN_PIN)));
    LCD_PORTA->MODER |=  ((1 << (2 * LCD_RS_PIN)) | (1 << (2 * LCD_EN_PIN)));

    // PB0–PB3 output
    for (int i = 0; i <= 3; i++) {
        LCD_PORTB->MODER &= ~(3 << (2 * i));
        LCD_PORTB->MODER |=  (1 << (2 * i));
    }

    delay_ms(20);
    LCD_Send4Bits(0x03);
    delay_ms(5);
    LCD_Send4Bits(0x03);
    delay_ms(1);
    LCD_Send4Bits(0x02); // 4-bit mode

    LCD_SendCommand(0x28); // 4-bit, 2 lines
    LCD_SendCommand(0x0C); // Display ON, Cursor OFF
    LCD_SendCommand(0x06); // Entry mode
    LCD_SendCommand(0x01); // Clear
    delay_ms(5);

    // Show "READY" immediately
    LCD_Print("READY");
}

void LCD_Clear(void) {
    LCD_SendCommand(0x01);
    delay_ms(2);
}

void LCD_Print(char *str) {
    while (*str) {
        LCD_SendData(*str++);
    }
}
