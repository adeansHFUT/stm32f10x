

#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "tftlcd.h"
#include "key.h"
#include "stm32_flash.h"



#define STM32_FLASH_SAVE_ADDR  0X08070000		//����FLASH �����ַ(����Ϊż��������ֵҪ���ڱ�������ռ��FLASH�Ĵ�С+0X08000000)

const u8 text_buf[]="www.prechin.net";
#define TEXTLEN sizeof(text_buf)


int main()
{
	u8 i=0;
	u8 key;
	u8 read_buf[TEXTLEN];
	
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //�ж����ȼ����� ��2��
	LED_Init();
	USART1_Init(9600);
	TFTLCD_Init();			//LCD��ʼ��
	KEY_Init();
	
	FRONT_COLOR=BLACK;
	LCD_ShowString(10,10,tftlcd_data.width,tftlcd_data.height,16,"PRECHIN STM32F1");
	LCD_ShowString(10,30,tftlcd_data.width,tftlcd_data.height,16,"www.prechin.net");
	LCD_ShowString(10,50,tftlcd_data.width,tftlcd_data.height,16,"STM32_Flash Test");
	LCD_ShowString(10,70,tftlcd_data.width,tftlcd_data.height,16,"K_UP:Write   K_DOWN:Read");
	
	FRONT_COLOR=RED;
	LCD_ShowString(10,130,tftlcd_data.width,tftlcd_data.height,16,"Write:");
	LCD_ShowString(10,150,tftlcd_data.width,tftlcd_data.height,16,"Read :");
	
	while(1)
	{
		key=KEY_Scan(0);
		if(key==KEY_UP)
		{
			STM32_FLASH_Write(STM32_FLASH_SAVE_ADDR,(u16*)text_buf,TEXTLEN);
			printf("д������Ϊ��%s\r\n",text_buf);
			LCD_ShowString(10+6*8,130,tftlcd_data.width,tftlcd_data.height,16,(u8 *)text_buf);
		}
		if(key==KEY_DOWN)
		{
			STM32_FLASH_Read(STM32_FLASH_SAVE_ADDR,(u16 *)read_buf,TEXTLEN);
			printf("��ȡ����Ϊ��%s\r\n",read_buf);
			LCD_ShowString(10+6*8,150,tftlcd_data.width,tftlcd_data.height,16,read_buf);
		}
		
		i++;
		if(i%20==0)
		{
			led1=!led1;
		}
		
		delay_ms(10);
			
	}
}
