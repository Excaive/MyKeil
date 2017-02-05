//Á÷Ë®µÆ1

#include <reg52.h>

void delay(int i)
{	int j;
	
	for(;i>0;i--)
		for(j=500;j>0;j--);
}

void main()
{	int k;

	while(1)
	{	P1=0xff;
		for(k=0;k<=8;k++)
		{	delay(30);
			P1=P1>>1;
		}
		P1=0xff;
		for(k=0;k<=8;k++)
		{	delay(30);
			P1=P1<<1;
		}
	}
}