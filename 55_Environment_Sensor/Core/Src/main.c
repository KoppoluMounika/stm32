#include <stdint.h>
#include <stdio.h>

#define RCC_BASE        0x40021000UL
#define GPIOA_BASE      0x48000000UL
#define GPIOB_BASE      0x48000400UL
#define USART2_BASE     0x40004400UL
#define I2C1_BASE       0x40005400UL

#define RCC_AHB2ENR     (*(volatile uint32_t*)(RCC_BASE + 0x4C))
#define RCC_APB1ENR1    (*(volatile uint32_t*)(RCC_BASE + 0x58))
#define GPIOA_MODER     (*(volatile uint32_t*)(GPIOA_BASE + 0x00))
#define GPIOA_AFRL      (*(volatile uint32_t*)(GPIOA_BASE + 0x20))
#define GPIOB_MODER     (*(volatile uint32_t*)(GPIOB_BASE + 0x00))
#define GPIOB_OTYPER    (*(volatile uint32_t*)(GPIOB_BASE + 0x04))
#define GPIOB_OSPEEDR   (*(volatile uint32_t*)(GPIOB_BASE + 0x08))
#define GPIOB_PUPDR     (*(volatile uint32_t*)(GPIOB_BASE + 0x0C))
#define GPIOB_AFRH      (*(volatile uint32_t*)(GPIOB_BASE + 0x24))
#define USART2_CR1      (*(volatile uint32_t*)(USART2_BASE + 0x00))
#define USART2_BRR      (*(volatile uint32_t*)(USART2_BASE + 0x0C))
#define USART2_ISR      (*(volatile uint32_t*)(USART2_BASE + 0x1C))
#define USART2_TDR      (*(volatile uint32_t*)(USART2_BASE + 0x28))
#define I2C1_CR1        (*(volatile uint32_t*)(I2C1_BASE + 0x00))
#define I2C1_CR2        (*(volatile uint32_t*)(I2C1_BASE + 0x04))
#define I2C1_TIMINGR    (*(volatile uint32_t*)(I2C1_BASE + 0x10))
#define I2C1_ISR        (*(volatile uint32_t*)(I2C1_BASE + 0x18))
#define I2C1_TXDR       (*(volatile uint32_t*)(I2C1_BASE + 0x28))
#define I2C1_RXDR       (*(volatile uint32_t*)(I2C1_BASE + 0x24))

#define BME280_ADDR  0x76

static void delay_ms(uint32_t ms){ for(uint32_t i=0;i<ms*4000;i++) __asm__("nop"); }

static void uart2_init(void){
    RCC_AHB2ENR |= (1<<0);
    RCC_APB1ENR1 |= (1<<17);
    GPIOA_MODER &= ~(3<<(2*2));
    GPIOA_MODER |=  (2<<(2*2));
    GPIOA_AFRL  |=  (7<<(4*2));
    USART2_BRR = 4000000/115200;
    USART2_CR1 = (1<<3)|(1<<0);
}
static void uart2_write(char c){ while(!(USART2_ISR & (1<<7))); USART2_TDR = c; }
static void uart2_print(char *s){ while(*s) uart2_write(*s++); }

static void i2c1_init(void){
    RCC_AHB2ENR |= (1<<1);
    RCC_APB1ENR1 |= (1<<21);
    GPIOB_MODER &= ~((3<<(8*2))|(3<<(9*2)));
    GPIOB_MODER |=  ((2<<(8*2))|(2<<(9*2)));
    GPIOB_AFRH  |=  (4<<(0*4))|(4<<(1*4));
    GPIOB_OTYPER |= (1<<8)|(1<<9);
    GPIOB_OSPEEDR |= (3<<(8*2))|(3<<(9*2));
    GPIOB_PUPDR  |= (1<<(8*2))|(1<<(9*2));
    I2C1_CR1 &= ~(1<<0);
    I2C1_TIMINGR = 0x00303D5B;
    I2C1_CR1 |= (1<<0);
}

static void i2c1_write_reg(uint8_t addr, uint8_t reg, uint8_t data){
    I2C1_CR2 = (addr<<1)|(1<<16);
    I2C1_CR2 |= (1<<13);
    while(!(I2C1_ISR & (1<<1)));
    I2C1_TXDR = reg;
    while(!(I2C1_ISR & (1<<6)));
    I2C1_CR2 = (addr<<1)|(1<<16);
    I2C1_TXDR = data;
    while(!(I2C1_ISR & (1<<6)));
}

static uint8_t i2c1_read_reg(uint8_t addr, uint8_t reg){
    I2C1_CR2 = (addr<<1)|(1<<16);
    I2C1_CR2 |= (1<<13);
    while(!(I2C1_ISR & (1<<1)));
    I2C1_TXDR = reg;
    while(!(I2C1_ISR & (1<<6)));
    I2C1_CR2 = (addr<<1)|(1<<10)|(1<<16);
    I2C1_CR2 |= (1<<13);
    while(!(I2C1_ISR & (1<<2)));
    return I2C1_RXDR;
}

static void bme280_init(void){
    uint8_t id = i2c1_read_reg(BME280_ADDR, 0xD0);
    if(id != 0x60){ uart2_print("BME280 not found\r\n"); return; }
    i2c1_write_reg(BME280_ADDR, 0xF2, 0x01);
    i2c1_write_reg(BME280_ADDR, 0xF4, 0x27);
}

static void bme280_read_data(void){
    int32_t temp_raw = (i2c1_read_reg(BME280_ADDR,0xFA)<<12) |
                       (i2c1_read_reg(BME280_ADDR,0xFB)<<4) |
                       (i2c1_read_reg(BME280_ADDR,0xFC)>>4);
    int32_t pres_raw = (i2c1_read_reg(BME280_ADDR,0xF7)<<12) |
                       (i2c1_read_reg(BME280_ADDR,0xF8)<<4) |
                       (i2c1_read_reg(BME280_ADDR,0xF9)>>4);
    int32_t hum_raw  = (i2c1_read_reg(BME280_ADDR,0xFD)<<8) |
                       (i2c1_read_reg(BME280_ADDR,0xFE));

    int temp = temp_raw/5120;
    int pres = pres_raw/25600;
    int hum  = hum_raw/1024;

    char buf[80];
    snprintf(buf,sizeof(buf),"TEMP:%dC  PRESS:%dhPa  HUMID:%d%%RH\r\n",temp,pres,hum);
    uart2_print(buf);
}

int main(void){
    uart2_init();
    i2c1_init();
    delay_ms(100);
    bme280_init();
    uart2_print("BME280 Real Sensor Readings\r\n");

    while(1){
        bme280_read_data();
        delay_ms(1000);
    }
}
