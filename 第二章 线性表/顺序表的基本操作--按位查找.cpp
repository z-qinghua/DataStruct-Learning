#include<stdio.h>

//��̬����ʵ��˳��� 
#define MaxSize 10

typedef struct{
	int data[MaxSize];				//�þ�̬����洢Ԫ�� 
	int length;						//��¼˳���ǰ���� 
}SqList;							//˳������� 

//��ʼ��˳���
void InitList(SqList &L){
	for(int i=0;i<MaxSize;i++)
		L.data[i]=0;				//˳���Ĭ��ֵΪ0 
	L.length=0; 					//˳���Ĭ��ֵΪ0 
}

//����
bool ListInsert(SqList &L,int i,int e){
	if(i<1||i>L.length+1)			//�ж�i��Χ�Ƿ�Ϸ� 
		return false;
	if(L.length>=MaxSize)			//˳������������ܲ��� 
		return false;
	for(int j=L.length;j>=i;j--)	//i��i�����Ԫ�غ���һλ 
		L.data[j]=L.data[j-1];
	L.data[i-1]=e;				
	L.length++;						//˳�����+1 
	return true;
}

//ɾ��
bool ListDelete(SqList &L,int i,int &e){
	if(i<1||i>L.length)					//�ж�i�ķ�Χ�Ƿ���Ч 
		return false;
	e=L.data[i-1];						//����ɾ����ֵ����e 
	for(int j=i;j<L.length;j++)			//i��i�����Ԫ��ǰ��һλ 
		L.data[j-1]=L.data[j];
	L.length--;							//˳�����-1 
	return true;
} 

//˳���λ����
int GetElem(SqList L,int i){
	return L.data[i-1];
} 
 

int main(){
	SqList L;							//����˳��� 
	InitList(L);						//��ʼ��˳��� 
	ListInsert(L,1,3);					//����Ԫ��ֵ 
	ListInsert(L,2,5);
	ListInsert(L,3,6);
	int e=-1;							//��ɾ����Ԫ��ֵ��e������ 
	if(ListDelete(L,1,e))				//ɾ��Ԫ��ֵ 
		printf("��ɾ����i��Ԫ�أ�ɾ��Ԫ��ֵΪ%d\n",e);
	else
		printf("λ��i���Ϸ���ɾ��ʧ��\n");
	for(int i=0;i<L.length;i++)
		printf("data[%d]=%d\n",i,L.data[i]);
	printf("��2��Ԫ��ֵΪ%d\n",GetElem(L,2));
	return 0;
	
}
