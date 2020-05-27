#include <stdio.h>  
#include <stdlib.h>  
#define MAXSIZE 100000  
int cmp(const void *a, const void *b)  
{  
    int *x = (int *)a;  
    int *y = (int *)b;  
    return (*x) - (*y);  
}  
int main()  
{  
    int cnt = 0;   //��ŵ绰�������  
    int iter = 0;  
    int Noduplicates = 0;  //�����ظ�����ı�־��Ϊ0���ʾ���ظ�  
    int Sum = 0;  
    int icount = 0;  
    char ch;      // ���ռ��������ַ�  
    int *PHONE = (int *)malloc(sizeof(int) * (MAXSIZE + 10));  
    scanf("%d",&cnt);  
    getchar();  
    //��ȡ���е绰���룬ת��Ϊ��������  
    for(iter = 0; iter < cnt; iter++)  
    {  
        Sum = 0;  
        ch = getchar();  
        while(ch != '\n')  
        {  
            if(ch >= '0' && ch <= '9')  
            {  
                Sum = Sum * 10 + ch - '0' ;  
            }  
            else if(ch >= 'A' && ch <= 'P')  
            {  
                Sum = Sum * 10 + (ch - 65) / 3 + 2 ;  
            }  
            else if(ch >= 'R' && ch <= 'Y')  
            {  
                Sum = Sum * 10 + (ch - 66) / 3 + 2 ;  
            }  
            ch = getchar();  
        }  
        PHONE[iter] = Sum;  
    }  
      
    //�ÿ��ŶԵ绰��������  
    qsort(PHONE, cnt, sizeof(int), cmp);  
      
    //����ź�˳��ĺ���  
    for(iter = 0, icount = 1; iter < cnt - 1 ; iter++)  
    {  
        icount = 1;  
        //ͳ���ظ��������  
        while(PHONE[iter] == PHONE[iter + 1])  
        {  
            iter++;  
            icount++;  
        }  
        if(icount > 1)  
        {  
            Noduplicates = 1;  
            printf("%03d-%04d %d\n",PHONE[iter] / 10000 ,PHONE[iter] % 10000 ,icount);  
        }  
    }  
    if(Noduplicates == 0)  
    {  
        printf("No duplicates.\n");  
    }  
    getchar();  
    return 0;  
}  
