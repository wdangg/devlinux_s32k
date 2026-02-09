/*
 * Ip_GPIO.c
 *
 *  Created on: Feb 7, 2026
 *      Author: nthda
 */

#include "Ip_GPIO.h"

void Ip_GPIO_GetGpioAddress(ePortName port, GPIO_Type **pGpio)
{
    switch (port)
    {
    case ePORTA:
        *pGpio = ((GPIO_Type *)IP_PTA_BASE);
        break;
    case ePORTB:
        *pGpio = ((GPIO_Type *)IP_PTB_BASE);
        break;
    case ePORTC:
        *pGpio = ((GPIO_Type *)IP_PTC_BASE);
        break;
    case ePORTD:
        *pGpio = ((GPIO_Type *)IP_PTD_BASE);
        break;
    case ePORTE:
        *pGpio = ((GPIO_Type *)IP_PTE_BASE);
        break;
    
    default:
        *pGpio = (GPIO_Type *)NULL;
        break;
    }
}

int32_t Ip_GPIO_EnableClock(uint32_t port)
{
    int32_t result = IP_RETURN_OK;
    uint32_t index = 0u;

    switch (port)
    {
        case ePORTA:
            index = PCC_PORTA_INDEX;
            break;
        case ePORTB:
            index = PCC_PORTB_INDEX;
            break;
        case ePORTC:
            index = PCC_PORTC_INDEX;
            break;
        case ePORTD:
            index = PCC_PORTD_INDEX;
            break;
        case ePORTE:
            index = PCC_PORTE_INDEX;
            break;

        default:
            result = IP_RETURN_ERROR;
            break;
    }

    /* Enable clock for PORT via PCC_CGC */
    IP_PCC->PCCn[index] |= PCC_PCCn_CGC(PCC_CGC_ENABLE);

    return result;
}

int32_t Ip_GPIO_SetDirection(uint32_t port, uint32_t pin, eGPIO_DIRECTION_t direction)
{
    int32_t result = IP_RETURN_ERROR;
    GPIO_Type *pGpio = NULL;

    Ip_GPIO_GetGpioAddress(port, &pGpio);

    /* Set pin direction via GPIO_PDD, port data direction */
    pGpio->PDDR &= (~GPIO_PDDR_PDD_MASK);
    pGpio->PDDR |= GPIO_PDDR_PDD(direction);

    return result;
}
