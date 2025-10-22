#include "lcd.h"
#include <stdint.h>

// Simple delay function (approximate)
void delay_ms(uint32_t ms)
{
    for(uint32_t i = 0; i < ms * 4000; i++); // adjust for your clock
}

void LCD_EnablePulse(void)
{
    GPIO_WriteToOutputPin(LCD_GPIO_PORT, EN_PIN, 1);
    delay_ms(1);
    GPIO_WriteToOutputPin(LCD_GPIO_PORT, EN_PIN, 0);
    delay_ms(1);
}

void LCD_Command(uint8_t cmd)
{
    GPIO_WriteToOutputPin(LCD_GPIO_PORT, RS_PIN, 0); // RS = 0 for command

    // High nibble
    GPIO_WriteToOutputPin(LCD_GPIO_PORT, D4_PIN, (cmd >> 4) & 0x01);
    GPIO_WriteToOutputPin(LCD_GPIO_PORT, D5_PIN, (cmd >> 5) & 0x01);
    GPIO_WriteToOutputPin(LCD_GPIO_PORT, D6_PIN, (cmd >> 6) & 0x01);
    GPIO_WriteToOutputPin(LCD_GPIO_PORT, D7_PIN, (cmd >> 7) & 0x01);
    LCD_EnablePulse();

    // Low nibble
    GPIO_WriteToOutputPin(LCD_GPIO_PORT, D4_PIN, (cmd >> 0) & 0x01);
    GPIO_WriteToOutputPin(LCD_GPIO_PORT, D5_PIN, (cmd >> 1) & 0x01);
    GPIO_WriteToOutputPin(LCD_GPIO_PORT, D6_PIN, (cmd >> 2) & 0x01);
    GPIO_WriteToOutputPin(LCD_GPIO_PORT, D7_PIN, (cmd >> 3) & 0x01);
    LCD_EnablePulse();

    delay_ms(2); // wait for command to execute
}

void LCD_SendChar(char data)
{
    GPIO_WriteToOutputPin(LCD_GPIO_PORT, RS_PIN, 1); // RS = 1 for data

    // High nibble
    GPIO_WriteToOutputPin(LCD_GPIO_PORT, D4_PIN, (data >> 4) & 0x01);
    GPIO_WriteToOutputPin(LCD_GPIO_PORT, D5_PIN, (data >> 5) & 0x01);
    GPIO_WriteToOutputPin(LCD_GPIO_PORT, D6_PIN, (data >> 6) & 0x01);
    GPIO_WriteToOutputPin(LCD_GPIO_PORT, D7_PIN, (data >> 7) & 0x01);
    LCD_EnablePulse();

    // Low nibble
    GPIO_WriteToOutputPin(LCD_GPIO_PORT, D4_PIN, (data >> 0) & 0x01);
    GPIO_WriteToOutputPin(LCD_GPIO_PORT, D5_PIN, (data >> 1) & 0x01);
    GPIO_WriteToOutputPin(LCD_GPIO_PORT, D6_PIN, (data >> 2) & 0x01);
    GPIO_WriteToOutputPin(LCD_GPIO_PORT, D7_PIN, (data >> 3) & 0x01);
    LCD_EnablePulse();

    delay_ms(2);
}

void LCD_SendString(char *str)
{
    while(*str)
        LCD_SendChar(*str++);
}

void LCD_Init(void)
{
    GPIO_PeriClockControl(LCD_GPIO_PORT, ENABLE);

    // Set PB0-PB5 as output
    for(int i=0;i<=5;i++)
    {
        LCD_GPIO_PORT->MODER &= ~(0x3 << (i*2)); // clear mode
        LCD_GPIO_PORT->MODER |=  (0x1 << (i*2)); // output
    }

    delay_ms(20); // Wait for LCD to power up

    LCD_Command(0x02); // 4-bit mode
    LCD_Command(0x28); // 2 lines, 5x7
    LCD_Command(0x0C); // Display on, cursor off
    LCD_Command(0x06); // Entry mode increment
    LCD_Command(0x01); // Clear display
}
