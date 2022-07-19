#include<stdio.h>
#include<stdlib.h>

//二叉排序树结点 
typedef struct BSTNode{
	int key;
	struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

//在二叉排序树中查找值为key的结点
/*
最坏空间复杂度O(1) 
*/
BSTNode *BST_Search(BSTree T,int key){
	while(T!=NULL && key!=T->key){		//若树空或等于根结点值，则结束循环 
		if(key<T->key)			//小于，则在左子树查找 
			T=T->lchild;		//大于，则在右子树查找 
		else
			T=T->rchild;
	}
	return T;
} 

//在二叉排序树中查找值为key的结点（递归实现）
/*
最坏空间复杂度O(h) 
*/
BSTNode *BSTSearch(BSTree T,int key){
	if(T==NULL)
		return NULL;	//查找失败
	if(key==T->key)
		return T;		//查找成功
	else if(key<T->key)
		return BSTSearch(T->lchild,key);	//在左子树查找
	else 
		return BSTSearch(T->rchild,key);	//在右子树查找 
} 

//在二叉排序树插入关键字为k的新结点（递归实现）
/*
最坏空间复杂度O(h) 
*/ 
int BST_Insert(BSTree &T,int k){
	if(T==NULL){					//原始为空，新插入的结点为根结点 
		T=(BSTree)malloc(sizeof(BSTNode));
		T->key=k;
		T->lchild=T->rchild=NULL;
		return 1;					//返回1，插入成功 
	}
	else if(k==T->key)				//树中存在相同关键字的结点，插入失败 
		return 0;
	else if(k<T->key)
		return BST_Insert(T->lchild,k);	//插入到左子树 
	else
		return BST_Insert(T->rchild,k); 	//插入到右子树 
} 

/*
二叉排序树的构造：
	按照str[]中的关键字序列建立二叉排序树 
*/ 
void Creat_BST(BSTree &T,int str[],int n){
	T=NULL;
	int i=0;
	while(i<n){
		BST_Insert(T,str[i]);
		i++;
	}
}

//二叉排序树中序遍历
void InOrder(BSTree T){
	if(T!=NULL){
		InOrder(T->lchild);
		printf("%d",T->key);
		InOrder(T->rchild);
	}
} 

int  main(){
	BSTree T=NULL;
	int str[]={5,4,3,1,8,7};
	Creat_BST(T,str,6);
	printf("中序遍历：");
	InOrder(T); 
	int k;
	printf("\n查找值："); 
	scanf("%d",&k);
	if(BSTSearch(T,k)!=NULL)
		printf("查找成功!\n");
	else
		printf("查找失败!\n");
	return 0;
}
