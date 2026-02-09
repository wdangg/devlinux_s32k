/*
 * Wrapper_GPIO.h
 *
 *  Created on: Feb 7, 2026
 *      Author: nthda
 */

#ifndef WRAPPER_GPIO_H_
#define WRAPPER_GPIO_H_

#include "S32K144_PinMap.h"
#include "Driver_GPIO.h"

ARM_GPIO_Pin_t Wrapper_EncodePin(sPinDef_t map_pin);

int32_t Wrapper_GPIO_Setup(sPinDef_t map_pin, ARM_GPIO_SignalEvent_t cb_event);

int32_t Wrapper_GPIO_SetDirection(sPinDef_t map_pin, ARM_GPIO_DIRECTION direction);

#endif /* WRAPPER_GPIO_H_ */
