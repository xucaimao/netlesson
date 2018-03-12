/*
程序设计实习MOOC / 程序设计与算法（一）第十周测验(2017冬季)  
4:mysort
write by xucaimao,2018-01-10 17:20,AC 2018-01-10 18:17:32
考察自己写排序函数，以及函数指针的运用
*/

#include <iostream>
using namespace std;
struct A {
	int nouse1;
	int nouse2;
	int n;
};
// 在此处补充你的代码
void mycopy(char * dest,char * source,int size){
	//拷贝size个字节
	for(int i=0;i<size;i++)
		* (dest+i)=*(source+i);
}

void mysort(void * array,int elementNum,int elementSize,int (*cmp)(const void *,const void*) ){
	//插入排序
	char * arr=(char*)array;
	char * v=new char[elementSize];
	for(int i=1;i<elementNum;i++){
		mycopy(v,arr+i*elementSize,elementSize);
		//v=arr[i];
		int j;
		for(j=i;j>=0 && cmp(arr+(j-1)*elementSize,v)>0;j--){
			mycopy(arr+j*elementSize,arr+(j-1)*elementSize,elementSize);
			//arr[j]=arr[j-1];
		}
		mycopy(arr+j*elementSize,v,elementSize);
		//arr[j]=v;
	}
	delete[] v;
}


int MyCompare1( const void * e1,const void * e2) {
	int * p1 = (int * ) e1;
	int * p2 = (int * ) e2;
	return * p1 - * p2;
}
int MyCompare2( const void * e1,const void * e2) {
	int * p1 = (int * ) e1;
	int * p2 = (int * ) e2;
	if( (* p1 %10) - (* p2 % 10))
		return (* p1 %10) - (* p2 % 10);
	else
		return * p1 - * p2;
}
int MyCompare3( const void * e1,const void * e2) {
	A * p1 = (A*) e1;
	A * p2 = (A*) e2;
	return p1->n - p2->n;
}
int a[20];
A b[20];
int main (){
	freopen("in.txt","r",stdin);	
	int n;
	while(cin >> n) {
		for(int i = 0;i < n; ++i) {
			cin >> a[i];
			b[i].n = a[i];
		}
		mysort(a,n,sizeof(int),MyCompare1);
		for(int i = 0;i < n; ++i) 
			cout << a[i] << "," ;
		cout << endl;
		mysort(a,n,sizeof(int),MyCompare2);
		for(int i = 0;i < n; ++i) 
			cout << a[i] << "," ;
		cout << endl;
		mysort(b,n,sizeof(A),MyCompare3);
		for(int i = 0;i < n; ++i) 
			cout << b[i].n << "," ;
		cout << endl;
	}
	return 0;
}