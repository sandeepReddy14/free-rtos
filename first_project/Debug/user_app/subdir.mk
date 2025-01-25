################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../user_app/task1.c \
../user_app/task2.c \
../user_app/user_app_main.c 

OBJS += \
./user_app/task1.o \
./user_app/task2.o \
./user_app/user_app_main.o 

C_DEPS += \
./user_app/task1.d \
./user_app/task2.d \
./user_app/user_app_main.d 


# Each subdirectory must supply rules for building sources it contributes
user_app/%.o user_app/%.su user_app/%.cyclo: ../user_app/%.c user_app/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/Users/sandeep/Documents/github-projects/frtos/free-rtos/first_project/user_app/include" -I"/Users/sandeep/Documents/github-projects/frtos/free-rtos/first_project/ThirdParty/FreeRTOS" -I"/Users/sandeep/Documents/github-projects/frtos/free-rtos/first_project/ThirdParty/FreeRTOS/include" -I"/Users/sandeep/Documents/github-projects/frtos/free-rtos/first_project/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-user_app

clean-user_app:
	-$(RM) ./user_app/task1.cyclo ./user_app/task1.d ./user_app/task1.o ./user_app/task1.su ./user_app/task2.cyclo ./user_app/task2.d ./user_app/task2.o ./user_app/task2.su ./user_app/user_app_main.cyclo ./user_app/user_app_main.d ./user_app/user_app_main.o ./user_app/user_app_main.su

.PHONY: clean-user_app

