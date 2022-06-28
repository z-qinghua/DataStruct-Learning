#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList; 

//初始化一个链表（带头结点）
bool InitList(LinkList &L){
	L=(LNode *)malloc(sizeof(LNode ));
	if(L==NULL)			//内存分配失败 
		return false;
	L->next=NULL;
	return true;			//初始化成功 
}

//按位序插入(带头结点),在表中第i个位置插入指定元素e 
bool InsertNextNode(LNode *p,int e);
bool ListInsert_tou(LinkList &L,int i,int e){
	if(i<1)						//判断i范围是否合法 
		return false;
	LNode *p;					//指向当前扫描到的结点
	int j=0;					//当前指向的是第几个结点 
	p=L;						//L指向头结点，头结点是第0个结点不存数据 
	while(p!=NULL && j<i-1){		//循环找到第i-1个结点 
		p=p->next ;
		j++;
	}
/*
	if(p==NULL)			//i不合法 
	 	return false; 
	LNode *s=(LNode *)malloc(sizeof(LNode));
	if(s==NULL)
		return false;
	s->data=e;
	s->next=p->next;
	p->next=s;				//将结点s连到p之后 
	return true;			//插入成功 
*/

	return InsertNextNode(p,e);
}

//按位序插入（不带头结点）
/*不带头结点写代码更不方便，推荐用带头结点*/ 
bool InitList(LinkList &L,int i,int e){
	if(i<1)
		return false;
	//插入第1个结点与其它结点操作不同
	if(i==1){
		LNode *s=(LNode *)malloc(sizeof(LNode));
		s->data=e;
		s->next=L;
		L=s;			//头指针为新结点 
	} 
	LNode *p;			//指向当前扫描的结点
	int j=1;			//当前扫描的是第几个结点
	p=L;				//p指向第一个结点（不是头结点
	while(p!=NULL && j<i-1){
		p=p->next;
		j++;
	}
	if(p==NULL)
		return false;		//i不合法
	LNode *s=(LNode *)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;			//插入成功 
}  

//指定结点的后插操作：在p结点后插入元素e
bool InsertNextNode(LNode *p,int e){
	if(p==NULL)
		return false;
	LNode *s=(LNode *)malloc(sizeof(LNode ));
	if(s==NULL)				//内存分配失败 
		return false;
	s->data=e;
	s->next=p->next;
	p->next=s;				//将结点s连到p之后 
	return true; 
}

//前插操作：在p结点之前插入元素e
bool InsertPriorNode(LNode *p,int e){
	if(p==NULL)
		return false;
	LNode *s=(LNode *)malloc(sizeof(LNode));
	if(s==NULL)
		return false;		//内存分配失败 
	s->next=p->next;		//新结点s连接到p之后 
	p->next=s;				 
	s->data=p->data;		//将p中元素值复制到s中
	p->data=e;				//将p中元素覆盖为e 
	return true;
} 

/*
//前插操作：在p结点之前插入结点s
bool InsertPriorNode(LNode *p,LNode *s){
	if(p==NULL || s==NULL)
		return false;
	s->next=p->next;
	p->next=s;
	int temp=p->data;			//交换数据域部分 
	p->data=s->data;
	s->data=temp;
	return true;
}
*/
 
//按位序删除（带头结点）
bool ListDelete(LinkList &L,int i,int &e){
	if(i<1)
		return false;
	LNode *p;				//指针p指向当前扫描到的结点 
	int j=0;				//p指向的是第几个结点 
	p=L;						//L指向头结点，头结点是第0个结点，不存数据 
	while(p!=NULL && j<i-1){		//循环找到第i-个结点 
		p=p->next;
		j++;
	}
	if(p==NULL)					//i值不合法 
		return false;
		
	if(p->next==NULL)			//第i-1个结点之后无其它结点 
		return false;
	LNode *q=p->next;			//用q指向被删除结点 
	e=q->data;					//用e返回元素的值 
	p->next=q->next;			//将q结点从链中断开 
	free(q); 					//释放q结点存储空间 
	return true;				//删除成功 
} 


//删除指定结点
/*
1.传入头指针，循环找到p的前驱节点 
2.偷天换日（如果p是最后一个结点，只能从表头开始遍历） 
*/
bool  DeleteNode(LNode *p){
	if(p==NULL)
		return false;
	LNode *q=p->next;			//令q指向p的后继结点 
	p->data=p->next->data;		//和后继结点交换数据 
	p->next=q->next;			//将q结点从链中断开 
	free(q);					//释放后继结点的存储空间 
	return true;
}

//主函数
int main(){
	LinkList L;
	InitList(L);
	ListInsert_tou(L,1,1);		//插入结点 
	ListInsert_tou(L,2,2);
	ListInsert_tou(L,3,3);
	
	int e=-1;
	if(ListDelete(L,2,e))
		printf("已删除第i个结点，删除元素值为%d\n",e);
		
	LNode *s=L;
	while(s->next!=NULL){
		s=s->next;
		printf("%d\n",s->data);
	}
	
	return 0;
} 
