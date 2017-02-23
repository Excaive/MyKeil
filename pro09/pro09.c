//定时器0工作方式1允许中断，使LED每0.5s亮一次

#include <reg52.h>
int i=100;

void main()
{	TMOD=0x01;
	TH0=0xec;
	TL0=0x78;
	P1=0x00;
	EA=1;		//开中断
	ET0=1;		//允许定时器0中断
	TR0=1;		//启动定时器0
	while(1);	
}

void t0(void) interrupt 1
{	TH0=0xec;
	TL0=0x78;
	i--;
	if(i<=0)
	{	P1=~P1;
		i=100;
	}
}