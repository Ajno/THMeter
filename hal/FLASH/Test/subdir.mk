################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Test/display_test.c" \
"../Test/io_test.c" \
"../Test/kbi_test.c" \
"../Test/pwm_test.c" \
"../Test/timer_test.c" \

C_SRCS += \
../Test/display_test.c \
../Test/io_test.c \
../Test/kbi_test.c \
../Test/pwm_test.c \
../Test/timer_test.c \

OBJS += \
./Test/display_test_c.obj \
./Test/io_test_c.obj \
./Test/kbi_test_c.obj \
./Test/pwm_test_c.obj \
./Test/timer_test_c.obj \

OBJS_QUOTED += \
"./Test/display_test_c.obj" \
"./Test/io_test_c.obj" \
"./Test/kbi_test_c.obj" \
"./Test/pwm_test_c.obj" \
"./Test/timer_test_c.obj" \

C_DEPS += \
./Test/display_test_c.d \
./Test/io_test_c.d \
./Test/kbi_test_c.d \
./Test/pwm_test_c.d \
./Test/timer_test_c.d \

C_DEPS_QUOTED += \
"./Test/display_test_c.d" \
"./Test/io_test_c.d" \
"./Test/kbi_test_c.d" \
"./Test/pwm_test_c.d" \
"./Test/timer_test_c.d" \

OBJS_OS_FORMAT += \
./Test/display_test_c.obj \
./Test/io_test_c.obj \
./Test/kbi_test_c.obj \
./Test/pwm_test_c.obj \
./Test/timer_test_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Test/display_test_c.obj: ../Test/display_test.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Test/display_test.args" -ObjN="Test/display_test_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Test/%.d: ../Test/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Test/io_test_c.obj: ../Test/io_test.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Test/io_test.args" -ObjN="Test/io_test_c.obj" "$<" -Lm="Test/io_test_c.d" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Test/io_test_c.d: ../Test/io_test.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Test/kbi_test_c.obj: ../Test/kbi_test.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Test/kbi_test.args" -ObjN="Test/kbi_test_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Test/pwm_test_c.obj: ../Test/pwm_test.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Test/pwm_test.args" -ObjN="Test/pwm_test_c.obj" "$<" -Lm="Test/pwm_test_c.d" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Test/pwm_test_c.d: ../Test/pwm_test.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Test/timer_test_c.obj: ../Test/timer_test.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Test/timer_test.args" -ObjN="Test/timer_test_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '


