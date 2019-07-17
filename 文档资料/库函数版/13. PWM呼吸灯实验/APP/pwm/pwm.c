#include "pwm.h"

/*******************************************************************************
* 函 数 名         : TIM3_CH1_PWM_Init
* 函数功能		   : TIM3通道1 PWM初始化函数
* 输    入         : per:重装载值
					 psc:分频系数
* 输    出         : 无
*******************************************************************************/
void TIM3_CH1_PWM_Init(u16 per,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure2;//通道2
	TIM_OCInitTypeDef TIM_OCInitStructure3;//通道3
	TIM_OCInitTypeDef TIM_OCInitStructure4;//通道3
	GPIO_InitTypeDef GPIO_InitStructure;//
	GPIO_InitTypeDef GPIO_InitStructure7;//c7管脚
	GPIO_InitTypeDef GPIO_InitStructure8;//c8
	GPIO_InitTypeDef GPIO_InitStructure9;//c9
	
	/* 开启时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//ioC enable
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//复用
	
	/*  配置GPIO的模式和IO口 */
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;//6
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//复用推挽输出
	GPIO_Init(GPIOC,&GPIO_InitStructure);//c
	
	GPIO_InitStructure7.GPIO_Pin=GPIO_Pin_7;//7
	GPIO_InitStructure7.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure7.GPIO_Mode=GPIO_Mode_AF_PP;//复用推挽输出
	GPIO_Init(GPIOC,&GPIO_InitStructure7);//c
	
	GPIO_InitStructure8.GPIO_Pin=GPIO_Pin_8;//7
	GPIO_InitStructure8.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure8.GPIO_Mode=GPIO_Mode_AF_PP;//复用推挽输出
	GPIO_Init(GPIOC,&GPIO_InitStructure8);//c
	
	GPIO_InitStructure9.GPIO_Pin=GPIO_Pin_9;//7
	GPIO_InitStructure9.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure9.GPIO_Mode=GPIO_Mode_AF_PP;//复用推挽输出
	GPIO_Init(GPIOC,&GPIO_InitStructure9);//c
	////////////////////////////////////////////以上完成4个管脚配置
	
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM3,ENABLE);//改变指定管脚的映射	
	
	TIM_TimeBaseInitStructure.TIM_Period=per;   //自动装载值
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc; //分频系数
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //设置向上计数模式
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);	
	
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OC1Init(TIM3,&TIM_OCInitStructure); //输出比较通道1初始化
	
	TIM_OCInitStructure2.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure2.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitStructure2.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OC2Init(TIM3,&TIM_OCInitStructure2); //输出比较通道2初始化
	
	TIM_OCInitStructure3.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure3.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitStructure3.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OC3Init(TIM3,&TIM_OCInitStructure3); //输出比较通道3初始化
	
	TIM_OCInitStructure4.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure4.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitStructure4.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OC4Init(TIM3,&TIM_OCInitStructure4); //输出比较通道4初始化
	//////////////////////以上完成4个pwm输出配置
	TIM_OC1PreloadConfig(TIM3,TIM_OCPreload_Enable); //使能TIMx在 CCR1 上的预装载寄存器
	TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable); //使能TIMx在 CCR2 上的预装载寄存器
	TIM_OC3PreloadConfig(TIM3,TIM_OCPreload_Enable); //使能TIMx在 CCR2 上的预装载寄存器
	TIM_OC4PreloadConfig(TIM3,TIM_OCPreload_Enable); //使能TIMx在 CCR2 上的预装载寄存器
	TIM_ARRPreloadConfig(TIM3,ENABLE);//使能预装载寄存器
	
	TIM_Cmd(TIM3,ENABLE); //使能定时器
		
}
void TIM4_CH1_PWM_Init(u16 per,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure2;//通道2
	TIM_OCInitTypeDef TIM_OCInitStructure3;//通道3
	TIM_OCInitTypeDef TIM_OCInitStructure4;//通道3
	GPIO_InitTypeDef GPIO_InitStructureD12;//
	
	/* 开启时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//ioD enable
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,DISABLE);//复用
	
	/*  配置GPIO的模式和IO口 */
	GPIO_InitStructureD12.GPIO_Pin=GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;//
	GPIO_InitStructureD12.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructureD12.GPIO_Mode=GPIO_Mode_AF_PP;//复用推挽输出
	GPIO_Init(GPIOB,&GPIO_InitStructureD12);//D
	
	////////////////////////////////////////////以上完成4个管脚配置
	
	GPIO_PinRemapConfig(GPIO_Remap_TIM4,DISABLE);//改变指定管脚的映射	
	
	TIM_TimeBaseInitStructure.TIM_Period=per;   //自动装载值
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc; //分频系数
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //设置向上计数模式
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStructure);	
	
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OC1Init(TIM4,&TIM_OCInitStructure); //输出比较通道1初始化
	
	TIM_OCInitStructure2.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure2.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitStructure2.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OC2Init(TIM4,&TIM_OCInitStructure2); //输出比较通道2初始化
	
	TIM_OCInitStructure3.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure3.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitStructure3.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OC3Init(TIM4,&TIM_OCInitStructure3); //输出比较通道3初始化
	
	TIM_OCInitStructure4.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure4.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitStructure4.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OC4Init(TIM4,&TIM_OCInitStructure4); //输出比较通道4初始化
	//////////////////////以上完成4个pwm输出配置
	TIM_OC1PreloadConfig(TIM4,TIM_OCPreload_Enable); //使能TIMx在 CCR1 上的预装载寄存器
	TIM_OC2PreloadConfig(TIM4,TIM_OCPreload_Enable); //使能TIMx在 CCR2 上的预装载寄存器
	TIM_OC3PreloadConfig(TIM4,TIM_OCPreload_Enable); //使能TIMx在 CCR2 上的预装载寄存器
	TIM_OC4PreloadConfig(TIM4,TIM_OCPreload_Enable); //使能TIMx在 CCR2 上的预装载寄存器
	TIM_ARRPreloadConfig(TIM4,ENABLE);//使能预装载寄存器
	
	TIM_Cmd(TIM4,ENABLE); //使能定时器
		
}

