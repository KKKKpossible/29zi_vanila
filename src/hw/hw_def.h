/*
 * hw_def.h
 *
 *  Created on: Mar 24, 2021
 *      Author: sungjinkim
 */

#ifndef SRC_HW_HW_DEF_H_
#define SRC_HW_HW_DEF_H_


#include "def.h"
#include "bsp.h"


#define USE_UART_OPTION
    #define HW_UART_CHANNEL_MAX     (4U)

#define USE_USB_OPTION
    #define HW_USB_CHANNEL_MAX      (1U)

#define USE_LED_OPTION
    #define HW_LED_CHANNEL_MAX      (2U)

#endif /* SRC_HW_HW_DEF_H_ */
