

#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "wwdg.h"

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
	
	led1=0;
	delay_ms(500);
	WWDG_Init();
	while(1)
	{
		led1=1;
	}
}
