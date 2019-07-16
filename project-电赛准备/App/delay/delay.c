#include "delay.h"

void delay_ms(unsigned int time)
{
	unsigned int j = 0;
	unsigned int i = 0;
	time = time/4;
	while(time--)
	{
		for(j = 200; j > 0; j--)
			for( i = 200; i > 0; i--);
	}
	
			
}