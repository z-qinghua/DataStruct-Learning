//��������������ʽ�洢
#include<stdio.h> 
#include<stdlib.h>

typedef struct ThreadNode{
	char data;
	struct ThreadNode *lchild,*rchild;
	int ltag,rtag;			//����������־ 
}ThreadNode,*ThreadTree;

//ȫ�ֱ���pre,ָ��ǽ���ʽ���ǰ�� 
ThreadNode *pre=NULL;
 
void visit(ThreadNode *q){
	if(q->lchild==NULL){//������Ϊ�գ�����ǰ����� 
		q->lchild=pre;
		q->ltag=1; 
	}
	if(pre!=NULL && pre->rchild==NULL){
		pre->rchild=q;//����ǰ�����ĺ������
		pre->rtag=1; 
	}
	pre=q;
}

//���������������һ�߱���һ�������� 
void InThread(ThreadTree T){
	if(T!=NULL){
		InThread(T->lchild);
		visit(T);
		InThread(T->rchild);
	}
}

//����������������T
void CreatInThread(ThreadTree T){
	pre=NULL;		//pre��ʼΪNULL
	if(T!=NULL){
		InThread(T);	//����������������
		if(pre->rchild==NULL)
			pre->rtag=1;	//������������һ����� 
	} 
} 

void PreThread(ThreadTree T){
	if(T!=NULL){
		visit(T);
		if(T->ltag==0)	//��ltag==0ʱ�����ܶ����������� ������ 
			PreThread(T->lchild);	//lchild����ǰ������
		PreThread(T->rchild); 
	}
} 

//����������������
void CreatPreThread(ThreadTree T){
	pre=NULL;	//��ʼΪNULL
	if(T!=NULL){
		PreThread(T);
		if(pre->rchild==NULL)
			pre->rtag=1;	//����������һ����� 
	} 
} 

void PostThread(ThreadTree T){
	if(T!=NULL){
		PostThread(T->lchild);
		PostThread(T->rchild);
		visit(T);
	}
}

//���������������� 
void CreatPostThread(ThreadTree T){
	pre==NULL;
	if(T!=NULL){
		PostThread(T);
		if(pre->rchild==NULL)
			pre->rtag=1;
	}
} 

/*
���������������������� 
*/

//�ҵ���pΪ���������У���һ������������Ľ��
ThreadNode *Firstnode(ThreadNode *p){
	//ѭ���ҵ������½�㣨��һ����Ҷ��㣩
	while(p->ltag==0)
		p=p->lchild;
	return p; 
}

//�������������������ҵ����p�ĺ�̽��
ThreadNode *Nextnode(ThreadNode *p){
	//�����������½��
	if(p->rtag==0)
		return Firstnode(p->rchild); 
	else
		return p->rchild;//rtag=1ֱ�ӷ��غ�� 
}

//�������������������������������������ʵ�ֵķǵݹ��㷨��
void InOrder(ThreadTree T){
	printf("\n���������");
	for(ThreadNode *p=Firstnode(T);p!=NULL;p=Nextnode(p))
		printf("%c",p->data);
}

/*
	��������������������ǰ�� 
*/

//�ҵ���pΪ�������������һ������������Ľ��
ThreadNode *Lastnode(ThreadNode *p){
	//ѭ���ҵ������½�㣨��һ����Ҷ��㣩
	while(p->rtag==0)
		p=p->rchild;
	return p; 
} 

//�������������������ҵ����p��ǰ�����
ThreadNode *Prenode(ThreadNode *p){
	//�����������½��
	if(p->ltag==0)
		return Lastnode(p->lchild);
	else
		return p->lchild;//ltag=1ֱ�ӷ���ǰ������  
}

//�������������������������������
void RevInOrder(ThreadNode *T){
	printf("\n�������������");
	for(ThreadNode *p=Lastnode(T);p!=NULL;p=Prenode(p))
		printf("%c",p->data);
} 

/*
	���������������������� 
*/


//����������
ThreadTree CreatThreadTree(){
	char x;
	ThreadTree B=(ThreadNode *)malloc(sizeof(ThreadNode));
	scanf("%c",&x);
	printf("%c",x);
	if(x!='.'){
		B->data=x;
		B->ltag=0;
		B->rtag=0;
		B->lchild=CreatThreadTree() ;
		B->rchild=CreatThreadTree() ;
	}
	else
		B=NULL;
	return B;
}
 
int main(){
	ThreadTree T=CreatThreadTree();
	CreatInThread(T);
	InOrder(T);
	RevInOrder(T);
	return 0;
}
