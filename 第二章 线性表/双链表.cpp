/*
�������޷������������ʱ��̫����
˫�����ɽ����ˣ��洢�ܶȵ�һ��� 
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct DNode{				//����˫���������� 
	int data;						//������ 
	struct DNode *prior,*next;		//ǰ���ͺ��ָ�� 
}DNode,*DLinkList;

//��ʼ��˫������ͷ��㣩 
 bool InitDLinkList(DLinkList &L){
 	L=(DNode *)malloc(sizeof(DNode));		//����һ��ͷ��� 
 	if(L==NULL)								//�ڴ����ʧ�� 
 		return false;
 	L->prior=NULL;							//ͷ����prior��Զָ��NULL 
 	L->next=NULL;							//ͷ���֮����ʱû�н�� 
 	return true;
 }
 
//˫������루��P�������s��㣩
bool InsertNextDNode(DNode *p,DNode *s){
	if(p==NULL || s==NULL)
		return false;
	s->next=p->next;
	if(p->next!=NULL)			//���p����к�̽�� 
		p->next->prior=s;
	s->prior=p;
	p->next=s;
	//�޸�ָ��Ҫע��˳��
	 
	return true;	
} 
 
//˫�����ɾ��(ɾ��p���ĺ�̽��)
bool DelelteNextDNode(DNode *p){
	if(p==NULL)
		return false;
	DNode *q=p->next;
	if(q==NULL)
		return false;
	p->next=q->next;
	if(q->next!=NULL)
		q->next->prior=p;
	free(q);
	return true;
} 

//���ٱ�
void DestroyList(DLinkList &L){
	while(L->next!=NULL)
		DelelteNextDNode(L);
	free(L);		//�ͷ�ͷ��� 
	L=NULL;			//ͷ���ָ��NULL 
} 


 int main(){
 	DLinkList L;
 	InitDLinkList(L);
 	
 	DNode *p=L;
 	//�������
	while(p!=NULL)
		p=p->next; 
 	
 	return 0;
 } 
