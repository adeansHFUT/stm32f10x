#include "exti.h"
/**�ⲿ�ж������GGPIOE2*/
void NVIC_con(void)
{
	 NVIC_InitTypeDef nvic_st;
	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1); //�����ж����ȼ�����
	 
	 nvic_st.NVIC_IRQChannel = EXTI2_IRQn;   //�ж�Դ
	 nvic_st.NVIC_IRQChannelPreemptionPriority = 0;  //������ռ���ȼ�
	 nvic_st.NVIC_IRQChannelSubPriority = 0;  //���������ȼ�
	 nvic_st.NVIC_IRQChannelCmd = ENABLE;
	 NVIC_Init (&nvic_st); 
}
void exti_config(void)
{
	GPIO_InitTypeDef gpio_st;
	EXTI_InitTypeDef exti_st;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOE ,ENABLE);
	
	NVIC_con();  //��ʼ��NVIC
	
	//��ʼ��GPIO
	gpio_st.GPIO_Pin = GPIO_Pin_2;      
	gpio_st.GPIO_Mode = GPIO_Mode_IPU;  //��������,������IPD�д�
	GPIO_Init(GPIOE , &gpio_st );
	
	//��ʼ��EXTI
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource2);  //ѡ��exti�ź�Դ
	exti_st.EXTI_Line = EXTI_Line2;  //�ж���ѡ��
	exti_st.EXTI_Mode = EXTI_Mode_Interrupt;  //�ж�ģʽ
	exti_st.EXTI_Trigger = EXTI_Trigger_Falling;  //�½��ش����ж�
	exti_st.EXTI_LineCmd = ENABLE;  
	EXTI_Init(&exti_st);
	

}

