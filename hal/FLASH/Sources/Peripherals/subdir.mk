################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Peripherals/io.c" \
"../Sources/Peripherals/kbi.c" \
"../Sources/Peripherals/pwm.c" \

C_SRCS += \
../Sources/Peripherals/io.c \
../Sources/Peripherals/kbi.c \
../Sources/Peripherals/pwm.c \

OBJS += \
./Sources/Peripherals/io_c.obj \
./Sources/Peripherals/kbi_c.obj \
./Sources/Peripherals/pwm_c.obj \

OBJS_QUOTED += \
"./Sources/Peripherals/io_c.obj" \
"./Sources/Peripherals/kbi_c.obj" \
"./Sources/Peripherals/pwm_c.obj" \

C_DEPS += \
./Sources/Peripherals/io_c.d \
./Sources/Peripherals/kbi_c.d \
./Sources/Peripherals/pwm_c.d \

C_DEPS_QUOTED += \
"./Sources/Peripherals/io_c.d" \
"./Sources/Peripherals/kbi_c.d" \
"./Sources/Peripherals/pwm_c.d" \

OBJS_OS_FORMAT += \
./Sources/Peripherals/io_c.obj \
./Sources/Peripherals/kbi_c.obj \
./Sources/Peripherals/pwm_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/Peripherals/io_c.obj: ../Sources/Peripherals/io.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/Peripherals/io.args" -ObjN="Sources/Peripherals/io_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/Peripherals/%.d: ../Sources/Peripherals/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/Peripherals/kbi_c.obj: ../Sources/Peripherals/kbi.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/Peripherals/kbi.args" -ObjN="Sources/Peripherals/kbi_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/Peripherals/pwm_c.obj: ../Sources/Peripherals/pwm.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/Peripherals/pwm.args" -ObjN="Sources/Peripherals/pwm_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '


