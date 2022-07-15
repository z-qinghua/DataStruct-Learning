#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//链式队列结点 
typedef struct LinkNode{
	BiTNode *data;	//存指针而不是结点 
	struct LinkNode *next;
}LinkNode;

typedef struct{
	LinkNode *front,*rear;
}LinkQueue;

//初始化队列
bool InitQueue(LinkQueue &Q) {
	Q.front=Q.rear=(LinkNode *)malloc(sizeof(LinkNode));
	if(Q.front==NULL)
		return false;
	else{
		Q.front->next=NULL;
		printf("\n队列初始化成功！\n");
	}
		
	return true;
}


//判空
bool IsEmpty(LinkQueue Q){
	if(Q.front==Q.rear)
		return true;
	else
		return false;
} 

//入队
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

//出队
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

//创建树
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
	InitQueue(Q);	//	初始化辅助队列 
	BiTree p;
	printf("层次遍历序列为："); 
	EnQueue(Q,T);		//将根结点入队 
	while(!IsEmpty(Q) ){		//队列不空则循环 
		p=DeQueue(Q,T);			//队列结点出队并访问该结点
		printf("%c",p->data);
		if(p->lchild!=NULL)
			EnQueue(Q,p->lchild);	//左孩子入队 
		if(p->rchild!=NULL)
			EnQueue(Q,p->rchild);  	//右孩子入队 
	}  
}

int main(){
	BiTree T=CreatBiTree() ;
	
	LevelOrder(T);
	return 0;
}
