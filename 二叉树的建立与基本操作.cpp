#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct treenode
{
        char data;
        struct treenode *left,*right;
};
 
int leaf=0;
 
struct treenode *CreateBiTree(struct treenode *p)
{
        int i,j,k,len,left=1;
        char c;
 
        scanf("%c",&c);
 
        if (c == '#')
        {
                return NULL;
        }
        else
        {
                p = (struct treenode*)malloc(sizeof(struct treenode));
                p->data = c;
                p->left = CreateBiTree(p->left);
                p->right = CreateBiTree(p->right);
        }
        return p;
}
 
void PrintTree(struct treenode *p,int space)
{
        int i;
        if (p == NULL)
        {
                return;
        }
        if (p->left == NULL && p->right == NULL)
        {
                leaf++;
        }
        for (i = 0;i < space;i++)
        {
                printf(" ");
        }
        printf("%c\n",p->data);
        PrintTree(p->left,space+4);
        PrintTree(p->right,space+4);
}
 
void PreOrderTraverse(struct treenode *p)
{
        if (p == NULL)
        {
                return;
        }
        printf("%c",p->data);
        PreOrderTraverse(p->left);
        PreOrderTraverse(p->right);
}
 
void InOrderTraverse(struct treenode *p)
{
        if (p == NULL)
        {
                return;
        }
        InOrderTraverse(p->left);
        printf("%c",p->data);
        InOrderTraverse(p->right);
}
 
void PostOrderTraverse(struct treenode *p)
{
        if (p == NULL)
        {
                return;
        }
        PostOrderTraverse(p->left);
        PostOrderTraverse(p->right);
        printf("%c",p->data);
}
 
void Swap(struct treenode *p)
{
        struct treenode *q;
 
        if (p == NULL)
        {
                return;
        }        
        Swap(p->left);
        Swap(p->right);
        q=p->right;
        p->right=p->left;
        p->left=q;
}
 
void main()
{
        int i,j,k;
        char in[100];
        struct treenode *root;
 
        root = (struct treenode*)malloc(sizeof(struct treenode));
        root=CreateBiTree(root);
        
        printf("BiTree\n");
        PrintTree(root,0);           //pre-output
 
        printf("pre_sequence  : ");
        PreOrderTraverse(root);         //pre,in,post
        printf("\n");
        printf("in_sequence   : ");
        InOrderTraverse(root);
        printf("\n");
        printf("post_sequence : ");
        PostOrderTraverse(root);
        printf("\n");
 
        printf("Number of leaf: %d\n",leaf);
        printf("BiTree swapped\n");
 
        Swap(root);
 
        PrintTree(root,0);
        printf("pre_sequence  : ");
        PreOrderTraverse(root);         //pre,in,post
        printf("\n");
        printf("in_sequence   : ");
        InOrderTraverse(root);
        printf("\n");
        printf("post_sequence : ");
        PostOrderTraverse(root);
        printf("\n");
 
}
