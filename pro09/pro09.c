//��ʱ��0������ʽ1�����жϣ�ʹLEDÿ0.5s��һ��

#include <reg52.h>
int i=100;

void main()
{	TMOD=0x01;
	TH0=0xec;
	TL0=0x78;
	P1=0x00;
	EA=1;		//���ж�
	ET0=1;		//����ʱ��0�ж�
	TR0=1;		//������ʱ��0
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