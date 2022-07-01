/*
用栈实现括号匹配：
依次扫描所有字符，遇到左括号入栈，遇到右括号则弹出栈顶元素检查是否匹配
匹配失败情况：
1.左括号单身
2.右括号单身
3.左右括号不匹配 
*/
#include<stdio.h>

#define Maxsize 20

typedef struct{
	char data[Maxsize];		//静态数组存放栈中元素 
	int top;				//栈顶指针 
}SqStack;

//初始化栈
void InitStack(SqStack &S){
	for(int i=0;i<Maxsize;i++)
		S.data[i]=0;
	S.top=-1;
} 

//判空
bool StackEmpty(SqStack S){
	if(S.top==-1)
		return true;
	else 
		return false;
}

//判满
bool StackFull(SqStack S){
	if(S.top==Maxsize-1)
		return true;
	else
		return false; 
}

//入栈
bool Push(SqStack &S,char x){
	if(StackFull(S))
		return false;			//栈满，入栈失败
	S.data[++S.top]=x;
	return true;
}

//出栈
bool Pop(SqStack &S,char &x){
	if(StackEmpty(S))
		return false;			//栈空，无元素出栈
	x=S.data[S.top--];
	return true;
}

//读取栈顶元素
bool GetTop(SqStack S,char &x){
	if(StackEmpty(S))
		return false;			//栈空，报错
	x=S.data[S.top];
	return true;
}

//打印栈元素
bool PrintStack(SqStack S){
	if(StackEmpty(S))
		return false;
	for(int i=0;i<=S.top;i++)
		printf("%c\n",S.data[i]);
	return true;
}

//括号匹配
bool BracketCheck(char str[],int length){
	SqStack S;		//声明一个栈 
	InitStack(S);		//初始化一个栈
	for(int i=0;i<length;i++){
		if(str[i]=='(' || str[i]=='[' || str[i]=='{'){
			Push(S,str[i]);			//扫描到左括号，入栈 
		}else{
			if(StackEmpty(S))	//扫描到右括号，且当前栈空，匹配失败 
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
	return StackEmpty(S);	//检索完全部括号后，栈空说明成功 ，否则失败 
} 

//主函数

int main(){
	char str[10];
	scanf("%s",str);
	if(BracketCheck(str,6))
		printf("匹配成功！\n");
	else
		printf("匹配失败！\n");
	return 0;
} 
