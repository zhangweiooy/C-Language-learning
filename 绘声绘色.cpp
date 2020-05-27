#include<stack>
#include<queue>
#include<cstdio>
using namespace std; 

int main()
{
    int n,b,c,f1,t1,t2,t3,t4,f2,f3,f4,j;
    stack<int> a1;
    queue<int> a2;
    priority_queue <int,vector<int>,less<int> > a3;
    priority_queue <int,vector<int>,greater<int> > a4; 
	while(scanf("%d",&n)!=EOF)
	{
		f1=1;
		f2=1;
		f3=1;
		f4=1;
		j=0;
		while(n--)
		{
			scanf("%d %d",&b,&c);
			if(f1==0&&f2==0&&f3==0&&f4==0)
			    continue;
			if(b==1)
			{
			    j=1;
				a1.push(c);
			    a2.push(c);
			    a3.push(c);
			    a4.push(c);
			}
			if(b==2)
			{
				if(j==0)
				{
					f1=f2=f3=f4=0;
					continue;
				}
				else{
				if(!a1.empty())
				    t1=a1.top();
				else
				    f1=0;
				if(!a2.empty())
				    t2=a2.front();
				else
				    f2=0;
				if(!a3.empty())
				    t3=a3.top();
				else
				    f3=0;
				if(!a4.empty())
				    t4=a4.top();
				if(c==t1&&f1==1)
				    a1.pop();
				else
				    f1=0;
				if(c==t2&&f2==1)
				    a2.pop();
				else
				    f2=0;
				if(c==t3&&f3==1)
				    a3.pop();
				else
				    f3=0;
				if(c==t4&&f4==1)
				    a4.pop();
				else
				    f4=0;
				}
			}
		}
		if(f1+f2+f3+f4>1)
			    printf("not sure\n");
			else if(f1+f2+f3+f4<1)
			         printf("pool zls\n");
			     else if(f1==1)
			              printf("stack\n");
			          else if(f2==1)
			                   printf("queue\n");
			               else if(f3==1)
			                        printf("big priority queue\n");
			                    else if(f4==1)
			                             printf("small priority queue\n");
		while(!a1.empty())
		    a1.pop();
		while(!a2.empty())
		    a2.pop();
		while(!a3.empty())
		    a3.pop();
		while(!a4.empty())
		    a4.pop();
	}
	return 0;	
} 
