#include<stdio.h>  
int i;   
//��ŵ���ݹ麯��  
//start��ʾ��ʼ����,tran��ʾ��������,end��ʾĿ������  
void Hanio(int n,char start,char tran,char end)
{  
    if(n==1)
	{                   //��n==1��ʱ�� 
        printf("Move from %c to %c\n",start,end); 
        i++;
    }  
    else
	{  
        Hanio(n-1,start,end,tran);   //�ݹ鴦���Ƚ�n-1������������������  
        printf("Move from %c to %c\n",start,end);          //Ȼ���ٽ����µĴ�����ֱ������Ŀ���� 
		i++;                            
        Hanio(n-1,tran,start,end);    //Ȼ���ظ����ϲ���,�ݹ鴦����ڹ������ϵ�n-1������  
                                     //��ʱ����ԭ������ʼ����Ϊ������(��Ϊ��ʼ���Ѿ�����)  
    }  
}  
int main()
{  
    int n;  
    scanf("%d",&n); 
    i = 0;       
    Hanio(n,'A','B','C');  
    printf("Total steps: %d\n",i);  
    return 0;  
}
