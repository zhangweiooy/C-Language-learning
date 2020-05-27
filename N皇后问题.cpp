#include <stdio.h>
#include <stdlib.h>
#define max 8
//sum����������Ŀ��ܵĸ�����ÿ�����һ�θ���Ҫ���λ��
//sum�������ͻᱻ+1
int queen[max], sum=0; /* maxΪ����������� */

void show() /* ������лʺ������ */
{
    int i;
    printf("(");
    //i����������queen[i]����ǰ��Ԫ��������������
    //ע��˴��±��Ǵ�0��ʼ��

    for(i = 0; i < max; i++)
    {
         printf(" %d", queen[i]+1);
    }
    printf(")\n");
    //ÿ�����һ�ֽ��ʱ����ô���Ľ�������ͻ�����1
    sum++;
}

//�˺��������жϻʺ�ǰ�ʺ��Ƿ���Է��ڴ�λ��
int PLACE(int n) /* ��鵱ǰ���ܷ���ûʺ� */
{
    //queen[i] == queen[n]���ڱ�֤Ԫ�ز�����ͬһ��
    //abs(queen[i] - queen[n]) == abs(n - i)����Լ��Ԫ�ز�����ͬһ���Ҳ�����ͬһ��б����
    int i;
    for(i = 0; i < n; i++) /* �����źͶԽ������Ƿ���Է��ûʺ� */
    {
        if(queen[i] == queen[n] || abs(queen[i] - queen[n]) == abs(n - i))
        {
            return 0;
        }
    }
    return 1;
}

//���ĺ��������ݷ���˼��
void NQUEENS(int n) /* ���ݳ��Իʺ�λ��,nΪ������ */
{
    int i;
    for(i = 0; i < max; i++)
    {
        //���Ƚ��ʺ���ڵ�0�е�λ�ã����ڵ�һ����˵�ǿ϶�������
        //���Ե�һ�ν��ʺ���ڵ�0��0�е�λ��
        queen[n] = i; /* ���ʺ�ڵ���ǰѭ������λ�� */
        if(PLACE(n))
        {
            if(n == max - 1)
            {
                show(); /* ���ȫ���ںã���������лʺ������ */
            }
            else
            {
                NQUEENS(n + 1); /* ��������ڷ���һ���ʺ� */
            }
        }
    }
}

int main()
{
    NQUEENS(0); /* �Ӻ�����Ϊ0��ʼ���γ��� */
    printf("\n");
    printf("�ܹ��Ľⷨ��%d��\n", sum);

    return 0;
}
