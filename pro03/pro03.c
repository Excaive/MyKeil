//LED…¡À∏£¨÷‹∆⁄2s

#include <reg52.h>

void delay(int i)
{	int j;
	
	for(;i>0;i--)
		for(j=24981;j>0;j--);
}

void main()
{	P1=0xff;
	delay(5);
	P1=0x00;
	delay(5);
}