//串的数据对象限定为字符集，串的基本操作，如增删改查等通常以字串为操作对象
 
#include<stdio.h>

#define MAXLEN 255		//预定义最大串长255

//静态数组实现（定长顺序存储） 
typedef struct{
	char ch[MAXLEN+1];		//每个分量存储一个字符
	int length;	 			//串的实际长度 
}SString;					
/*
StrAssign(&T,chars[]):赋值操作。把串T赋值为chars
StrCopy(&T,S):复制操作。由串S复制得到串T
StEmpty(S):判空操作。若S为空串，则返回TRUE，否则返回false
StrLength(S):求串长。返回串S的元素个数
ClearString(&S):清空操作。将S清为空串
DestroyString(&S):销毁串（回收存储空间）
Concat(&T,S1,S2):串联接。用T返回由S1和S2联接而成的新串 
*/

//动态数组存储（堆分配存储） 
/*
typedef struct{
	char *ch;				//按串长分配存储区，ch指向串的基地址
	int length;				// 串的长度 
}HString;
HString S;
S.ch=(char *)malloc(MAXLEN*sizeof(char));
S.length=0;
*/

/*
串的链式存储
typedef struct StringNode{
	char ch;			//每个节点存一个字符
	struct StringNode *next; 
}StringNode,*String;

typedef struct StringNode{
	char ch[4];			//每个节点存多个字符
	struct StringNode *next;
}StringNode,*String;
typedef struct{
StringNode *head,*tail;	//头尾指针 
int length;
}LString;
*/

//生成串
int StrAssign(SString &T,char chars[]){
	int i=0;
	while(chars[i]!='\0'){
		T.ch[i]=chars[i];//将字符常量的值赋给S
		i++; 
	}
	T.length=i;//将i值赋给T
	return 0; 
} 

//复制串
void StrCopy(SString &T,SString S){
	int i=0;
	for(i=0;i<S.length;i++){
		T.ch[i]=S.ch[i];
	}
	T.length=S.length;//复制长度 
} 

//判空
bool StrEmpty(SString S){
	if(S.length==0)
		return true;
	else
		return false;
}

//联接串
int ConcatString(SString &T,SString S1,SString S2){//用T返回由S1和S2连接而成的新串 
	int i,j;
	for(i=0;i<S1.length;i++){		//首先将S1复制到串T 
		T.ch[i]=S1.ch[i];
	}
	T.length=S1.length;
	for(j=0;j<S2.length;j++){//再次循环，将S2复制到串T 
		T.ch[T.length]=S2.ch[j];
		T.length++;
	}
	return 0;
}


//求子串（用sub返回串S的 第pos个字符起长度为len的子串） 
bool SubString(SString &Sub,SString S,int pos,int len){
	//子串范围越界
	if(pos+len-1>S.length)
		return false;
	for(int i=pos;i<pos+len;i++){
		Sub.ch[i-pos+1]=S.ch[i];
	}
	Sub.length=len;
	return true; 
} 

//在串T第pos个字符之前插入串S
bool StrInsert(SString &T,int pos,SString S){
	if(pos<1||pos>T.length){
		printf("输入有误！\n");
		return false; 
	}
	for(int i=(T.length-1);i>=pos-1;i--){	//循环，将T从第poss个字符往后的所有字符都后移S.leng个位置 
		T.ch[i+S.length]=S.ch[i];
	}
	int j=0;
	int k=pos-1;
	for(j=0;j<S.length;j++){//循环，将串S依次插入到T移动后空出来的位置
		T.ch[k]=S.ch[j]; 
		k++;
	}
	T.length+=S.length; 
	return true;	
} 

//从串S中删除第pos个字符起长度为len的子串
bool StrDelete(SString &S,int pos,int len){
	if(pos<1 || pos>(S.length-len+1)){
		printf("输入有误!\n");
		return false;
	}
	for(int i=pos+len;i<=S.length;i++){
		S.ch[i-len-1]=S.ch[i-1];
	}	
	S.length-=len;//更新长度 
	return true;
} 

//比较操作
int StrCompare(SString S,SString T){
	for(int i;i<=S.length && i<=T.length;i++){
		if(S.ch[i]!=T.ch[i])
			return S.ch[i]-T.ch[i];
	}
	//扫描过的所有字符都相同，，则长度长的串更大
	 return S.length-T.length;
} 

//求串长
int StrLength(SString S){
	return S.length;
} 
 

//定位操作
int Index(SString S,SString T){
	int i=1,n=StrLength(S),m=StrLength(T);
	SString sub;	//用于暂存子串
	while(i<=n-m+1){
		SubString(sub,S,i,m);
		if(StrCompare(sub,T)!=0)
			++i;
		else
			return i;		//返回子串在主串中的位置 
	}
	return 0;		//S中不存在与T相等的子串 
} 

//清空串
void ClearString(SString &S){
	for(int i=0;i<S.length;i++){
		S.ch[i]=0;
	}
	S.length=0;
	printf("清理完成！\n"); 
} 

//遍历并打印串
int ShowString(SString S){
	if(S.length==0){
		printf("当前串为空！");
		return 0;
	}
	for(int i=0;i<S.length;i++){
		printf("%c",S.ch[i]);
	}
	printf("\0");
	return 0;
} 

 

int main(){
	SString S;//定义一个串
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
