//��ʱ��0������ʽ1��ֹ�жϣ�ʹLEDÿ0.5s��һ��

#include <reg52.h>

void delay(int i)
{	TMOD=0x01;		//��ʱ��0������ʽ1
	IE=0x00;		//��ֹ�ж�
	TR0=1;			//������ʱ��0
	while(i!=0)
	{	TH0=0xec;
		TL0=0x78;
		while(TF0!=1);
		TF0=0;		//��ʱʱ�䵽������
		i--;
	}
	TR0=0;			//�رն�ʱ��0
}

void main()
{	for(;;)
	{	P1=0x00;
		delay(100);
		P1=0xff;
		delay(100);
	}
}