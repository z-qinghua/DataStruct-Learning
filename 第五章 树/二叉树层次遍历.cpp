#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//��ʽ���н�� 
typedef struct LinkNode{
	BiTNode *data;	//��ָ������ǽ�� 
	struct LinkNode *next;
}LinkNode;

typedef struct{
	LinkNode *front,*rear;
}LinkQueue;

//��ʼ������
bool InitQueue(LinkQueue &Q) {
	Q.front=Q.rear=(LinkNode *)malloc(sizeof(LinkNode));
	if(Q.front==NULL)
		return false;
	else{
		Q.front->next=NULL;
		printf("\n���г�ʼ���ɹ���\n");
	}
		
	return true;
}


//�п�
bool IsEmpty(LinkQueue Q){
	if(Q.front==Q.rear)
		return true;
	else
		return false;
} 

//���
bool EnQueue(LinkQueue &Q,BiTree x){
	LinkNode *s=(LinkNode *)malloc(sizeof(LinkNode));
	if(s==NULL)
		return false;
	else{
		s->data=x;
		s->next=NULL;
		Q.rear->next=s;
		Q.rear=s;
	}
	return true;
}

//����
BiTree DeQueue(LinkQueue &Q,BiTree &x){
	if(IsEmpty(Q))
		return 0;
	else{
		LinkNode *p=Q.front->next;
		x=p->data;
		Q.front->next=p->next;
		if(Q.rear==p)
			Q.rear=Q.front;
		free(p);
	}
	return x;
} 

//������
BiTree CreatBiTree(){
	char x;
	BiTree B=(BiTree )malloc(sizeof(BiTNode));
	scanf("%c",&x);
	printf("%c",x);
	if(x!='.'){
		B->data=x;
		B->lchild=CreatBiTree();
		B->rchild=CreatBiTree(); 
	}
	else
		B=NULL;
	return B;
}

void LevelOrder(BiTree T){
	LinkQueue Q;
	InitQueue(Q);	//	��ʼ���������� 
	BiTree p;
	printf("��α�������Ϊ��"); 
	EnQueue(Q,T);		//���������� 
	while(!IsEmpty(Q) ){		//���в�����ѭ�� 
		p=DeQueue(Q,T);			//���н����Ӳ����ʸý��
		printf("%c",p->data);
		if(p->lchild!=NULL)
			EnQueue(Q,p->lchild);	//������� 
		if(p->rchild!=NULL)
			EnQueue(Q,p->rchild);  	//�Һ������ 
	}  
}

int main(){
	BiTree T=CreatBiTree() ;
	
	LevelOrder(T);
	return 0;
}
