

#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "adc_temp.h"


/*******************************************************************************
* �� �� ��         : main
* ��������		   : ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
int main()
{
	u8 i=0;
	int temp=0;
	
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //�ж����ȼ����� ��2��
	LED_Init();
	USART1_Init(9600);
	ADC_Temp_Init();
	
	while(1)
	{
		i++;
		if(i%20==0)
		{
			led1=!led1;
		}
		
		if(i%50==0)
		{
			temp=Get_Temperture();
			if(temp<0)
			{
				temp=-temp;
				printf("�ڲ��¶ȼ��ֵΪ��-");
			}
			else
			{
				printf("�ڲ��¶ȼ��ֵΪ��+");
			}
			printf("%.2f��C\r\n",(float)temp/100);
		}
		delay_ms(10);	
	}
}
