

#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "hwjs.h"


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
	Hwjs_Init();
	
	while(1)
	{
		if(hw_jsbz==1)	//���������յ�
		{
			hw_jsbz=0;	   //����
			printf("��������� %0.8X\r\n",hw_jsm);	//��ӡ
			hw_jsm=0;					//����������
		}		
		
		i++;
		if(i%20==0)
		{
			led1=!led1;
		}
		
		delay_ms(10);
	}
}
