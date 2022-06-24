#include<stdio.h>



////顺序表的定义 
//typedef struct{
//	int num;	//号数 
//	int people; //人数 
//} Customer; 


//顺序表的实现--静态分配
#define MaxSize 10		//定义最大长度 
typedef struct{
	int data[MaxSize];			//用静态“数组”存放数据元素
	int length; 				//顺序表当前长度 
}SqList; 						//顺序表类型定义

//基本操作--初始化一个顺序表
void InitList(SqList &L){
	int i;
	for(i=0;i<MaxSize;i++)
		L.data[i]=0;		//所有数据元素初始化
	L.length=0;				//顺序表初试长度0 
} 



int main(){
	SqList L;					//声明一个顺序表
	InitList(L); 				//初始化顺序表
	//....未完待续
	int i;
	for(i=0;i<L.length;i++)
		printf("data[%d]=%d\n",i,L.data[i]); 
	return 0; 
	 
}


