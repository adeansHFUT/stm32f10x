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
	TIM3_CH12_steer_PWM_Init(1000,72-1);  // 72M/(72*1000)=1kMz的舵机频率，arr=1000	
	TIM_SetCompare1(TIM3,500);  //i值最大可以取499，因为ARR最大值是499.,499是不转
	TIM_SetCompare2(TIM3,750);
	updatepage(pagetable,0,"sf",844);
	while(1) 
	{		
		TIM_SetCompare1(TIM3,500);  //i值最大可以取499，因为ARR最大值是499.,499是不转
		TIM_SetCompare2(TIM3,750);
	}	  
	return 0;
}