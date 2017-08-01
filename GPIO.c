/*
 * GPIO.c
 *
 *  Created on: Jul 31, 2017
 *      Author: Tung
 */

#include "../include.h"
#include "GPIO.h"

static uint32_t LED_Status=LED_RED;
static void SWITCH_ISR(void);
extern void config_LED(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutputOD(LED_PORT, LED_RED | LED_BLUE);
    GPIOPinWrite(LED_PORT, LED_RED | LED_BLUE, 0);


}

extern void Blinky_LED(void)
{
    static uint8_t i=0;
    if (i==0)
    {
        i=LED_Status;
    }
    else
    {
        i=0;
    }
    GPIOPinWrite(LED_PORT, LED_RED | LED_BLUE, i);
    SysCtlDelay(SysCtlClockGet()/3);
}

extern void Config_SWITCH(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOInput(SWITCH_PORT, SWITCH);
    GPIOPadConfigSet(SWITCH_PORT, SWITCH, GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD_WPU);
    GPIOIntRegister(SWITCH_PORT,&SWITCH_ISR);
    GPIOIntEnable(SWITCH_PORT,GPIO_INT_PIN_4);
    IntEnable(INT_GPIOF);
    IntMasterEnable();
}
static void SWITCH_ISR(void)
{
    if(LED_Status==LED_RED)
        LED_Status=LED_BLUE;
    else
        LED_Status=LED_RED;

}
