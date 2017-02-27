//键盘试验

#include <reg52.h>
sbit key1=P3^2;
sbit key2=P3^3;
sbit key3=P3^4;
sbit key4=P3^5;

void delay(int n)
{	int i,j;

	for(i=0;i<n;i++)
		for(j=0;j<10000;j++);
}

void main()
{	int i;	

	P1=0xff;
	while(1)
	{	if(key1==0)		//按S7，LED闪烁一次
		{	for(i=0;i<50;i++);
			if(key1==0)
			{	while(key1==0);
				P1=0x00;
				delay(5);
				P1=0xff;
			}
		}

		if(key2==0)		//按S6，LED闪烁两次
		{	for(i=0;i<50;i++);
			if(key2==0)
			{	while(key2==0);
				P1=0x00;
				delay(5);
				P1=0xff;
				delay(5);
				P1=0x00;
				delay(5);
				P1=0xff;
			}
		}
	}
}