/*
 * usb.h
 *
 *  Created on: Mar 24, 2021
 *      Author: sungjinkim
 */

#ifndef SRC_COMMON_HW_INC_USB_H_
#define SRC_COMMON_HW_INC_USB_H_


#include "hw_def.h"


#ifdef  USE_USB_OPTION
#define DEF_USB_CHANNEL_MAX HW_USB_CHANNEL_MAX


bool     usbInit          (void);
bool     cdcWriteOnBuffer (uint8_t data);
uint8_t  cdcGetFromBuffer (void);
uint32_t cdcAvailable     (void);
uint32_t cdcTransmit      (uint8_t* data, uint32_t len);
uint32_t cdcGetBaud       (void);


#endif

#endif /* SRC_COMMON_HW_INC_USB_H_ */
