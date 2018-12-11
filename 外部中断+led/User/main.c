#include "stm32f10x.h"
#include "led.h" 
#include "exti.h"

void delay(__IO u32 ncount)
{
	for(; ncount != 0; ncount--);
}

int main()
{
	LED_Init();
	exti_config();
	led(1); //³õÊ¼»¯Îª1
	while(1)
	{
		
//		led(1);
//		delay(0xffff0);
//		led(0)
//		delay(0xffff0);	
	}
	return 0;
}