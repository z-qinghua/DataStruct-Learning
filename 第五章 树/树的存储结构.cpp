#include<stdio.h>

#define MaxSize 100

//������˳��洢
struct TreeNode{
	int value;	//�������Ԫ��
	bool isEmpty; 
};

TreeNode  t[MaxSize];	//����һ���ṹ�����飬 ���������¡��������ҵ�˳�����δ洢��������еĸ������
//�����õ�һ��λ�ÿ�ȱ����֤�����±�ͽ����һ�� 

//����������ʽ�洢
typedef struct BiTNode{
	int data;		//������
	struct BiTNode *lchild,*rchild;		//���Һ���ָ�� 
}BiTNode,*BiTree;
//n�����Ķ���������n+1�������� 

//����һ�ſ���
BiTree root=NULL;

//������ڵ�
root=(BiTree)malloc(sizeof(BiTNode));
root->data={1};
root->lchild=NULL;
root->rchild=NULL;

//�����½��
BiTNode *p=(BiTNode *)malloc(sizeof(BiTNode));
p->data={2};
p->lchild=NULL;
p->rchild=NULL;
root->lchild=p;	//��Ϊ���������� 
