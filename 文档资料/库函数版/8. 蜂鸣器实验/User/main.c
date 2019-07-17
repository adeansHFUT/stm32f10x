

#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "beep.h"


/*******************************************************************************
* �� �� ��         : main
* ��������		   : ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
int main()
{
	u16 i=0;
	SysTick_Init(72);
	LED_Init();
	BEEP_Init();
	while(1)
	{
		i++;
		if(i%10==0)
		{
			beep=!beep;
		}
		if(i%20000==0)
		{
			led1=!led1;	
		}
		delay_us(10);  
	}
}
