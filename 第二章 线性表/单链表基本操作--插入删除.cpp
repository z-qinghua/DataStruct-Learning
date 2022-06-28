#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList; 

//��ʼ��һ��������ͷ��㣩
bool InitList(LinkList &L){
	L=(LNode *)malloc(sizeof(LNode ));
	if(L==NULL)			//�ڴ����ʧ�� 
		return false;
	L->next=NULL;
	return true;			//��ʼ���ɹ� 
}

//��λ�����(��ͷ���),�ڱ��е�i��λ�ò���ָ��Ԫ��e 
bool InsertNextNode(LNode *p,int e);
bool ListInsert_tou(LinkList &L,int i,int e){
	if(i<1)						//�ж�i��Χ�Ƿ�Ϸ� 
		return false;
	LNode *p;					//ָ��ǰɨ�赽�Ľ��
	int j=0;					//��ǰָ����ǵڼ������ 
	p=L;						//Lָ��ͷ��㣬ͷ����ǵ�0����㲻������ 
	while(p!=NULL && j<i-1){		//ѭ���ҵ���i-1����� 
		p=p->next ;
		j++;
	}
/*
	if(p==NULL)			//i���Ϸ� 
	 	return false; 
	LNode *s=(LNode *)malloc(sizeof(LNode));
	if(s==NULL)
		return false;
	s->data=e;
	s->next=p->next;
	p->next=s;				//�����s����p֮�� 
	return true;			//����ɹ� 
*/

	return InsertNextNode(p,e);
}

//��λ����루����ͷ��㣩
/*����ͷ���д����������㣬�Ƽ��ô�ͷ���*/ 
bool InitList(LinkList &L,int i,int e){
	if(i<1)
		return false;
	//�����1�������������������ͬ
	if(i==1){
		LNode *s=(LNode *)malloc(sizeof(LNode));
		s->data=e;
		s->next=L;
		L=s;			//ͷָ��Ϊ�½�� 
	} 
	LNode *p;			//ָ��ǰɨ��Ľ��
	int j=1;			//��ǰɨ����ǵڼ������
	p=L;				//pָ���һ����㣨����ͷ���
	while(p!=NULL && j<i-1){
		p=p->next;
		j++;
	}
	if(p==NULL)
		return false;		//i���Ϸ�
	LNode *s=(LNode *)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;			//����ɹ� 
}  

//ָ�����ĺ���������p�������Ԫ��e
bool InsertNextNode(LNode *p,int e){
	if(p==NULL)
		return false;
	LNode *s=(LNode *)malloc(sizeof(LNode ));
	if(s==NULL)				//�ڴ����ʧ�� 
		return false;
	s->data=e;
	s->next=p->next;
	p->next=s;				//�����s����p֮�� 
	return true; 
}

//ǰ���������p���֮ǰ����Ԫ��e
bool InsertPriorNode(LNode *p,int e){
	if(p==NULL)
		return false;
	LNode *s=(LNode *)malloc(sizeof(LNode));
	if(s==NULL)
		return false;		//�ڴ����ʧ�� 
	s->next=p->next;		//�½��s���ӵ�p֮�� 
	p->next=s;				 
	s->data=p->data;		//��p��Ԫ��ֵ���Ƶ�s��
	p->data=e;				//��p��Ԫ�ظ���Ϊe 
	return true;
} 

/*
//ǰ���������p���֮ǰ������s
bool InsertPriorNode(LNode *p,LNode *s){
	if(p==NULL || s==NULL)
		return false;
	s->next=p->next;
	p->next=s;
	int temp=p->data;			//���������򲿷� 
	p->data=s->data;
	s->data=temp;
	return true;
}
*/
 
//��λ��ɾ������ͷ��㣩
bool ListDelete(LinkList &L,int i,int &e){
	if(i<1)
		return false;
	LNode *p;				//ָ��pָ��ǰɨ�赽�Ľ�� 
	int j=0;				//pָ����ǵڼ������ 
	p=L;						//Lָ��ͷ��㣬ͷ����ǵ�0����㣬�������� 
	while(p!=NULL && j<i-1){		//ѭ���ҵ���i-����� 
		p=p->next;
		j++;
	}
	if(p==NULL)					//iֵ���Ϸ� 
		return false;
		
	if(p->next==NULL)			//��i-1�����֮����������� 
		return false;
	LNode *q=p->next;			//��qָ��ɾ����� 
	e=q->data;					//��e����Ԫ�ص�ֵ 
	p->next=q->next;			//��q�������жϿ� 
	free(q); 					//�ͷ�q���洢�ռ� 
	return true;				//ɾ���ɹ� 
} 


//ɾ��ָ�����
/*
1.����ͷָ�룬ѭ���ҵ�p��ǰ���ڵ� 
2.͵�컻�գ����p�����һ����㣬ֻ�ܴӱ�ͷ��ʼ������ 
*/
bool  DeleteNode(LNode *p){
	if(p==NULL)
		return false;
	LNode *q=p->next;			//��qָ��p�ĺ�̽�� 
	p->data=p->next->data;		//�ͺ�̽�㽻������ 
	p->next=q->next;			//��q�������жϿ� 
	free(q);					//�ͷź�̽��Ĵ洢�ռ� 
	return true;
}

//������
int main(){
	LinkList L;
	InitList(L);
	ListInsert_tou(L,1,1);		//������ 
	ListInsert_tou(L,2,2);
	ListInsert_tou(L,3,3);
	
	int e=-1;
	if(ListDelete(L,2,e))
		printf("��ɾ����i����㣬ɾ��Ԫ��ֵΪ%d\n",e);
		
	LNode *s=L;
	while(s->next!=NULL){
		s=s->next;
		printf("%d\n",s->data);
	}
	
	return 0;
} 
