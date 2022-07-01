/*
��ջʵ������ƥ�䣺
����ɨ�������ַ���������������ջ�������������򵯳�ջ��Ԫ�ؼ���Ƿ�ƥ��
ƥ��ʧ�������
1.�����ŵ���
2.�����ŵ���
3.�������Ų�ƥ�� 
*/
#include<stdio.h>

#define Maxsize 20

typedef struct{
	char data[Maxsize];		//��̬������ջ��Ԫ�� 
	int top;				//ջ��ָ�� 
}SqStack;

//��ʼ��ջ
void InitStack(SqStack &S){
	for(int i=0;i<Maxsize;i++)
		S.data[i]=0;
	S.top=-1;
} 

//�п�
bool StackEmpty(SqStack S){
	if(S.top==-1)
		return true;
	else 
		return false;
}

//����
bool StackFull(SqStack S){
	if(S.top==Maxsize-1)
		return true;
	else
		return false; 
}

//��ջ
bool Push(SqStack &S,char x){
	if(StackFull(S))
		return false;			//ջ������ջʧ��
	S.data[++S.top]=x;
	return true;
}

//��ջ
bool Pop(SqStack &S,char &x){
	if(StackEmpty(S))
		return false;			//ջ�գ���Ԫ�س�ջ
	x=S.data[S.top--];
	return true;
}

//��ȡջ��Ԫ��
bool GetTop(SqStack S,char &x){
	if(StackEmpty(S))
		return false;			//ջ�գ�����
	x=S.data[S.top];
	return true;
}

//��ӡջԪ��
bool PrintStack(SqStack S){
	if(StackEmpty(S))
		return false;
	for(int i=0;i<=S.top;i++)
		printf("%c\n",S.data[i]);
	return true;
}

//����ƥ��
bool BracketCheck(char str[],int length){
	SqStack S;		//����һ��ջ 
	InitStack(S);		//��ʼ��һ��ջ
	for(int i=0;i<length;i++){
		if(str[i]=='(' || str[i]=='[' || str[i]=='{'){
			Push(S,str[i]);			//ɨ�赽�����ţ���ջ 
		}else{
			if(StackEmpty(S))	//ɨ�赽�����ţ��ҵ�ǰջ�գ�ƥ��ʧ�� 
				return false;
			char topElem=-1;
			Pop(S,topElem);
			if(str[i]==')' &&topElem!='(')
				return false;
			if(str[i]==']' &&topElem!='[')
				return false;
			if(str[i]=='}' &&topElem!='{')
				return false;
		} 
	} 
	return StackEmpty(S);	//������ȫ�����ź�ջ��˵���ɹ� ������ʧ�� 
} 

//������

int main(){
	char str[10];
	scanf("%s",str);
	if(BracketCheck(str,6))
		printf("ƥ��ɹ���\n");
	else
		printf("ƥ��ʧ�ܣ�\n");
	return 0;
} 
