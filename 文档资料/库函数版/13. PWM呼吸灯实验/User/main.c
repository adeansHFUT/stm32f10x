

#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "pwm.h"

int main()
{
	u16 i=0,j=300;  
	u8 fx=0;
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //中断优先级分组 分2组
	LED_Init();
	TIM3_CH1_PWM_Init(500,72-1); //频率是2Kh
	TIM4_CH1_PWM_Init(500,72-1);
	while(1)
	{
		
		if(fx==0)
		{
			i++;
			if(i==400)
			{
				fx=1;
			}
		}
		else
		{
			i--;
			if(i==0)                                                                               
			{
				fx=0;
			}
		}
		TIM_SetCompare1(TIM4,400-i);  //i值最大可以取499，因为ARR最大值是499.,499是不转
		TIM_SetCompare2(TIM4,i);
		TIM_SetCompare3(TIM4,400-i);
		TIM_SetCompare4(TIM4,499);
		delay_ms(10);	
	}
}
