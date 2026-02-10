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

    /* Turn off led */
    Wrapper_GPIO_SetOuput(LED_BLUE, 1u);

    while(1)
    {
        if (BTN_PRESSED == Wrapper_GPIO_GetInput(BTN0))
        {
            delay_ms(1000000);
            if (0 == Wrapper_GPIO_GetDataOuput(LED_BLUE))
            {
                Wrapper_GPIO_SetOuput(LED_BLUE, 1);
            }
            else
            {
                Wrapper_GPIO_SetOuput(LED_BLUE, 0);
            }
        }
    }
    return 0;
}
