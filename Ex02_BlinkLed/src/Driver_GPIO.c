/*
 * Copyright (c) 2023 ARM Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Driver_GPIO.h"

/* Pin mapping */
#define GPIO_MAX_PINS 160U

/**
 * @brief
 *
 * @param pin
 * @param cb_event
 * @return * int32_t
 */
static int32_t GPIO_Setup(ARM_GPIO_Pin_t pin, ARM_GPIO_SignalEvent_t cb_event)
{
    int32_t result = ARM_DRIVER_OK;

    if (PIN_IS_AVAILABLE(pin))
    {
    }
    else
    {
        result = ARM_GPIO_ERROR_PIN;
    }

    return result;
}

/**
 * @brief
 *
 * @param pin
 * @param direction
 * @return * int32_t
 */
static int32_t GPIO_SetDirection(ARM_GPIO_Pin_t pin, ARM_GPIO_DIRECTION direction)
{
    int32_t result = ARM_DRIVER_OK;

    if (PIN_IS_AVAILABLE(pin))
    {
        switch (direction)
        {
        case ARM_GPIO_INPUT:
            break;
        case ARM_GPIO_OUTPUT:
            break;
        default:
            result = ARM_DRIVER_ERROR_PARAMETER;
            break;
        }
    }
    else
    {
        result = ARM_GPIO_ERROR_PIN;
    }

    return result;
}

/**
 * @brief
 *
 * @param pin
 * @param mode
 * @return * int32_t
 */
static int32_t GPIO_SetOutputMode(ARM_GPIO_Pin_t pin, ARM_GPIO_OUTPUT_MODE mode)
{
    int32_t result = ARM_DRIVER_OK;

    if (PIN_IS_AVAILABLE(pin))
    {
        switch (mode)
        {
        case ARM_GPIO_PUSH_PULL:
            break;
        case ARM_GPIO_OPEN_DRAIN:
            break;
        default:
            result = ARM_DRIVER_ERROR_PARAMETER;
            break;
        }
    }
    else
    {
        result = ARM_GPIO_ERROR_PIN;
    }

    return result;
}

/**
 * @brief
 *
 * @param pin
 * @param resistor
 * @return * int32_t
 */
static int32_t GPIO_SetPullResistor(ARM_GPIO_Pin_t pin, ARM_GPIO_PULL_RESISTOR resistor)
{
    int32_t result = ARM_DRIVER_OK;

    if (PIN_IS_AVAILABLE(pin))
    {
        switch (resistor)
        {
        case ARM_GPIO_PULL_NONE:
            break;
        case ARM_GPIO_PULL_UP:
            break;
        case ARM_GPIO_PULL_DOWN:
            break;
        default:
            result = ARM_DRIVER_ERROR_PARAMETER;
            break;
        }
    }
    else
    {
        result = ARM_GPIO_ERROR_PIN;
    }

    return result;
}

/**
 * @brief
 *
 * @param pin
 * @param trigger
 * @return * int32_t
 */
static int32_t GPIO_SetEventTrigger(ARM_GPIO_Pin_t pin, ARM_GPIO_EVENT_TRIGGER trigger)
{
    int32_t result = ARM_DRIVER_OK;

    if (PIN_IS_AVAILABLE(pin))
    {
        switch (trigger)
        {
        case ARM_GPIO_TRIGGER_NONE:
            break;
        case ARM_GPIO_TRIGGER_RISING_EDGE:
            break;
        case ARM_GPIO_TRIGGER_FALLING_EDGE:
            break;
        case ARM_GPIO_TRIGGER_EITHER_EDGE:
            break;
        default:
            result = ARM_DRIVER_ERROR_PARAMETER;
            break;
        }
    }
    else
    {
        result = ARM_GPIO_ERROR_PIN;
    }

    return result;
}

/**
 * @brief
 *
 * @param pin
 * @param val
 * @return * void
 */
static void GPIO_SetOutput(ARM_GPIO_Pin_t pin, uint32_t val)
{

    if (PIN_IS_AVAILABLE(pin))
    {
    }
}

/**
 * @brief
 *
 * @param pin
 * @return * uint32_t
 */
static uint32_t GPIO_GetInput(ARM_GPIO_Pin_t pin)
{
    uint32_t val = 0U;

    if (PIN_IS_AVAILABLE(pin))
    {
    }
    return val;
}

/* GPIO Driver access structure */
ARM_DRIVER_GPIO Driver_GPIO = {
    GPIO_Setup,
    GPIO_SetDirection,
    GPIO_SetOutputMode,
    GPIO_SetPullResistor,
    GPIO_SetEventTrigger,
    GPIO_SetOutput,
    GPIO_GetInput
};
