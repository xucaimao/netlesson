/*
程序设计实习MOOC / 程序设计与算法（一）第八九周测验(2017冬季)  
2:指针练习:输出Tesla
write by xucaimao,2018-01-02 13:50,AC 
*/

#include <iostream>
using namespace std;
void Print(const char * p1, const char * p2) 
{  
	for(;p1<p2;p1++) 	
		cout << * p1;
}
int main()  
{
	const char * s = "Tesla123";
	Print(s,s+5);
	cout << endl;
	Print(s,s+3);
	cout << endl;
	
	return 0;
}