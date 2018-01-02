/*
程序设计实习MOOC / 程序设计与算法（一）第八九周测验(2017冬季)  
1:指针练习：输出Hello
write by xucaimao,2018-01-02 13:50,AC 
*/

#include <iostream>
using namespace std;
int main() {
	char s[] = "Hello";  
	char * p;
	for(p=s;*p!='\0';p++)
		cout << * p ;
	return 0;
}