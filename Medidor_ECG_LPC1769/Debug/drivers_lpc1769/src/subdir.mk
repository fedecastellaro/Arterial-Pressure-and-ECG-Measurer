################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers_lpc1769/src/FW_ADC.c \
../drivers_lpc1769/src/FW_DAC.c \
../drivers_lpc1769/src/FW_EXTINT.c \
../drivers_lpc1769/src/FW_GPIO.c \
../drivers_lpc1769/src/FW_PINSEL.c \
../drivers_lpc1769/src/FW_SysTick.c \
../drivers_lpc1769/src/FW_UART.c \
../drivers_lpc1769/src/cr_startup_lpc175x_6x.c \
../drivers_lpc1769/src/crp.c 

OBJS += \
./drivers_lpc1769/src/FW_ADC.o \
./drivers_lpc1769/src/FW_DAC.o \
./drivers_lpc1769/src/FW_EXTINT.o \
./drivers_lpc1769/src/FW_GPIO.o \
./drivers_lpc1769/src/FW_PINSEL.o \
./drivers_lpc1769/src/FW_SysTick.o \
./drivers_lpc1769/src/FW_UART.o \
./drivers_lpc1769/src/cr_startup_lpc175x_6x.o \
./drivers_lpc1769/src/crp.o 

C_DEPS += \
./drivers_lpc1769/src/FW_ADC.d \
./drivers_lpc1769/src/FW_DAC.d \
./drivers_lpc1769/src/FW_EXTINT.d \
./drivers_lpc1769/src/FW_GPIO.d \
./drivers_lpc1769/src/FW_PINSEL.d \
./drivers_lpc1769/src/FW_SysTick.d \
./drivers_lpc1769/src/FW_UART.d \
./drivers_lpc1769/src/cr_startup_lpc175x_6x.d \
./drivers_lpc1769/src/crp.d 


# Each subdirectory must supply rules for building sources it contributes
drivers_lpc1769/src/%.o: ../drivers_lpc1769/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/home/federico/Escritorio/Primeras pruebas_u/ej_controlador_adc_serie/aplicacion/inc" -I"/home/federico/Escritorio/Primeras pruebas_u/ej_controlador_adc_serie/primitivas/inc" -I"/home/federico/Escritorio/Primeras pruebas_u/ej_controlador_adc_serie/drivers_infotronic/inc" -I"/home/federico/Escritorio/Primeras pruebas_u/ej_controlador_adc_serie/drivers_lpc1769/inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


