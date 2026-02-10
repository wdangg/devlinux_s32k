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
    uint32_t time_out = IP_TIMEOUT;

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
    
    while (((time_out--) > IP_TIMEOUT_OCCURRED) && 
            (0u != (IP_PCC->PCCn[index] & PCC_PCCn_PR_MASK)))
    {
        /* Set CGC field until PR field is set */
        IP_PCC->PCCn[index] |= PCC_PCCn_CGC(PCC_CGC_ENABLE);
    }

    if (IP_TIMEOUT_OCCURRED == time_out)
    {
        result = IP_RETURN_ERROR;
    }

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

uint32_t Ip_GPIO_GetInput(uint32_t port, uint32_t pin)
{
    uint32_t result = 0u;
    GPIO_Type *pGpio = NULL;
    uint32_t pin_mask = 0u;
    uint32_t reg_val = 0u;

    pin_mask = (1u << (uint32_t)pin);
    Ip_GPIO_GetGpioAddress(port, &pGpio);
    reg_val = (uint32_t)(pGpio->PDIR);
    
    if (0u != (pin_mask & reg_val))
    {
        result = 1u;
    }

    return result;
}

uint32_t Ip_GPIO_GetDataOuput(uint32_t port, uint32_t pin)
{
    uint32_t ret_val = 0u;
    GPIO_Type *pGpio = NULL;
    uint32_t pin_mask = 0u;
    
    pin_mask = (1u << (uint32_t)pin);
    Ip_GPIO_GetGpioAddress(port, &pGpio);

    if (pin_mask == (pin_mask & (pGpio->PDOR)))
    {
        ret_val = 1u;
    }
    else
    {
        ret_val = 0u;
    }

    return ret_val;
}

void Ip_GPIO_SetOuput(uint32_t port, uint32_t pin, uint32_t val)
{
    GPIO_Type *pGpio = NULL;
    uint32_t data = 0u;
    uint32_t pin_mask = 0u;

    if (0u != val)
    {
        data = 1u;
    }
    pin_mask = (1u << pin);
    Ip_GPIO_GetGpioAddress(port, &pGpio);
    /* Clear data be fore write */
    pGpio->PDOR &= ~pin_mask;
    /* Write data */
    pGpio->PDOR |= GPIO_PDOR_PDO(data);
}

void Ip_GPIO_ToggleOuput(uint32_t port, uint32_t pin)
{
    GPIO_Type *pGpio = NULL;
    uint32_t data = 0u;
    uint32_t pin_mask = 0u;

    Ip_GPIO_GetGpioAddress(port, &pGpio);
    pin_mask = (1u << pin);
    if (pin_mask == (pin_mask & (pGpio->PDOR)))
    {
        data = 0u;
    }
    else
    {
        data = 1u;
    }
    /* Clear data be fore write */
    pGpio->PDOR &= ~pin_mask;
    /* Write data */
    pGpio->PDOR |= GPIO_PDOR_PDO(data);
}
