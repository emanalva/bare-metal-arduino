# Microcontroller and Clock settings
MCU = atmega328p
F_CPU = 16000000UL

# Compiler and flags
CC = avr-gcc
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall

# Files
TARGET = main
SRC = main.c

# Default target
all: $(TARGET).hex

# Compile the C file to object file
$(TARGET).o: $(SRC)
	$(CC) $(CFLAGS) -c $< -o $@

# Link object file to create ELF file
$(TARGET).elf: $(TARGET).o
	$(CC) $(CFLAGS) $< -o $@

# Convert ELF to HEX for uploading
$(TARGET).hex: $(TARGET).elf
	avr-objcopy -O ihex -R .eeprom $< $@

# Flash the HEX file to the Arduino
flash: $(TARGET).hex
	avrdude -c arduino -p m328p -P /dev/cu.usbmodem142101 -b 115200 -U flash:w:$(TARGET).hex:i

# Clean up generated files
clean:
	rm -f *.o *.elf *.hex
