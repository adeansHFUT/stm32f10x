#include "led.h"


void LED_Init()
{
 
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(LED_PORT_RCC,ENABLE);
	GPIO_InitStructure.GPIO_Pin = LED_PIN;    //GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
	GPIO_Init(LED_PORT,&GPIO_InitStructure); 
	GPIO_SetBits(LED_PORT,LED_PIN); 
	
}

void led_change(void) //led灯取反
{
	GPIO_WriteBit(LED_PORT, LED_PIN, (BitAction)(1-GPIO_ReadOutputDataBit (LED_PORT,LED_PIN)));
}

