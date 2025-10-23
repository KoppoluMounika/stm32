#include "main.h"
#include "spi.h"
#include "gpio.h"
#include <string.h>

void SystemClock_Config(void);
void Error_Handler(void);

uint8_t tx_buffer[5] = {'H','E','L','L','O'};
uint8_t rx_buffer[5];

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_SPI1_Init();

  while (1)
  {
    if (HAL_SPI_TransmitReceive(&hspi1, tx_buffer, rx_buffer, sizeof(tx_buffer), HAL_MAX_DELAY) == HAL_OK)
    {
      if (memcmp(tx_buffer, rx_buffer, sizeof(tx_buffer)) == 0)
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
      HAL_Delay(500);
    }
  }
}
