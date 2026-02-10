/*
 * S32K144_PinMap.h
 *
 *  Created on: Feb 7, 2026
 *      Author: nthda
 */

#ifndef S32K144_PINMAP_H_
#define S32K144_PINMAP_H_

#include <stdint.h>
#include "S32K144.h"

typedef enum
{
    ePORTA,
    ePORTB,
    ePORTC,
    ePORTD,
    ePORTE,
    eMAX_PORT
} ePortName;

typedef struct
{
    ePortName port;
    uint32_t pin;
} sPinDef_t;

#define PTD15 ((sPinDef_t){ePORTD, 15u})  /* led red ptd15  */
#define PTD16 ((sPinDef_t){ePORTD, 16u})   /* led green ptd4 */
#define PTD0  ((sPinDef_t){ePORTD, 0u})   /* led blue ptd0  */
#define PTC12 ((sPinDef_t){ePORTC, 12u})  /* button 0 ptc12 */
#define PTC13 ((sPinDef_t){ePORTC, 13u})  /* button 1 ptc13 */

/* User RGB LED */
#define LED_RED     PTD15
#define LED_GREEN   PTD16
#define LED_BLUE    PTD0

/* User button */
#define BTN0    PTC12
#define BTN1    PTC13

#define PORT_MAX_NUM            5u
#define GPIO_MAX_PIN_IN_PORT    32u

#define PORT_NUM_SHIFT          8u
#define PIN_NUM_MASK            ((uint32_t)0xFFu)
#define PORT_NUM_MASK           ((uint32_t)(0xFFu << PORT_NUM_SHIFT))
#define ENCODE_PORT_NUM(x)      ((uint32_t)(x << PORT_NUM_SHIFT))
#define ENCODE_PIN_NUM(x)       ((uint32_t)(x << 0u))

#define DECODE_PORT_NUM(x)      (((uint32_t)x & PORT_NUM_MASK) >> PORT_NUM_SHIFT)
#define DECODE_PIN_NUM(x)       ((uint32_t)((uint32_t)x & PIN_NUM_MASK))

/* Pin mapping */
#define GPIO_MAX_PINS 160U
#define PIN_IS_AVAILABLE(n) ((DECODE_PORT_NUM(n) < PORT_MAX_NUM) && (DECODE_PIN_NUM(n) < 32))

#endif /* S32K144_PINMAP_H_ */
