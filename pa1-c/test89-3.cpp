/*
程序设计实习MOOC / 程序设计与算法（一）第八九周测验(2017冬季)  
3:指针练习：ForEach
write by xucaimao,2018-01-02 13:50,AC 
函数指针(*f)函数名加上*,外面再套上括号
*/

#include <iostream>
using namespace std;

void ForEach(void * a, int width, int num, void (*f)(void *))

{
	for(int i = 0;i < num; ++i) 
		f((char*)a+width*i);
}

void PrintSquare(void * p)
{
	int * q = (int*)p;
	int n = *q;
	cout << n * n << ",";
}
void PrintChar(void * p) {
	char * q = (char*)p;
	cout << *q << ",";
}
int main()
{
	int a[5] = {1,2,3,4,5};
	char s[] = "hello!";
	ForEach(a,sizeof(int),5,PrintSquare); 
	cout << endl;
	ForEach(s,sizeof(char),6,PrintChar);
	return 0;
}