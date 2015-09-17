################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Sources/buttons.cpp \

C_SRCS_QUOTED += \
"../Sources/display.c" \
"../Sources/main.c" \
"../Sources/timer.c" \

C_SRCS += \
../Sources/display.c \
../Sources/main.c \
../Sources/timer.c \

CPP_SRCS_QUOTED += \
"../Sources/buttons.cpp" \

OBJS += \
./Sources/buttons_cpp.obj \
./Sources/display_c.obj \
./Sources/main_c.obj \
./Sources/timer_c.obj \

OBJS_QUOTED += \
"./Sources/buttons_cpp.obj" \
"./Sources/display_c.obj" \
"./Sources/main_c.obj" \
"./Sources/timer_c.obj" \

CPP_DEPS_QUOTED += \
"./Sources/buttons_cpp.d" \

CPP_DEPS += \
./Sources/buttons_cpp.d \

C_DEPS += \
./Sources/display_c.d \
./Sources/main_c.d \
./Sources/timer_c.d \

C_DEPS_QUOTED += \
"./Sources/display_c.d" \
"./Sources/main_c.d" \
"./Sources/timer_c.d" \

OBJS_OS_FORMAT += \
./Sources/buttons_cpp.obj \
./Sources/display_c.obj \
./Sources/main_c.obj \
./Sources/timer_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/buttons_cpp.obj: ../Sources/buttons.cpp
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/buttons.args" -ObjN="Sources/buttons_cpp.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.cpp
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/display_c.obj: ../Sources/display.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/display.args" -ObjN="Sources/display_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/main.args" -ObjN="Sources/main_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/timer_c.obj: ../Sources/timer.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/timer.args" -ObjN="Sources/timer_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '


