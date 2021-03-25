/*
 * hw.c
 *
 *  Created on: Mar 24, 2021
 *      Author: sungjinkim
 */


#include "hw.h"





bool gpioInit(void)
{
    bool ret = true;

    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    return ret;
}

bool hwInit(void)
{
    bool ret = true;

    bspInit();
    gpioInit();

    usbInit();
    uartInit();

    return ret;
}
