#include "S32K144.h"
#include <stdio.h>
#include <stdint.h>
#include "Wrapper_GPIO.h"

/* led blue ptd0  */
/* button 0 ptc12 */

#define PCC_CGC_ENABLE          1u
#define PORT_PCR_MUX_GPIO       1u
#define PORT_PCR_PE_ENABLE      1u
#define PORT_PCR_PS_PULLDOWN    0u
#define PORT_PCR_PS_PULLUP      1u
#define GPIO_PDDR_OUPUT         1u
#define GPIO_PDDR_INPUT         0u

void delay_ms(const uint32_t ms)
{
    volatile uint32_t i = 0u;
    for (i = 0; i < ms; i++)
    {
        /* do nothing */
    }
}

int main(void)
{
    // /* Enable clock for port C and port D via CGC of PCC, bus interface BUS_CLK */
    // IP_PCC->PCCn[PCC_PORTC_INDEX] |= PCC_PCCn_CGC(PCC_CGC_ENABLE);
    // IP_PCC->PCCn[PCC_PORTD_INDEX] |= PCC_PCCn_CGC(PCC_CGC_ENABLE);

    // /* Config PTD0 and PTC12 as GPIO mode via PORT_PCRn_MUX */
    // IP_PORTD->PCR[LED_BLUE.pin] |= PORT_PCR_MUX(PORT_PCR_MUX_GPIO);
    // IP_PORTC->PCR[BTN0.pin] |= PORT_PCR_MUX(PORT_PCR_MUX_GPIO);

    // /* Config PTD0 as OUPUT pin via GPIO PDDR */
    // IP_PTD->PDDR |= GPIO_PDDR_PDD(GPIO_PDDR_OUPUT);
    
    // /* Config PTC12 as INPUT pin via GPIO PDDR */
    // IP_PTD->PDDR &= ~GPIO_PDDR_PDD(GPIO_PDDR_INPUT);

    // /* Enable pull for BTN0-PTC12 via PORT_PCR_PE */
    // IP_PORTC->PCR[BTN0.pin] |= PORT_PCR_PE(PORT_PCR_PE_ENABLE);
    
    // /* Set pull-down for BTN0 via PORT_PCR_PS */
    // IP_PORTC->PCR[BTN0.pin] |= PORT_PCR_PS(PORT_PCR_PS_PULLDOWN);

    Wrapper_GPIO_Setup(LED_BLUE, NULL);
    Wrapper_GPIO_SetDirection(LED_BLUE, ARM_GPIO_OUTPUT);

    while(1)
    {
        // if ((IP_PTC->PDIR & (1u << (uint32_t)BTN0.pin)) != ((1u << (uint32_t)BTN0.pin)))
        // {
            delay_ms(3000000);
            IP_PTD->PTOR |= (1u << LED_BLUE.pin);
        // }
    }

    return 0;
}
