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
	steerFrequency_Init(1);	
	set_steerDuty(1, 500); // 50%
	set_steerDuty(2, 250); //25%
	updatepage(pagetable,0,"sf",844);
	while(1) 
	{		
		
	}	  
	return 0;
}