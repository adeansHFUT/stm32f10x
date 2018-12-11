#ifndef __led_H
#define __led_H
#include "stm32f10x.h"

#define LED_PORT GPIOC

#define LED_PIN (GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5) 

#define LED_PORT_RCC  RCC_APB2Periph_GPIOC

#define led(a) {if(a) GPIO_ResetBits(LED_PORT,LED_PIN); else GPIO_SetBits(LED_PORT, LED_PIN); }

void LED_Init(void);
void led_change(void);

#endif