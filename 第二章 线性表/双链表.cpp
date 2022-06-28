/*
单链表：无法逆向检索，有时候不太方便
双链表：可进可退，存储密度低一点点 
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct DNode{				//定义双链表结点类型 
	int data;						//数据域 
	struct DNode *prior,*next;		//前驱和后继指针 
}DNode,*DLinkList;

//初始化双链表（带头结点） 
 bool InitDLinkList(DLinkList &L){
 	L=(DNode *)malloc(sizeof(DNode));		//分配一个头结点 
 	if(L==NULL)								//内存分配失败 
 		return false;
 	L->prior=NULL;							//头结点的prior永远指向NULL 
 	L->next=NULL;							//头结点之后暂时没有结点 
 	return true;
 }
 
//双链表插入（在P结点后插入s结点）
bool InsertNextDNode(DNode *p,DNode *s){
	if(p==NULL || s==NULL)
		return false;
	s->next=p->next;
	if(p->next!=NULL)			//如果p结点有后继结点 
		p->next->prior=s;
	s->prior=p;
	p->next=s;
	//修改指针要注意顺序
	 
	return true;	
} 
 
//双链表的删除(删除p结点的后继结点)
bool DelelteNextDNode(DNode *p){
	if(p==NULL)
		return false;
	DNode *q=p->next;
	if(q==NULL)
		return false;
	p->next=q->next;
	if(q->next!=NULL)
		q->next->prior=p;
	free(q);
	return true;
} 

//销毁表
void DestroyList(DLinkList &L){
	while(L->next!=NULL)
		DelelteNextDNode(L);
	free(L);		//释放头结点 
	L=NULL;			//头结点指向NULL 
} 


 int main(){
 	DLinkList L;
 	InitDLinkList(L);
 	
 	DNode *p=L;
 	//后向遍历
	while(p!=NULL)
		p=p->next; 
 	
 	return 0;
 } 
