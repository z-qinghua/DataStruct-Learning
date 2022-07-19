#include<stdio.h>

#define MaxSize 100

//二叉树顺序存储
struct TreeNode{
	int value;	//结点数据元素
	bool isEmpty; 
};

TreeNode  t[MaxSize];	//定义一个结构体数组， 按照上至下、从左至右的顺序依次存储完二叉树中的各个结点
//可以让第一个位置空缺，保证数组下标和结点编号一致 

//二叉树的链式存储
typedef struct BiTNode{
	int data;		//数据域
	struct BiTNode *lchild,*rchild;		//左、右孩子指针 
}BiTNode,*BiTree;
//n个结点的二叉链表共有n+1个空链域 

//定义一颗空树
BiTree root=NULL;

//插入根节点
root=(BiTree)malloc(sizeof(BiTNode));
root->data={1};
root->lchild=NULL;
root->rchild=NULL;

//插入新结点
BiTNode *p=(BiTNode *)malloc(sizeof(BiTNode));
p->data={2};
p->lchild=NULL;
p->rchild=NULL;
root->lchild=p;	//作为根结点的左孩子 
