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

#define PORT_MAX_NUM  5u
#define GPIO_MAX_PIN_IN_PORT    32u

#define PORT_NUM_SHIFT   8u
#define PORT_NUM_MASK    ((uint32_t)(0xFFu << PORT_NUM_SHIFT))
#define ENCODE_PORT_NUM(x)  ((uint32_t)(x << PORT_NUM_SHIFT))

#define ENCODE_PIN_NUM(x)  ((uint32_t)(x << 0u))

#define PIN_MASK     ((uint32_t)(0xFFFFu & (~PORT_NUM_MASK)))

#define PIN_IS_AVAILABLE(n) ((PORT_NUM_MASK < PORT_MAX_NUM) && ())

ARM_GPIO_Pin_t Wrapper_EncodePin(sPinDef_t map_pin);

void Wrapper_GPIO_Setup(sPinDef_t map_pin, ARM_GPIO_SignalEvent_t cb_event);

#endif /* WRAPPER_GPIO_H_ */
