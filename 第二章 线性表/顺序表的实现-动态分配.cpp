#include<stdio.h>
#include<stdlib.h> 

#define InitSize 10		//˳���ĳ�ʼ����
typedef struct{
	int *data;			//ָʾ��̬���������ָ�� 
	int MaxSize;		//˳�����������
	int length;		//˳���ĵ�ǰ���� 
}SqList;				//˳�������Ͷ��壨��̬���䣩

//��ʼ��˳���
void InitList(SqList &L){
	L.data=(int *)malloc(InitSize*sizeof(int));
	L.length=0;
	L.MaxSize=InitSize;
}

 //���Ӷ�̬����ĳ���
 void IncreaseSize(SqList &L,int len){
 	int *p=L.data;
 	L.data=(int *)malloc((L.MaxSize+len)*sizeof(int));
 	for(int i=0;i<L.length;i++)
 		L.data[i]=p[i];		//�����ݸ��Ƶ�������
	
	L.MaxSize=L.MaxSize+len;//˳�����󳤶�����len 
	free(p); 				//�ͷ�ԭ�����ڴ�ռ� 
 } 
 
 int main(){
 	SqList L;				//����һ��˳���
	InitList(L);			//��ʼ��һ��˳���

	IncreaseSize(L,5); 		//��˳�����뼸��Ԫ��
	return 0; 
 } 
