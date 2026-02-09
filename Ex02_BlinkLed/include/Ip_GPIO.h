/*
 * Ip_GPIO.h
 *
 *  Created on: Feb 9, 2026
 *      Author: nthda
 */

#ifndef IP_GPIO_H_
#define IP_GPIO_H_

#include <stdio.h>
#include "S32K144.h"
#include "S32K144_PinMap.h"
#include "Ip_Common.h"

#define PCC_CGC_ENABLE          1u

typedef enum 
{
    eIP_GPIO_INPUT,                       ///< Input (default)
    eIP_GPIO_OUTPUT                       ///< Output
} eGPIO_DIRECTION_t;

void Ip_GPIO_GetGpioAddress(ePortName port, GPIO_Type **pGpio);

int32_t Ip_GPIO_EnableClock(uint32_t port);

int32_t Ip_GPIO_SetDirection(uint32_t port, uint32_t pin, eGPIO_DIRECTION_t direction);

#endif /* IP_GPIO_H_ */
