#ifndef _UART_H_
#define _UART_H_

#include "global.h"
#include <stdint.h>

#define UART_UBRR_CALC(BAUD_,FREQ_) ((FREQ_)/((BAUD_)*16L)-1)
#define UART_BAUD_RATE      9600 

void uartInit(void);
void uartSetBaudRate(uint16_t baudrate);
void uartSendByte(uint8_t byte);
void uartSendString(const char* string);

#endif
