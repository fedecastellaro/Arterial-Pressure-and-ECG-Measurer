################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../aplicacion/src/AP_Controlador.c \
../aplicacion/src/main.c 

OBJS += \
./aplicacion/src/AP_Controlador.o \
./aplicacion/src/main.o 

C_DEPS += \
./aplicacion/src/AP_Controlador.d \
./aplicacion/src/main.d 


# Each subdirectory must supply rules for building sources it contributes
aplicacion/src/%.o: ../aplicacion/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/home/federico/Escritorio/Primeras pruebas_u/ej_controlador_adc_serie/aplicacion/inc" -I"/home/federico/Escritorio/Primeras pruebas_u/ej_controlador_adc_serie/primitivas/inc" -I"/home/federico/Escritorio/Primeras pruebas_u/ej_controlador_adc_serie/drivers_infotronic/inc" -I"/home/federico/Escritorio/Primeras pruebas_u/ej_controlador_adc_serie/drivers_lpc1769/inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


