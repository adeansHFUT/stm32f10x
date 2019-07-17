

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
	
int main()
{
	u8 i=0;
	u32 free,total;
	
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //�ж����ȼ����� ��2��
	LED_Init();
	USART1_Init(9600);
	TFTLCD_Init();			//LCD��ʼ��
	
	EN25QXX_Init();				//��ʼ��EN25Q128	  
	my_mem_init(SRAMIN);		//��ʼ���ڲ��ڴ��
	
	FRONT_COLOR=RED;//��������Ϊ��ɫ 
	LCD_ShowString(10,10,tftlcd_data.width,tftlcd_data.height,16,"PRECHIN STM32F1");	
	LCD_ShowString(10,30,tftlcd_data.width,tftlcd_data.height,16,"FatFs Test");	
	LCD_ShowString(10,50,tftlcd_data.width,tftlcd_data.height,16,"www.prechin.net");
	
	while(SD_Init())//��ⲻ��SD��
	{
		LCD_ShowString(10,100,tftlcd_data.width,tftlcd_data.height,16,"SD Card Error!");
		printf("SD Card Error!\r\n");
		delay_ms(500);					
	}
	
 	FRONT_COLOR=BLUE;	//��������Ϊ��ɫ 
	//���SD���ɹ� 			
	printf("SD Card OK!\r\n");	
	LCD_ShowString(10,100,tftlcd_data.width,tftlcd_data.height,16,"SD Card OK    ");
	
	FATFS_Init();							//Ϊfatfs��ر��������ڴ�				 
  	f_mount(fs[0],"0:",1); 					//����SD�� 	
			  
	while(FATFS_GetFree("0:",&total,&free))	//�õ�SD������������ʣ������
	{
		LCD_ShowString(10,120,tftlcd_data.width,tftlcd_data.height,16,"SD Card Fatfs Error!");
		printf(" SD�� FAT ����");
		delay_ms(200);
	}
 	FRONT_COLOR=BLUE;//��������Ϊ��ɫ	   
	LCD_ShowString(10,120,tftlcd_data.width,tftlcd_data.height,16,"SD Card Fatfs OK!     ");	 
	LCD_ShowString(10,140,tftlcd_data.width,tftlcd_data.height,16,"SD Total Size:     MB");	 
	LCD_ShowString(10,160,tftlcd_data.width,tftlcd_data.height,16,"SD  Free Size:     MB"); 	    
 	LCD_ShowNum(10+8*14,140,total>>10,5,16);				//��ʾSD�������� MB
 	LCD_ShowNum(10+8*14,160,free>>10,5,16);					//��ʾSD��ʣ������ MB
	printf("SD Total Size: %ldMB\r\n",total>>10);
	printf("SD  Free Size: %ldMB\r\n",free>>10);
	
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
