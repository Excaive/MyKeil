//蜂鸣器响

#include <reg52.h>
sbit BEEP=P0^4;

void delay(int i)
{	int j;
	
	for(;i>0;i--)
		for(j=250;j>0;j--);
}

void main()
{	int t;	

	BEEP=1;
	while(1)
	{	for(t=100;t>0;t--)
		{	BEEP=~BEEP;		//按位取反
			delay(1);		
		}
		delay(100);
	}	
}