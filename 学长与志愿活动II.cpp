#include <stdio.h>
#include <stdlib.h>
//typedef int bool;
#define true 1
#define false 0
int  GreedSelector(int n,long s[],long f[],bool A[])
{
    A[1]=true;
    int i,j=1,count=1;
    for (i=2;i<=n;i++)
    {

        if(s[i]>=f[j])
    {
        A[i]=true ;
        j=i;
 count++;
    }
    else A[i]=false;
    }
return count;
}

int  main()
{
    int i,n=11;
    int p;
    long s[1000],f[1000];
    bool A[1000];
    
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%ld %ld",&s[i],&f[i]);
    p=GreedSelector(n,s,f,A);
    printf("���ŵĽ�Ŀ����Ϊ:%d\n",p);
    printf("��Ŀ��ѡȡ���Ϊ(0��ʾ��ѡ 1��ʾѡȡ):\n");
    for(i=1;i<=n;i++)
        printf("%d ",A[i]);
    printf("\n");
    return 0;
}
