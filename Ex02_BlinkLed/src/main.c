#include "S32K144.h"

#define DELAY_TIME      50000U

void delay(const uint32_t time)
{
    volatile uint32_t i;
    for (i = 0; i < time; i++)
    {
        /* do nothing */
    }
}

int main()
{
    /* Cap clock cho PORTC */
    IP_PCC->PCCn[PCC_PORTC_INDEX] |= PCC_PCCn_CGC(1);

    /* Cap clock cho PORTD */
    IP_PCC->PCCn[PCC_PORTD_INDEX] |= PCC_PCCn_CGC(1);

    /* Chon chuc nang cho PTC12*/
    IP_PORTC->PCR[12] |= PORT_PCR_MUX(0b001);

    /* Chon chuc nang cho PTD0*/
    IP_PORTD->PCR[0] |= PORT_PCR_MUX(0b001);

    /* Cau hinh input cho PTC12 */
    IP_PTC->PDDR &= ~(1U << 12);

    /* Cau hinh output cho PTD0 */
    IP_PTD->PDDR |= (1U << 0);

    /* Cau hinh pull-down cho PTC12 */
    IP_PORTC->PCR[12] &= ~(1U << 0);

    /* Cau hinh pu-pd enable */
    IP_PORTC->PCR[12] |= (1U << 0);

    /* Turn off PTD0 */
    IP_PTD->PDOR &= ~(1U << 0);

    while (1)
    {
        IP_PTD->PDOR |= (1U << 0);
        delay(DELAY_TIME);
        IP_PTD->PDOR &= ~(1U << 0);
        delay(DELAY_TIME);
    }

    return 0;
}