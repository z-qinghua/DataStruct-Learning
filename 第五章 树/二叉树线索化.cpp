//线索二叉树的链式存储
#include<stdio.h> 
#include<stdlib.h>

typedef struct ThreadNode{
	char data;
	struct ThreadNode *lchild,*rchild;
	int ltag,rtag;			//左右线索标志 
}ThreadNode,*ThreadTree;

//全局变量pre,指向挡墙访问结点的前驱 
ThreadNode *pre=NULL;
 
void visit(ThreadNode *q){
	if(q->lchild==NULL){//左子树为空，建立前驱结点 
		q->lchild=pre;
		q->ltag=1; 
	}
	if(pre!=NULL && pre->rchild==NULL){
		pre->rchild=q;//建立前驱结点的后继线索
		pre->rtag=1; 
	}
	pre=q;
}

//中序遍历二叉树，一边遍历一边线索化 
void InThread(ThreadTree T){
	if(T!=NULL){
		InThread(T->lchild);
		visit(T);
		InThread(T->rchild);
	}
}

//中序线索化二叉树T
void CreatInThread(ThreadTree T){
	pre=NULL;		//pre初始为NULL
	if(T!=NULL){
		InThread(T);	//中序线索化二叉树
		if(pre->rchild==NULL)
			pre->rtag=1;	//处理遍历的最后一个结点 
	} 
} 

void PreThread(ThreadTree T){
	if(T!=NULL){
		visit(T);
		if(T->ltag==0)	//当ltag==0时，才能对左子树先序 线索化 
			PreThread(T->lchild);	//lchild不是前驱线索
		PreThread(T->rchild); 
	}
} 

//先序线索化二叉树
void CreatPreThread(ThreadTree T){
	pre=NULL;	//初始为NULL
	if(T!=NULL){
		PreThread(T);
		if(pre->rchild==NULL)
			pre->rtag=1;	//处理遍历最后一个结点 
	} 
} 

void PostThread(ThreadTree T){
	if(T!=NULL){
		PostThread(T->lchild);
		PostThread(T->rchild);
		visit(T);
	}
}

//后续线索化二叉树 
void CreatPostThread(ThreadTree T){
	pre==NULL;
	if(T!=NULL){
		PostThread(T);
		if(pre->rchild==NULL)
			pre->rtag=1;
	}
} 

/*
中序线索二叉树找中序后继 
*/

//找到以p为根的子树中，第一个被中序遍历的结点
ThreadNode *Firstnode(ThreadNode *p){
	//循环找到最左下结点（不一定是叶结点）
	while(p->ltag==0)
		p=p->lchild;
	return p; 
}

//在中序线索二叉树中找到结点p的后继结点
ThreadNode *Nextnode(ThreadNode *p){
	//右子树最左下结点
	if(p->rtag==0)
		return Firstnode(p->rchild); 
	else
		return p->rchild;//rtag=1直接返回后继 
}

//对中序线索二叉树进行中序遍历（利用线索实现的非递归算法）
void InOrder(ThreadTree T){
	printf("\n中序遍历：");
	for(ThreadNode *p=Firstnode(T);p!=NULL;p=Nextnode(p))
		printf("%c",p->data);
}

/*
	中序线索二叉树找中序前驱 
*/

//找到以p为根的子树，最后一个被中序遍历的结点
ThreadNode *Lastnode(ThreadNode *p){
	//循环找到最右下结点（不一定是叶结点）
	while(p->rtag==0)
		p=p->rchild;
	return p; 
} 

//在中序线索二叉树中找到结点p的前驱结点
ThreadNode *Prenode(ThreadNode *p){
	//左子树最右下结点
	if(p->ltag==0)
		return Lastnode(p->lchild);
	else
		return p->lchild;//ltag=1直接返回前驱线索  
}

//对中序线索二叉树进行逆向中序遍历
void RevInOrder(ThreadNode *T){
	printf("\n逆向中序遍历：");
	for(ThreadNode *p=Lastnode(T);p!=NULL;p=Prenode(p))
		printf("%c",p->data);
} 

/*
	先序线索二叉树找先序后继 
*/


//创建二叉树
ThreadTree CreatThreadTree(){
	char x;
	ThreadTree B=(ThreadNode *)malloc(sizeof(ThreadNode));
	scanf("%c",&x);
	printf("%c",x);
	if(x!='.'){
		B->data=x;
		B->ltag=0;
		B->rtag=0;
		B->lchild=CreatThreadTree() ;
		B->rchild=CreatThreadTree() ;
	}
	else
		B=NULL;
	return B;
}
 
int main(){
	ThreadTree T=CreatThreadTree();
	CreatInThread(T);
	InOrder(T);
	RevInOrder(T);
	return 0;
}
