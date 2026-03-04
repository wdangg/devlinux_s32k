#include "S32K144.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
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

#define BTN_PRESSED             0u
#define BTN_RELEASED            1u

#define S32_NVIC_ISER_BASE  ((uint32_t)0xE000E100u)

typedef struct 
{
    volatile uint32_t ISER[15u];
} S32_NVIC_ISER_t;

S32_NVIC_ISER_t *S32_NVIC_ISER = ((S32_NVIC_ISER_t *)S32_NVIC_ISER_BASE);

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
    /* Setup led pin PTD0 */
    Wrapper_GPIO_Setup(LED_BLUE, NULL);
    /* Config led pin is ouput */
    Wrapper_GPIO_SetDirection(LED_BLUE, ARM_GPIO_OUTPUT);
    
    Wrapper_GPIO_Setup(BTN0, NULL);

    Wrapper_GPIO_SetDirection(BTN0, ARM_GPIO_INPUT);
    Wrapper_GPIO_SetPullResistor(BTN0, ARM_GPIO_PULL_UP);
    
    /* Interrupt configured PORT_PCR_IRQC */
    /**
        1000 ISF flag and Interrupt when logic 0.
        1001 ISF flag and Interrupt on rising-edge.
        1010 ISF flag and Interrupt on falling-edge.
        1011 ISF flag and Interrupt on either edge.
        1100 ISF flag and Interrupt when logic 1.
     */
    IP_PORTC->PCR[BTN0.pin] &= ~PORT_PCR_IRQC_MASK;
    /* falling edge */
    IP_PORTC->PCR[BTN0.pin] |= PORT_PCR_IRQC(0b1010);

    /* NVIC enable interrupt */
    S32_NVIC_ISER->ISER[PORTC_IRQn/32] |= (1 << (PORTC_IRQn % 32));

    /* Turn off led */
    Wrapper_GPIO_SetOuput(LED_BLUE, 1u);

    while(1)
    {
        /* Do nothing, wait interrupt */
    }
    return 0;
}

void PORTC_IRQHandler(void)
{
    /* Clear pneding via PORT_PCR_ISF - write 1 to clear*/
    IP_PORTC->PCR[BTN0.pin] |= PORT_PCR_ISF_MASK;
    /* Toggle the blue led */
    Wrapper_GPIO_ToggleOuput(LED_BLUE);
}
