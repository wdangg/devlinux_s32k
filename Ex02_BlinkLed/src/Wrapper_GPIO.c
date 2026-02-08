/*
 * Wrapper_GPIO.c
 *
 *  Created on: Feb 7, 2026
 *      Author: nthda
 */

#include "Wrapper_GPIO.h"

ARM_GPIO_Pin_t Wrapper_EncodePin(sPinDef_t map_pin)
{
    return ((ARM_GPIO_Pin_t)(ENCODE_PORT_NUM(map_pin.port) | (ENCODE_PIN_NUM(map_pin.pin))));
}

void Wrapper_GPIO_Setup(sPinDef_t map_pin, ARM_GPIO_SignalEvent_t cb_event)
{
    ARM_GPIO_Pin_t pin = 0;

    pin = Wrapper_EncodePin(map_pin);
    Driver_GPIO.Setup(pin, cb_event);
}

