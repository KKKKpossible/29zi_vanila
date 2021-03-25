/*
 * ap.c
 *
 *  Created on: Mar 24, 2021
 *      Author: sungjinkim
 */


#include "ap.h"





bool apInit(void)
{
    bool ret = true;

    uartOpen(DEF_UART_CHANNEL_0, 115200);

    return ret;
}

void apMain(void)
{
    uint32_t pre_tick = millis();

    while(true)
    {
        if(millis() - pre_tick >= 100)
        {
            pre_tick = millis();
        }

        if(uartAvailable(DEF_UART_CHANNEL_0) == true)
        {
            uartPrintf(DEF_UART_CHANNEL_0, "Received Data = %c\r\n", uartRead(DEF_UART_CHANNEL_0));
        }
    }
}
