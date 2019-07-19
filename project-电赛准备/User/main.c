#include "include.h"

show_node pagetable[16]; //用于OLED 屏幕显示字符的节点数字
/*16字体0模式--->4个节点(8字符)*/
/*12字体0模式--->8个节点(10字符)*/
/*16字体1模式--->8个节点(4字符)*/
/*12字体1模式--->16个节点(5字符)*/
int main(void)
{ 
	SysTick_Init(72);
	LED_Init();
	NVIC_Configuration(); 	 
	OLED_Init();			//oled初始化
	OLED_Clear(); 
	TIM2_Init(200,72000-1);  // 1/(72M/72000)=1ms,200ms 定时器2
	steerFrequency_Init(1);	
	set_steerDuty(1, 500); // 50%
	set_steerDuty(2, 250); //25%
	updatepage(pagetable,0,"sf",844);
	while(1) 
	{		
		
	}	  
	return 0;
}