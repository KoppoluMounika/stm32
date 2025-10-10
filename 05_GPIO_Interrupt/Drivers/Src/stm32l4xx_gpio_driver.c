#include "stm32l4xx_gpio_driver.h"

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if (EnorDi == ENABLE)
	{
		if (pGPIOx == GPIOA) RCC->AHB2ENR |= (1 << 0);
		else if (pGPIOx == GPIOB) RCC->AHB2ENR |= (1 << 1);
		else if (pGPIOx == GPIOC) RCC->AHB2ENR |= (1 << 2);
		else if (pGPIOx == GPIOD) RCC->AHB2ENR |= (1 << 3);
		else if (pGPIOx == GPIOE) RCC->AHB2ENR |= (1 << 4);
		else if (pGPIOx == GPIOH) RCC->AHB2ENR |= (1 << 7);
	}
	else
	{
		// disable if needed
	}
}

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp = 0;

	// Enable peripheral clock
	GPIO_PeriClockControl(pGPIOHandle->pGPIOx, ENABLE);

	// Configure mode
	if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER |= temp;
	}
	else
	{
		// Interrupt mode
		if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FT)
		{
			EXTI->FTSR1 |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			EXTI->RTSR1 &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}
		else if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RT)
		{
			EXTI->RTSR1 |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			EXTI->FTSR1 &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}
		else if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RFT)
		{
			EXTI->RTSR1 |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			EXTI->FTSR1 |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}

		// Configure GPIO port in SYSCFG EXTICR
		uint8_t temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 4;
		uint8_t temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 4;
		uint8_t portcode = (uint8_t)(GPIO_BASEADDR_TO_CODE(pGPIOHandle->pGPIOx));
		SYSCFG->EXTICR[temp1] &= ~(0xF << (4 * temp2));
		SYSCFG->EXTICR[temp1] |= (portcode << (4 * temp2));

		// Enable interrupt delivery in EXTI IMR
		EXTI->IMR1 |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	}

	// Output type
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER |= temp;

	// Speed
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;

	// PUPD
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR |= temp;
}


void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t GPIO_PinNumber, uint32_t Value)
{
	if (Value == 1)
		pGPIOx->ODR |= (1 << GPIO_PinNumber);
	else
		pGPIOx->ODR &= ~(1 << GPIO_PinNumber);
}

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t GPIO_PinNumber)
{
	pGPIOx->ODR ^= (1 << GPIO_PinNumber);
}

void GPIO_IRQ_interrupt_Config(uint8_t IRQNumber, uint8_t EnorDi)
{
	if (EnorDi == ENABLE)
	{
		if (IRQNumber <= 31)
			*NVIC_ISER0 |= (1 << IRQNumber);
		else if (IRQNumber < 64)
			*NVIC_ISER1 |= (1 << (IRQNumber % 32));
	}
	else
	{
		if (IRQNumber <= 31)
			*NVIC_ICER0 |= (1 << IRQNumber);
		else if (IRQNumber < 64)
			*NVIC_ICER1 |= (1 << (IRQNumber % 32));
	}
}

void GPIO_IRQ_priority_Config(uint8_t IRQNumber, uint8_t priority)
{
	uint8_t iprx = IRQNumber / 4;
	uint8_t iprx_section = IRQNumber % 4;
	uint8_t shift_amount = (8 * iprx_section) + (8 - NO_PR_BITS_IMPLEMENTED);

	*(NVIC_PR_BASE_ADDR + iprx) |= (priority << shift_amount);
}

void GPIO_IRQHandling(uint8_t GPIO_PinNumber)
{
	if (EXTI->PR1 & (1 << GPIO_PinNumber))
	{
		EXTI->PR1 |= (1 << GPIO_PinNumber); // clear pending
	}
}
