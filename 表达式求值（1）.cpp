#include<cstdio>
#include<stack>
#include<cstring>
#include<cmath>
#include <cctype>
using namespace std;
char str[1010];
int  priority[9][9]={
                    {1,1,-1,-1,-1,-1,-1,1,1},
                    {1,1,-1,-1,-1,-1,-1,1,1},
					{1,1,1,1,1,-1,-1,1,1},
					{1,1,1,1,1,-1,-1,1,1},
					{1,1,1,1,1,-1,-1,1,1},
					{1,1,1,1,1,-1,-1,1,1},
					{-1,-1,-1,-1,-1,-1,-1,0,2},
					{1,1,1,1,1,1,2,1,1},
					{-1,-1,-1,-1,-1,-1,-1,2,0}
					};
int flag;
stack <char> op;
stack <int> num;
int match(char ch)
{
	int l,r;
	switch(op.top())
	{
		case '+':l=0;break;
		case '-':l=1;break;
		case '*':l=2;break;
		case '/':l=3;break;
		case '%':l=4;break;
		case '^':l=5;break;
		case '(':l=6;break;
		case ')':l=7;break;
		case '#':l=8;break;	
	}
	switch(ch)
	{
		case '+':r=0;break;
		case '-':r=1;break;
		case '*':r=2;break;
		case '/':r=3;break;
		case '%':r=4;break;
		case '^':r=5;break;
		case '(':r=6;break;
		case ')':r=7;break;
		case '#':r=8;break;	
	}
	return priority[l][r];
}
int calc(int a, char c, int b)
{
	switch (c)
	{
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': 
		if (b == 0) flag=2;
		else
		    return a / b;
		break;
	case '%': 
		if (b == 0) 
		     flag=2;
		else
		    return a % b;
		break;
	case '^': 
		if (b < 0) 
		    flag=1;
		else
		    return pow(a, b);
		break;
	}
	return -1;
}
int get_number(int& i)
{
	int ans = 0;
	while (isdigit(str[i])) ans = ans * 10 + str[i++] - '0';
	return ans;
}
void back()
{
	int b = num.top(); num.pop();
	int a = num.top(); num.pop();
	char o = op.top(); op.pop();
	int n=calc(a, o, b);
	num.push(n);
}
void back_to(char end,char errorc)
{
	while (op.top() != end&&flag==0)
	{
		if (op.top() == errorc)
		{
			flag=1;
			return;
		}    
		else
		    back();
	}
	return;
}
void process(char op)
{
	while(match(op)==1&&flag==0)
	{
		back();
	}
}
void calculate()
{
	op.push('#');
	int len = strlen(str);
	if (!isdigit(str[len - 1]) && str[len - 1] != ')')
	    flag=1;
	int sign=1;
	int i=0;
	while(i<len&&flag==0)
	{
		if (isdigit(str[i]))
		{
			if (i > 0 && str[i - 1] == ')') 
			    flag=1;
			else
			{
				num.push(sign * get_number(i));
			    sign = 1;
			}
		}
		else if (str[i] == '(')
		{
			if (i > 0 && isdigit(str[i - 1])) 
			    flag=1;
			if (i > 0 && str[i - 1] == ')') 
			    flag=1;
			op.push(str[i]);
			i++;
		}
		else if (str[i] == ')')
		{
			if (i == 0 || !isdigit(str[i - 1]) && str[i - 1] != ')') 
			    flag=1;
			else
			{
				back_to('(','#');
			    op.pop();
			    i++;
			}
			
		}
		else if (str[i] == '-' && (i == 0 || !isdigit(str[i - 1]) && str[i - 1] != ')'))
		{
			sign = -1;
			i++;
		}
		else
		{
			if (i == 0 || str[i - 1] == '(') 
			    flag=1;
			process(str[i]);
			op.push(str[i]);
			i++;
		}
	}
	if(flag==0)
	{
		back_to('#','(');
		if(flag==1)
		    printf("error.\n");
		else if(flag==2)
		    printf("Divide 0.\n");
		else
		    printf("%d\n",num.top());
	}
	else if(flag==1)
	    printf("error.\n");
	else if(flag==2)
	    printf("Divide 0.\n");
}
int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%s",str);
		calculate();
		while(!op.empty())
		    op.pop();
		while(!num.empty())
		    num.pop();
		flag=0;
	}
}
