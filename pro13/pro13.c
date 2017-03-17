//P1¿ÚÍâ½Ó¾ØÕó¼üÅÌ

#include <reg52.h>

sbit P1_0 = P1^0;
sbit P1_1 = P1^1;
sbit P1_2 = P1^2;
sbit P1_3 = P1^3;
sbit P1_4 = P1^4;
sbit P1_5 = P1^5;
sbit P1_6 = P1^6;
sbit P1_7 = P1^7;
sbit P2_0 = P2^0;
sbit P2_1 = P2^1;
sbit P2_2 = P2^2;
sbit P2_3 = P2^3;

int r;
int keynum[4][5]={{ 1, 2, 3, 4,21},
                  { 5, 6, 7, 8,22},
				  { 9,10,11,12,23},
				  {13,14,15,16,24}};
int table[]={0xc0,0xf9,0xa4,0xb0,0x99,
             0x92,0x82,0xf8,0x80,0x90};

int keyboard()
{ 	
	int i,j,t;

	r=0;
	P1=0xf0;
 	while(1)
	{
	 	if(P1_4==0)
		{
		 	i=0;
			for(t=0;t<20;t++);
			if(P1_4==0)
				break;
		}
		if(P1_5==0)
		{
		 	i=1;
			for(t=0;t<20;t++);
			if(P1_5==0)
				break;
		}
		if(P1_6==0)
		{
		 	i=2;
			for(t=0;t<20;t++);
			if(P1_6==0)
				break;
		}
		if(P1_7==0)
		{
		 	i=3;
			for(t=0;t<20;t++);
			if(P1_7==0)
				break;
		}																		  
	}
	P1_3=1;
	if(P1_4&&P1_5&&P1_6&&P1_7)
	{ 
		j=0;
		r=1;
	}
	else
	{
		P1_3=0;
		P1_2=1;
		if(P1_4&&P1_5&&P1_6&&P1_7)
		{
			j=1;
			r=1;
		}
		else
		{
			P1_2=0;
			P1_1=1;
			if(P1_4&&P1_5&&P1_6&&P1_7)
			{
				j=2;
				r=1;
			}
			else
			{
				P1_1=0;
				P1_0=1;
				if(P1_4&&P1_5&&P1_6&&P1_7)
				{
					j=3;
					r=1;
				}
				else
				{
					j=4;
					r=1;
				}
			}			
		}
	}
	return(keynum[i][j]);
}

void main()
{
	int temp,o,t;

	while(1)
	{
		temp=keyboard();
		if(r==1)
			o=temp;

		P0=table[o/10];
		P2_2 = 0;
		for(t=0;t<20;t++);
		P2_2 = 1;

		P0=table[o%10];
		P2_3 = 0;
		for(t=0;t<20;t++);
		P2_3 = 1;
	}
}