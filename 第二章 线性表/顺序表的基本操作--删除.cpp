#include<stdio.h>

//用静态分配实现顺序表
#define MaxSize 10

typedef struct{
	int data[MaxSize];			//用静态数组存储元素 
	int length;					//记录顺序表当前长度 
}SqList;						//顺序表类型

//顺序表初始化
void InitList(SqList &L) {
	for(int i=0;i<MaxSize;i++)
		L.data[i]=0;			//顺序表默认值0
	L.length=0;					//顺序表初始长度0 	
}

//顺序表插入
bool ListInsert(SqList &L,int i,int e){
//	int j;
	if(i<1||i>L.length+1)
		return false;			//i范围不合法 
	if(L.length>=MaxSize)
		return false;			//顺序表满
	for(int j=L.length;j>=i;j--)	//i和i后面元素后移一位 
		L.data[j]=L.data[j-1];
	L.data[i-1]=e;
	L.length=L.length+1;			//顺序表长度+1 
	return true;
}


//顺序表删除
bool ListDelete(SqList &L,int i,int &e){
	int j;
	if(i<1||i>L.length)				//判断i的范围是否有效 
		return false;
	e=L.data[i-1];					//将被删除的元素值赋给e 
	for(j=i;j<L.length;j++)	//将第i个位置后的元素前移 
		L.data[j-1]=L.data[j]; 		
	L.length--;						//顺序表长度-1 
	return true;
} 
 
 
int main(){
	SqList L;		//声明一个顺序表
	InitList(L);	//初始化一个顺序表
	ListInsert(L,1,4);	//插入元素值 
	ListInsert(L,2,3);
	int e=-1;			//被删除的元素用e带回来
	if(ListDelete(L,1,e))	//删除元素值 
		printf("已删除第1个元素，删除元素值为%d\n",e);
	else
		printf("位序i不合法，删除失败\n");
		
	for(int i=0;i<L.length;i++)
		printf("data[%d]=%d\n",i,L.data[i]); 		
	return 0;
}
