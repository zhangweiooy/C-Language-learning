#include<cstdio>
#include<cstring>
using namespace std;
typedef struct Node
{
	char a[50];
	int top;
}stack;
int isempty(stack *s)
{
	return s->top==-1;
}
void initstack(stack *s)
{
	s->top=-1;
}
void push(stack *s,char b)
{
	s->top++;
	s->a[s->top]=b;
}
void pop(stack *s,char* b)
{
	*b=s->a[s->top];
	s->top--;
}
void gettop(stack *s,char* b)
{
	*b=s->a[s->top];
}
bool match(char x,char y)
{
	if(y==']')
	    if(x=='[')
	        return true;
	    else
	        return false;
	if(y==')')
	    if(x=='(')
	        return true;
	    else
	        return false;
	return false;
}
int main()
{
	char temp[100];
	gets(temp);
	stack* s;
	char ch;
	initstack(s);
	for(int i=0;temp[i]!='\0';i++)
	{
		if(temp[i]=='['||temp[i]=='(')
		    push(s,temp[i]);
		if(temp[i]==']'||temp[i]==')')
		{
			if(isempty(s))
			{
				printf("Match false!\n");
				return 0;
			}
			else
			{
				gettop(s,&ch);
				if(match(ch,temp[i]))
				    pop(s,&ch);
				else
				{
					printf("Match false!\n");
				    return 0;
				}
			}
		}
	}
	if(isempty(s))
	    printf("Match succeed!\n");
	else
	    printf("Match false!\n");
	return 0;
}
