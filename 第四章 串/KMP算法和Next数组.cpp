//����ģʽƥ���㷨���Ż�

#include<stdio.h>

#define MAXLEN 255

typedef struct{
	char ch[MAXLEN+1];
	int length;
}SString;

//NEXT����
void Get_Next(SString T,int next[]){
	int i=1,j=0;
	next[1]=0;
	while(i<T.length){
		if(j==0||T.ch[i]==T.ch[j]){
			++i;
			++j;
			//��pi=pj��next[j+1]=next[j]+1
			next[i]=j; 
		}
		else
		//������j=next[j]��ѭ������ 
			j=next[j];
	}
}
/*
nextval������
�����next����
����nextval[1]=0
for(int j=2;j<=T.length;j++){
	if(T.ch[next[j]]==T.ch[j])
		nextval[j]=nextval[next[j]];
	else
		nextval[j]=next[j]; 
}

*/
//KMP�㷨 
int Index(SString S,SString T){
	int i=1,j=1;
	int next[T.length+1];
	Get_Next(T,next); 
	while(i<=S.length && j<=T.length){
		if(j==0 || S.ch[i]==T.ch[j]){
			i++;
			j++;
		}
		else{
			j=next[j];
		}
	}
	if(j>T.length)
		return i-T.length;//�˴���Ϊi������+1���ʶ�������+1 
	else
		return 0;
}
/*
KMP�㷨���Ż�
���Ӵ���ģʽ����ƥ��ʱ�� j=nextval[j];
*/

int main(){
	
	return 0;
} 
