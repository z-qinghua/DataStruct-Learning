#include<stdio.h> 

//��̬����ʵ��˳���
#define MaxSize 10

typedef struct{
	int data[MaxSize];									//�þ�̬����洢Ԫ�� 
	int length;											//��¼˳���ǰ���� 
}SqList;												//˳������� 

//��ʼ��
void InitList(SqList &L){
	for(int i=0;i<MaxSize;i++)							//˳���Ԫ��Ĭ��ֵΪ0 
		L.data[i]=0;									
	L.length=0;											//˳�����Ĭ��Ϊ0 
}

//����
bool ListInsert(SqList &L,int i,int e){
	if(i<1||i>L.length+1)								//�ж�i��Χ�Ƿ�Ϸ� 
		return false;
	if(L.length>=MaxSize)	
		return false;								//˳�������������ʧ�� 
	for(int j=L.length;j>=i;j--)					//Ԫ��i��֮��Ԫ�غ���һλ 
		L.data[j]=L.data[j-1];
	L.data[i-1]=e;
	L.length++;										//˳�����+1 
	return true; 
}


//ɾ��
bool ListDelete(SqList &L,int i,int &e){
	if(i<1||i>L.length)								//�ж�i�ķ�Χ�Ƿ���Ч 
		return false;
	e=L.data[i-1];									//����ɾ��Ԫ��ֵ����e 
	for(int j=i;j<L.length;j++)
		L.data[j-1]=L.data[j];
	L.length--;										//˳�����-1 
	return true;
}


//��λ����
int GetElem(SqList L,int i){
	if(i>=1&&i<=L.length)		
		return L.data[i-1];
	else
		return 0;
}

//��ֵ����
//��˳���L�в��ҵ�һ��Ԫ��ֵ����e��Ԫ�أ���������λ�� 
int LocateElem(SqList &L,int e){
	for(int i=0;i<L.length;i++)
		if(L.data[i]==e)
			return i+1;			//�����±�Ϊi��Ԫ��ֵ����e��������λ��i+1 
	return 0;					//�˳�ѭ����˵������ʧ�� 
}

//������ 
int main(){
	SqList L;				//����˳���L 
	InitList(L);			//��ʼ��˳���
				 
	ListInsert(L,1,1);		//����Ԫ��ֵ 
	ListInsert(L,2,2);
	ListInsert(L,3,3);
	ListInsert(L,4,5);
	
	int e=-1;
	if(ListDelete(L,2,e))				//ɾ��Ԫ��ֵ 
		printf("��ɾ����i��Ԫ�أ�ɾ��Ԫ��ֵΪ%d\n",e);
	else
		printf("λ��i���Ϸ���ɾ��ʧ��\n");
	for(int i=0;i<L.length;i++)
		printf("data[%d]=%d\n",i,L.data[i]);
		
	if(GetElem(L,2)!=0)	
		printf("��i��Ԫ��ֵΪ%d\n",GetElem(L,2));
	else
		printf("��λ��Ƿ���\n");
	
	if(LocateElem(L,3)!=0)
		printf("Ԫ��ֵi��λ��Ϊ%d\n",LocateElem(L,3));
	else 
		printf("��Ԫ��ֵ�����ڣ�\n");
		
	return 0;
}
