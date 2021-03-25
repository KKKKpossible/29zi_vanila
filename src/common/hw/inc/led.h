/*
 * led.h
 *
 *  Created on: 2021. 3. 25.
 *      Author: sungjinkim
 */

#ifndef SRC_COMMON_HW_INC_LED_H_
#define SRC_COMMON_HW_INC_LED_H_


#include "hw_def.h"


#ifdef  USE_LED_OPTION
#define DEF_LED_MAX_CHANNEL HW_LED_CHANNEL_MAX

bool ledInit   (void);
bool ledOn     (uint8_t ch);
bool ledOff    (uint8_t ch);
bool ledToggle (uint8_t ch);

#endif


#endif /* SRC_COMMON_HW_INC_LED_H_ */
