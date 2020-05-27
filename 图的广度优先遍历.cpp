#include<cstdio>
#include<cstdlib>
#include<queue>
using namespace std;

int visited[200];

typedef struct  ArcNode
{
	int adjvex;
	struct ArcNode *next;
} ArcNode;

typedef struct tNode
{
	char vexdata;
	ArcNode *firstarc;
} VNode;
VNode Adjlist[200];

void CreatGraph()
{
	int u,v;
	while(scanf("%d,%d",&u,&v)&&u!=-1&&v!=-1)
	{
		ArcNode *p,*q;
		p=(ArcNode *)malloc(sizeof(ArcNode));
		q=(ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex=v; 
		p->next=Adjlist[u].firstarc;
		Adjlist[u].firstarc=p;
		q->adjvex=u; 
		q->next=Adjlist[v].firstarc;
		Adjlist[v].firstarc=q;
	}
	return;
}

void VisitGraph(int n)
{
	for(int i=0;i<n;i++)
	{
		ArcNode *p;
		printf("%c",Adjlist[i].vexdata);
		p=(ArcNode *)malloc(sizeof(ArcNode));
		p=Adjlist[i].firstarc;
		while(p!=NULL)
		{
			printf(" %d",p->adjvex);
			p=p->next;
		}
		printf("\n");
	}
    return;
}
void BFS(int v)
{
	queue <int> Q;
	printf("%c",Adjlist[v].vexdata);
	visited[v]=1;
	Q.push(v);
	while(!Q.empty())
	{
		v=Q.front();
		Q.pop();
		ArcNode *p;
		p=Adjlist[v].firstarc;
		while(p!=NULL)
		{
			if(visited[p->adjvex]==0)
			{
				printf("%c",Adjlist[p->adjvex].vexdata);
				visited[p->adjvex]=1;
				Q.push(p->adjvex);
			}
			p=p->next;
		}
	}
	return;
}
void BFSTraverse(int n)
{
	for(int i=0;i<n;i++)
	    visited[i]=0;
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		    BFS(i);
	}
	return;
}
int main()
{
	int n=0;
	char ch=getchar();
	while(ch!='*')
	{
		if(ch!='\n')
		{
	    	Adjlist[n].vexdata=ch;
	    	Adjlist[n].firstarc=NULL;    	
	    	n++;	
		}
		ch=getchar(); 	
	}
	CreatGraph();
	printf("the ALGraph is\n");
	VisitGraph(n);
	printf("the Breadth-First-Seacrh list:");
	BFSTraverse(n);
	printf("\n");
}
