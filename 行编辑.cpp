#include<cstdio>
#include<cstdlib>
#include<cstring>
typedef struct Node
{
	char a[100];
	struct Node *next;
} node;
int main()
{
    freopen("in.txt","r",stdin); 

	char s[100],m[100],n[100],order,temp[100];
	int i,j,count=0,line1,line2;
	node *p,*q,*head;
	head=(node*)malloc(sizeof(node));
	q=head;
	gets(s);
	while(1)
	{
		gets(s);
		if(strcmp(s,"[/Text]")==0)
		    break;
		p=(node*)malloc(sizeof(node));
		strcpy(p->a,s);
		p->next=NULL;
		q->next=p;
		q=p;
		count++;
	}
	while(scanf("%c ",&order)!=EOF)
	{
		if(order=='i')
		{
			scanf("%d/",&line1);
			gets(s);
			if(line1>count)
			{
				q=head;
				while(q->next!=NULL)
				    q=q->next;
				p=(node*)malloc(sizeof(node));
				strcpy(p->a,s);
				p->next=NULL;
				q->next=p;
				count++;
			}
			else
			{
				q=head;
				for(i=1;i<line1;i++)
				    q=q->next;       //查找到之前的那一行 
				p=(node*)malloc(sizeof(node));
				strcpy(p->a,s);
				p->next=q->next;
				q->next=p;
				count++;
			}
		}
		if(order=='d')
		{
			scanf("%d",&line1);
			q=head;
			for(i=1;i<line1;i++)
			    q=q->next;
			q->next=q->next->next;
			free(q->next) ;
			count--;
		}
		if(order=='f')
		{
			scanf("%d/%d",&line1,&line2);
			q=p=head;
			for(i=1;i<=line1;i++)
				q=q->next;
			for(i=1;i<line2;i++)
			    p=p->next;
			strcat(q->a,p->next->a);
			p->next=p->next->next;
			free(p->next);
			count--;
		}
		if(order=='c')
		{
			gets(s);
			int k=0,kk=0;
			for(i=0;s[i]!='\0';i++)
			{
				if(s[i]!='\\'&&s[i+1]=='/')
				    s[i+1]='\0';
				j=i+2;
			}
			for(i=0;s[i]!='\0';i++)
			{
				if(s[i]!='\\')
				    m[k++]=s[i];
				else
				{
					m[k++]=s[i+1];   //是"\"要跳过去一个
					i++; 
				}
			}
			m[k]='\0';
			for(i=j;s[i]!='\0';i++)
			{
				if(s[i]!='\\')
				    n[kk++]=s[i];
				else
				{
					n[kk++]=s[i+1];
					i++;
				}
			}
			n[kk]='\0';
			int lm=strlen(m),ln=strlen(n);
			k=kk=0;
			int flag=0;
			memset(temp,0,sizeof(temp));
			p=head->next;
			for(k=1;k<=count;k++)
			{
				kk=0;
				for(i=0;p->a[i]!='\0';i++)
				{
					if(p->a[i]!=m[0])
					{
						temp[kk++]=p->a[i];
						temp[kk]='\0';
					}
					else
					{
						for(j=0;j<lm;j++)
						    if(p->a[i+j]!=m[j])
						    {
						    	flag=0;
						    	break;
							}
							if(j==lm)
							    flag=1;
						if(flag==1)
					    {
					    	strcat(temp,n);
					    	i=i+lm-1;
					    	kk=kk+ln;
					    }
				    	else
					    {
					    	temp[kk++]=p->a[i];
					    	temp[kk]='\0';
					    }
					}	
				}
			    strcpy(p->a,temp);
			    memset(temp,0,sizeof(temp)); 
			    p=p->next;
		    }
		}
	}
	p=head->next;
	for(i=1;i<=count;p=p->next,i++)
	    puts(p->a); 
}
