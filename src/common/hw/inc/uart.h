/*
 * uart.h
 *
 *  Created on: Mar 24, 2021
 *      Author: sungjinkim
 */

#ifndef SRC_COMMON_HW_INC_UART_H_
#define SRC_COMMON_HW_INC_UART_H_


#include "hw_def.h"


#ifdef  USE_UART_OPTION
#define DEF_UART_CHANNEL_MAX     HW_UART_CHANNEL_MAX


bool     uartInit      (void);

bool     uartOpen      (uint8_t ch, uint32_t baud);
bool     uartClose     (uint8_t ch);

bool     uartAvailable (uint8_t ch);
uint8_t  uartRead      (uint8_t ch);
uint32_t uartPrintf    (uint8_t ch, char* fm, ...);
uint32_t uartGetBaud   (uint8_t ch);
uint32_t uartWrite     (uint8_t ch, uint8_t* data, uint32_t len);

#endif

#endif /* SRC_COMMON_HW_INC_UART_H_ */
