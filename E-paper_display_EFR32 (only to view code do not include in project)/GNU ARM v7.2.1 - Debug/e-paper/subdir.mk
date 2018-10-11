################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../e-paper/Adafruit_GFX.c \
../e-paper/GxEPD.c \
../e-paper/GxFont_GFX.c \
../e-paper/GxGDEP015OC1.c 

OBJS += \
./e-paper/Adafruit_GFX.o \
./e-paper/GxEPD.o \
./e-paper/GxFont_GFX.o \
./e-paper/GxGDEP015OC1.o 

C_DEPS += \
./e-paper/Adafruit_GFX.d \
./e-paper/GxEPD.d \
./e-paper/GxFont_GFX.d \
./e-paper/GxGDEP015OC1.d 


# Each subdirectory must supply rules for building sources it contributes
e-paper/Adafruit_GFX.o: ../e-paper/Adafruit_GFX.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32MG12P332F1024GL125=1' '-DDEBUG=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/EFR32MG12_BRD4162A/config" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/e-paper" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/fonts" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"e-paper/Adafruit_GFX.d" -MT"e-paper/Adafruit_GFX.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

e-paper/GxEPD.o: ../e-paper/GxEPD.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32MG12P332F1024GL125=1' '-DDEBUG=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/EFR32MG12_BRD4162A/config" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/e-paper" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/fonts" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"e-paper/GxEPD.d" -MT"e-paper/GxEPD.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

e-paper/GxFont_GFX.o: ../e-paper/GxFont_GFX.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32MG12P332F1024GL125=1' '-DDEBUG=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/EFR32MG12_BRD4162A/config" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/e-paper" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/fonts" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"e-paper/GxFont_GFX.d" -MT"e-paper/GxFont_GFX.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

e-paper/GxGDEP015OC1.o: ../e-paper/GxGDEP015OC1.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32MG12P332F1024GL125=1' '-DDEBUG=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/EFR32MG12_BRD4162A/config" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/e-paper" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/fonts" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"e-paper/GxGDEP015OC1.d" -MT"e-paper/GxGDEP015OC1.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


