

#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "tftlcd.h"
#include "key.h"
#include "sram.h"
#include "malloc.h" 


	
int main()
{
	u8 i=0;
	u8 key;
	u8 *p=0;
	u8 sramx=0;	//Ĭ��Ϊ�ڲ�sram
	
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //�ж����ȼ����� ��2��
	LED_Init();
	USART1_Init(9600);
	TFTLCD_Init();			//LCD��ʼ��
	KEY_Init();
	FSMC_SRAM_Init();
	
	my_mem_init(SRAMIN);		//��ʼ���ڲ��ڴ��
	my_mem_init(SRAMEX);		//��ʼ���ⲿ�ڴ��
	
	FRONT_COLOR=RED;//��������Ϊ��ɫ 
	LCD_ShowString(10,10,tftlcd_data.width,tftlcd_data.height,16,"PRECHIN STM32F1");	
	LCD_ShowString(10,30,tftlcd_data.width,tftlcd_data.height,16,"MALLOC TEST");	
	LCD_ShowString(10,50,tftlcd_data.width,tftlcd_data.height,16,"www.prechin.net");  
	LCD_ShowString(10,80,tftlcd_data.width,tftlcd_data.height,16,"K_UP:Malloc  K_DOWN:Free");
	LCD_ShowString(10,100,tftlcd_data.width,tftlcd_data.height,16,"K_RIGHT:SRAM Choice"); 
 	
	FRONT_COLOR=BLUE;//��������Ϊ��ɫ 
	LCD_ShowString(10,150,tftlcd_data.width,tftlcd_data.height,16,"SRAMIN");
	LCD_ShowString(10,190,tftlcd_data.width,tftlcd_data.height,16,"SRAMIN  USED:   %");
	LCD_ShowString(10,210,tftlcd_data.width,tftlcd_data.height,16,"SRAMEX  USED:   %");
	
	while(1)
	{
		key=KEY_Scan(0);//��֧������	
		switch(key)
		{
			case KEY_UP:	//K_UP����
				p=mymalloc(sramx,2*1024);//����2K�ֽ�
				if(p!=NULL)printf("2K�ڴ�����ɹ���\r\n");
				break;
			case KEY_DOWN:	//K_DOWN����	  
				myfree(sramx,p);//�ͷ��ڴ�
				p=NULL;			//ָ��յ�ַ
				break;
			case KEY_RIGHT:	//K_RIGHT���� 
				sramx++; 
				if(sramx>1)
					sramx=0;
				if(sramx==0)
					LCD_ShowString(10,150,tftlcd_data.width,tftlcd_data.height,16,"SRAMIN ");
				else if(sramx==1)
					LCD_ShowString(10,150,tftlcd_data.width,tftlcd_data.height,16,"SRAMEX ");

				break;
		}
		
		LCD_ShowNum(10+13*8,190,my_mem_perused(SRAMIN),3,16);//��ʾ�ڲ��ڴ�ʹ����
		LCD_ShowNum(10+13*8,210,my_mem_perused(SRAMEX),3,16);//��ʾ�ⲿ�ڴ�ʹ����
		
		i++;
		if(i%20==0)
		{
			led1=!led1;
			printf("SRAMIN:%d\r\n",my_mem_perused(SRAMIN));
			printf("SRAMEX:%d\r\n",my_mem_perused(SRAMEX));
		}
		delay_ms(10);
			
	}
	
}
