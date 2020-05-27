#include"stdio.h"
#include"string.h"
#include"stdlib.h"
typedef struct stu
{
	char name[50],level;
	int point,pm;
} STU;
char judge(int p)
{
	if (p>=90)
	    return 'A';
	if (p>=80)
	    return 'B';
	if (p>=70)
	    return 'C';
	if (p>=60)
	    return 'D';
	return 'F';
}
int main()
{
    STU a[6];
	int i,j,temp,max,count=0;
	char s[200]={'\0'};
	for(i=1;i<=5;i++){
		gets(s);
	 	for (j=0;s[j]!=',';j++)
	 	    {
	 	 	    a[i].name[j]=s[j];
		    }
		a[i].name[j]='\0';
		a[i].point=atoi(s+j+1);	
		a[i].level=judge(a[i].point);
	}	
	for(i=1;count<5;i++){
		max=0;
		for(j=1;j<=5;j++){
			if(a[j].point>max){
				max=a[j].point;
			}
		}
		for(j=1;j<=5;j++){
			if(a[j].point==max){
				a[j].pm=i;
		        a[j].point=0;
		        count++;
			}
		}
		
	}
	for (i=1;i<=5;i++)
	    printf("%s-%c-%d\n",a[i].name,a[i].level,a[i].pm);
	 return 0;
}
