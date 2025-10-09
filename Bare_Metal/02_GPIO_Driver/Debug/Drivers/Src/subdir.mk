################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Src/stm32l4_gpio_driver.c 

OBJS += \
./Drivers/Src/stm32l4_gpio_driver.o 

C_DEPS += \
./Drivers/Src/stm32l4_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Src/%.o Drivers/Src/%.su Drivers/Src/%.cyclo: ../Drivers/Src/%.c Drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DNUCLEO_L476RG -DSTM32L476RGTx -c -IDrivers/CMSIS/Device/ST/STM32L4xx/Include/ -IDrivers/Inc -IIDrivers/Inc -IIDrivers/STM32L4xx_HAL_Driver/Inc -IIDrivers/CMSIS/Include -IIDrivers/CMSIS/Device/ST/STM32L4xx/Include -IIInc -IDrivers/CMSIS/Include/ -IDrivers/STM32L4xx_HAL_Driver/Inc/ -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include/ -I../Drivers/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Src

clean-Drivers-2f-Src:
	-$(RM) ./Drivers/Src/stm32l4_gpio_driver.cyclo ./Drivers/Src/stm32l4_gpio_driver.d ./Drivers/Src/stm32l4_gpio_driver.o ./Drivers/Src/stm32l4_gpio_driver.su

.PHONY: clean-Drivers-2f-Src

