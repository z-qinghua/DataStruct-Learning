#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{				//定义单链表结点类型 
	int data;						//每个结点放一个数据元素
	struct LNode *next;				//指针指向下一个结点 
}LNode,*LinkList;

////初始化一个单链表（带头结点）
//bool InitList(LinkList &L){
//	L=(LNode *)malloc(sizeof(LNode))	//分配一个头结点
//	if(L==NULL) 						//内存不足，分配失败
//		return false;
//	
//	L-next == NULL; 
//	return true;
//}

//在第i个位置插入元素e(带头结点)
//bool ListInsert(LinkList &L,int i,int e){
//	if(i<1)
//		return false;
//	LNode *p;			//指向p当前扫描到的结点
//	int j=0;			//当前p指向第几个结点 
//	p=L; 				//L指向头结点，头结点是第0个结点（不存数据）
//	while(p!=NULL && j<i-1){
//		p=p->next;
//		j++;
//	}
//	if(p==NULL)
//		return false;
//	LNode *s=(LNode *)malloc(sizeof(LNode));
//	s->data=e;
//	s->next=p->next;
//	p->next=s;			//将结点s连到p之后 
//	
//	return true;		//插入成功 	 
//} 

//后插操作：在p结点之后插入元素e
//bool InsertNextNode(LNode *p,int e){
//	if(p==NULL)
//		return false;
//	LNode *s=(LNode *)malloc(sizeof(LNode));
//	if(s==NULL)
//		return false;		//内存分配失败
//	s->data=e;
//	s->next=p->next;
//	p->next=s;
//	return true; 
//} 

LinkList List_TailInsert(LinkList &L){		//正向建立单链表
	int x;
	L=(LinkList)malloc(sizeof(LNode));	//建立头结点 
	LNode *s,*r=L;						//r作为表尾指针
	scanf("%d",&x);						//输入结点的值
	while(x!=9999){
		s=(LNode *)malloc(sizeof(LNode ));
		s->data=x;
		r->next=s;
		r=s;							//r指向新的表尾结点 
		scanf("%d",&x);
	}
	r->next=NULL; 						//表尾结点指针置空 
	return L;	
} 


int main(){
	LinkList L;		//声明一个指向单链表的指针

	//尾插法建立单链表 
	List_TailInsert(L);
	LNode *s=L;
	//依次输出 
	while(s->next!=NULL){
		s=s->next;
		printf("%d\n",s->data);
	}
	return 0; 
} 
