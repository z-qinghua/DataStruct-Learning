#include<stdio.h>
#include<stdlib.h>

//双亲表示法（顺序存储）
//每个结点保存指向双亲的“指针” 

#define MAX_TREE_SIZE 100	//树中最多结点数
typedef struct{		//树的结点定义 
	int data;		//数据元素 
	int parent;			//双亲位置域 
}PTNode;
typedef struct{			//树的类型定义 
	PTNode nodes[MAX_TREE_SIZE];	//双亲表示
	int n;				//结点数 
}PTree;

//孩子表示法（顺序+链式存储）
//孩子表示法：顺序存储各个结点，每个结点中保存孩子链表头指针

struct CTNode{
	int child;		//孩子结点在数组中的位置
	struct CTNode *next;	//下一个孩子 
};

typedef struct{
	int data;
	struct CTNode *firstChild;	//第一个孩子 
}CTBox;

typedef struct{
	CTBox nodes[MAX_TREE_SIZE];
	int n,r;	//结点数和根的位置 
}CTree;

//孩子兄弟表示法 

typedef struct CSNode{
	int data;
	struct CSNode *firstchild,*nextsibling;	//第一个孩子和右兄弟指针 
}CSNode,*CSTree; 
