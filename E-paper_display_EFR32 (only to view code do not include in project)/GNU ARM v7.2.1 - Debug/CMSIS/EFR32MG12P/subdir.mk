################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4/platform/Device/SiliconLabs/EFR32MG12P/Source/system_efr32mg12p.c 

S_UPPER_SRCS += \
C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4/platform/Device/SiliconLabs/EFR32MG12P/Source/GCC/startup_efr32mg12p.S 

OBJS += \
./CMSIS/EFR32MG12P/startup_efr32mg12p.o \
./CMSIS/EFR32MG12P/system_efr32mg12p.o 

C_DEPS += \
./CMSIS/EFR32MG12P/system_efr32mg12p.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/EFR32MG12P/startup_efr32mg12p.o: C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4/platform/Device/SiliconLabs/EFR32MG12P/Source/GCC/startup_efr32mg12p.S
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Assembler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -c -x assembler-with-cpp -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/EFR32MG12_BRD4162A/config" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/inc" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/e-paper" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/fonts" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/" '-DEFR32MG12P332F1024GL125=1' -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

CMSIS/EFR32MG12P/system_efr32mg12p.o: C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4/platform/Device/SiliconLabs/EFR32MG12P/Source/system_efr32mg12p.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32MG12P332F1024GL125=1' '-DDEBUG=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/EFR32MG12_BRD4162A/config" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/e-paper" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/fonts" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"CMSIS/EFR32MG12P/system_efr32mg12p.d" -MT"CMSIS/EFR32MG12P/system_efr32mg12p.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


