################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/led_blinker_app.c 

OBJS += \
./Core/led_blinker_app.o 

C_DEPS += \
./Core/led_blinker_app.d 


# Each subdirectory must supply rules for building sources it contributes
Core/%.o Core/%.su Core/%.cyclo: ../Core/%.c Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/Users/sandeep/Documents/github-projects/frtos/free-rtos/common/ThirdParty/FreeRTOS/License -I/Users/sandeep/Documents/github-projects/frtos/free-rtos/common/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F -I/Users/sandeep/Documents/github-projects/frtos/free-rtos/common/ThirdParty/FreeRTOS/portable/MemMang -I/Users/sandeep/Documents/github-projects/frtos/free-rtos/common/ThirdParty/FreeRTOS -I/Users/sandeep/Documents/github-projects/frtos/free-rtos/common/ThirdParty/FreeRTOS/include -I"/Users/sandeep/Documents/github-projects/frtos/free-rtos/led_tasks/Core" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core

clean-Core:
	-$(RM) ./Core/led_blinker_app.cyclo ./Core/led_blinker_app.d ./Core/led_blinker_app.o ./Core/led_blinker_app.su

.PHONY: clean-Core

