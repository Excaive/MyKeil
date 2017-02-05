//Á÷Ë®µÆ2

#include <reg52.h>
#include <intrins.h>

void delay(int i)
{	int j;
	
	for(;i>0;i--)
		for(j=500;j>0;j--);
}

void main()
{	int k;

	while(1)
	{	P1=0x33;
		for(k=0;k<=24;k++)
		{	delay(30);
			P1=_crol_(P1,1);
		}
		P1=0x33;
		for(k=0;k<=24;k++)
		{	delay(30);
			P1=_cror_(P1,1);
		}
	}
}