#include<stdio.h>
#include<stdlib.h> 

typedef struct LinkNode{		//链式队列结点 
	int data;
	struct LinkNode *next;
}LinkNode;

typedef struct{				//链式队列 
	LinkNode *front,*rear;		//队列的队头和队尾指针 
}LinkQueue; 

//初始化（带头结点） 
bool InitQueue(LinkQueue &Q){
	//初始时，front，rear都指向头结点 
	Q.front=Q.rear=(LinkNode *)malloc(sizeof(LinkNode));
	if(Q.front==NULL)
		return false;
	Q.front->next=NULL;
	return true;
}

//判空
bool EmptyQueue(LinkQueue Q){
	if(Q.front==Q.rear)
		return true;
	else 
		return false;
}

//入队（带头结点）
bool EnQueue(LinkQueue &Q,int x){
	LinkNode *s=(LinkNode *)malloc(sizeof(LinkNode));
	if(s==NULL)
		return false;
	s->data=x;
	s->next=NULL;
	Q.rear->next=s;			//新结点插入到rear之后 
	Q.rear=s;				//修改表尾指针
	return true; 
} 

//出队（带头结点）
bool DeQueue(LinkQueue &Q,int &x){
	if(EmptyQueue(Q))		//空队 
		return false;
	LinkNode *p=Q.front->next;			 
	x=p->data;				//用变量x返回队头元素
	Q.front->next=p->next;		//修改头结点的 next指针 
	if(Q.rear==p)
		Q.rear=Q.front;			//修改rear指针 
	free(p);			//释放结点空间 
	return true;
} 


int main(){
	LinkQueue Q;
	InitQueue(Q);		//一定要初始化 
				
	EnQueue(Q,2);
	EnQueue(Q,5);
	int x=-1;
	if(DeQueue(Q,x))
		printf("出队元素值：%d\n",x);
		
	return 0; 
}
