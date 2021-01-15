################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Enemy.cpp \
../block.cpp \
../boxObj.cpp \
../main.cpp \
../player.cpp 

OBJS += \
./Enemy.o \
./block.o \
./boxObj.o \
./main.o \
./player.o 

CPP_DEPS += \
./Enemy.d \
./block.d \
./boxObj.d \
./main.d \
./player.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/Users/kailau/Desktop/cpp/SFML -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


