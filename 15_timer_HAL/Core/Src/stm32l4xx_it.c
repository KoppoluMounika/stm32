/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32l4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  */
/* USER CODE END Header */

#include "main.h"
#include "stm32l4xx_it.h"
#include "stm32l4xx_hal_tim.h"

extern TIM_HandleTypeDef htim2;

/******************************************************************************/
/* Cortex-M4 Processor Interruption and Exception Handlers                    */
/******************************************************************************/

void SysTick_Handler(void)
{
    HAL_IncTick();
}

/******************************************************************************/
/* STM32L4xx Peripheral Interrupt Handlers                                    */
/******************************************************************************/

void TIM2_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&htim2);
}

/* USER CODE BEGIN 1 */
/* USER CODE END 1 */
