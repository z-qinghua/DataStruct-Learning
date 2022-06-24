#include<stdio.h>

//用静态分配方式实现顺序表
#define MaxSize 10			//定义最大长度 

typedef struct{
	int data[MaxSize];		//静态数组存放数据元素
	int length;				//顺序表当前长度
}SqList;					//顺序表类型定义


//基本操作--初始化一个顺序表
void InitList(SqList &L){
	int i;
	for(i=0;i<MaxSize;i++)
		L.data[i]=0;		//所有数据元素初始化
	L.length=0;				//顺序表初试长度0 
} 

//插入操作
//好的算法应该具有“健壮性” ，能处理异常情况 
bool ListInsert(SqList &L,int i,int e){
	int j; 
	if(i<1||i>L.length+1)			//判断i的范围是否有效 
		return false;
	if(L.length>=MaxSize)			//当前存储空间已满，不能插入
		return false; 
	for(j=L.length;j>=i;j--)		//将第i个元素及之后元素后移
		L.data[j]=L.data[j-1];
	L.data[i-1]=e;						//在位置i处放入e
	L.length=L.length+1;				//长度+1 
	return true;
}

int main(){
	SqList L;						//声明一个顺序表
	InitList(L);					//初始化顺序表
	ListInsert(L,1,3);				//插入几个元素 
	
	for(int i=0;i<L.length;i++)
		printf("data[%d]=%d\n",i,L.data[i]); 
	return 0;
} 
