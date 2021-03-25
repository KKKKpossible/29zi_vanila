/*
 * usb.c
 *
 *  Created on: Mar 24, 2021
 *      Author: sungjinkim
 */


#include "usb.h"
#include "usb_device.h"
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_cdc.h"
#include "usbd_cdc_if.h"


extern USBD_HandleTypeDef hUsbDeviceHS;


bool usbInit(void)
{
    bool ret = true;

    if (USBD_Init(&hUsbDeviceHS, &HS_Desc, DEVICE_HS) != USBD_OK)
    {
        Error_Handler();
    }
    if (USBD_RegisterClass(&hUsbDeviceHS, &USBD_CDC) != USBD_OK)
    {
        Error_Handler();
    }
    if (USBD_CDC_RegisterInterface(&hUsbDeviceHS, &USBD_Interface_fops_HS) != USBD_OK)
    {
        Error_Handler();
    }
    if (USBD_Start(&hUsbDeviceHS) != USBD_OK)
    {
        Error_Handler();
    }

    return ret;
}
