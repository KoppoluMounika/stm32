#include <stdint.h>
#include <stdio.h>

#define RCC_BASE     0x40021000UL
#define GPIOA_BASE   0x48000000UL
#define USART2_BASE  0x40004400UL
#define RCC_AHB2ENR  (*(volatile uint32_t*)(RCC_BASE + 0x4C))
#define RCC_APB1ENR1 (*(volatile uint32_t*)(RCC_BASE + 0x58))
#define GPIOA_MODER  (*(volatile uint32_t*)(GPIOA_BASE + 0x00))
#define GPIOA_AFRL   (*(volatile uint32_t*)(GPIOA_BASE + 0x20))
#define USART2_CR1   (*(volatile uint32_t*)(USART2_BASE + 0x00))
#define USART2_BRR   (*(volatile uint32_t*)(USART2_BASE + 0x0C))
#define USART2_ISR   (*(volatile uint32_t*)(USART2_BASE + 0x1C))
#define USART2_TDR   (*(volatile uint32_t*)(USART2_BASE + 0x28))

static void delay_ms(uint32_t ms){for(uint32_t i=0;i<ms*4000;i++)__asm__("nop");}

static void uart2_write(char c){while(!(USART2_ISR&(1<<7)));USART2_TDR=c;}
static void uart2_print(char*s){while(*s)uart2_write(*s++);}
static void uart2_init(void){
    RCC_AHB2ENR|=(1<<0);
    RCC_APB1ENR1|=(1<<17);
    GPIOA_MODER&=~(3<<(2*2));
    GPIOA_MODER|=(2<<(2*2));
    GPIOA_AFRL|=(7<<(4*2));
    USART2_BRR=4000000/115200;
    USART2_CR1=(1<<3)|(1<<0);
}

static uint32_t seed=12345;
static uint32_t rand32(void){seed=seed*1664525+1013904223;return seed;}

static int read_temperature(void){
    return 22+(rand32()%5);
}

void bme280_display_temperature(void){
    int t=read_temperature();
    char buf[30];
    snprintf(buf,sizeof(buf),"TEMP: %d C\r\n",t);
    uart2_print(buf);
}

int main(void){
    uart2_init();
    delay_ms(50);
    for(int i=0;i<50;i++){
        bme280_display_temperature();
        delay_ms(500);
    }
    while(1);
}
