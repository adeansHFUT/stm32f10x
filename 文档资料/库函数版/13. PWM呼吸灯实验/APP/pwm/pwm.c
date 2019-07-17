#include "pwm.h"

/*******************************************************************************
* �� �� ��         : TIM3_CH1_PWM_Init
* ��������		   : TIM3ͨ��1 PWM��ʼ������
* ��    ��         : per:��װ��ֵ
					 psc:��Ƶϵ��
* ��    ��         : ��
*******************************************************************************/
void TIM3_CH1_PWM_Init(u16 per,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure2;//ͨ��2
	TIM_OCInitTypeDef TIM_OCInitStructure3;//ͨ��3
	TIM_OCInitTypeDef TIM_OCInitStructure4;//ͨ��3
	GPIO_InitTypeDef GPIO_InitStructure;//
	GPIO_InitTypeDef GPIO_InitStructure7;//c7�ܽ�
	GPIO_InitTypeDef GPIO_InitStructure8;//c8
	GPIO_InitTypeDef GPIO_InitStructure9;//c9
	
	/* ����ʱ�� */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//ioC enable
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//����
	
	/*  ����GPIO��ģʽ��IO�� */
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;//6
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//�����������
	GPIO_Init(GPIOC,&GPIO_InitStructure);//c
	
	GPIO_InitStructure7.GPIO_Pin=GPIO_Pin_7;//7
	GPIO_InitStructure7.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure7.GPIO_Mode=GPIO_Mode_AF_PP;//�����������
	GPIO_Init(GPIOC,&GPIO_InitStructure7);//c
	
	GPIO_InitStructure8.GPIO_Pin=GPIO_Pin_8;//7
	GPIO_InitStructure8.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure8.GPIO_Mode=GPIO_Mode_AF_PP;//�����������
	GPIO_Init(GPIOC,&GPIO_InitStructure8);//c
	
	GPIO_InitStructure9.GPIO_Pin=GPIO_Pin_9;//7
	GPIO_InitStructure9.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure9.GPIO_Mode=GPIO_Mode_AF_PP;//�����������
	GPIO_Init(GPIOC,&GPIO_InitStructure9);//c
	////////////////////////////////////////////�������4���ܽ�����
	
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM3,ENABLE);//�ı�ָ���ܽŵ�ӳ��	
	
	TIM_TimeBaseInitStructure.TIM_Period=per;   //�Զ�װ��ֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc; //��Ƶϵ��
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //�������ϼ���ģʽ
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);	
	
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OC1Init(TIM3,&TIM_OCInitStructure); //����Ƚ�ͨ��1��ʼ��
	
	TIM_OCInitStructure2.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure2.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitStructure2.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OC2Init(TIM3,&TIM_OCInitStructure2); //����Ƚ�ͨ��2��ʼ��
	
	TIM_OCInitStructure3.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure3.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitStructure3.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OC3Init(TIM3,&TIM_OCInitStructure3); //����Ƚ�ͨ��3��ʼ��
	
	TIM_OCInitStructure4.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure4.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitStructure4.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OC4Init(TIM3,&TIM_OCInitStructure4); //����Ƚ�ͨ��4��ʼ��
	//////////////////////�������4��pwm�������
	TIM_OC1PreloadConfig(TIM3,TIM_OCPreload_Enable); //ʹ��TIMx�� CCR1 �ϵ�Ԥװ�ؼĴ���
	TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable); //ʹ��TIMx�� CCR2 �ϵ�Ԥװ�ؼĴ���
	TIM_OC3PreloadConfig(TIM3,TIM_OCPreload_Enable); //ʹ��TIMx�� CCR2 �ϵ�Ԥװ�ؼĴ���
	TIM_OC4PreloadConfig(TIM3,TIM_OCPreload_Enable); //ʹ��TIMx�� CCR2 �ϵ�Ԥװ�ؼĴ���
	TIM_ARRPreloadConfig(TIM3,ENABLE);//ʹ��Ԥװ�ؼĴ���
	
	TIM_Cmd(TIM3,ENABLE); //ʹ�ܶ�ʱ��
		
}
void TIM4_CH1_PWM_Init(u16 per,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure2;//ͨ��2
	TIM_OCInitTypeDef TIM_OCInitStructure3;//ͨ��3
	TIM_OCInitTypeDef TIM_OCInitStructure4;//ͨ��3
	GPIO_InitTypeDef GPIO_InitStructureD12;//
	
	/* ����ʱ�� */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//ioD enable
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,DISABLE);//����
	
	/*  ����GPIO��ģʽ��IO�� */
	GPIO_InitStructureD12.GPIO_Pin=GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;//
	GPIO_InitStructureD12.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructureD12.GPIO_Mode=GPIO_Mode_AF_PP;//�����������
	GPIO_Init(GPIOB,&GPIO_InitStructureD12);//D
	
	////////////////////////////////////////////�������4���ܽ�����
	
	GPIO_PinRemapConfig(GPIO_Remap_TIM4,DISABLE);//�ı�ָ���ܽŵ�ӳ��	
	
	TIM_TimeBaseInitStructure.TIM_Period=per;   //�Զ�װ��ֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc; //��Ƶϵ��
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //�������ϼ���ģʽ
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStructure);	
	
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OC1Init(TIM4,&TIM_OCInitStructure); //����Ƚ�ͨ��1��ʼ��
	
	TIM_OCInitStructure2.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure2.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitStructure2.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OC2Init(TIM4,&TIM_OCInitStructure2); //����Ƚ�ͨ��2��ʼ��
	
	TIM_OCInitStructure3.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure3.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitStructure3.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OC3Init(TIM4,&TIM_OCInitStructure3); //����Ƚ�ͨ��3��ʼ��
	
	TIM_OCInitStructure4.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure4.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitStructure4.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OC4Init(TIM4,&TIM_OCInitStructure4); //����Ƚ�ͨ��4��ʼ��
	//////////////////////�������4��pwm�������
	TIM_OC1PreloadConfig(TIM4,TIM_OCPreload_Enable); //ʹ��TIMx�� CCR1 �ϵ�Ԥװ�ؼĴ���
	TIM_OC2PreloadConfig(TIM4,TIM_OCPreload_Enable); //ʹ��TIMx�� CCR2 �ϵ�Ԥװ�ؼĴ���
	TIM_OC3PreloadConfig(TIM4,TIM_OCPreload_Enable); //ʹ��TIMx�� CCR2 �ϵ�Ԥװ�ؼĴ���
	TIM_OC4PreloadConfig(TIM4,TIM_OCPreload_Enable); //ʹ��TIMx�� CCR2 �ϵ�Ԥװ�ؼĴ���
	TIM_ARRPreloadConfig(TIM4,ENABLE);//ʹ��Ԥװ�ؼĴ���
	
	TIM_Cmd(TIM4,ENABLE); //ʹ�ܶ�ʱ��
		
}

