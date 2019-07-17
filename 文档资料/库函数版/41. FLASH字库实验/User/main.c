

#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "tftlcd.h"
#include "key.h"
#include "malloc.h" 
#include "sd.h"
#include "flash.h"
#include "ff.h" 
#include "fatfs_app.h"
#include "key.h"
#include "font_show.h"


int main()
{
	u8 i=0;
	u8 key;
	
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //�ж����ȼ����� ��2��
	LED_Init();
	USART1_Init(9600);
	TFTLCD_Init();			//LCD��ʼ��
	KEY_Init();
	EN25QXX_Init();				//��ʼ��EN25Q128	  
	my_mem_init(SRAMIN);		//��ʼ���ڲ��ڴ��
	
	FRONT_COLOR=RED;//��������Ϊ��ɫ 
	while(SD_Init()!=0)
	{	
		LCD_ShowString(10,10,tftlcd_data.width,tftlcd_data.height,16,"SD Card Error!");
	}
	FATFS_Init();							//Ϊfatfs��ر��������ڴ�				 
  	f_mount(fs[0],"0:",1); 					//����SD�� 
 	f_mount(fs[1],"1:",1); 				//����FLASH.
		
	LCD_ShowString(10,10,tftlcd_data.width,tftlcd_data.height,16,"Font Test     ");	
	LCD_ShowString(10,30,tftlcd_data.width,tftlcd_data.height,16,"www.prechin.net");
	LCD_ShowString(10,50,tftlcd_data.width,tftlcd_data.height,16,"K_UP: Font Update");

	while(1)
	{
FONT:		
		LCD_ShowFont16Char(10, 180, "���пƼ�");
		LCD_ShowFont12Char(10, 201, "PRECHIN");
		LCD_ShowFont12Char(10, 222, "www.prechin.net");    
		LCD_ShowFont12Char(10, 243, "��ӭʹ������STM32F1������");
		LCD_ShowFont12Char(10, 260, "����K_UP���������ֿ����....");
		
		while(1)
		{
			key=KEY_Scan(0);
			if(key==KEY_UP)
			{
				FontUpdate(GUI_UPDATE_ALL);
				LCD_Clear(WHITE);
				goto FONT;
			}
				
			i++;
			if(i%20==0)
			{
				led1=!led1;
			}
			delay_ms(10);
		}
		
	}
	
}
