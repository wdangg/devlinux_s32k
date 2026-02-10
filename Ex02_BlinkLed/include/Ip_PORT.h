/*
 * Ip_PORT.h
 *
 *  Created on: Feb 9, 2026
 *      Author: nthda
 */

#ifndef IP_PORT_H_
#define IP_PORT_H_

#include <stdio.h>
#include "S32K144.h"
#include "S32K144_PinMap.h"
#include "Ip_Common.h"

typedef enum
{
    ePORT_PCRn_AL_0, /* analog */
    ePORT_PCRn_AL_1, /* gpio */
    ePORT_PCRn_AL_2, /* chip-specific */
    ePORT_PCRn_AL_3, /* chip-specific */
    ePORT_PCRn_AL_4, /* chip-specific */
    ePORT_PCRn_AL_5, /* chip-specific */
    ePORT_PCRn_AL_6, /* chip-specific */
    ePORT_PCRn_AL_7, /* chip-specific */
} ePORT_ALTERNATIVE_t;

/**
\brief GPIO Pull enable
*/
typedef enum {
    IP_PORT_PCR_PE_NOT_ENABLE,                     /* Pull not enable */
    IP_PORT_PCR_PE_ENABLE,                         /* Pull enable */
} ePORT_PCR_PE_t;

/**
\brief GPIO Pull selection
*/
typedef enum {
    IP_PORT_PCR_PS_PULLDOWN,                      /* Pull-down selection */
    IP_PORT_PCR_PS_PULLUP,                        /* Pull-up selection */
} ePORT_PCR_PS_t;

void Ip_PORT_GetPortAddress(ePortName port, PORT_Type **pPort);

int32_t Ip_PORT_SetMux(uint32_t port, uint32_t pin, ePORT_ALTERNATIVE_t alternative);

int32_t Ip_PORT_PullEnable(uint32_t port, uint32_t pin, ePORT_PCR_PE_t pe);

int32_t Ip_PORT_PullSelect(uint32_t port, uint32_t pin, ePORT_PCR_PE_t ps);

#endif /* IP_PORT_H_ */
