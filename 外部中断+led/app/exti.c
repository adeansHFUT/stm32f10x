#include "exti.h"
/**外部中断引脚蜧GPIOE2*/
void NVIC_con(void)
{
	 NVIC_InitTypeDef nvic_st;
	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1); //设置中断优先级分组
	 
	 nvic_st.NVIC_IRQChannel = EXTI2_IRQn;   //中断源
	 nvic_st.NVIC_IRQChannelPreemptionPriority = 0;  //设置抢占优先级
	 nvic_st.NVIC_IRQChannelSubPriority = 0;  //设置子优先级
	 nvic_st.NVIC_IRQChannelCmd = ENABLE;
	 NVIC_Init (&nvic_st); 
}
void exti_config(void)
{
	GPIO_InitTypeDef gpio_st;
	EXTI_InitTypeDef exti_st;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOE ,ENABLE);
	
	NVIC_con();  //初始化NVIC
	
	//初始化GPIO
	gpio_st.GPIO_Pin = GPIO_Pin_2;      
	gpio_st.GPIO_Mode = GPIO_Mode_IPU;  //上拉输入,书上是IPD有错
	GPIO_Init(GPIOE , &gpio_st );
	
	//初始化EXTI
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource2);  //选择exti信号源
	exti_st.EXTI_Line = EXTI_Line2;  //中断线选择
	exti_st.EXTI_Mode = EXTI_Mode_Interrupt;  //中断模式
	exti_st.EXTI_Trigger = EXTI_Trigger_Falling;  //下降沿触发中断
	exti_st.EXTI_LineCmd = ENABLE;  
	EXTI_Init(&exti_st);
	

}

