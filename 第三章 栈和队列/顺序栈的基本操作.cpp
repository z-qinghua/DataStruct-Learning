/*
顺序存储：给各个数据元素分配连续的存储空间，大小为MaxSize*sizeof(ElemType) 
*/
#include<stdio.h>

#define MaxSize 10			//定义栈中元素的最大个数
typedef struct{
	int data[MaxSize];			//静态数组中存放栈中元素
	int top;					//栈顶指针 
}SqStack; 

//初始化栈
void InitstStack(SqStack &S){
	int i;
	for(i=0;i<MaxSize;i++)
		S.data[i]=0;
	S.top=-1;				//初始化栈顶指针
}


//判断栈空
bool SqStackEmpty(SqStack S){
	if(S.top==-1)			//栈空 
		return true;
	else					//不空 
		return false;
} 

//新元素入栈
bool Push(SqStack &S,int x){
	if(S.top==MaxSize-1)			//栈满，报错 
		return false;
	S.top=S.top+1;					//指针先加1
	S.data[S.top]=x;
//	S.data[++S.top]=x
	return true; 
} 

//出栈操作
bool Pop(SqStack &S,int &x){
	if(S.top==-1)			//栈空，报错
		return false;
	x=S.data[S.top];
	S.top--;
//	x=S.data[S.top--];
	return true;
}
//读栈顶元素 
bool GetTop(SqStack S,int &x){
	if(S.top==-1)
		return false;		//栈空，报错 
	x=S.data[S.top];		//x记录栈顶元素 
	return true;
}


int main(){
	SqStack S;			//声明一个顺序栈
	InitstStack(S);
	Push(S,2);
	printf("%d\n",S.top); 	//栈丁指针位置 
	Push(S,3);
	printf("%d\n",S.top);
	
	int x=-1;
	Pop(S,x);
	printf("%d\n",x);		//出栈元素值 
	printf("%d\n",S.top);	//出栈后元素指针位置 
	
	for(int i=0;i<=MaxSize;i++){
		printf("%d\n",S.data[i]);
	}
		
	return 0; 
}
