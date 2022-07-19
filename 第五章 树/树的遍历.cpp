#include<stdio.h>

//树的先根遍历
//先根遍历。若树非空，先访问根结点，再依次对每棵子树进行先根遍历
void PreOrder(Treenode *R){
	if(R!=NULL){
		visit(R);//访问根结点
		while(R还有下一个子树T)
			PreOrder(T);//先根遍历下一棵子树 
	}
}
//树的先根遍历序列与这棵树相应二叉树的先序序列相同

//树的后根遍历
/*
后根遍历：若树非空，先依次对每棵子树进行后根遍历，最后再访问根结点  
*/
void PostOrder(TreeNode *R){
	if(R!=NULL){
		while(R还有下一棵子树T)
			PostOrder(T);	//后根遍历下一棵子树 
		visit(R);	//访问根结点 
	}
} 
