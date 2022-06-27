#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
	int data;
	struct LNode *next; 
}LNode,*LinkList; 

//后插操作：在p结点之后插入元素e
//bool InsertNextNode(LNode *p,int e){
//	if(p=NULL)
//		return false;
//	LNode *s=(LNode *)malloc(sizeof(LNode));
//	if(s==NULL)
//		return false;			//内存分配失败
//	s->data=e;					//用结点s保存数据元素 
//	s->next=p->next;
//	p->next=s;					//将结点s连到p之后 
//	return true; 
//} 


//头插法建立单链表
LinkList List_HeadInsert(LinkList &L){		//逆向建立单链表 (重要应用：链表的逆置)
	int x;
	L=(LNode *)malloc(sizeof(LNode));		//建立头结点 
	L->next=NULL; 
	scanf("%d",&x);
	while(x!=9999){
		LNode *s=(LNode *)malloc(sizeof(LNode));
//		if(s==NULL)
//			return false; 
		s->data=x;
		s->next=L->next;
		L->next=s;						//将新结点插入表中，L为头指针 
		scanf("%d",&x);
	} 
	return L; 
}

int main(){
	LinkList L;				//声明一个指向单链表的指针
	List_HeadInsert(L);
	while(L->next!=NULL){
		L=L->next;
		printf("%d\n",L->data);
	} 
	return 0;
}
