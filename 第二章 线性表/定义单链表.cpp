#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

//初始化一个单链表(带头结点)
bool InitList_tou(LinkList &L){
	L=(LNode *)malloc(sizeof(LNode));		//分配一个头结点 
	if(L==NULL)							//内存不足，分配失败 
		return false;
	L->next = NULL;							//头结点之后暂时没有结点 
	return true;
} 
//初始化一个单链表（不带头结点）
bool InitList(LinkList &L){
	L=NULL;							//空表，暂时没有任何结点 
	return true;
} 


//判断表是否为空(带头结点)
bool Empty(LinkList L){
	if(L->next==NULL)
		return true;
	else
		return false;
} 

int main(){
	LinkList L;
	InitList_tou(L);
	return 0;
}
