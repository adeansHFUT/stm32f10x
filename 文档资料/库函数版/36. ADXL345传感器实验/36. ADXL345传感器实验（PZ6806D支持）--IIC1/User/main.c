

#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "tftlcd.h"
#include "key.h"
#include "adxl345.h"


//x,y:��ʼ��ʾ������λ��
//num:Ҫ��ʾ������
//mode:0,��ʾ���ٶ�ֵ;1,��ʾ�Ƕ�ֵ;
void ADXL_Show_num(u16 x,u16 y,short num,u8 mode)   //ADXL345��ʾ
{
	u8 valbuf[3];
	if(mode==0)	  //��ʾ���ٶ�ֵ
	{
		if(num<0)
		{
			num=-num;
			LCD_ShowString(x,y,tftlcd_data.width,tftlcd_data.height,16,"-");
		}
		else
		{
			LCD_ShowString(x,y,tftlcd_data.width,tftlcd_data.height,16," ");
		}
		valbuf[0]=num/100+0x30;
		valbuf[1]=num%100/10+0x30;
		valbuf[2]=num%100%10+0x30;	
		LCD_ShowString(x+10,y,tftlcd_data.width,tftlcd_data.height,16,valbuf);	
	}
	else		 //��ʾ�Ƕ�ֵ
	{
		if(num<0)
		{
			num=-num;
			LCD_ShowString(x,y,tftlcd_data.width,tftlcd_data.height,16,"-");
		}
		else
		{
			LCD_ShowString(x,y,tftlcd_data.width,tftlcd_data.height,16," ");
		}
		valbuf[0]=num/10+0x30;
		valbuf[1]='.';
		valbuf[2]=num%10+0x30;	
		LCD_ShowString(x+10,y,tftlcd_data.width,tftlcd_data.height,16,valbuf);		
	}		
}

void data_pros()	//���ݴ�����
{
	short x,y,z;
	short xang,yang,zang;	
	u8 key;
	ADXL345_Read_Average(&x,&y,&z,10);  //��ȡx,y,z 3������ļ��ٶ�ֵ �ܹ�10��
	ADXL_Show_num(60,120,x,0);
	ADXL_Show_num(60,140,y,0);
	ADXL_Show_num(60,160,z,0);

	xang=ADXL345_Get_Angle(x,y,z,1);
	yang=ADXL345_Get_Angle(x,y,z,2);
	zang=ADXL345_Get_Angle(x,y,z,0);
	ADXL_Show_num(60,180,xang,1);
	ADXL_Show_num(60,200,yang,1);
	ADXL_Show_num(60,220,zang,1);

	key=KEY_Scan(0);
	if(key==KEY_UP)		  //����K_UPУ׼
	{
		led2=0;		//LED2����ʾ����У׼
		ADXL345_AUTO_Adjust((char*)&x,(char*)&y,(char*)&z);
		led2=1;	   //LED2���ʾУ׼���
	}
}

int main()
{
	u8 i=0;

	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //�ж����ȼ����� ��2��
	LED_Init();
	USART1_Init(9600);
	TFTLCD_Init();			//LCD��ʼ��
	KEY_Init();
	
	FRONT_COLOR=BLACK;

	LCD_ShowString(10,10,tftlcd_data.width,tftlcd_data.height,16,"PRECHIN STM32F1");
	LCD_ShowString(10,30,tftlcd_data.width,tftlcd_data.height,16,"www.prechin.net");
	LCD_ShowString(10,50,tftlcd_data.width,tftlcd_data.height,16,"ADXL345 Test");
	LCD_ShowString(10,90,tftlcd_data.width,tftlcd_data.height,16,"K_UP:ADXL345 Adjust");
	LCD_ShowString(10,120,tftlcd_data.width,tftlcd_data.height,16,"X Val:");
	LCD_ShowString(10,140,tftlcd_data.width,tftlcd_data.height,16,"Y Val:");
	LCD_ShowString(10,160,tftlcd_data.width,tftlcd_data.height,16,"Z Val:");
	LCD_ShowString(10,180,tftlcd_data.width,tftlcd_data.height,16,"X Ang:");
	LCD_ShowString(10,200,tftlcd_data.width,tftlcd_data.height,16,"Y Ang:");
	LCD_ShowString(10,220,tftlcd_data.width,tftlcd_data.height,16,"Z Ang:");
	
	FRONT_COLOR=RED;
	
	while(ADXL345_Init())
	{
		printf("ADXL345 Error!\r\n");
		LCD_ShowString(130,50,tftlcd_data.width,tftlcd_data.height,16,"Error  ");
		delay_ms(200);
	}
	printf("ADXL345 OK!\r\n");
	LCD_ShowString(130,50,tftlcd_data.width,tftlcd_data.height,16,"Success");
	while(1)
	{
		
		i++;
		if(i%20==0)
		{
			led1=!led1;
			data_pros();
		}
		delay_ms(10);
			
	}
	
}
