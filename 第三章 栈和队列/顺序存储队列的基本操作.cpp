/*
1.������ֻ������һ�˽��в��룬����һ��ɾ�������Ա�
2.��ͷ������ɾ����һ�ˣ���β����������һ�� 
*/

//��˳��洢ʵ��

#include<stdio.h>

#define MaxSize 10

typedef struct{
	int data[MaxSize];			//��̬����洢����Ԫ�� 
	int front,rear;				//��ͷָ��Ͷ�βָ�� 
}SqQueue;

//��ʼ��
void InitQueue(SqQueue &Q){
	Q.front=Q.rear=0;			//��ʼʱ����ͷ��βָ��ָ��0 
	int i;
	for(i=0;i<MaxSize;i++)
		Q.data[i]=0;
}

 
//�п�
bool QueueEmpty(SqQueue Q){
	if(Q.front==Q.rear)
		return true;
	else 
		return false; 
} 

//����
bool  QueueFull(SqQueue Q){
	if((Q.rear+1)%MaxSize==Q.front)
		return true;
	else
		return false;
}

//���
bool EnQueue(SqQueue &Q,int x){
	if(QueueFull(Q))
		return false;			//�������� 
	Q.data[Q.rear]=x;			//��x�����β 
	Q.rear=(Q.rear+1)%MaxSize;					//��βָ����� 
	//��ģ���㽫�洢�ռ����߼��ϱ���˻�״������������һ���洢��Ԫ 
	return true;		 
}

//����
bool DeQueue(SqQueue &Q,int &x){
	if(QueueEmpty(Q))			//�ж϶Կ� 
		return false;
	x=Q.data[Q.front];		
	Q.front=(Q.front+1)%MaxSize;	//��ͷָ����� 
	return true; 
}

//��ö�ͷԪ�ص�ֵ
bool GetHead(SqQueue Q,int &x){
	if(QueueEmpty(Q))			//�Կ��򱨴� 
		return false;
	x=Q.data[Q.front];
	return true;
} 
 
//�������Ԫ��
bool PrintQueue(SqQueue Q){
	if(QueueEmpty(Q))
		return false;
	int len=1,i=Q.front;
	while(len<=(Q.rear+MaxSize-Q.front)%MaxSize){
		printf("%d\n",Q.data[i]);
		len++;
		i=(i+1)%MaxSize;
	}
	return true;
} 

//������
int main(){
	SqQueue Q;		//����һ������
	InitQueue(Q);	//��ʼ��
	 
	EnQueue(Q,2); 	//��� 
	EnQueue(Q,5);
	
	int x=-1;
	if(DeQueue(Q,x))
		printf("����Ԫ��ֵ��%d\n",x); 
	
	PrintQueue(Q);
	return 0; 
} 
