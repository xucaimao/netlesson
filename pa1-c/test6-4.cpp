/*
程序设计实习MOOC / 程序设计与算法（一）第六周测验(2017冬季)  
4:编程填空：第i位取反
位运算
write by xucaimao,2017-12-12 13:30,AC 
*/

#include <iostream>
using namespace std;

int bitManipulation2(int n, int i) {
// 在此处补充你的代码
	return n^=(1<<i);
}

int main() {
	int t, n, i;
	cin >> t;
	while (t--) {
		cin >> n >> i;
		cout << bitManipulation2(n, i) << endl;
	}
	return 0;
}