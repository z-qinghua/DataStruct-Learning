#include<stdio.h>

#define MaxSize 10		//����ջ�����Ԫ�ظ��� 

typedef struct{
	int data[MaxSize];		//��̬����洢ջ��Ԫ�� 
	int top0;				//0��ջ��ָ�� 
	int top1;				//1��ջ��ָ�� 
}ShStack;

//��ʼ��ջ
void InitStack(ShStack &S){
	int i;
	for(i=0;i<MaxSize;i++)
		S.data[i]=0;
	S.top0=-1;
	S.top1=MaxSize;
} 

//�п�
bool EmptyStack(ShStack S){
	if(S.top0==-1 && S.top1==MaxSize)
		return true;
	else 
		return false;
}

//��ջ
bool Push0(ShStack &S,int x){
	if(S.top0+1==S.top1)		//ջ�� 
		return false;
	else
		S.data[++S.top0]=x;
	return true; 
} 

bool Push1(ShStack &S,int x){
	if(S.top0+1==S.top1)
		return false;			//ջ��
	else
		S.data[--S.top1]=x;
	return true; 
}

//��ջ
bool Pop0(ShStack &S,int &x){
	if(EmptyStack(S))
		return false;		//ջ�� 
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
	ShStack S;			//����һ������ջ
	InitStack(S);		//��ʼ��ջ 
	
	if(Push0(S,2))
	printf("��ջԪ��ֵ��%d\n",S.data[S.top0]);
	
	int x=-1;
	if(Pop0(S,x))
		printf("��ջԪ��ֵ��%d\n",x);
		
	if(EmptyStack(S))
		printf("ջ��\n");
	return 0;
} 

