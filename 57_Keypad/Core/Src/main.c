/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : STM32 Keypad UART Example
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <string.h>

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

/* Keypad definitions (4x4 matrix) */
#define ROW1_PIN GPIO_PIN_0
#define ROW2_PIN GPIO_PIN_1
#define ROW3_PIN GPIO_PIN_2
#define ROW4_PIN GPIO_PIN_3
#define ROW_GPIO_PORT GPIOB

#define COL1_PIN GPIO_PIN_4
#define COL2_PIN GPIO_PIN_5
#define COL3_PIN GPIO_PIN_6
#define COL4_PIN GPIO_PIN_7
#define COL_GPIO_PORT GPIOB

char keys[4][4] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

/* Message to send over UART */
char msg[] = "pressed...\r\n";

/* Function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);

/* USER CODE BEGIN 0 */
/* Scan 4x4 keypad matrix, return pressed key or 0 */
char scanKeypad(void)
{
    // Set all columns HIGH
    HAL_GPIO_WritePin(COL_GPIO_PORT, COL1_PIN|COL2_PIN|COL3_PIN|COL4_PIN, GPIO_PIN_SET);

    for (int row=0; row<4; row++)
    {
        uint16_t rowPin = (ROW1_PIN << row);
        HAL_GPIO_WritePin(ROW_GPIO_PORT, rowPin, GPIO_PIN_RESET); // Set current row LOW

        for (int col=0; col<4; col++)
        {
            uint16_t colPin = (COL1_PIN << col);
            if (HAL_GPIO_ReadPin(COL_GPIO_PORT, colPin) == GPIO_PIN_RESET)
            {
                HAL_GPIO_WritePin(ROW_GPIO_PORT, rowPin, GPIO_PIN_SET); // Reset row
                return keys[row][col]; // Return pressed key
            }
        }

        HAL_GPIO_WritePin(ROW_GPIO_PORT, rowPin, GPIO_PIN_SET); // Reset row
    }

    return 0; // No key pressed
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
    /* MCU Configuration--------------------------------------------------------*/
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_USART2_UART_Init();

    /* Infinite loop */
    while (1)
    {
        char key = scanKeypad();
        if (key != 0)
        {
            HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
            HAL_Delay(200); // debounce
        }
    }
}

/* System Clock Configuration */
void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
        Error_Handler();

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
    RCC_OscInitStruct.PLL.PLLM = 1;
    RCC_OscInitStruct.PLL.PLLN = 10;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
    RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
    RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
        Error_Handler();

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                                |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
        Error_Handler();
}

/* USART2 init function */
static void MX_USART2_UART_Init(void)
{
    huart2.Instance = USART2;
    huart2.Init.BaudRate = 115200;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;
    huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
    huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
    if (HAL_UART_Init(&huart2) != HAL_OK)
        Error_Handler();
}

/* GPIO init function */
static void MX_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOB_CLK_ENABLE();

    // Columns as output
    GPIO_InitStruct.Pin = COL1_PIN|COL2_PIN|COL3_PIN|COL4_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(COL_GPIO_PORT, &GPIO_InitStruct);

    // Rows as input with pull-up
    GPIO_InitStruct.Pin = ROW1_PIN|ROW2_PIN|ROW3_PIN|ROW4_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(ROW_GPIO_PORT, &GPIO_InitStruct);
}

/* Error Handler */
void Error_Handler(void)
{
    __disable_irq();
    while (1) {}
}
