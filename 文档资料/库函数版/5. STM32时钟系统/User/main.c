

#include "stm32f10x.h"
#include "led.h"


/*******************************************************************************
* �� �� ��         : delay
* ��������		   : ��ʱ������ͨ��whileѭ��ռ��CPU���ﵽ��ʱ����
* ��    ��         : i
* ��    ��         : ��
*******************************************************************************/
void delay(u32 i)
{
	while(i--);
}

/*******************************************************************************
* �� �� ��         : RCC_HSE_Config
* ��������		   : �Զ���ϵͳʱ�ӣ�����ͨ���޸�PLLʱ��Դ�ͱ�Ƶϵ��ʵ��ʱ�ӵ���
* ��    ��         : div��RCC_PLLSource_HSE_Div1/RCC_PLLSource_HSE_Div2
					 pllm��RCC_PLLMul_2-RCC_PLLMul_16
* ��    ��         : ��
*******************************************************************************/
void RCC_HSE_Config(u32 div,u32 pllm) //�Զ���ϵͳʱ�䣨�����޸�ʱ�ӣ�
{
	RCC_DeInit(); //������RCC�Ĵ�������Ϊȱʡֵ
	RCC_HSEConfig(RCC_HSE_ON);//�����ⲿ���پ���HSE��
	if(RCC_WaitForHSEStartUp()==SUCCESS) //�ȴ�HSE����
	{
		RCC_HCLKConfig(RCC_SYSCLK_Div1);//����AHBʱ�ӣ�HCLK��
		RCC_PCLK1Config(RCC_HCLK_Div2);//���õ���AHBʱ�ӣ�PCLK1��
		RCC_PCLK2Config(RCC_HCLK_Div1);//���ø���AHBʱ�ӣ�PCLK2��
		RCC_PLLConfig(div,pllm);//����PLLʱ��Դ����Ƶϵ��
		RCC_PLLCmd(ENABLE); //ʹ�ܻ���ʧ��PLL
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY)==RESET);//���ָ����RCC��־λ�������,PLL����
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);//����ϵͳʱ�ӣ�SYSCLK��
		while(RCC_GetSYSCLKSource()!=0x08);//��������ϵͳʱ�ӵ�ʱ��Դ,0x08��PLL��Ϊϵͳʱ��
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
	RCC_HSE_Config(RCC_PLLSource_HSE_Div2,RCC_PLLMul_9);   //36M
	LED_Init();
	while(1)
	{
		GPIO_ResetBits(LED_PORT,GPIO_Pin_0);//����D1
		delay(6000000);
		GPIO_SetBits(LED_PORT,GPIO_Pin_0);
		delay(6000000);
	}
}
