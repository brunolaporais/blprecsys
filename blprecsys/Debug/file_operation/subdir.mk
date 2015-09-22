################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../file_operation/input.cpp \
../file_operation/output.cpp 

OBJS += \
./file_operation/input.o \
./file_operation/output.o 

CPP_DEPS += \
./file_operation/input.d \
./file_operation/output.d 


# Each subdirectory must supply rules for building sources it contributes
file_operation/%.o: ../file_operation/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


