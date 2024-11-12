# Compiler option
CC = avr-gcc

# Optimize for size, clock 16Mhz, mcu atmega328p
CFLAGS = -Os -DF_CPU=16000000UL -mmcu=atmega328p

# USBPORT
USBPORT := $(shell ls /dev/ttyUSB*)

%.out: %.c
	$(CC) $(CFLAGS) $< -o $@

%.hex: %.out
	avr-objcopy -O ihex -R .eeprom $< $@

open-port:
	sudo chmod 666 ${USBPORT}

install.%: %.hex
	avrdude -F -V -c arduino -p ATMEGA328P -P \
		${USBPORT} -b 115200 -U flash:w:$<

.PHONY: all
all: timer1-interrupt.out

.PHONY: clean
clean: 
	rm -f *.hex *.out
