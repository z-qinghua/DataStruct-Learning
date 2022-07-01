/*
˳��洢������������Ԫ�ط��������Ĵ洢�ռ䣬��СΪMaxSize*sizeof(ElemType) 
*/
#include<stdio.h>

#define MaxSize 10			//����ջ��Ԫ�ص�������
typedef struct{
	int data[MaxSize];			//��̬�����д��ջ��Ԫ��
	int top;					//ջ��ָ�� 
}SqStack; 

//��ʼ��ջ
void InitstStack(SqStack &S){
	int i;
	for(i=0;i<MaxSize;i++)
		S.data[i]=0;
	S.top=-1;				//��ʼ��ջ��ָ��
}


//�ж�ջ��
bool SqStackEmpty(SqStack S){
	if(S.top==-1)			//ջ�� 
		return true;
	else					//���� 
		return false;
} 

//��Ԫ����ջ
bool Push(SqStack &S,int x){
	if(S.top==MaxSize-1)			//ջ�������� 
		return false;
	S.top=S.top+1;					//ָ���ȼ�1
	S.data[S.top]=x;
//	S.data[++S.top]=x
	return true; 
} 

//��ջ����
bool Pop(SqStack &S,int &x){
	if(S.top==-1)			//ջ�գ�����
		return false;
	x=S.data[S.top];
	S.top--;
//	x=S.data[S.top--];
	return true;
}
//��ջ��Ԫ�� 
bool GetTop(SqStack S,int &x){
	if(S.top==-1)
		return false;		//ջ�գ����� 
	x=S.data[S.top];		//x��¼ջ��Ԫ�� 
	return true;
}


int main(){
	SqStack S;			//����һ��˳��ջ
	InitstStack(S);
	Push(S,2);
	printf("%d\n",S.top); 	//ջ��ָ��λ�� 
	Push(S,3);
	printf("%d\n",S.top);
	
	int x=-1;
	Pop(S,x);
	printf("%d\n",x);		//��ջԪ��ֵ 
	printf("%d\n",S.top);	//��ջ��Ԫ��ָ��λ�� 
	
	for(int i=0;i<=MaxSize;i++){
		printf("%d\n",S.data[i]);
	}
		
	return 0; 
}
