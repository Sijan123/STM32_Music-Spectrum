################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include sp_drivers/src/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Music_Spectrum.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Music_Spectrum.list \


# All Target
all: Music_Spectrum.elf secondary-outputs

# Tool invocations
Music_Spectrum.elf: $(OBJS) $(USER_OBJS) E:\study\german\ language\7th\ sem\Projects\Music_Spectrum\STM32F446RETX_FLASH.ld
	arm-none-eabi-gcc -o "Music_Spectrum.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"E:\study\german language\7th sem\Projects\Music_Spectrum\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Music_Spectrum.map" -Wl,--gc-sections -static -L"E:\study\german language\7th sem\Projects\Music_Spectrum\libs" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Music_Spectrum.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Music_Spectrum.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
