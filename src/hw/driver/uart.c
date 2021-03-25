/*
 * uart.c
 *
 *  Created on: Mar 24, 2021
 *      Author: sungjinkim
 */


#include "uart.h"
#include "usb.h"
#include "stdio.h"
#include "stdarg.h"


static bool uart_isopen[DEF_UART_CHANNEL_MAX] = {0, };


bool uartInit(void)
{
    bool ret = true;

    for(int i = 0; i < DEF_UART_CHANNEL_MAX; i++)
    {
        uart_isopen[i] = false;
    }

    return ret;
}


bool uartOpen(uint8_t ch, uint32_t baud)
{
    bool ret = true;

    switch(ch)
    {
        case DEF_UART_CHANNEL_0:
        case DEF_UART_CHANNEL_1:
        case DEF_UART_CHANNEL_2:
        case DEF_UART_CHANNEL_3:
            uart_isopen[ch] = true;
            break;
        default:
            ret = false;
            break;
    }

    return ret;
}

bool uartClose(uint8_t ch)
{
    bool ret = true;

    switch(ch)
    {
        case DEF_UART_CHANNEL_0:
        case DEF_UART_CHANNEL_1:
        case DEF_UART_CHANNEL_2:
        case DEF_UART_CHANNEL_3:
            uart_isopen[ch] = false;
            break;
        default:
            ret = false;
            break;
    }

    return ret;
}

bool uartAvailable(uint8_t ch)
{
    bool ret = true;

    switch(ch)
    {
        case DEF_UART_CHANNEL_0:
            ret = cdcAvailable();
            break;
        default:
            break;
    }

    return ret;
}

uint32_t uartWrite(uint8_t ch, uint8_t* data, uint32_t len)
{
    uint32_t ret = 0;

    switch(ch)
    {
        case DEF_UART_CHANNEL_0:
            ret = cdcTransmit(data, len);
            break;
        case DEF_UART_CHANNEL_1:
            break;
        case DEF_UART_CHANNEL_2:
            break;
        case DEF_UART_CHANNEL_3:
            break;
    }

    return ret;
}

uint8_t uartRead(uint8_t ch)
{
    uint8_t ret = true;

    switch(ch)
    {
        case DEF_UART_CHANNEL_0:
            ret = cdcGetFromBuffer();
            break;
        default:
            break;
    }

    return ret;
}

uint32_t uartPrintf(uint8_t ch, char* fm, ...)
{
    uint32_t ret = 0;

    char buff[2048] = {0, };
    va_list args;
    int len;

    va_start(args, fm);
    len = vsprintf(buff, (const char*)fm, args);

    ret = uartWrite(ch, (uint8_t*)buff, len);

    va_end(args);

    return ret;
}

uint32_t uartGetBaud(uint8_t ch)
{
    uint32_t ret;

    switch(ch)
    {
        case DEF_UART_CHANNEL_0:
            ret = cdcGetBaud();
            break;
        default:
            break;
    }

    return ret;
}
