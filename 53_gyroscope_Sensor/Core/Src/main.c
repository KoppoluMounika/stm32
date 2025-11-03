#include <stdint.h>
#include <stdio.h>
#define RCC_BASE        0x40021000UL
#define GPIOB_BASE      0x48000400UL
#define I2C1_BASE       0x40005400UL
#define USART2_BASE     0x40004400UL
#define RCC_AHB2ENR     (*(volatile uint32_t*)(RCC_BASE + 0x4C))
#define RCC_APB1ENR1    (*(volatile uint32_t*)(RCC_BASE + 0x58))
#define GPIOB_MODER     (*(volatile uint32_t*)(GPIOB_BASE + 0x00))
#define GPIOB_AFRL      (*(volatile uint32_t*)(GPIOB_BASE + 0x20))
#define GPIOB_OTYPER    (*(volatile uint32_t*)(GPIOB_BASE + 0x04))
#define GPIOB_PUPDR     (*(volatile uint32_t*)(GPIOB_BASE + 0x0C))
#define I2C1_CR1        (*(volatile uint32_t*)(I2C1_BASE + 0x00))
#define I2C1_TIMINGR    (*(volatile uint32_t*)(I2C1_BASE + 0x10))
#define I2C1_ISR        (*(volatile uint32_t*)(I2C1_BASE + 0x18))
#define I2C1_ICR        (*(volatile uint32_t*)(I2C1_BASE + 0x1C))
#define I2C1_TXDR       (*(volatile uint32_t*)(I2C1_BASE + 0x28))
#define I2C1_CR2        (*(volatile uint32_t*)(I2C1_BASE + 0x04))
#define USART2_CR1      (*(volatile uint32_t*)(USART2_BASE + 0x00))
#define USART2_BRR      (*(volatile uint32_t*)(USART2_BASE + 0x0C))
#define USART2_ISR      (*(volatile uint32_t*)(USART2_BASE + 0x1C))
#define USART2_TDR      (*(volatile uint32_t*)(USART2_BASE + 0x28))

static void delay_ms(uint32_t ms){for(uint32_t i=0;i<ms*4000;i++)__asm__("nop");}
static void uart2_init(void){
    RCC_AHB2ENR|=(1<<0); RCC_APB1ENR1|=(1<<17);
    (*(volatile uint32_t*)(0x48000000+0x00))&=~(3<<(2*2));
    (*(volatile uint32_t*)(0x48000000+0x00))|=(2<<(2*2));
    (*(volatile uint32_t*)(0x48000000+0x20))|=(7<<(4*2));
    USART2_BRR=4000000/115200; USART2_CR1=(1<<3)|(1<<0);
}
static void uart2_write(char c){while(!(USART2_ISR&(1<<7)));USART2_TDR=c;}
static void uart2_print(char*s){while(*s)uart2_write(*s++);}
static void i2c1_init(void){
    RCC_AHB2ENR|=(1<<1); RCC_APB1ENR1|=(1<<21);
    GPIOB_MODER&=~((3<<(8*2))|(3<<(9*2)));
    GPIOB_MODER|=((2<<(8*2))|(2<<(9*2)));
    GPIOB_AFRL|=(4<<((8-8)*4))|(4<<((9-8)*4));
    GPIOB_OTYPER|=(1<<8)|(1<<9);
    GPIOB_PUPDR|=(1<<(8*2))|(1<<(9*2));
    I2C1_CR1&=~(1<<0);
    I2C1_TIMINGR=0x20303E5D;
    I2C1_CR1|=(1<<0);
}
int main(void){
    uart2_init(); i2c1_init(); delay_ms(100);
    uart2_print("\r\nScanning I2C bus...\r\n");
    char msg[32];
    for(uint8_t addr=1; addr<128; addr++){
        I2C1_ICR=0x3F38;
        I2C1_CR2=(addr<<1)|(1<<16)|(1<<13);
        int timeout=100000;
        while(!(I2C1_ISR&(1<<6)) && --timeout);
        I2C1_CR2|=(1<<14);
        if(I2C1_ISR&(1<<4)) {
            snprintf(msg,sizeof(msg),"Found device at 0x%02X\r\n",addr);
            uart2_print(msg);
        }
        delay_ms(10);
    }
    uart2_print("Scan complete.\r\n");
    while(1);
}
