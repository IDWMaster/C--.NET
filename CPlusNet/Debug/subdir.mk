################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BinaryReader.cpp \
../BinaryWriter.cpp \
../Console.cpp \
../FileStream.cpp \
../RThread.cpp \
../Stream.cpp \
../Thread.cpp 

OBJS += \
./BinaryReader.o \
./BinaryWriter.o \
./Console.o \
./FileStream.o \
./RThread.o \
./Stream.o \
./Thread.o 

CPP_DEPS += \
./BinaryReader.d \
./BinaryWriter.d \
./Console.d \
./FileStream.d \
./RThread.d \
./Stream.d \
./Thread.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -Dwin32 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


