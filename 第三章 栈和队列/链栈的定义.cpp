#include<stdio.h>
#include<stdlib.h>

typedef struct LinkNode{
	int data;			//数据域
	struct LinkNode *next;		//指针域 
}LinkNode,*LiStack; 

/*
进栈出栈都只能在栈顶一端进行（链头作为栈顶） 
*/

//初始化
bool InitStack(LiStack &S) {
	S=(LiStack )malloc(sizeof(LinkNode));
	if(S==NULL)
		return false;
	else
		S->next=NULL;
	return true;
}

int main(){
	LiStack S;
	InitStack(S);
	return 0;
}
