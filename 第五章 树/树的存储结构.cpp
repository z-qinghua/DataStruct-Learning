#include<stdio.h>
#include<stdlib.h>

//˫�ױ�ʾ����˳��洢��
//ÿ����㱣��ָ��˫�׵ġ�ָ�롱 

#define MAX_TREE_SIZE 100	//�����������
typedef struct{		//���Ľ�㶨�� 
	int data;		//����Ԫ�� 
	int parent;			//˫��λ���� 
}PTNode;
typedef struct{			//�������Ͷ��� 
	PTNode nodes[MAX_TREE_SIZE];	//˫�ױ�ʾ
	int n;				//����� 
}PTree;

//���ӱ�ʾ����˳��+��ʽ�洢��
//���ӱ�ʾ����˳��洢������㣬ÿ������б��溢������ͷָ��

struct CTNode{
	int child;		//���ӽ���������е�λ��
	struct CTNode *next;	//��һ������ 
};

typedef struct{
	int data;
	struct CTNode *firstChild;	//��һ������ 
}CTBox;

typedef struct{
	CTBox nodes[MAX_TREE_SIZE];
	int n,r;	//������͸���λ�� 
}CTree;

//�����ֵܱ�ʾ�� 

typedef struct CSNode{
	int data;
	struct CSNode *firstchild,*nextsibling;	//��һ�����Ӻ����ֵ�ָ�� 
}CSNode,*CSTree; 
