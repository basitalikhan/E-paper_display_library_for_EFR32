################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include fonts/subdir.mk
-include emlib/subdir.mk
-include e-paper/subdir.mk
-include CMSIS/EFR32MG12P/subdir.mk
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
all: E-paper_display_EFR32.axf

# Tool invocations
E-paper_display_EFR32.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -T "E-paper_display_EFR32.ld" -Xlinker --gc-sections -Xlinker -Map="E-paper_display_EFR32.map" -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -o E-paper_display_EFR32.axf "./CMSIS/EFR32MG12P/startup_efr32mg12p.o" "./CMSIS/EFR32MG12P/system_efr32mg12p.o" "./e-paper/Adafruit_GFX.o" "./e-paper/GxEPD.o" "./e-paper/GxFont_GFX.o" "./e-paper/GxGDEP015OC1.o" "./emlib/em_acmp.o" "./emlib/em_adc.o" "./emlib/em_aes.o" "./emlib/em_assert.o" "./emlib/em_burtc.o" "./emlib/em_can.o" "./emlib/em_cmu.o" "./emlib/em_core.o" "./emlib/em_cryotimer.o" "./emlib/em_crypto.o" "./emlib/em_csen.o" "./emlib/em_dac.o" "./emlib/em_dbg.o" "./emlib/em_dma.o" "./emlib/em_ebi.o" "./emlib/em_emu.o" "./emlib/em_gpcrc.o" "./emlib/em_gpio.o" "./emlib/em_i2c.o" "./emlib/em_idac.o" "./emlib/em_int.o" "./emlib/em_lcd.o" "./emlib/em_ldma.o" "./emlib/em_lesense.o" "./emlib/em_letimer.o" "./emlib/em_leuart.o" "./emlib/em_mpu.o" "./emlib/em_msc.o" "./emlib/em_opamp.o" "./emlib/em_pcnt.o" "./emlib/em_prs.o" "./emlib/em_qspi.o" "./emlib/em_rmu.o" "./emlib/em_rtc.o" "./emlib/em_rtcc.o" "./emlib/em_system.o" "./emlib/em_timer.o" "./emlib/em_usart.o" "./emlib/em_vcmp.o" "./emlib/em_vdac.o" "./emlib/em_wdog.o" "./fonts/glcdfont.o" "./logo-screen.o" "./src/bsp_trace.o" "./src/i2cspm.o" "./src/main.o" "./src/retargetio.o" "./src/retargetserial.o" "./src/si7013.o" "./src/udelay.o" "./src/ustimer.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: E-paper_display_EFR32.hex'
	arm-none-eabi-objcopy -O ihex "E-paper_display_EFR32.axf" "E-paper_display_EFR32.hex"
	@echo ' '

	@echo 'Building bin file: E-paper_display_EFR32.bin'
	arm-none-eabi-objcopy -O binary "E-paper_display_EFR32.axf" "E-paper_display_EFR32.bin"
	@echo ' '

	@echo 'Building s37 file: E-paper_display_EFR32.s37'
	arm-none-eabi-objcopy -O srec "E-paper_display_EFR32.axf" "E-paper_display_EFR32.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "E-paper_display_EFR32.axf"
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) E-paper_display_EFR32.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
