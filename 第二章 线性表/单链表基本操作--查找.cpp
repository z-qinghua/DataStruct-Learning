#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

//初始化链表（带头结点）
bool Initlist(LinkList &L){
	L=(LNode *)malloc(sizeof(LNode));		//指向头结点 
	if(L==NULL)
		return false;					//内存分配失败 
	L->next=NULL;						 
	return true;	
} 

//指定结点p后插入元素e
bool InsertNextNode(LNode *p,int e){
	if(p==NULL)
		return false;
	LNode *s=(LNode *)malloc(sizeof(LNode));
	if(s==NULL)
		return false;			//内存分配失败 
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
} 


//按位查找(带头结点)
LNode *GetElem(LinkList L,int i){
	if(i<0) 
		return NULL;
	LNode *p;				//指向当前扫描到的结点 
	int j=0;				//当前p指向第几个结点 
	p=L;
	while(p!=NULL && j<i){		//循环找到第i个结点 
		p=p->next;
		j++;
	}
	return p;
}

//按值查找，找到数据与==e的结点
LNode *LocateElem(LinkList L,int e){
	LNode *p=L->next;
	//从第一个结点开始查找数据与为e的结点 
	while(p!=NULL && p->data!=e)
		p=p->next;
	return p;			//找到 后返回该结点指针，否则返回NULL 
} 


//按位序插入（带头结点） 
bool ListInsert(LinkList &L,int i,int e){
	if(i<1)
		return false;
	else
		return InsertNextNode(GetElem(L,i-1),e); 
} 

//按位序删除（带头结点）
bool ListDelete(LinkList &L,int i,int &e){
	if(i<1)
		return false;
	LNode *p=GetElem(L,i-1);
	if(p==NULL)
		return false;
	LNode *q=p->next;
	e=p->next->data;
	p->next=q->next;
	free(q);
	return true;
} 

//求表的长度
int Length(LinkList L){
	int len=0;
	LNode *p=L;
	while(p!=NULL){
		p=p->next;
		len++;
	}
	return len;
} 

//主函数
int main(){
	LinkList L;		//声明一个链表
	Initlist(L);	//初始化
	ListInsert(L,1,1);
	ListInsert(L,2,2);
	ListInsert(L,3,3);
	
	if(GetElem(L,4)==NULL)
		printf("i范围非法!\n");
		
	//删除
	int e=-1;
	if(ListDelete(L,1,e))
		printf("已删除第i个结点，元素值为%d\n",e); 
	else
		printf("i范围非法!\n");
		
	LNode *s=L;
	while(s->next!=NULL){
		s=s->next;
		printf("%d\n",s->data);
	}
	
	printf("链表长度为%d\n",Length(L));
	 
	return 0;
} 

/*
封装的好处：
	避免重复代码，简洁、易维护。 
*/
