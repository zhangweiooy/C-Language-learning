#include <stdio.h>  
#include <stdlib.h>  
int main()  
{  
    int i,n;  
    scanf("%d",&n);  
    for(i=2;i<=n;i++)  
    {  
        while(n!=i)     //��i=n��������������n����  
        {  
            if(n%i==0)  //��i�������������ӡ��i��ֵ�������̸�n����ֵ  
            {  
                printf("%d\n",i);  
                n=n/i;  
            }  
            else break;//�����ܱ�i������������һ��i  
        }  
    }  
    printf("%d\n",n);   //�����Ǵ�ӡ���һ����������Ҳ���ǵ���iʱ���Ǹ�  
    return 0;  
}  
