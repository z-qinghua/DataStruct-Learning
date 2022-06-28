#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

//��ʼ��������ͷ��㣩
bool Initlist(LinkList &L){
	L=(LNode *)malloc(sizeof(LNode));		//ָ��ͷ��� 
	if(L==NULL)
		return false;					//�ڴ����ʧ�� 
	L->next=NULL;						 
	return true;	
} 

//ָ�����p�����Ԫ��e
bool InsertNextNode(LNode *p,int e){
	if(p==NULL)
		return false;
	LNode *s=(LNode *)malloc(sizeof(LNode));
	if(s==NULL)
		return false;			//�ڴ����ʧ�� 
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
} 


//��λ����(��ͷ���)
LNode *GetElem(LinkList L,int i){
	if(i<0) 
		return NULL;
	LNode *p;				//ָ��ǰɨ�赽�Ľ�� 
	int j=0;				//��ǰpָ��ڼ������ 
	p=L;
	while(p!=NULL && j<i){		//ѭ���ҵ���i����� 
		p=p->next;
		j++;
	}
	return p;
}

//��ֵ���ң��ҵ�������==e�Ľ��
LNode *LocateElem(LinkList L,int e){
	LNode *p=L->next;
	//�ӵ�һ����㿪ʼ����������Ϊe�Ľ�� 
	while(p!=NULL && p->data!=e)
		p=p->next;
	return p;			//�ҵ� �󷵻ظý��ָ�룬���򷵻�NULL 
} 


//��λ����루��ͷ��㣩 
bool ListInsert(LinkList &L,int i,int e){
	if(i<1)
		return false;
	else
		return InsertNextNode(GetElem(L,i-1),e); 
} 

//��λ��ɾ������ͷ��㣩
bool ListDelete(LinkList &L,int i,int &e){
	if(i<1)
		return false;
	LNode *p=GetElem(L,i-1);
	if(p==NULL)
		return false;
	LNode *q=p->next;
	e=p->next->data;
	p->next=q->next;
	free(q);
	return true;
} 

//���ĳ���
int Length(LinkList L){
	int len=0;
	LNode *p=L;
	while(p!=NULL){
		p=p->next;
		len++;
	}
	return len;
} 

//������
int main(){
	LinkList L;		//����һ������
	Initlist(L);	//��ʼ��
	ListInsert(L,1,1);
	ListInsert(L,2,2);
	ListInsert(L,3,3);
	
	if(GetElem(L,4)==NULL)
		printf("i��Χ�Ƿ�!\n");
		
	//ɾ��
	int e=-1;
	if(ListDelete(L,1,e))
		printf("��ɾ����i����㣬Ԫ��ֵΪ%d\n",e); 
	else
		printf("i��Χ�Ƿ�!\n");
		
	LNode *s=L;
	while(s->next!=NULL){
		s=s->next;
		printf("%d\n",s->data);
	}
	
	printf("������Ϊ%d\n",Length(L));
	 
	return 0;
} 

/*
��װ�ĺô���
	�����ظ����룬��ࡢ��ά���� 
*/
