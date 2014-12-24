#include "uart.h"

/*
 * Port usage:  PB0 - IN  - Shake Sensor
 *              PB1 - OUT - DTR (Shield Wake Up)
 *              PB2 - IN  - RI (Shield recieved something)
 *              PB3 - OUT - PWR (Shield Power Up)
 *              PB4 - OUT - RST (Shield hard reset) 
 */

int main(void) {
    uartInit();
    uartSetBaudRate(9600);
    uartSendString("Hello World!");
    return 0;
}
