################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../fonts/glcdfont.c 

OBJS += \
./fonts/glcdfont.o 

C_DEPS += \
./fonts/glcdfont.d 


# Each subdirectory must supply rules for building sources it contributes
fonts/glcdfont.o: ../fonts/glcdfont.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32MG12P332F1024GL125=1' '-DDEBUG=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/EFR32MG12_BRD4162A/config" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/e-paper" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/fonts" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"fonts/glcdfont.d" -MT"fonts/glcdfont.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


