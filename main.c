#include "uart.h"

int main(void) {
    uartInit();
    uartSetBaudRate(9600);
    uartSendString("Hello World!");
    return 0;
}
