/*
 * Ip_PORT.c
 *
 *  Created on: Feb 9, 2026
 *      Author: nthda
 */
#include "Ip_PORT.h"

void Ip_PORT_GetPortAddress(ePortName port, PORT_Type **pPort)
{
    switch (port)
    {
    case ePORTA:
        *pPort = ((PORT_Type *)IP_PORTA_BASE);
        break;
    case ePORTB:
        *pPort = ((PORT_Type *)IP_PORTB_BASE);
        break;
    case ePORTC:
        *pPort = ((PORT_Type *)IP_PORTC_BASE);
        break;
    case ePORTD:
        *pPort = ((PORT_Type *)IP_PORTD_BASE);
        break;
    case ePORTE:
        *pPort = ((PORT_Type *)IP_PORTE_BASE);
        break;
    
    default:
        *pPort = (PORT_Type *)NULL;
        break;
    }
}

int32_t Ip_PORT_SetMux(uint32_t port, uint32_t pin, ePORT_ALTERNATIVE_t alternative)
{
    int32_t result = IP_RETURN_ERROR;
    PORT_Type *pPort = NULL;

    Ip_PORT_GetPortAddress(port, &pPort);

    if ((ePORT_PCRn_AL_0 <= alternative) && (ePORT_PCRn_AL_7 > alternative))
    {
        /* Clear MUX data before write */
        pPort->PCR[pin] &= (~(PORT_PCR_MUX_MASK));
        /* Write data for MUX */
        pPort->PCR[pin] |= PORT_PCR_MUX(alternative);
    }

    return result;
}

