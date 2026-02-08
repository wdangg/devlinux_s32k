/*
 * S32K144_PinMap.h
 *
 *  Created on: Feb 7, 2026
 *      Author: nthda
 */

#ifndef S32K144_PINMAP_H_
#define S32K144_PINMAP_H_

#include <stdint.h>

typedef enum
{
    PORTA,
    PORTB,
    PORTC,
    PORTD
} ePortName;

typedef struct
{
    ePortName port;
    uint32_t pin;
} sPinDef_t;

#define PTD15 ((sPinDef_t){PORTD, 15u})  /* led red ptd15  */
#define PTD4  ((sPinDef_t){PORTD, 4u})   /* led green ptd4 */
#define PTD0  ((sPinDef_t){PORTD, 0u})   /* led blue ptd0  */
#define PTC12 ((sPinDef_t){PORTC, 12u})  /* button 0 ptc12 */
#define PTC13 ((sPinDef_t){PORTC, 13u})  /* button 1 ptc13 */

/* User RGB LED */
#define LED_RED     PTD15
#define LED_GREEN   PTD4
#define LED_BLUE    PTD0

/* User button */
#define BTN0    PTC12
#define BTN1    PTC13

#endif /* S32K144_PINMAP_H_ */
