#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
	int data;
	struct LNode *next; 
}LNode,*LinkList; 

//����������p���֮�����Ԫ��e
//bool InsertNextNode(LNode *p,int e){
//	if(p=NULL)
//		return false;
//	LNode *s=(LNode *)malloc(sizeof(LNode));
//	if(s==NULL)
//		return false;			//�ڴ����ʧ��
//	s->data=e;					//�ý��s��������Ԫ�� 
//	s->next=p->next;
//	p->next=s;					//�����s����p֮�� 
//	return true; 
//} 


//ͷ�巨����������
LinkList List_HeadInsert(LinkList &L){		//������������ (��ҪӦ�ã����������)
	int x;
	L=(LNode *)malloc(sizeof(LNode));		//����ͷ��� 
	L->next=NULL; 
	scanf("%d",&x);
	while(x!=9999){
		LNode *s=(LNode *)malloc(sizeof(LNode));
//		if(s==NULL)
//			return false; 
		s->data=x;
		s->next=L->next;
		L->next=s;						//���½�������У�LΪͷָ�� 
		scanf("%d",&x);
	} 
	return L; 
}

int main(){
	LinkList L;				//����һ��ָ�������ָ��
	List_HeadInsert(L);
	while(L->next!=NULL){
		L=L->next;
		printf("%d\n",L->data);
	} 
	return 0;
}
