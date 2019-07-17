

#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "tftlcd.h"
#include "key.h"
#include "malloc.h" 
#include "sd.h"

	
int main()
{
	u8 i=0;
	u32 sd_size;
	u8 sd_buf[6];
	
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //�ж����ȼ����� ��2��
	LED_Init();
	USART1_Init(9600);
	TFTLCD_Init();			//LCD��ʼ��
	
	FRONT_COLOR=RED;//��������Ϊ��ɫ 
	LCD_ShowString(10,10,tftlcd_data.width,tftlcd_data.height,16,"PRECHIN STM32F1");	
	LCD_ShowString(10,30,tftlcd_data.width,tftlcd_data.height,16,"SD CARD TEST");	
	LCD_ShowString(10,50,tftlcd_data.width,tftlcd_data.height,16,"www.prechin.net");  
	
	
	while(SD_Init())//��ⲻ��SD��
	{
		LCD_ShowString(10,80,tftlcd_data.width,tftlcd_data.height,16,"SD Card Error!");
		printf("SD Card Error!\r\n");
		delay_ms(500);					
	}
	
	FRONT_COLOR=BLUE;	//��������Ϊ��ɫ 
	//���SD���ɹ� 			
	printf("SD Card OK!\r\n");	
	LCD_ShowString(10,80,tftlcd_data.width,tftlcd_data.height,16,"SD Card OK    ");
	
	/* ��ʾSD������ */
    if(SD_Type == 0x06)
	{
		LCD_ShowString(10, 100,tftlcd_data.width,tftlcd_data.height,16,"SDV2HC OK!");
	}
	else if(SD_Type == 0x04)
	{
		LCD_ShowString(10, 100,tftlcd_data.width,tftlcd_data.height,16,"SDV2 OK!");
	}
	else if(SD_Type == 0x02)
	{
		LCD_ShowString(10, 100,tftlcd_data.width,tftlcd_data.height,16,"SDV1 OK!");
	}
	else if(SD_Type == 0x01)
	{
		LCD_ShowString(10, 100,tftlcd_data.width,tftlcd_data.height,16,"MMC OK!");
	}
	
	LCD_ShowString(10,120,tftlcd_data.width,tftlcd_data.height,16,"SD Card Size:     MB");
	
	sd_size=SD_GetSectorCount();//�õ�������
	sd_size=sd_size>>11;  //��ʾSD������   MB
	printf("\nSD������Ϊ��%dMB\n", sd_size);
	
	sd_buf[0]=sd_size/10000+0x30;
	sd_buf[1]=sd_size%10000/1000+0x30;
	sd_buf[2]=sd_size%10000%1000/100+0x30;
	sd_buf[3]=sd_size%10000%1000%100/10+0x30;
	sd_buf[4]=sd_size%10000%1000%100%10+0x30;
	sd_buf[5]='\0';
	LCD_ShowString(115,120,tftlcd_data.width,tftlcd_data.height,16,sd_buf);
	
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
