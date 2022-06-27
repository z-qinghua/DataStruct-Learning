#include<stdio.h> 

//静态分配实现顺序表
#define MaxSize 10

typedef struct{
	int data[MaxSize];									//用静态数组存储元素 
	int length;											//记录顺序表当前长度 
}SqList;												//顺序表类型 

//初始化
void InitList(SqList &L){
	for(int i=0;i<MaxSize;i++)							//顺序表元素默认值为0 
		L.data[i]=0;									
	L.length=0;											//顺序表长度默认为0 
}

//插入
bool ListInsert(SqList &L,int i,int e){
	if(i<1||i>L.length+1)								//判断i范围是否合法 
		return false;
	if(L.length>=MaxSize)	
		return false;								//顺序表已满，插入失败 
	for(int j=L.length;j>=i;j--)					//元素i及之后元素后移一位 
		L.data[j]=L.data[j-1];
	L.data[i-1]=e;
	L.length++;										//顺序表长度+1 
	return true; 
}


//删除
bool ListDelete(SqList &L,int i,int &e){
	if(i<1||i>L.length)								//判断i的范围是否有效 
		return false;
	e=L.data[i-1];									//将被删除元素值赋给e 
	for(int j=i;j<L.length;j++)
		L.data[j-1]=L.data[j];
	L.length--;										//顺序表长度-1 
	return true;
}


//按位查找
int GetElem(SqList L,int i){
	if(i>=1&&i<=L.length)		
		return L.data[i-1];
	else
		return 0;
}

//按值查找
//在顺序表L中查找第一个元素值等于e的元素，并返回其位序 
int LocateElem(SqList &L,int e){
	for(int i=0;i<L.length;i++)
		if(L.data[i]==e)
			return i+1;			//数组下标为i的元素值等于e，返回其位序i+1 
	return 0;					//退出循环，说明查找失败 
}

//主函数 
int main(){
	SqList L;				//声明顺序表L 
	InitList(L);			//初始化顺序表
				 
	ListInsert(L,1,1);		//插入元素值 
	ListInsert(L,2,2);
	ListInsert(L,3,3);
	ListInsert(L,4,5);
	
	int e=-1;
	if(ListDelete(L,2,e))				//删除元素值 
		printf("已删除第i个元素，删除元素值为%d\n",e);
	else
		printf("位序i不合法，删除失败\n");
	for(int i=0;i<L.length;i++)
		printf("data[%d]=%d\n",i,L.data[i]);
		
	if(GetElem(L,2)!=0)	
		printf("第i个元素值为%d\n",GetElem(L,2));
	else
		printf("该位序非法！\n");
	
	if(LocateElem(L,3)!=0)
		printf("元素值i的位序为%d\n",LocateElem(L,3));
	else 
		printf("该元素值不存在！\n");
		
	return 0;
}
