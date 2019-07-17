

#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "wkup.h"


/*******************************************************************************
* �� �� ��         : main
* ��������		   : ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
int main()
{

	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //�ж����ȼ����� ��2��
	LED_Init();
	USART1_Init(9600);
	
	while(1)
	{
		printf("time: 5\r\n");
		led1=0;
		delay_ms(1000);	//��1����ʾ����
		
		printf("time: 4\r\n");
		led1=1;
		delay_ms(1000);
		
		printf("time: 3\r\n");
		led1=0;
		delay_ms(1000);
		
		printf("time: 2\r\n");
		led1=1;
		delay_ms(1000);
		
		printf("time: 1\r\n");
		led1=0;
		delay_ms(1000);
		
		printf("����ϵͳ����ģʽ\r\n");
		Enter_Standby_Mode();	
	}
}
