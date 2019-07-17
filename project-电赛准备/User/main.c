#include "include.h"
show_node pagetable[16]; //用于OLED 屏幕显示字符的节点数字
/*16字体0模式--->4个节点(8字符)*/
/*12字体0模式--->8个节点(10字符)*/
/*16字体1模式--->8个节点(4字符)*/
/*12字体1模式--->16个节点(5字符)*/
int main(void)
{ 
    u8 t;
	LED_Init();
	NVIC_Configuration(); 	 
	OLED_Init();			//oled初始化 ，x是列，y是行
	OLED_Clear(); 
	t=' ';
	updatepage(pagetable, 0, "hello", 666);
	updatepage(pagetable, 1, "world", 2333);
	showpage(pagetable, 0, 12);
	while(1);
	while(1) 
	{		
		OLED_Clear();
		OLED_ShowCHinese(0,0,0); //
		OLED_ShowCHinese(18,0,1);
		OLED_ShowCHinese(36,0,2);
		OLED_ShowCHinese(54,0,3);//
		OLED_ShowCHinese(72,0,4);
		OLED_ShowCHinese(90,0,5);//
		OLED_ShowCHinese(108,0,6);//
		OLED_ShowString(0,3,"1.3' OLED TEST");
	
		OLED_ShowString(0,6,"ASCII:");  
		OLED_ShowString(63,6,"CODE:");  
		OLED_ShowChar(48,6,t); 
		t++;
		if(t>'~')t=' ';
		OLED_ShowNum(103,6,t,3,16);
			
		delay_ms(8000);
		delay_ms(8000);
		delay_ms(8000);
		delay_ms(8000);
		delay_ms(8000);
		delay_ms(8000);
		delay_ms(8000);
		OLED_Clear();
		OLED_DrawBMP(0,0,128,8,BMP1); 
		delay_ms(8000);
		delay_ms(8000);
		delay_ms(8000);
		delay_ms(8000);
		delay_ms(8000);
		delay_ms(8000);
		delay_ms(8000);
		delay_ms(8000);
		OLED_DrawBMP(0,0,128,8,BMP2);
		delay_ms(8000);
		delay_ms(8000);
		delay_ms(8000);
		delay_ms(8000);
		delay_ms(8000);
		delay_ms(8000);
		delay_ms(8000);

	}	  
	return 0;
}