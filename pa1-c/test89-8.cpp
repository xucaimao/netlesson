/*
程序设计实习MOOC / 程序设计与算法（一）第八九周测验(2017冬季)  
8:指针练习：指向指针的指针
write by xucaimao,2018-01-02 15:27,AC 
*/

#include <iostream>
using namespace std;
int main()
{
	int x,y,z;
	x = 10;
	y = 20;
	z = 30;
	
	int * a[3]  = { &x, &y,&z};
	for(int ** p=a;
// 在此处补充你的代码
p < a + 3; ++p) 
			cout<< * (*p) << endl;
	return 0;
	
}