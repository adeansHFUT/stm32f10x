

#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "tftlcd.h"



#define ID_ADDRESS 		0x1ffff7e8  //����ǹ̶���ID��ַ

int main()
{
	u8 i=0;
	u8 sys_id[12];
	
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //�ж����ȼ����� ��2��
	LED_Init();
	USART1_Init(9600);
	TFTLCD_Init();			//LCD��ʼ��
	
	FRONT_COLOR=BLACK;
	LCD_ShowString(10,10,tftlcd_data.width,tftlcd_data.height,16,"PRECHIN STM32F1");
	LCD_ShowString(10,30,tftlcd_data.width,tftlcd_data.height,16,"www.prechin.net");
	LCD_ShowString(10,50,tftlcd_data.width,tftlcd_data.height,16,"Program encryption Test");
	
	FRONT_COLOR=RED;
	
	for(i=0;i<12;i++)  //��ID��ȫ����ӡ���
	{
		sys_id[i]=*((u8 *)(ID_ADDRESS+i));
		printf("%x ",sys_id[i]);	
	}
	
	//�Ա�ID�������ȷִ��������򣬷�������ܼ���
	if(sys_id[0]==0x33&&sys_id[1]==0xff&&sys_id[2]==0xd5&&sys_id[3]==0x05&&
		sys_id[4]==0x4D&&sys_id[5]==0x4B&&sys_id[6]==0x35&&sys_id[7]==0x39&&
		sys_id[8]==0x38&&sys_id[9]==0x83&&sys_id[10]==0x21&&sys_id[11]==0x51)
	{	
		
		LCD_ShowString(10,130,tftlcd_data.width,tftlcd_data.height,16,"Decrypt Success");
		printf("\r\n������ܳɹ�\r\n");
		
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
	else
	{
		LCD_ShowString(10,130,tftlcd_data.width,tftlcd_data.height,16,"Decrypt Error    ");
		printf("\r\n�������ʧ��\r\n");
		while(1);
	}	
	
}
