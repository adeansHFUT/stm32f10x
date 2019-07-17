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