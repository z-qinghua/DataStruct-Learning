#include<stdio.h>

//�þ�̬���䷽ʽʵ��˳���
#define MaxSize 10			//������󳤶� 

typedef struct{
	int data[MaxSize];		//��̬����������Ԫ��
	int length;				//˳���ǰ����
}SqList;					//˳������Ͷ���


//��������--��ʼ��һ��˳���
void InitList(SqList &L){
	int i;
	for(i=0;i<MaxSize;i++)
		L.data[i]=0;		//��������Ԫ�س�ʼ��
	L.length=0;				//˳�����Գ���0 
} 

//�������
//�õ��㷨Ӧ�þ��С���׳�ԡ� ���ܴ����쳣��� 
bool ListInsert(SqList &L,int i,int e){
	int j; 
	if(i<1||i>L.length+1)			//�ж�i�ķ�Χ�Ƿ���Ч 
		return false;
	if(L.length>=MaxSize)			//��ǰ�洢�ռ����������ܲ���
		return false; 
	for(j=L.length;j>=i;j--)		//����i��Ԫ�ؼ�֮��Ԫ�غ���
		L.data[j]=L.data[j-1];
	L.data[i-1]=e;						//��λ��i������e
	L.length=L.length+1;				//����+1 
	return true;
}

int main(){
	SqList L;						//����һ��˳���
	InitList(L);					//��ʼ��˳���
	ListInsert(L,1,3);				//���뼸��Ԫ�� 
	
	for(int i=0;i<L.length;i++)
		printf("data[%d]=%d\n",i,L.data[i]); 
	return 0;
} 
