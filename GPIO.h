/*
 * GPIO.h
 *
 *  Created on: Jul 31, 2017
 *      Author: Tung
 */

#ifndef GPIO_GPIO_H_
#define GPIO_GPIO_H_
#define LED_PORT             GPIO_PORTF_BASE
#define LED_RED              GPIO_PIN_1
#define LED_BLUE             GPIO_PIN_2

#define SWITCH_PORT          GPIO_PORTF_BASE
#define SWITCH               GPIO_PIN_4


extern void Config_LED(void);
extern void Blinky_LED(void);
extern void Config_SWITCH(void);




#endif /* GPIO_GPIO_H_ */
