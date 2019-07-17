

#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "key.h"
#include "dma.h"


#define send_buf_len 5000
u8 send_buf[send_buf_len];
/*******************************************************************************
* �� �� ��         : Send_Data
* ��������		   : Ҫ���͵�����
* ��    ��         : p��ָ�����			 
* ��    ��         : ��
*******************************************************************************/
void Send_Data(u8 *p)
{
	u16 i;
	for(i=0;i<send_buf_len;i++)
	{
		*p='5';
		p++;
	}
}


/*******************************************************************************
* �� �� ��         : main
* ��������		   : ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
int main()
{
	u8 i=0;
	u8 key;
	
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //�ж����ȼ����� ��2��
	LED_Init();
	USART1_Init(9600);
	KEY_Init();
	DMAx_Init(DMA1_Channel4,(u32)&USART1->DR,(u32)send_buf,send_buf_len);
	Send_Data(send_buf);
	
	while(1)
	{
		key=KEY_Scan(0);
		if(key==KEY_UP)
		{
			USART_DMACmd(USART1,USART_DMAReq_Tx,ENABLE);  //ʹ�ܴ���1��DMA����     
			DMAx_Enable(DMA1_Channel4,send_buf_len);     //��ʼһ��DMA���䣡
		

			//�ȴ�DMA������ɣ���ʱ������������һЩ��
			//ʵ��Ӧ���У����������ڼ䣬����ִ�����������
			while(1)
			{
				if(DMA_GetFlagStatus(DMA1_FLAG_TC4)!=0)//�ж�ͨ��4�������
				{
					DMA_ClearFlag(DMA1_FLAG_TC4);
					break;
				}
				led2=!led2;
				delay_ms(300);	
			}
		}
		
		i++;
		if(i%20==0)
		{
			led1=!led1;
		}
		
		delay_ms(10);	
	}
}
