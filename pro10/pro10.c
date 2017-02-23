//x'xx".x秒表

#include <reg52.h>
int i=2,dsec,sec,min;
int table[]={0xc0,0xf9,0xa4,0xb0,0x99,
             0x92,0x82,0xf8,0x80,0x90};
sbit P2_0 = P2^0;
sbit P2_1 = P2^1;
sbit P2_2 = P2^2;
sbit P2_3 = P2^3;

void main()
{	int j;

	TMOD=0x01;
	TH0=0x3c;
	TL0=0xb0;
	EA=1;		//开中断
	ET0=1;		//允许定时器0中断
	TR0=1;		//启动定时器0
	while(1)
	{	P0=table[min]-0x80;
		P2_0 = 0;
		for(j=0;j<20;j++);
		P2_0 = 1;

		P0=table[sec/10];
		P2_1 = 0;
		for(j=0;j<20;j++);
		P2_1 = 1;

		P0=table[sec%10]-0x80;
		P2_2 = 0;
		for(j=0;j<20;j++);
		P2_2 = 1;

		P0=table[dsec];
		P2_3 = 0;
		for(j=0;j<20;j++);
		P2_3 = 1;
	}	
}

void t0(void) interrupt 1
{	TH0=0x3c;
	TL0=0xb0;
	i--;
	if(i<=0)
	{	dsec++;

		if(dsec==10)
		{	sec++;
			dsec=0;

			if(sec==60)
			{	min++;
				sec=0;

				if(min==10)
					min=0;
			}
		}
		i=2;
	}
}