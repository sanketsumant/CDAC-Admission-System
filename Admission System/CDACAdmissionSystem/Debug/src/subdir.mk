################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Admissionsystem.cpp \
../src/Capacity.cpp \
../src/Center.cpp \
../src/Course.cpp \
../src/Eligibility.cpp \
../src/Preference.cpp \
../src/Student.cpp \
../src/main.cpp 

OBJS += \
./src/Admissionsystem.o \
./src/Capacity.o \
./src/Center.o \
./src/Course.o \
./src/Eligibility.o \
./src/Preference.o \
./src/Student.o \
./src/main.o 

CPP_DEPS += \
./src/Admissionsystem.d \
./src/Capacity.d \
./src/Center.d \
./src/Course.d \
./src/Eligibility.d \
./src/Preference.d \
./src/Student.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


