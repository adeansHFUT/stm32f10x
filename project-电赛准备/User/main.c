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
	TIM2_Init(200,72000-1);  // 1/(72M/72000),200ms
	//showpage(pagetable, 1, 12);
	while(1) 
	{		
		updatepage(pagetable, 0, "hello", 666);
		updatepage(pagetable, 1, "world", 2333);
		updatepage(pagetable, 2, "start", 465);
		updatepage(pagetable, 3, "world", 2333);
		updatepage(pagetable, 4, "start", 465);
		delay_ms(1000);
		updatepage(pagetable, 0, "new", 1);
		updatepage(pagetable, 1, "new", 2);
		updatepage(pagetable, 2, "new", 3);
		updatepage(pagetable, 3, "new", 4);
		updatepage(pagetable, 4, "new", 5);
		delay_ms(1000);
	}	  
	return 0;
}