################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Src/gpio_drivers.c \
../Drivers/Src/i2c_driver.c 

OBJS += \
./Drivers/Src/gpio_drivers.o \
./Drivers/Src/i2c_driver.o 

C_DEPS += \
./Drivers/Src/gpio_drivers.d \
./Drivers/Src/i2c_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Src/%.o Drivers/Src/%.su Drivers/Src/%.cyclo: ../Drivers/Src/%.c Drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DNUCLEO_L476RG -DSTM32L476RGTx -c -I../Inc -I"C:/Users/KOPPOLU MOUNIKA/OneDrive - BITSILICA Pvt. Ltd/Desktop/stm32/07_I2C_Interrupt/Drivers/Src" -I"C:/Users/KOPPOLU MOUNIKA/OneDrive - BITSILICA Pvt. Ltd/Desktop/stm32/07_I2C_Interrupt/Drivers/Inc" -I"C:/Users/KOPPOLU MOUNIKA/OneDrive - BITSILICA Pvt. Ltd/Desktop/stm32/07_I2C_Interrupt/Drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Src

clean-Drivers-2f-Src:
	-$(RM) ./Drivers/Src/gpio_drivers.cyclo ./Drivers/Src/gpio_drivers.d ./Drivers/Src/gpio_drivers.o ./Drivers/Src/gpio_drivers.su ./Drivers/Src/i2c_driver.cyclo ./Drivers/Src/i2c_driver.d ./Drivers/Src/i2c_driver.o ./Drivers/Src/i2c_driver.su

.PHONY: clean-Drivers-2f-Src

