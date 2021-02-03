################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_prg.c \
C:/Users/Silver/Documents/Embedded/Lock\ System/KEY_prog.c \
../LCD_prg.c \
../SEV_prg.c \
C:/Users/Silver/Documents/Embedded/Lock\ System/STEPPER_prg.c \
../main.c 

OBJS += \
./DIO_prg.o \
./KEY_prog.o \
./LCD_prg.o \
./SEV_prg.o \
./STEPPER_prg.o \
./main.o 

C_DEPS += \
./DIO_prg.d \
./KEY_prog.d \
./LCD_prg.d \
./SEV_prg.d \
./STEPPER_prg.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

KEY_prog.o: C:/Users/Silver/Documents/Embedded/Lock\ System/KEY_prog.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"KEY_prog.d" -MT"KEY_prog.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

STEPPER_prg.o: C:/Users/Silver/Documents/Embedded/Lock\ System/STEPPER_prg.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"STEPPER_prg.d" -MT"STEPPER_prg.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


