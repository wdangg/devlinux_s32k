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

int32_t Wrapper_GPIO_Setup(sPinDef_t map_pin, ARM_GPIO_SignalEvent_t cb_event)
{
    int32_t result = ARM_DRIVER_OK;
    ARM_GPIO_Pin_t pin;
    
    pin = Wrapper_EncodePin(map_pin);
    result = Driver_GPIO.Setup(pin, cb_event);

    return result;
}

int32_t Wrapper_GPIO_SetDirection(sPinDef_t map_pin, ARM_GPIO_DIRECTION direction)
{
    int32_t result = ARM_DRIVER_OK;
    ARM_GPIO_Pin_t pin;
    
    pin = Wrapper_EncodePin(map_pin);
    result = Driver_GPIO.SetDirection(pin, direction);

    return result;
}

int32_t Wrapper_GPIO_SetPullResistor(sPinDef_t map_pin, ARM_GPIO_PULL_RESISTOR ps)
{
    int32_t result = ARM_DRIVER_OK;
    ARM_GPIO_Pin_t pin;
    
    pin = Wrapper_EncodePin(map_pin);
    result = Driver_GPIO.SetPullResistor(pin, ps);
    
    return result;
}

void Wrapper_GPIO_SetOuput(sPinDef_t map_pin, uint32_t val)
{
    ARM_GPIO_Pin_t pin;
    
    pin = Wrapper_EncodePin(map_pin);
    Driver_GPIO.SetOutput(pin, val);
}

uint32_t Wrapper_GPIO_GetInput(sPinDef_t map_pin)
{
    uint32_t result = 0u;
    ARM_GPIO_Pin_t pin;
    
    pin = Wrapper_EncodePin(map_pin);
    result = Driver_GPIO.GetInput(pin);

    return result;
}

uint32_t Wrapper_GPIO_GetDataOuput(sPinDef_t map_pin)
{
    uint32_t result = 0;
    ARM_GPIO_Pin_t pin;
    
    pin = Wrapper_EncodePin(map_pin);
    result = Driver_GPIO.GetDataOutput(pin);

    return result;
}

void Wrapper_GPIO_ToggleOuput(sPinDef_t map_pin)
{
    ARM_GPIO_Pin_t pin;
    
    pin = Wrapper_EncodePin(map_pin);
    Driver_GPIO.ToggleOutput(pin);
}
