/*
 * bsp.h
 *
 *  Created on: Mar 24, 2021
 *      Author: sungjinkim
 */

#ifndef SRC_BSP_BSP_H_
#define SRC_BSP_BSP_H_


#include "def.h"
#include "stm32f4xx_hal.h"





bool     bspInit(void);

void     SystemClock_Config(void);
void     Error_Handler(void);

void     delay(uint32_t ms);
uint32_t millis(void);


#endif /* SRC_BSP_BSP_H_ */
