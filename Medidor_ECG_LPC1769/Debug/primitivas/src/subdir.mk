################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../primitivas/src/PR_LCD.c \
../primitivas/src/PR_Serie.c \
../primitivas/src/PR_Teclado.c 

OBJS += \
./primitivas/src/PR_LCD.o \
./primitivas/src/PR_Serie.o \
./primitivas/src/PR_Teclado.o 

C_DEPS += \
./primitivas/src/PR_LCD.d \
./primitivas/src/PR_Serie.d \
./primitivas/src/PR_Teclado.d 


# Each subdirectory must supply rules for building sources it contributes
primitivas/src/%.o: ../primitivas/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/home/federico/Escritorio/Primeras pruebas_u/ej_controlador_adc_serie/aplicacion/inc" -I"/home/federico/Escritorio/Primeras pruebas_u/ej_controlador_adc_serie/primitivas/inc" -I"/home/federico/Escritorio/Primeras pruebas_u/ej_controlador_adc_serie/drivers_infotronic/inc" -I"/home/federico/Escritorio/Primeras pruebas_u/ej_controlador_adc_serie/drivers_lpc1769/inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


