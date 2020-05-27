#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count;                                                                               /*count����������ʱ��������*/

/*---------------����չ������洢�����----------------*/
typedef enum { ATOM, LIST } ListTag;                                                     /*ATOMΪԭ�ӽ�㣻LISTΪ�ӱ�*/
/*����ö������ListTag������ǽ������*/

typedef struct node 
{
	ListTag  tag;                                                                        /*�������֣���������ԭ�ӽ��ͱ���*/
	union 
	{
		char  data;                                                                      /*dataΪԭ�ӽ��ֵ��*/
		struct node *hp;                                                                 /*hpΪ����ı�ͷָ��*/
	} ptr;
	struct node *tp;                                                                     /*tpָ����һ��Ԫ�ؽ��*/
} GLNode;

void Substring( char *sub, char *s, int pos, int len )
{
	s = s + pos;                                                                         /*�ƶ���s[0]���posλ*/
	while ( len > 0 )                                                                    /*����*/
	{	
		*sub = *s;
		sub++;    s++;
		len--;
	}
	*sub = '\0';                                                                         /*"����"����sub[]*/
}
/*����Substring( )����������s[]��s[0]���posλ����lenλ������sub[]��*/

void sever( char *str, char *hstr )
{   
	int n, i, k;                                                                          /*nΪstr[]���ȣ�i,k����ѭ��*/
	char ch[2];                                                                           /*ch�����洢str[0]�н������Ĳ���*/
	n = strlen(str);                                                                      /*����str[]���Ȳ�����n��*/
	i = k = 0;                                                                            /*i,k����ֵ*/
	do                                                                                    /*����str[]����һ���ӱ��Ȳ�����i��*/
	{	
		Substring( ch, str, i++, 1 );                                                     /*��ȡstr[]�ĵ�i+1λ����ch��*/
		if ( *ch=='(' )
			k ++;
		else 
			if ( *ch==')' )
				k --;
	} while ( i<n && ( *ch!=',' || k!=0 ) );                                               /*��ǰ�ӱ�δ����*/

	if ( i<n )                                                                             /*��str[]��ʣ���ӱ��ȴ���1*/
	{ 	
		Substring( hstr, str, 0, i-1 );                                                    /*���ַ���str[]����һ���ӱ����hstr[]*/
		Substring( str, str, i, n-i );                                                     /*��str[]ֵɾ����ǰ�ӱ�*/
	}
	else                                                                                   /*��str[]�б���Ϊһ���ӱ�*/
	{	
		strcpy( hstr, str );
		str[0] = '\0';
	}
}
/*����sever(  )�������ַ���str[]����һ���ӱ��ȡ������hstr[]��*/

int PrintGList( GLNode * T )
{
	GLNode *p=T, *q;

	if ( p==NULL )                                                        /*��ǰ��Ȳ�������*/
		printf( ")" );
	else                                                                  /*����ݹ��������Ȳ�*/
	{	
		if ( p->tag==ATOM )                                               /*��ǰΪԭ�ӽ��*/
		{ 	
			if ( count > 0 )                                              /*��ԭ�ӽ��Ǹò��һ�����*/
				printf( "," );
			printf( "%c", p->ptr.data );
			count ++;
		}
		else                                                              /*��ǰΪ����*/
		{	
			q = p->ptr.hp;                                                /*pָ��ýڵ��ӱ�*/
			if ( q == NULL )                                              /*���ӱ�Ϊ��*/
			{	
				if ( count > 0 )
					printf(",");
				printf("(");
			}
			else                                                          /*����*/
				if ( q->tag == LIST )                                     /*��ǰΪ�ӱ�*/
			   {	
				   if ( count > 0 )
					  printf( "," );
				   printf( "(" );
				   count = 0;
				}
			if(q==NULL)   count++;
			PrintGList( q );                                              /*���ú���PrintGList()����ӱ�q*/
			PrintGList( p->tp );                                          /*���ú���PrintGList()����ӱ�p����һ�ӱ�*/
		}
	}
	return 1;
}
/*�ݹ麯��PrintGList(  )�������T������Ȳ�����ಿ��*/

int CreateGList( GLNode **L,  char *s )
{
	GLNode *p, *q;
	char sub[100],  hsub[100];

	p = *L;
	if ( strcmp(s, "()" )==0 )                                                           /*��ǰ��Ϊ��ʱ*/
		*L = NULL;
	else                                                                                 /*����*/
	{
		*L = ( GLNode * ) malloc( sizeof( GLNode ) );                                    /*������ռ�*/
		if ( strlen(s)==1 )                                                              /*��ǰΪԭ�ӽ��*/
		{   
			(*L)->tag = ATOM;
			(*L)->ptr.data = s[0];
		}
		else                                                                             /*��ǰΪ�ӱ�*/
		{	
			(*L)->tag = LIST;
			p = *L;
			Substring( sub, s, 1, strlen(s)-2 );                                         /*��ǰ��Ȳ�s[]ȥ���Ŵ���sub[]*/
			do                                                                           /*ѭ���Ե�ǰ��Ȳ㽨��*/
			{	
				sever( sub, hsub );                                                      /*ȡsub[]����һ���ӱ����hsub[]��*/
				CreateGList( &p->ptr.hp, hsub );                                         /*�ݹ�����Ե�ǰ�ӱ���*/
				q = p;
				if ( strlen(sub) > 0 )
				{	
					p = (GLNode *) malloc( sizeof(GLNode) );
					p->tag = LIST;
					q->tp = p;
				}
			} while ( strlen(sub)>0 );
			q->tp = NULL;                                                                /*�����ơ���ṹ*/
		}
	}
	return 1;
}
/*�ݹ麯��CreateGList()�������������*/

GLNode * reverse( GLNode *head )
{
	GLNode * q[3];/*
	if(head == NULL)
		return NULL;*/
	q[0] = NULL;//ǰһ��ָ��
	q[1] = head;//��ǰָ��
	if(head != NULL)
		q[2] = head->tp;//��һ��ָ��
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
	//q[1]->tp = q[0];                   //����ָ��
	//q[0] = q[1];
	//q[1] = q[2];
	//if(q[2] == NULL)
	//	return head;
	//q[2] = q[2]->tp;
	//return reverse( q[1] );
/*�ݹ麯��GLNode * reverse()������ɹ����ķ���*/

void print( GLNode * L )
{
	if ( L == NULL )                                                      /*����Ϊ��ʱ*/
		printf( "()" );
	else                                                                  /*����*/
	{
		if ( L->tag == LIST )                                             /*��ǰΪ����ʱ*/
			printf( "(" );
		if ( L->ptr.hp != NULL )                                          /*��ǰ��㲻Ϊ��ʱ���ú���PrintGList(  )�����������ಿ��*/
			PrintGList( L );
		else                                                              /*��ǰ���Ϊ��*/
		{
			PrintGList( L );
			if ( L->tp == NULL )                                          /*����������*/
				printf( ")" );
		}
	}
	printf( "\n" );
}
/*����print()�����������Ĺ����*/

int main( )
{
	char list[100];                                                        /*list[]�����洢���������*/
	GLNode *L, *G;                                                         /*LΪ����list[]�����Ĺ����GΪ����Ĺ����*/

	scanf("%s", list);                                                     /*��������*/
	CreateGList( &L, list );                                               /*���ú���CreateGList()���������*/

	G = reverse( L );                                                      /*���ú���reverse()��ɹ������*/

	count = 0;
	print( G );                                                            /*���ú���print()�������Ĺ����*/

	return 0;
}