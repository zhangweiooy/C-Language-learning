#include <stdio.h>
#include <string.h>
int fun(char *a)//判断百岁老人
{
    if(strcmp(&a[14],"996")==0||
    strcmp(&a[14],"997")==0||
    strcmp(&a[14],"998")==0||
    strcmp(&a[14],"999")==0)
    return 1;
    else return 0;
}
char fun2(char *a)//计算检验码
{
    int t1[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char t2[]="10X98765432";
    int sum=0;
    for(int i=0;i<17;i++)sum+=(a[i]-'0')*t1[i];
    return t2[sum%11];
}
int main()
{
    int n,i;
    char a[20];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",a);
        int len=strlen(a);
        if(len==15)
        {
            for(i=17;i>=8;i--)a[i]=a[i-2];
            a[6]='1';
            if(fun(a)==1)a[7]='8';
            else a[7]='9';
            a[17]=fun2(a);
            a[18]=0;
            printf("%s\n",a);
        }
        else
        {
            if(fun2(a)==a[17])printf("Valid\n");
            else printf("Invalid\n");
        }
    }
    system("pause");
    return 0;
}
