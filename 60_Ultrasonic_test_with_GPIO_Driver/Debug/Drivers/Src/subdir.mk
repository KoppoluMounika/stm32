################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Src/lcd_gpio.c \
../Drivers/Src/ultrasonic_gpio.c 

OBJS += \
./Drivers/Src/lcd_gpio.o \
./Drivers/Src/ultrasonic_gpio.o 

C_DEPS += \
./Drivers/Src/lcd_gpio.d \
./Drivers/Src/ultrasonic_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Src/%.o Drivers/Src/%.su Drivers/Src/%.cyclo: ../Drivers/Src/%.c Drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DNUCLEO_L476RG -DSTM32L476RGTx -c -I../Inc -I"C:/Users/KOPPOLU MOUNIKA/OneDrive - BITSILICA Pvt. Ltd/Desktop/stm32/12_LCD_With_Ultrasonic_sensor/Drivers/Inc" -I"C:/Users/KOPPOLU MOUNIKA/OneDrive - BITSILICA Pvt. Ltd/Desktop/stm32/12_LCD_With_Ultrasonic_sensor/Drivers" -I"C:/Users/KOPPOLU MOUNIKA/OneDrive - BITSILICA Pvt. Ltd/Desktop/stm32/12_LCD_With_Ultrasonic_sensor/Drivers/Inc" -I"C:/Users/KOPPOLU MOUNIKA/OneDrive - BITSILICA Pvt. Ltd/Desktop/stm32/12_LCD_With_Ultrasonic_sensor/Drivers/Src" -I"C:/Users/KOPPOLU MOUNIKA/OneDrive - BITSILICA Pvt. Ltd/Desktop/stm32/12_LCD_With_Ultrasonic_sensor/Drivers/Inc" -I"C:/Users/KOPPOLU MOUNIKA/OneDrive - BITSILICA Pvt. Ltd/Desktop/stm32/12_LCD_With_Ultrasonic_sensor/Drivers/Src" -I"C:/Users/KOPPOLU MOUNIKA/OneDrive - BITSILICA Pvt. Ltd/Desktop/stm32/12_LCD_With_Ultrasonic_sensor/Drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Src

clean-Drivers-2f-Src:
	-$(RM) ./Drivers/Src/lcd_gpio.cyclo ./Drivers/Src/lcd_gpio.d ./Drivers/Src/lcd_gpio.o ./Drivers/Src/lcd_gpio.su ./Drivers/Src/ultrasonic_gpio.cyclo ./Drivers/Src/ultrasonic_gpio.d ./Drivers/Src/ultrasonic_gpio.o ./Drivers/Src/ultrasonic_gpio.su

.PHONY: clean-Drivers-2f-Src

