#include<stdio.h>
#include<stdlib.h>
 
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;


//创建树
BiTree CreatBiTree(){
	char x;
	BiTree B=(BiTree )malloc(sizeof(BiTNode));
	scanf("%c",&x);
	printf("%c",x);

	if(x!='.'){
		B->data=x;
		B->lchild=CreatBiTree();
		B->rchild=CreatBiTree(); 
	} 
	else
		B=NULL;
	return B;
} 
//先序遍历 
void PreOrder(BiTree T){
	if(T!=NULL){
		printf("%c",T->data);		//访问根结点 
		PreOrder(T->lchild);		//	递归遍历左子树 
		PreOrder(T->rchild); 		//递归遍历右子树 
	}
} 

//中序遍历
 void InOrder(BiTree T){
 	if(T!=NULL){
 		InOrder(T->lchild);		//递归遍历左子树 
 		printf("%c",T->data);					//访问根结点 
 		InOrder(T->rchild);			//递归遍历右子树 
	 }
 } 
 
//后序遍历
void PostOrder(BiTree T){
	if(T!=NULL){
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c",T->data);
	}
} 

//求树的深度
int TreeDepth(BiTree T){
	if(T==NULL)
		return 0;
	else{
		int l=TreeDepth(T->lchild);
		int r=TreeDepth(T->rchild);
		//树的深度=Max{左子树深度，右子树深度}+1 
		return l>r?l+1:r+1;
	}
} 

int main(){
	BiTree T=CreatBiTree();
	printf("\n先序遍历：");
	PreOrder(T);
	
	printf("\n中序遍历：");
	InOrder(T);
	
	printf("\n后序遍历：");
	PostOrder(T); 
	
	printf("\n树的深度为：%d\n",TreeDepth(T));
	return 0;
}
