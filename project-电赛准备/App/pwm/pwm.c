#include "pwm.h"

/*******************************************************************************
* 函 数 名         : TIM3_CH3_PWM_Init
* 函数功能		   : TIM3通道PWM初始化函数(舵机)
* 输    入         : per:重装载值
					 psc:分频系数
* 输    出         : 无
*******************************************************************************/
void TIM3_CH12_steer_PWM_Init(u16 per,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;

	TIM_OCInitTypeDef TIM_OCInitStructure1;//通道1
	TIM_OCInitTypeDef TIM_OCInitStructure2;//通道2
	GPIO_InitTypeDef GPIO_InitStructure6;//A6管脚
	GPIO_InitTypeDef GPIO_InitStructure7;//A7管脚

	
	/* 开启时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//ioC enable
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);

	
	/*  配置GPIO的模式和IO口 */
	GPIO_InitStructure6.GPIO_Pin=GPIO_Pin_6;
	GPIO_InitStructure6.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure6.GPIO_Mode=GPIO_Mode_Out_PP;//该推挽输出
	GPIO_Init(GPIOA,&GPIO_InitStructure6);
	
	GPIO_InitStructure7.GPIO_Pin=GPIO_Pin_7;
	GPIO_InitStructure7.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure7.GPIO_Mode=GPIO_Mode_Out_PP;//推挽输出
	GPIO_Init(GPIOA,&GPIO_InitStructure7);
	
	
	////////////////////////////////////////////以上完出管脚配置
	
	
	TIM_TimeBaseInitStructure.TIM_Period=per;   //自动装载值(用于设置pwm频率)
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc; //分频系数
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //设置向上计数模式
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);	
	
	TIM_OCInitStructure1.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure1.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitStructure1.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OC1Init(TIM3,&TIM_OCInitStructure1); //输出比较通道1初始化
	
	TIM_OCInitStructure2.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure2.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitStructure2.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OC2Init(TIM3,&TIM_OCInitStructure2); //输出比较通道2初始化
	

	//////////////////////以上完出pwm输出配置
	
	TIM_OC1PreloadConfig(TIM3,TIM_OCPreload_Enable); //使能TIMx在 CCR2 上的预装载寄存器
	TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable); //使能TIMx在 CCR2 上的预装载寄存器
	TIM_ARRPreloadConfig(TIM3,ENABLE);//使能预装载寄存器

	TIM_Cmd(TIM3,ENABLE); //使能定时器
		
}


