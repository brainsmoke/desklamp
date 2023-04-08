
# change these to the right values

MCU=attiny1624 # as known by avr-gcc
PROG_MCU=attiny1624 # as known by the programmer
PROG_DEVICE=-u /dev/ttyUSB0

TARGET=firmware.hex
OBJ=firmware.o
ELFTARGET=firmware.elf
COMMON=uart.o adc.o io.o gamma.o rtc.o dial.o system.o prot.o settings.o
HEADERS=$(wildcard *.h)
LDFLAGS=-Wl,-T,ld/avrxmega3.xn -B lib
CFLAGS=-std=gnu99 -Wall -Os -D__AVR_DEV_LIB_NAME__=tn1624 -B lib -g

.PHONY: clean

all: $(TARGET) $(ELFTARGET)

%.hex: %.elf
	avr-objcopy -j .text -j .data -j .rodata -O ihex $< $@

%.elf: %.o $(COMMON)
	avr-gcc $(LDFLAGS) -mmcu=$(MCU) -o $@ $^

%.o: %.S $(HEADERS)
	avr-gcc $(CFLAGS) -mmcu=$(MCU) -c -o $@ $< 

%.o: %.c $(HEADERS)
	avr-gcc $(CFLAGS) -O -mmcu=$(MCU) -c -o $@ $<


flash: $(TARGET)
	pymcuprog erase -m flash -t uart -d $(PROG_MCU) $(PROG_DEVICE)
	pymcuprog write -t uart -d $(PROG_MCU) $(PROG_DEVICE) -f $(TARGET)

#fuses:
#	avrdude -v -c usbtiny -pt85 -U lfuse:w:0xe2:m -U hfuse:w:0xdf:m -U efuse:w:0xff:m

clean:
	-rm $(TARGET) $(ELFTARGET) $(OBJ)
