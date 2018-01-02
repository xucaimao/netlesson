/*
程序设计实习MOOC / 程序设计与算法（一）第八九周测验(2017冬季)  
9:指针练习：SwapMemory
write by xucaimao,2018-01-02 16:15,AC 
*/

#include <iostream>
using namespace std;
void SwapMemory(void * m1,void * m2, int size)
{
// 在此处补充你的代码
	char temp;
	char* s=(char*)m1;
	char* t=(char*)m2;
	for(int i=0;i<size;i++){
		temp=*s;
		*s=*t;
		*t=temp;
		s++;t++;
	}
}

void PrintIntArray(int * a,int n)
{
	for(int i = 0;i < n; ++i)
		cout << a[i] << ",";
	cout << endl;
}

int main()
{
	int a[5] = {1,2,3,4,5};
	int b[5] = {10,20,30,40,50};
	SwapMemory(a,b,5 * sizeof(int));
	PrintIntArray(a,5);
	PrintIntArray(b,5);
	char s1[] = "12345";
	char s2[] = "abcde";
	SwapMemory(s1,s2,5);
	cout << s1 << endl;
	cout << s2 << endl;
	return 0;
}