/*
程序设计实习MOOC / 程序设计与算法（一）第八九周测验(2017冬季)  
6:指针练习：Memcpy之二
write by xucaimao,2018-01-02 14:40,AC 
*/

#include <iostream>
using namespace std;
void Memcpy( void * src, void * dest, int size)
{
	char * s=(char*)src;
	char temp[40];
	char * t=temp;
	for(int i=0;i<size;i++)
		*t++=*s++;
	t=temp;
	char * d=(char*)dest;
	for(int i=0;i<size;i++)
		*d++=*t++;
}

void Print(int * p,int size)
{
	for(int i = 0;i < size; ++i)
		cout << p[i] << ",";
	cout << endl;
}

int main()
{
	int a[10];
	int n;
	cin >> n;
	for(int i = 0;i < n; ++i)
		cin >> a[i];
	int b[10] = {0};
	Memcpy(a,b,sizeof(a));
	Print(b,n);
	
	int c[10] = {1,2,3,4,5,6,7,8,9,10};
	Memcpy(c,c+5,5*sizeof(int)); //将c的前一半拷贝到后一半 
	Print(c,10);

	char s[10] = "123456789";
	Memcpy(s+2,s+4,5); //将s[2]开始的5个字符拷贝到s[4]开始的地方 
	cout << s << endl;
	
	char s1[10] = "123456789";
	Memcpy(s1+5,s1+1,4); //将s1[5]开始的4个字符拷贝到s1[1]开始的地方 
	cout << s1 << endl;
	
	
	return 0;
}