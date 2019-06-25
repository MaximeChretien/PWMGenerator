# Makefile for AVR microcontrollers using C
# v1.2
# Made by Maxime Chretien (MixLeNain)

# Device settings
DEVICE=attiny85
CLOCK=8000000
FUSES=-U lfuse:w:0xE2:m -U hfuse:w:0xD9:m -U efuse:w:0xFF:m

# Programmer settings
BAUD=19200
PROGRAMMER=stk500v1
PORT=/dev/ttyACM0
UPLOADER=avrdude -b $(BAUD) -c $(PROGRAMMER) -P $(PORT) -p $(DEVICE)

# Build settings
CC=avr-gcc
CFLAGS=-Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE)
TARGET=main.hex
ELF=$(patsubst %.hex, %.elf, $(TARGET))
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
DEPS=$(wildcard *.h)

.PHONY: all install flash fuse disasm clean mrproper

all: $(TARGET)

install: flash fuse

flash:	all
	$(UPLOADER) -U flash:w:$(TARGET):i

fuse:
	$(UPLOADER) $(FUSES)

$(TARGET) : $(ELF)
	rm -f $(TARGET)
	avr-objcopy -j .text -j .data -O ihex $(ELF) $(TARGET)

$(ELF) : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o:%.c $(DEPS)
	$(CC) -o $@ -c $< $(CFLAGS)

disasm:	$(ELF)
	avr-objdump -d $<

clean:
	rm -f *.o core

mrproper: clean
	rm -f $(TARGET) $(ELF)
