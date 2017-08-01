

#include "include.h"

/**
 * main.c
 */

void main(void)
{
    SysCtlClockSet(SYSCTL_SYSDIV_5  | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);

    Config_LED();
    Config_SWITCH();

    while(1)
    {

             Blinky_LED();



    }

}
