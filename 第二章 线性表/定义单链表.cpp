#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

//��ʼ��һ��������(��ͷ���)
bool InitList_tou(LinkList &L){
	L=(LNode *)malloc(sizeof(LNode));		//����һ��ͷ��� 
	if(L==NULL)							//�ڴ治�㣬����ʧ�� 
		return false;
	L->next = NULL;							//ͷ���֮����ʱû�н�� 
	return true;
} 
//��ʼ��һ������������ͷ��㣩
bool InitList(LinkList &L){
	L=NULL;							//�ձ���ʱû���κν�� 
	return true;
} 


//�жϱ��Ƿ�Ϊ��(��ͷ���)
bool Empty(LinkList L){
	if(L->next==NULL)
		return true;
	else
		return false;
} 

int main(){
	LinkList L;
	InitList_tou(L);
	return 0;
}
