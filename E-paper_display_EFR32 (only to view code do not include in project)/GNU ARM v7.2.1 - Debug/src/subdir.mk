################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bsp_trace.c \
../src/i2cspm.c \
../src/main.c \
../src/retargetio.c \
../src/retargetserial.c \
../src/si7013.c \
../src/udelay.c \
../src/ustimer.c 

OBJS += \
./src/bsp_trace.o \
./src/i2cspm.o \
./src/main.o \
./src/retargetio.o \
./src/retargetserial.o \
./src/si7013.o \
./src/udelay.o \
./src/ustimer.o 

C_DEPS += \
./src/bsp_trace.d \
./src/i2cspm.d \
./src/main.d \
./src/retargetio.d \
./src/retargetserial.d \
./src/si7013.d \
./src/udelay.d \
./src/ustimer.d 


# Each subdirectory must supply rules for building sources it contributes
src/bsp_trace.o: ../src/bsp_trace.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32MG12P332F1024GL125=1' '-DDEBUG=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/EFR32MG12_BRD4162A/config" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/e-paper" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/fonts" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/bsp_trace.d" -MT"src/bsp_trace.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/i2cspm.o: ../src/i2cspm.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32MG12P332F1024GL125=1' '-DDEBUG=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/EFR32MG12_BRD4162A/config" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/e-paper" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/fonts" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/i2cspm.d" -MT"src/i2cspm.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/main.o: ../src/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32MG12P332F1024GL125=1' '-DDEBUG=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/EFR32MG12_BRD4162A/config" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/e-paper" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/fonts" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/main.d" -MT"src/main.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/retargetio.o: ../src/retargetio.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32MG12P332F1024GL125=1' '-DDEBUG=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/EFR32MG12_BRD4162A/config" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/e-paper" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/fonts" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/retargetio.d" -MT"src/retargetio.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/retargetserial.o: ../src/retargetserial.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32MG12P332F1024GL125=1' '-DDEBUG=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/EFR32MG12_BRD4162A/config" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/e-paper" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/fonts" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/retargetserial.d" -MT"src/retargetserial.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/si7013.o: ../src/si7013.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32MG12P332F1024GL125=1' '-DDEBUG=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/EFR32MG12_BRD4162A/config" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/e-paper" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/fonts" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/si7013.d" -MT"src/si7013.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/udelay.o: ../src/udelay.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32MG12P332F1024GL125=1' '-DDEBUG=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/EFR32MG12_BRD4162A/config" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/e-paper" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/fonts" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/udelay.d" -MT"src/udelay.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/ustimer.o: ../src/ustimer.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32MG12P332F1024GL125=1' '-DDEBUG=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/EFR32MG12_BRD4162A/config" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/e-paper" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/fonts" -I"C:/Users/UTF-Labs-2/SimplicityStudio/v4_workspace/E-paper_display_EFR32/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/ustimer.d" -MT"src/ustimer.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


