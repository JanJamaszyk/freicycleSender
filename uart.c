#include "uart.h"
#include <string.h>
#include <avr/io.h>

void uartInit(void) {
	//uartSetBaudRate(UART_BAUD_RATE);
	//UCSRA |= (1 << U2X);
	UCSRB |= (1 << TXEN);
}

void uartSetBaudRate(uint16_t baudrate) {
	//baudrate = baudrate/2;
	UBRRH = (uint8_t) (UART_UBRR_CALC(baudrate,F_CPU)>>8);
	UBRRL = (uint8_t) (UART_UBRR_CALC(baudrate,F_CPU));
}

void uartSendByte(uint8_t byte) {
	while (!(UCSRA & (1 << UDRE)));
	UDR = byte;
}

void uartSendString(const char* string) {
    int len = strlen(string);
    int i;
    for(i=0; i<len; i++) {
        uartSendByte((uint8_t) string[i]);
    }
}
