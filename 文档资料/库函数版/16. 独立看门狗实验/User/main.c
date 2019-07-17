

#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "key.h"
#include "iwdg.h"


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
	
	KEY_Init();
	IWDG_Init(4,800); //ֻҪ��1280ms�ڽ���ι���Ͳ��Ḵλϵͳ
	
	led2=1;
	printf("��λϵͳ\r\n");
	
	while(1)
	{
		if(KEY_Scan(0)==KEY_UP)
		{
			IWDG_FeedDog();//ι��
			led2=0;
			printf("ι��\r\n");
		}
		
		i++;
		if(i%20==0)
		{
			led1=!led1;
			
		}
		delay_ms(10);
	}
}
