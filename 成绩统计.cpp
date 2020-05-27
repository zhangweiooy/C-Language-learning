#include"stdio.h"
int main()
{
	float a[4],b[4];
	int i;
	char n[4][8]={{"wanglei"},{"lihong"},{"zhangli"},{"liuming"}};
    a[0]=(78+90+87+92)*1.0/4;
    a[1]=(88+91+89+78)*1.0/4;
    a[2]=(84+76+83+75)*1.0/4;
    a[3]=(88+90+71+83)*1.0/4;
    b[0]=(78+88+84+88)*1.0/4;
    b[1]=(90+91+76+90)*1.0/4;
    b[2]=(87+89+83+71)*1.0/4;
    b[3]=(92+78+75+83)*1.0/4;
    for(i=0;i<4;i++)
    {
    	if(a[i]==(int)a[i])
    	    printf("%s,%d\n",n[i],(int)a[i]);
    	else
    	    printf("%s,%.2f\n",n[i],a[i]);
	}
	printf("AVERAGE:");
	for(i=0;i<4;i++)
	{
		if(b[i]==(int)b[i])
		{
			if(i==3)
			    printf("%d\n",(int)b[i]);
			else
			    printf("%d,",(int)b[i]);
		}
		else
		{
			if(i==3)
			    printf("%.2f\n",b[i]);
			else
			    printf("%.2f,",b[i]);
		}
	}
	return 0;
}
