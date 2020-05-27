#include<cstdio>
#include<stack>
using namespace std;
stack<char>op;
int  priority[8][8]={
                    {1,1,-1,-1,-1,-1,1,1},
                    {1,1,-1,-1,-1,-1,1,1},
					{1,1,1,1,-1,-1,1,1},
					{1,1,1,1,-1,-1,1,1},
					{1,1,1,1,-1,-1,1,1},
					{-1,-1,-1,-1,-1,-1,0,2},
					{1,1,1,1,1,2,1,0},
					{-1,-1,-1,-1,-1,-1,2,0}
					};
void match(char ch)
{
	int l,r;
	switch(op.top())
	{
		case '+':l=0;break;
		case '-':l=1;break;
		case '*':l=2;break;
		case '/':l=3;break;
		case '^':l=4;break;
		case '(':l=5;break;
		case ')':l=6;break;
		case '#':l=7;break;	
	}
	switch(ch)
	{
		case '+':r=0;break;
		case '-':r=1;break;
		case '*':r=2;break;
		case '/':r=3;break;
		case '^':r=4;break;
		case '(':r=5;break;
		case ')':r=6;break;
		case '#':r=7;break;	
	}
	
	int flag=priority[l][r];
	if(flag==1)
	{
		printf("%c",op.top());
		op.pop();
		match(ch);
	}   
	else if(flag==-1)
	{
		op.push(ch);
		return;
	}
	else
	{
		op.pop();
		return;
	}
	return;
}
int main()
{
	int N;
	scanf("%d",&N);
	getchar();
	while(N--)
	{
	    char ch;
	    int flag=1;
	    op.push('#');
	    ch=getchar();
		while(ch!='\n')
		{
			if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'||ch=='('||ch==')'||ch=='#')
			{
				if(ch=='-')
				{
					if(flag==1)
					{
						flag=0;
						printf("%c",ch);
					}
					else
					{
					    flag=1;
						match(ch);
					}    
				}
				else
				{
					if(ch==')')
					    match(ch);
					else
					{
					    flag=1;
					    match(ch);	
					}	
				}
			}    
			else
			{
				flag=0;
				printf("%c",ch);
			}
			ch=getchar();
		}
		printf("\n");
	}
	return 0;
}
