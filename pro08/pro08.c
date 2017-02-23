//定时器0工作方式1禁止中断，使LED每0.5s亮一次

#include <reg52.h>

void delay(int i)
{	TMOD=0x01;		//定时器0工作方式1
	IE=0x00;		//禁止中断
	TR0=1;			//启动定时器0
	while(i!=0)
	{	TH0=0xec;
		TL0=0x78;
		while(TF0!=1);
		TF0=0;		//计时时间到，清零
		i--;
	}
	TR0=0;			//关闭定时器0
}

void main()
{	for(;;)
	{	P1=0x00;
		delay(100);
		P1=0xff;
		delay(100);
	}
}