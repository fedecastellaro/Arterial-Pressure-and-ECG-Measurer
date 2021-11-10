################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include primitivas/src/subdir.mk
-include drivers_lpc1769/src/subdir.mk
-include drivers_infotronic/src/subdir.mk
-include aplicacion/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: ej_controlador_adc_serie.axf

# Tool invocations
ej_controlador_adc_serie.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="ej_controlador_adc_serie.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m3 -mthumb -T "ej_controlador_adc_serie_Debug.ld" -o "ej_controlador_adc_serie.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) ej_controlador_adc_serie.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "ej_controlador_adc_serie.axf"; # arm-none-eabi-objcopy -v -O binary "ej_controlador_adc_serie.axf" "ej_controlador_adc_serie.bin" ; # checksum -p LPC1769 -d "ej_controlador_adc_serie.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
