################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Src/lcd.c \
../Drivers/Src/stm32l4xx_gpio_driver.c 

OBJS += \
./Drivers/Src/lcd.o \
./Drivers/Src/stm32l4xx_gpio_driver.o 

C_DEPS += \
./Drivers/Src/lcd.d \
./Drivers/Src/stm32l4xx_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Src/%.o Drivers/Src/%.su Drivers/Src/%.cyclo: ../Drivers/Src/%.c Drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DNUCLEO_L476RG -DSTM32L476RGTx -c -I../Inc -I"C:/Users/KOPPOLU MOUNIKA/OneDrive - BITSILICA Pvt. Ltd/Desktop/stm32/10_LCD/Drivers/Inc" -I"C:/Users/KOPPOLU MOUNIKA/OneDrive - BITSILICA Pvt. Ltd/Desktop/stm32/10_LCD/Drivers/Src" -I"C:/Users/KOPPOLU MOUNIKA/OneDrive - BITSILICA Pvt. Ltd/Desktop/stm32/10_LCD/Drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Src

clean-Drivers-2f-Src:
	-$(RM) ./Drivers/Src/lcd.cyclo ./Drivers/Src/lcd.d ./Drivers/Src/lcd.o ./Drivers/Src/lcd.su ./Drivers/Src/stm32l4xx_gpio_driver.cyclo ./Drivers/Src/stm32l4xx_gpio_driver.d ./Drivers/Src/stm32l4xx_gpio_driver.o ./Drivers/Src/stm32l4xx_gpio_driver.su

.PHONY: clean-Drivers-2f-Src

