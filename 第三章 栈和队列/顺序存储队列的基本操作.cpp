/*
1.队列是只允许在一端进行插入，在另一端删除的线性表
2.队头：允许删除的一端；队尾：允许插入的一端 
*/

//用顺序存储实现

#include<stdio.h>

#define MaxSize 10

typedef struct{
	int data[MaxSize];			//静态数组存储队列元素 
	int front,rear;				//队头指针和队尾指针 
}SqQueue;

//初始化
void InitQueue(SqQueue &Q){
	Q.front=Q.rear=0;			//初始时，队头队尾指针指向0 
	int i;
	for(i=0;i<MaxSize;i++)
		Q.data[i]=0;
}

 
//判空
bool QueueEmpty(SqQueue Q){
	if(Q.front==Q.rear)
		return true;
	else 
		return false; 
} 

//判满
bool  QueueFull(SqQueue Q){
	if((Q.rear+1)%MaxSize==Q.front)
		return true;
	else
		return false;
}

//入队
bool EnQueue(SqQueue &Q,int x){
	if(QueueFull(Q))
		return false;			//队满报错 
	Q.data[Q.rear]=x;			//将x插入队尾 
	Q.rear=(Q.rear+1)%MaxSize;					//队尾指针后移 
	//用模运算将存储空间在逻辑上变成了环状，代价牺牲了一个存储单元 
	return true;		 
}

//出队
bool DeQueue(SqQueue &Q,int &x){
	if(QueueEmpty(Q))			//判断对空 
		return false;
	x=Q.data[Q.front];		
	Q.front=(Q.front+1)%MaxSize;	//队头指针后移 
	return true; 
}

//获得队头元素的值
bool GetHead(SqQueue Q,int &x){
	if(QueueEmpty(Q))			//对空则报错 
		return false;
	x=Q.data[Q.front];
	return true;
} 
 
//输出队列元素
bool PrintQueue(SqQueue Q){
	if(QueueEmpty(Q))
		return false;
	int len=1,i=Q.front;
	while(len<=(Q.rear+MaxSize-Q.front)%MaxSize){
		printf("%d\n",Q.data[i]);
		len++;
		i=(i+1)%MaxSize;
	}
	return true;
} 

//主函数
int main(){
	SqQueue Q;		//声明一个队列
	InitQueue(Q);	//初始化
	 
	EnQueue(Q,2); 	//入队 
	EnQueue(Q,5);
	
	int x=-1;
	if(DeQueue(Q,x))
		printf("出队元素值：%d\n",x); 
	
	PrintQueue(Q);
	return 0; 
} 
