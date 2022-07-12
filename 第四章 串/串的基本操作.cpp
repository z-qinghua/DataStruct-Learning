//�������ݶ����޶�Ϊ�ַ��������Ļ�������������ɾ�Ĳ��ͨ�����ִ�Ϊ��������
 
#include<stdio.h>

#define MAXLEN 255		//Ԥ������󴮳�255

//��̬����ʵ�֣�����˳��洢�� 
typedef struct{
	char ch[MAXLEN+1];		//ÿ�������洢һ���ַ�
	int length;	 			//����ʵ�ʳ��� 
}SString;					
/*
StrAssign(&T,chars[]):��ֵ�������Ѵ�T��ֵΪchars
StrCopy(&T,S):���Ʋ������ɴ�S���Ƶõ���T
StEmpty(S):�пղ�������SΪ�մ����򷵻�TRUE�����򷵻�false
StrLength(S):�󴮳������ش�S��Ԫ�ظ���
ClearString(&S):��ղ�������S��Ϊ�մ�
DestroyString(&S):���ٴ������մ洢�ռ䣩
Concat(&T,S1,S2):�����ӡ���T������S1��S2���Ӷ��ɵ��´� 
*/

//��̬����洢���ѷ���洢�� 
/*
typedef struct{
	char *ch;				//����������洢����chָ�򴮵Ļ���ַ
	int length;				// ���ĳ��� 
}HString;
HString S;
S.ch=(char *)malloc(MAXLEN*sizeof(char));
S.length=0;
*/

/*
������ʽ�洢
typedef struct StringNode{
	char ch;			//ÿ���ڵ��һ���ַ�
	struct StringNode *next; 
}StringNode,*String;

typedef struct StringNode{
	char ch[4];			//ÿ���ڵ�����ַ�
	struct StringNode *next;
}StringNode,*String;
typedef struct{
StringNode *head,*tail;	//ͷβָ�� 
int length;
}LString;
*/

//���ɴ�
int StrAssign(SString &T,char chars[]){
	int i=0;
	while(chars[i]!='\0'){
		T.ch[i]=chars[i];//���ַ�������ֵ����S
		i++; 
	}
	T.length=i;//��iֵ����T
	return 0; 
} 

//���ƴ�
void StrCopy(SString &T,SString S){
	int i=0;
	for(i=0;i<S.length;i++){
		T.ch[i]=S.ch[i];
	}
	T.length=S.length;//���Ƴ��� 
} 

//�п�
bool StrEmpty(SString S){
	if(S.length==0)
		return true;
	else
		return false;
}

//���Ӵ�
int ConcatString(SString &T,SString S1,SString S2){//��T������S1��S2���Ӷ��ɵ��´� 
	int i,j;
	for(i=0;i<S1.length;i++){		//���Ƚ�S1���Ƶ���T 
		T.ch[i]=S1.ch[i];
	}
	T.length=S1.length;
	for(j=0;j<S2.length;j++){//�ٴ�ѭ������S2���Ƶ���T 
		T.ch[T.length]=S2.ch[j];
		T.length++;
	}
	return 0;
}


//���Ӵ�����sub���ش�S�� ��pos���ַ��𳤶�Ϊlen���Ӵ��� 
bool SubString(SString &Sub,SString S,int pos,int len){
	//�Ӵ���ΧԽ��
	if(pos+len-1>S.length)
		return false;
	for(int i=pos;i<pos+len;i++){
		Sub.ch[i-pos+1]=S.ch[i];
	}
	Sub.length=len;
	return true; 
} 

//�ڴ�T��pos���ַ�֮ǰ���봮S
bool StrInsert(SString &T,int pos,SString S){
	if(pos<1||pos>T.length){
		printf("��������\n");
		return false; 
	}
	for(int i=(T.length-1);i>=pos-1;i--){	//ѭ������T�ӵ�poss���ַ�����������ַ�������S.leng��λ�� 
		T.ch[i+S.length]=S.ch[i];
	}
	int j=0;
	int k=pos-1;
	for(j=0;j<S.length;j++){//ѭ��������S���β��뵽T�ƶ���ճ�����λ��
		T.ch[k]=S.ch[j]; 
		k++;
	}
	T.length+=S.length; 
	return true;	
} 

//�Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ�
bool StrDelete(SString &S,int pos,int len){
	if(pos<1 || pos>(S.length-len+1)){
		printf("��������!\n");
		return false;
	}
	for(int i=pos+len;i<=S.length;i++){
		S.ch[i-len-1]=S.ch[i-1];
	}	
	S.length-=len;//���³��� 
	return true;
} 

//�Ƚϲ���
int StrCompare(SString S,SString T){
	for(int i;i<=S.length && i<=T.length;i++){
		if(S.ch[i]!=T.ch[i])
			return S.ch[i]-T.ch[i];
	}
	//ɨ����������ַ�����ͬ�����򳤶ȳ��Ĵ�����
	 return S.length-T.length;
} 

//�󴮳�
int StrLength(SString S){
	return S.length;
} 
 

//��λ����
int Index(SString S,SString T){
	int i=1,n=StrLength(S),m=StrLength(T);
	SString sub;	//�����ݴ��Ӵ�
	while(i<=n-m+1){
		SubString(sub,S,i,m);
		if(StrCompare(sub,T)!=0)
			++i;
		else
			return i;		//�����Ӵ��������е�λ�� 
	}
	return 0;		//S�в�������T��ȵ��Ӵ� 
} 

//��մ�
void ClearString(SString &S){
	for(int i=0;i<S.length;i++){
		S.ch[i]=0;
	}
	S.length=0;
	printf("������ɣ�\n"); 
} 

//��������ӡ��
int ShowString(SString S){
	if(S.length==0){
		printf("��ǰ��Ϊ�գ�");
		return 0;
	}
	for(int i=0;i<S.length;i++){
		printf("%c",S.ch[i]);
	}
	printf("\0");
	return 0;
} 

 

int main(){
	SString S;//����һ����
//	ClearString(S);
	char chars[]="zengqinghua";
	int i=0;
	while(chars[i]!='\0'){
		printf("%c",chars[i]);
		++i;	
	}
	
	StrAssign(S,chars); 
	ShowString(S);
	return 0;
} 
