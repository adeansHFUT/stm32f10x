

#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "tftlcd.h"


/*******************************************************************************
* �� �� ��         : main
* ��������		   : ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
int main()
{
	u8 i=0;
	
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //�ж����ȼ����� ��2��
	LED_Init();
	USART1_Init(9600);
	TFTLCD_Init();			//LCD��ʼ��
	
	FRONT_COLOR=BLACK;
	LCD_ShowString(10,10,tftlcd_data.width,tftlcd_data.height,12,"Hello World!");
	LCD_ShowString(10,30,tftlcd_data.width,tftlcd_data.height,16,"Hello World!");
	LCD_ShowString(10,50,tftlcd_data.width,tftlcd_data.height,24,"Hello World!");
	LCD_ShowFontHZ(10, 80,"���пƼ�");
	LCD_ShowString(10,120,tftlcd_data.width,tftlcd_data.height,24,"www.prechin.cn");
	while(1)
	{
		i++;
		if(i%20==0)
		{
			led1=!led1;
		}
		
		delay_ms(10);
			
	}
}
