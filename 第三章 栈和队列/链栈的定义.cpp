#include<stdio.h>
#include<stdlib.h>

typedef struct LinkNode{
	int data;			//������
	struct LinkNode *next;		//ָ���� 
}LinkNode,*LiStack; 

/*
��ջ��ջ��ֻ����ջ��һ�˽��У���ͷ��Ϊջ���� 
*/

//��ʼ��
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
