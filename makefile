CC=avr-gcc
CCCOPY=avr-objcopy
TRANSFER=avrdude
AVRNAME=attiny2313
AVRTRANSFERNAME=t2313
AVRPROGRAMMER=-c avrispmkII -P /dev/cu.usbserial
AVRINTERNAL=-U lfuse:w:0xE4:m  -U hfuse:w:0xdf:m -U efuse:w:0xff:m
AVREXTERNAL=-U lfuse:w:0xDE:m  -U hfuse:w:0xdf:m -U efuse:w:0xff:m
CFLAGS=-Wall -Wstrict-prototypes -Os -mcall-prologues -mmcu=$(AVRNAME)
LDFLAGS=$(CFLAGS)
CCCFLAGS=-R .eeprom -O ihex
TFLAGS=-p $(AVRTRANSFERNAME) $(AVRPROGRAMMER) 
FUSEFLAGS= $(AVRINTERNAL)
# Only for Usage with external oszillator otherwise use $(AVRINTERNAL)
SOURCES=main.c uart.c
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=freicycleSender

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@.out
	$(CCCOPY) $(CCCFLAGS) $@.out $@.hex

transfer:
	$(TRANSFER) $(TFLAGS) $(FUSEFLAGS) -U flash:w:$(EXECUTABLE).hex:a

testConnection:
	$(TRANSFER) $(TFLAGS)

clean:
	rm -f *.o *.out *.hex *.map

.c.o:
	$(CC) $(CFLAGS) $< -o $@

