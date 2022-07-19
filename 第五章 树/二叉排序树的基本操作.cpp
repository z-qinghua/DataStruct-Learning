#include<stdio.h>
#include<stdlib.h>

//������������� 
typedef struct BSTNode{
	int key;
	struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

//�ڶ����������в���ֵΪkey�Ľ��
/*
��ռ临�Ӷ�O(1) 
*/
BSTNode *BST_Search(BSTree T,int key){
	while(T!=NULL && key!=T->key){		//�����ջ���ڸ����ֵ�������ѭ�� 
		if(key<T->key)			//С�ڣ��������������� 
			T=T->lchild;		//���ڣ��������������� 
		else
			T=T->rchild;
	}
	return T;
} 

//�ڶ����������в���ֵΪkey�Ľ�㣨�ݹ�ʵ�֣�
/*
��ռ临�Ӷ�O(h) 
*/
BSTNode *BSTSearch(BSTree T,int key){
	if(T==NULL)
		return NULL;	//����ʧ��
	if(key==T->key)
		return T;		//���ҳɹ�
	else if(key<T->key)
		return BSTSearch(T->lchild,key);	//������������
	else 
		return BSTSearch(T->rchild,key);	//������������ 
} 

//�ڶ�������������ؼ���Ϊk���½�㣨�ݹ�ʵ�֣�
/*
��ռ临�Ӷ�O(h) 
*/ 
int BST_Insert(BSTree &T,int k){
	if(T==NULL){					//ԭʼΪ�գ��²���Ľ��Ϊ����� 
		T=(BSTree)malloc(sizeof(BSTNode));
		T->key=k;
		T->lchild=T->rchild=NULL;
		return 1;					//����1������ɹ� 
	}
	else if(k==T->key)				//���д�����ͬ�ؼ��ֵĽ�㣬����ʧ�� 
		return 0;
	else if(k<T->key)
		return BST_Insert(T->lchild,k);	//���뵽������ 
	else
		return BST_Insert(T->rchild,k); 	//���뵽������ 
} 

/*
�����������Ĺ��죺
	����str[]�еĹؼ������н������������� 
*/ 
void Creat_BST(BSTree &T,int str[],int n){
	T=NULL;
	int i=0;
	while(i<n){
		BST_Insert(T,str[i]);
		i++;
	}
}

//�����������������
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
	printf("���������");
	InOrder(T); 
	int k;
	printf("\n����ֵ��"); 
	scanf("%d",&k);
	if(BSTSearch(T,k)!=NULL)
		printf("���ҳɹ�!\n");
	else
		printf("����ʧ��!\n");
	return 0;
}
