

#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "input.h"


/*******************************************************************************
* �� �� ��         : main
* ��������		   : ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
int main()
{
	u8 i=0;
	u32 indata=0;
	
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //�ж����ȼ����� ��2��
	LED_Init();
	USART1_Init(9600);
	TIM5_CH1_Input_Init(0xffff,71);  //��1MƵ�ʼ���
	
	while(1)
	{
		if(TIM5_CH1_CAPTURE_STA&0x80) //�ɹ�����
		{
			indata=TIM5_CH1_CAPTURE_STA&0x3f;
			indata*=0xffff; //�����������һ�εļ�������ʱ�� us
			indata+=TIM5_CH1_CAPTURE_VAL;//���ϸߵ�ƽ�����ʱ��
			printf("�ߵ�ƽ����ʱ�䣺%d us\r\n",indata); //�ܵĸߵ�ƽʱ��
			TIM5_CH1_CAPTURE_STA=0; //��ʼ��һ�β���
		}
		
		i++;
		if(i%20==0)
		{
			led1=!led1;
		}
		delay_ms(10);
	}
}
