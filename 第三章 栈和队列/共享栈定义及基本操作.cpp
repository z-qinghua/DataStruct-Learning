#include<stdio.h>

#define MaxSize 10		//定义栈中最大元素个数 

typedef struct{
	int data[MaxSize];		//静态数组存储栈中元素 
	int top0;				//0好栈顶指针 
	int top1;				//1好栈顶指针 
}ShStack;

//初始化栈
void InitStack(ShStack &S){
	int i;
	for(i=0;i<MaxSize;i++)
		S.data[i]=0;
	S.top0=-1;
	S.top1=MaxSize;
} 

//判空
bool EmptyStack(ShStack S){
	if(S.top0==-1 && S.top1==MaxSize)
		return true;
	else 
		return false;
}

//入栈
bool Push0(ShStack &S,int x){
	if(S.top0+1==S.top1)		//栈满 
		return false;
	else
		S.data[++S.top0]=x;
	return true; 
} 

bool Push1(ShStack &S,int x){
	if(S.top0+1==S.top1)
		return false;			//栈满
	else
		S.data[--S.top1]=x;
	return true; 
}

//出栈
bool Pop0(ShStack &S,int &x){
	if(EmptyStack(S))
		return false;		//栈空 
	else
		x=S.data[S.top0--];
	return true;
} 

bool Pop1(ShStack &S,int &x){
	if(EmptyStack(S))
		return false;
	else
		x=S.data[S.top1--];
	return true;
} 


int main(){
	ShStack S;			//声明一个共享栈
	InitStack(S);		//初始化栈 
	
	if(Push0(S,2))
	printf("入栈元素值：%d\n",S.data[S.top0]);
	
	int x=-1;
	if(Pop0(S,x))
		printf("出栈元素值：%d\n",x);
		
	if(EmptyStack(S))
		printf("栈空\n");
	return 0;
} 

