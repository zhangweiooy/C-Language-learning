#include<stdio.h>  
int i;   
//汉诺塔递归函数  
//start表示起始柱子,tran表示过渡柱子,end表示目标柱子  
void Hanio(int n,char start,char tran,char end)
{  
    if(n==1)
	{                   //当n==1的时候 
        printf("Move from %c to %c\n",start,end); 
        i++;
    }  
    else
	{  
        Hanio(n-1,start,end,tran);   //递归处理，先将n-1个盘子移至过渡柱上  
        printf("Move from %c to %c\n",start,end);          //然后再将底下的大盘子直接移至目标柱 
		i++;                            
        Hanio(n-1,tran,start,end);    //然后重复以上步骤,递归处理放在过渡柱上的n-1个盘子  
                                     //此时借助原来的起始柱作为过渡柱(因为起始柱已经空了)  
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
