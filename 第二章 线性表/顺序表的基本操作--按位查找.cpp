#include<stdio.h>

//静态分配实现顺序表 
#define MaxSize 10

typedef struct{
	int data[MaxSize];				//用静态数组存储元素 
	int length;						//记录顺序表当前长度 
}SqList;							//顺序表类型 

//初始化顺序表
void InitList(SqList &L){
	for(int i=0;i<MaxSize;i++)
		L.data[i]=0;				//顺序表默认值为0 
	L.length=0; 					//顺序表默认值为0 
}

//插入
bool ListInsert(SqList &L,int i,int e){
	if(i<1||i>L.length+1)			//判断i范围是否合法 
		return false;
	if(L.length>=MaxSize)			//顺序表已满，不能插入 
		return false;
	for(int j=L.length;j>=i;j--)	//i及i后面的元素后移一位 
		L.data[j]=L.data[j-1];
	L.data[i-1]=e;				
	L.length++;						//顺序表长度+1 
	return true;
}

//删除
bool ListDelete(SqList &L,int i,int &e){
	if(i<1||i>L.length)					//判断i的范围是否有效 
		return false;
	e=L.data[i-1];						//将被删除的值赋给e 
	for(int j=i;j<L.length;j++)			//i及i后面的元素前移一位 
		L.data[j-1]=L.data[j];
	L.length--;							//顺序表长度-1 
	return true;
} 

//顺序表按位查找
int GetElem(SqList L,int i){
	return L.data[i-1];
} 
 

int main(){
	SqList L;							//声明顺序表 
	InitList(L);						//初始化顺序表 
	ListInsert(L,1,3);					//插入元素值 
	ListInsert(L,2,5);
	ListInsert(L,3,6);
	int e=-1;							//被删除的元素值用e带回来 
	if(ListDelete(L,1,e))				//删除元素值 
		printf("已删除第i个元素，删除元素值为%d\n",e);
	else
		printf("位序i不合法，删除失败\n");
	for(int i=0;i<L.length;i++)
		printf("data[%d]=%d\n",i,L.data[i]);
	printf("第2个元素值为%d\n",GetElem(L,2));
	return 0;
	
}
