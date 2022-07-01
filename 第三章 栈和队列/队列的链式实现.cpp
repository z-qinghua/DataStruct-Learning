#include<stdio.h>
#include<stdlib.h> 

typedef struct LinkNode{		//��ʽ���н�� 
	int data;
	struct LinkNode *next;
}LinkNode;

typedef struct{				//��ʽ���� 
	LinkNode *front,*rear;		//���еĶ�ͷ�Ͷ�βָ�� 
}LinkQueue; 

//��ʼ������ͷ��㣩 
bool InitQueue(LinkQueue &Q){
	//��ʼʱ��front��rear��ָ��ͷ��� 
	Q.front=Q.rear=(LinkNode *)malloc(sizeof(LinkNode));
	if(Q.front==NULL)
		return false;
	Q.front->next=NULL;
	return true;
}

//�п�
bool EmptyQueue(LinkQueue Q){
	if(Q.front==Q.rear)
		return true;
	else 
		return false;
}

//��ӣ���ͷ��㣩
bool EnQueue(LinkQueue &Q,int x){
	LinkNode *s=(LinkNode *)malloc(sizeof(LinkNode));
	if(s==NULL)
		return false;
	s->data=x;
	s->next=NULL;
	Q.rear->next=s;			//�½����뵽rear֮�� 
	Q.rear=s;				//�޸ı�βָ��
	return true; 
} 

//���ӣ���ͷ��㣩
bool DeQueue(LinkQueue &Q,int &x){
	if(EmptyQueue(Q))		//�ն� 
		return false;
	LinkNode *p=Q.front->next;			 
	x=p->data;				//�ñ���x���ض�ͷԪ��
	Q.front->next=p->next;		//�޸�ͷ���� nextָ�� 
	if(Q.rear==p)
		Q.rear=Q.front;			//�޸�rearָ�� 
	free(p);			//�ͷŽ��ռ� 
	return true;
} 


int main(){
	LinkQueue Q;
	InitQueue(Q);		//һ��Ҫ��ʼ�� 
				
	EnQueue(Q,2);
	EnQueue(Q,5);
	int x=-1;
	if(DeQueue(Q,x))
		printf("����Ԫ��ֵ��%d\n",x);
		
	return 0; 
}
