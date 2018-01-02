/*
程序设计实习MOOC / 程序设计与算法（一）第八九周测验(2017冬季)  
7:指针练习：MyMax
write by xucaimao,2018-01-02 15:27,AC 
编写一个 MyMax函数，可以用来求任何数组中的最大值 使得程序按要求输出
三个比较函数的返回值为>0 =0 <0 三种情况
*/

#include <iostream>
using namespace std;
// 在此处补充你的代码
void* MyMax( void* arr,int sizeT,int sizeArray,int (*cmp)(void*,void*) ){
	char * ans=(char*)arr;//假设第一个数是最大的数
	for(int i=0;i<sizeArray;i++){
		char * p=(char*)arr+(i*sizeT);//p指向数组中的每一个元素
		int res=cmp( (void*)ans , (void*)p );
		if(res<0) ans=p;
	}
	return (void*)ans;
}

int Compare1(void * n1,void * n2)
{
	int * p1 = (int * )n1;
	int * p2 = (int * )n2;
	return ((*p1)%10) - ((*p2)%10);
}
int Compare2(void * n1,void * n2)
{
	int * p1 = (int * )n1;
	int * p2 = (int * )n2;
	return *p1 - *p2;
}
#define eps 1e-6
int	Compare3(void * n1,void * n2)
{
	float * p1 = (float * )n1;
	float * p2 = (float * )n2;
	if( * p1 - * p2 > eps)
		return 1;
	else if(* p2 - * p1 > eps)
		return -1;
	else
		return 0; 
}

int main()
{
	int t;
	int a[10];
	float d[10];
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 0;i < n; ++i)
			cin >> a[i];
		for(int i = 0;i < n; ++i)
			cin >> d[i];
		int * p = (int *) MyMax(a,sizeof(int),n,Compare1);
		cout << * p << endl;
		p = (int *) MyMax(a,sizeof(int),n,Compare2);
		cout << * p << endl;
		float * pd = (float * )MyMax(d,sizeof(float),n,Compare3);
		cout << * pd << endl;
	}
	return 0;
}

