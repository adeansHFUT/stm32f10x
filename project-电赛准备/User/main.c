#include "include.h"

show_node pagetable[16]; //����OLED ��Ļ��ʾ�ַ��Ľڵ�����
/*16����0ģʽ--->4���ڵ�(8�ַ�)*/
/*12����0ģʽ--->8���ڵ�(10�ַ�)*/
/*16����1ģʽ--->8���ڵ�(4�ַ�)*/
/*12����1ģʽ--->16���ڵ�(5�ַ�)*/
int main(void)
{ 
	SysTick_Init(72);
	LED_Init();
	NVIC_Configuration(); 	 
	OLED_Init();			//oled��ʼ��
	OLED_Clear(); 
	TIM2_Init(200,72000-1);  // 1/(72M/72000)=1ms,200ms ��ʱ��2
	TIM3_CH12_steer_PWM_Init(1000,72-1);  // 72M/(72*1000)=1kMz�Ķ��Ƶ�ʣ�arr=1000	
	TIM_SetCompare1(TIM3,500);  //iֵ������ȡ499����ΪARR���ֵ��499.,499�ǲ�ת
	TIM_SetCompare2(TIM3,750);
	updatepage(pagetable,0,"sf",844);
	while(1) 
	{		
		TIM_SetCompare1(TIM3,500);  //iֵ������ȡ499����ΪARR���ֵ��499.,499�ǲ�ת
		TIM_SetCompare2(TIM3,750);
	}	  
	return 0;
}