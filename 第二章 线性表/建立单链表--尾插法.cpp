#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{				//���嵥���������� 
	int data;						//ÿ������һ������Ԫ��
	struct LNode *next;				//ָ��ָ����һ����� 
}LNode,*LinkList;

////��ʼ��һ����������ͷ��㣩
//bool InitList(LinkList &L){
//	L=(LNode *)malloc(sizeof(LNode))	//����һ��ͷ���
//	if(L==NULL) 						//�ڴ治�㣬����ʧ��
//		return false;
//	
//	L-next == NULL; 
//	return true;
//}

//�ڵ�i��λ�ò���Ԫ��e(��ͷ���)
//bool ListInsert(LinkList &L,int i,int e){
//	if(i<1)
//		return false;
//	LNode *p;			//ָ��p��ǰɨ�赽�Ľ��
//	int j=0;			//��ǰpָ��ڼ������ 
//	p=L; 				//Lָ��ͷ��㣬ͷ����ǵ�0����㣨�������ݣ�
//	while(p!=NULL && j<i-1){
//		p=p->next;
//		j++;
//	}
//	if(p==NULL)
//		return false;
//	LNode *s=(LNode *)malloc(sizeof(LNode));
//	s->data=e;
//	s->next=p->next;
//	p->next=s;			//�����s����p֮�� 
//	
//	return true;		//����ɹ� 	 
//} 

//����������p���֮�����Ԫ��e
//bool InsertNextNode(LNode *p,int e){
//	if(p==NULL)
//		return false;
//	LNode *s=(LNode *)malloc(sizeof(LNode));
//	if(s==NULL)
//		return false;		//�ڴ����ʧ��
//	s->data=e;
//	s->next=p->next;
//	p->next=s;
//	return true; 
//} 

LinkList List_TailInsert(LinkList &L){		//������������
	int x;
	L=(LinkList)malloc(sizeof(LNode));	//����ͷ��� 
	LNode *s,*r=L;						//r��Ϊ��βָ��
	scanf("%d",&x);						//�������ֵ
	while(x!=9999){
		s=(LNode *)malloc(sizeof(LNode ));
		s->data=x;
		r->next=s;
		r=s;							//rָ���µı�β��� 
		scanf("%d",&x);
	}
	r->next=NULL; 						//��β���ָ���ÿ� 
	return L;	
} 


int main(){
	LinkList L;		//����һ��ָ�������ָ��

	//β�巨���������� 
	List_TailInsert(L);
	LNode *s=L;
	//������� 
	while(s->next!=NULL){
		s=s->next;
		printf("%d\n",s->data);
	}
	return 0; 
} 
