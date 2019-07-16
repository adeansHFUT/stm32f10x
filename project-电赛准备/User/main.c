#include "include.h"

int main(void)
{ 
    LED_Init();
	while(1)
	{
		delay_ms(1000);
		LED_Turn0();
		delay_ms(1000);
		LED_Turn1();

	}
	
	while(1);

	return 0;
}