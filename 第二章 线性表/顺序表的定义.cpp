#include<stdio.h>



////˳���Ķ��� 
//typedef struct{
//	int num;	//���� 
//	int people; //���� 
//} Customer; 


//˳����ʵ��--��̬����
#define MaxSize 10		//������󳤶� 
typedef struct{
	int data[MaxSize];			//�þ�̬�����顱�������Ԫ��
	int length; 				//˳���ǰ���� 
}SqList; 						//˳������Ͷ���

//��������--��ʼ��һ��˳���
void InitList(SqList &L){
	int i;
	for(i=0;i<MaxSize;i++)
		L.data[i]=0;		//��������Ԫ�س�ʼ��
	L.length=0;				//˳�����Գ���0 
} 



int main(){
	SqList L;					//����һ��˳���
	InitList(L); 				//��ʼ��˳���
	//....δ�����
	int i;
	for(i=0;i<L.length;i++)
		printf("data[%d]=%d\n",i,L.data[i]); 
	return 0; 
	 
}


