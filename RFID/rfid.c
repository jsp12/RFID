#include <LPC214X.H>
unsigned char read()
{
unsigned char ch;
while(!(U0LSR&0X01));
ch=U0RBR;
return ch;
}
int main()
{
unsigned char i,t=0,temp[13],pswd[12]="03001C0D6A78";
IO0DIR=0XFFFFFFFF;
	IO0PIN=0X00000000;
	PINSEL0=0X05;
	U0LCR=0X83;
	U0DLL=0X61;
	U0LCR=0X03;
	for(i=0;i<12;i++)
	temp[i]=read();
	for(i=0;i<12;i++)
{
	if(temp[i]==pswd[i])
		t++;
}
if(t>10)
	IO0PIN=0XFFFFFFF;
}


