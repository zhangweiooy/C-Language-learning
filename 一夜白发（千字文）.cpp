#include<stdio.h>
#include<string.h>
int a[65536],u1,u2,u3,i,flag=0,m;
unsigned char c1,c2,c3;
void calculate()
{
	for(i=128;i<=65535;i++)
	{
		if(i<=2047)
		{
			if(a[i]>=2)
			{
				printf("%c%c 0x%04x %d\n",(i/64+128+64),(i%64+128),i,a[i]);
			}
		}
		if(i>2047&&i<=65535)
		{
			if(a[i]>=2)
			{
				printf("%c%c%c 0x%04x %d\n",(i/4096+128+64+32),((i%4096)/64+128),(i%64+128),i,a[i]);
			}
		}
	}
}
int main()
{
	memset(a,0,sizeof(a));
	while((c1=getchar())!=255)
	{
		u1=c1;
		if(u1<128)
		    continue;
		if(u1>=192&&u1<=223)
		{
			c2=getchar();
			u2=c2;
			m=(u1-128-64)*64+u2-128;
			a[m]++;
		 } 
		if(u1>=224&&u1<=239)
		{
			c2=getchar();
			c3=getchar();
			u2=c2;
			u3=c3;
			m=(u1-128-64-32)*4096+(u2-128)*64+u3-128;
			a[m]++;
		}
	}
	for(i=0;i<=65535;i++)
	    if(a[i]>=2)
	    {
	    	flag=1;
	    	break;
		}
	if(flag==1)
	    calculate();
	else
	    printf("No repeat!\n");
}
