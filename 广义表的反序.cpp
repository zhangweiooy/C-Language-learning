#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count;                                                                               /*count在输出广义表时用来计数*/

/*---------------用扩展型链表存储广义表----------------*/
typedef enum { ATOM, LIST } ListTag;                                                     /*ATOM为原子结点；LIST为子表*/
/*定义枚举类型ListTag用来标记结点类型*/

typedef struct node 
{
	ListTag  tag;                                                                        /*公共部分，用于区分原子结点和表结点*/
	union 
	{
		char  data;                                                                      /*data为原子结点值域*/
		struct node *hp;                                                                 /*hp为表结点的表头指针*/
	} ptr;
	struct node *tp;                                                                     /*tp指向下一个元素结点*/
} GLNode;

void Substring( char *sub, char *s, int pos, int len )
{
	s = s + pos;                                                                         /*移动到s[0]后第pos位*/
	while ( len > 0 )                                                                    /*复制*/
	{	
		*sub = *s;
		sub++;    s++;
		len--;
	}
	*sub = '\0';                                                                         /*"完善"数组sub[]*/
}
/*函数Substring( )用来将数组s[]从s[0]后第pos位复制len位到数组sub[]中*/

void sever( char *str, char *hstr )
{   
	int n, i, k;                                                                          /*n为str[]长度；i,k用作循环*/
	char ch[2];                                                                           /*ch用来存储str[0]中截下来的部分*/
	n = strlen(str);                                                                      /*计算str[]长度并存入n中*/
	i = k = 0;                                                                            /*i,k赋初值*/
	do                                                                                    /*计算str[]中下一个子表长度并存入i中*/
	{	
		Substring( ch, str, i++, 1 );                                                     /*截取str[]的第i+1位存入ch中*/
		if ( *ch=='(' )
			k ++;
		else 
			if ( *ch==')' )
				k --;
	} while ( i<n && ( *ch!=',' || k!=0 ) );                                               /*当前子表未结束*/

	if ( i<n )                                                                             /*当str[]中剩余子表长度大于1*/
	{ 	
		Substring( hstr, str, 0, i-1 );                                                    /*将字符串str[]中下一个子表存入hstr[]*/
		Substring( str, str, i, n-i );                                                     /*在str[]值删除当前子表*/
	}
	else                                                                                   /*当str[]中本身为一个子表*/
	{	
		strcpy( hstr, str );
		str[0] = '\0';
	}
}
/*函数sever(  )用来将字符串str[]中下一个子表截取并存入hstr[]中*/

int PrintGList( GLNode * T )
{
	GLNode *p=T, *q;

	if ( p==NULL )                                                        /*当前深度层输出完毕*/
		printf( ")" );
	else                                                                  /*否则递归输出该深度层*/
	{	
		if ( p->tag==ATOM )                                               /*当前为原子结点*/
		{ 	
			if ( count > 0 )                                              /*该原子结点非该层第一个结点*/
				printf( "," );
			printf( "%c", p->ptr.data );
			count ++;
		}
		else                                                              /*当前为表结点*/
		{	
			q = p->ptr.hp;                                                /*p指向该节点子表*/
			if ( q == NULL )                                              /*该子表为空*/
			{	
				if ( count > 0 )
					printf(",");
				printf("(");
			}
			else                                                          /*否则*/
				if ( q->tag == LIST )                                     /*当前为子表*/
			   {	
				   if ( count > 0 )
					  printf( "," );
				   printf( "(" );
				   count = 0;
				}
			if(q==NULL)   count++;
			PrintGList( q );                                              /*调用函数PrintGList()输出子表q*/
			PrintGList( p->tp );                                          /*调用函数PrintGList()输出子表p的下一子表*/
		}
	}
	return 1;
}
/*递归函数PrintGList(  )用来输出T所在深度层的其余部分*/

int CreateGList( GLNode **L,  char *s )
{
	GLNode *p, *q;
	char sub[100],  hsub[100];

	p = *L;
	if ( strcmp(s, "()" )==0 )                                                           /*当前表为空时*/
		*L = NULL;
	else                                                                                 /*否则*/
	{
		*L = ( GLNode * ) malloc( sizeof( GLNode ) );                                    /*申请结点空间*/
		if ( strlen(s)==1 )                                                              /*当前为原子结点*/
		{   
			(*L)->tag = ATOM;
			(*L)->ptr.data = s[0];
		}
		else                                                                             /*当前为子表*/
		{	
			(*L)->tag = LIST;
			p = *L;
			Substring( sub, s, 1, strlen(s)-2 );                                         /*当前深度层s[]去括号存入sub[]*/
			do                                                                           /*循环对当前深度层建表*/
			{	
				sever( sub, hsub );                                                      /*取sub[]中下一个子表存入hsub[]中*/
				CreateGList( &p->ptr.hp, hsub );                                         /*递归继续对当前子表建表*/
				q = p;
				if ( strlen(sub) > 0 )
				{	
					p = (GLNode *) malloc( sizeof(GLNode) );
					p->tag = LIST;
					q->tp = p;
				}
			} while ( strlen(sub)>0 );
			q->tp = NULL;                                                                /*“完善”表结构*/
		}
	}
	return 1;
}
/*递归函数CreateGList()用来创建广义表*/

GLNode * reverse( GLNode *head )
{
	GLNode * q[3];/*
	if(head == NULL)
		return NULL;*/
	q[0] = NULL;//前一个指针
	q[1] = head;//当前指针
	if(head != NULL)
		q[2] = head->tp;//后一个指针
	while(q[1] != NULL){
		head = q[1];
		if(q[1]->ptr.hp != NULL && q[1]->ptr.hp->tag == LIST)
			q[1]->ptr.hp = reverse (q[1]->ptr.hp);
		q[1]->tp = q[0];
		q[0] = q[1];
		q[1] = q[2];
		if(q[2] != NULL)
			q[2] = q[2]->tp;
	}
	return head;
}
	//q[1]->tp = q[0];                   //横向换指针
	//q[0] = q[1];
	//q[1] = q[2];
	//if(q[2] == NULL)
	//	return head;
	//q[2] = q[2]->tp;
	//return reverse( q[1] );
/*递归函数GLNode * reverse()用来完成广义表的反序*/

void print( GLNode * L )
{
	if ( L == NULL )                                                      /*当表为空时*/
		printf( "()" );
	else                                                                  /*否则*/
	{
		if ( L->tag == LIST )                                             /*当前为表结点时*/
			printf( "(" );
		if ( L->ptr.hp != NULL )                                          /*当前结点不为空时调用函数PrintGList(  )输出广义表其余部分*/
			PrintGList( L );
		else                                                              /*当前结点为空*/
		{
			PrintGList( L );
			if ( L->tp == NULL )                                          /*输出表后括号*/
				printf( ")" );
		}
	}
	printf( "\n" );
}
/*函数print()用来输出反序的广义表*/

int main( )
{
	char list[100];                                                        /*list[]用来存储读入的数据*/
	GLNode *L, *G;                                                         /*L为依据list[]建立的广义表，G为反序的广义表*/

	scanf("%s", list);                                                     /*读入数据*/
	CreateGList( &L, list );                                               /*调用函数CreateGList()建立广义表*/

	G = reverse( L );                                                      /*调用函数reverse()完成广义表反序*/

	count = 0;
	print( G );                                                            /*调用函数print()输出反序的广义表*/

	return 0;
}