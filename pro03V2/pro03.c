//LED…¡À∏£¨÷‹∆⁄2s

#include <reg52.h>

void delay(int i)
{	long j;
	
	for(;i>0;i--)
		for(j=20403;j>0;j--);
}

void main()
{	P1=0xff;
	delay(1);
	P1=0x00;
	delay(1);
}