#include<stdio.h>

//�þ�̬����ʵ��˳���
#define MaxSize 10

typedef struct{
	int data[MaxSize];			//�þ�̬����洢Ԫ�� 
	int length;					//��¼˳���ǰ���� 
}SqList;						//˳�������

//˳����ʼ��
void InitList(SqList &L) {
	for(int i=0;i<MaxSize;i++)
		L.data[i]=0;			//˳���Ĭ��ֵ0
	L.length=0;					//˳����ʼ����0 	
}

//˳������
bool ListInsert(SqList &L,int i,int e){
//	int j;
	if(i<1||i>L.length+1)
		return false;			//i��Χ���Ϸ� 
	if(L.length>=MaxSize)
		return false;			//˳�����
	for(int j=L.length;j>=i;j--)	//i��i����Ԫ�غ���һλ 
		L.data[j]=L.data[j-1];
	L.data[i-1]=e;
	L.length=L.length+1;			//˳�����+1 
	return true;
}


//˳���ɾ��
bool ListDelete(SqList &L,int i,int &e){
	int j;
	if(i<1||i>L.length)				//�ж�i�ķ�Χ�Ƿ���Ч 
		return false;
	e=L.data[i-1];					//����ɾ����Ԫ��ֵ����e 
	for(j=i;j<L.length;j++)	//����i��λ�ú��Ԫ��ǰ�� 
		L.data[j-1]=L.data[j]; 		
	L.length--;						//˳�����-1 
	return true;
} 
 
 
int main(){
	SqList L;		//����һ��˳���
	InitList(L);	//��ʼ��һ��˳���
	ListInsert(L,1,4);	//����Ԫ��ֵ 
	ListInsert(L,2,3);
	int e=-1;			//��ɾ����Ԫ����e������
	if(ListDelete(L,1,e))	//ɾ��Ԫ��ֵ 
		printf("��ɾ����1��Ԫ�أ�ɾ��Ԫ��ֵΪ%d\n",e);
	else
		printf("λ��i���Ϸ���ɾ��ʧ��\n");
		
	for(int i=0;i<L.length;i++)
		printf("data[%d]=%d\n",i,L.data[i]); 		
	return 0;
}
