/*
程序设计实习MOOC / 程序设计与算法（一）第六周测验(2017冬季)  
3:编程填空：第i位替换
位运算
write by xucaimao,2017-12-12 13:30,AC 
*/

#include <iostream>
using namespace std;

int bitManipulation1(int n, int m, int i) {
// 在此处补充你的代码
	int t=1<<i;
	m=m&t;
	n=n&(~t);
	n=n^m;
	return n;
}

int main() {
	int n, m, i, t;
	cin >> t;
	while (t--) { 
		cin >> n >> m >> i;
		cout << bitManipulation1(n, m, i) << endl;
	}
	return 0;
}