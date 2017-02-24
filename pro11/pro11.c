//用无源蜂鸣器演奏《献给爱丽丝》
  
#include <reg52.h>    
#include <intrins.h>    
sbit Beep =  P0^4 ;    
unsigned char n=0,s,b;             //n 节拍，s 升音，b 八度

int code pitch1[]  = { 111, 256, 228, 207, 192, 172, 153, 135};
int code pitch1s[] = { 111, 241, 214, 111, 183, 160, 143}; 
int code pitch2[]  = { 111, 127, 113, 101,  95,  85,  76,  67};
int code pitch2s[] = { 111, 120, 107, 111,  90,  80,  71};
int code pitch3[]  = { 111,  64,  57,  50,  48,  42,  38};
int code pitch3s[] = { 111,  60,  53, 111,  45,  40};
    
unsigned char code music_tab[] =
{                              //音高，升音，八度，节拍   
	3,	0,	3,	4,
	2,	1,	3,	4,
	3,	0,	3,	4,
	2,	1,	3,	4,
	3,	0,	3,	4,
	7,	0,	2,	4,
	2,	0,	3,	4,
	1,	0,	3,	4,	//
	6,	0,	2,	4,
	3,	0,	1,	4,
	6,	0,	1,	4,
	1,	0,	2,	4,
	3,	0,	2,	4,
	6,	0,	2,	4,	//
	7,	0,	2,	4,
	5,	1,	1,	4,
	7,	0,	1,	4,
	3,	0,	2,	4,
	1,	0,	3,	4,
	7,	0,	2,	4,	//
	6,	0,	2,	4,
	1,	0,	2,	4,
	3,	0,	2,	4,
	7,	0,	2,	4,
	1,	0,	3,	4,
	2,	0,	3,	4,	//
	3,	0,	3,	12,
	5,	0,	2,	4,
	4,	0,	3,	4,
	3,	0,	3,	4,	//
	2,	0,	3,	12,
	3,	0,	2,	4,
	3,	0,	3,	4,
	2,	0,	3,	4,	//
	1,	0,	3,	12,
	3,	0,	2,	4,
	2,	0,	3,	4,
	1,	0,	3,	4,	//
	7,	0,	2,	12,
	3,	0,	2,	4,
	1,	0,	3,	4,
	7,	0,	2,	4,	//
	6,	0,	2,	16,

	0x00
};   
  
void delay (unsigned char m)   //控制频率延时    
{	int i;
	if(s==0)
	{	if(b==1)       i=pitch1[m];
		else if(b==2)  i=pitch2[m];
		     else      i=pitch3[m];
	}
	else
	{	if(b==1)       i=pitch1s[m];
		else if(b==2)  i=pitch2s[m];
		     else      i=pitch3s[m];
	}
	while(--i);   
}   
void delayms(unsigned char a)  //毫秒延时子程序    
{	while(--a);     
}    
void main()   
{	unsigned char p,m;         //m 音高    
	unsigned char i=0;      
	TMOD = 0x01;   
	TH0  = 0x3c;
	TL0  = 0xaf;   
	EA   = 1;
	ET0  = 1;  
play:
	while(1)   
	{   
	a:  p=music_tab[i];   
		if(p==0x00)       
		{	i=0;
			delayms(1000); 
			goto play;         //如果碰到结束符,延时1秒,回到开始再来一遍  
		}       
		else if(p==0xff)  
		{	i=i+1;
			delayms(100);
			TR0=0;
			goto a;            //若碰到休止符,延时100ms,继续取下一音符
		}      
		else
		{	m=music_tab[i++];  //音高
			s=music_tab[i++];  //升音
			b=music_tab[i++];  //八度
			n=music_tab[i++];  //节拍
		}      
		TR0=1;                 //开定时器0    
		while(n!=0)            //等待节拍完成,输出音频  
		{	Beep=~Beep;
			delay(m);    
		} 
		TR0=0;                 //关定时器0    
	}   
} 
void int0() interrupt 1        //采用中断定时器0 控制节拍    
{	TH0=0x3c;   
	TL0=0xaf;   
	n--;   
} 