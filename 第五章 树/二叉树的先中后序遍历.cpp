#include<stdio.h>
#include<stdlib.h>
 
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;


//������
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
//������� 
void PreOrder(BiTree T){
	if(T!=NULL){
		printf("%c",T->data);		//���ʸ���� 
		PreOrder(T->lchild);		//	�ݹ���������� 
		PreOrder(T->rchild); 		//�ݹ���������� 
	}
} 

//�������
 void InOrder(BiTree T){
 	if(T!=NULL){
 		InOrder(T->lchild);		//�ݹ���������� 
 		printf("%c",T->data);					//���ʸ���� 
 		InOrder(T->rchild);			//�ݹ���������� 
	 }
 } 
 
//�������
void PostOrder(BiTree T){
	if(T!=NULL){
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c",T->data);
	}
} 

//���������
int TreeDepth(BiTree T){
	if(T==NULL)
		return 0;
	else{
		int l=TreeDepth(T->lchild);
		int r=TreeDepth(T->rchild);
		//�������=Max{��������ȣ����������}+1 
		return l>r?l+1:r+1;
	}
} 

int main(){
	BiTree T=CreatBiTree();
	printf("\n���������");
	PreOrder(T);
	
	printf("\n���������");
	InOrder(T);
	
	printf("\n���������");
	PostOrder(T); 
	
	printf("\n�������Ϊ��%d\n",TreeDepth(T));
	return 0;
}
