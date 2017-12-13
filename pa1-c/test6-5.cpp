/*
程序设计实习MOOC / 程序设计与算法（一）第六周测验(2017冬季)  
5:编程填空：左边i位取反
位运算
write by xucaimao,2017-12-12 13:30,AC 
*/

#include <iostream>
using namespace std;

int bitManipulation3(int n, int i) {
// 在此处补充你的代码
	for(int j=1;j<=i;j++){
		n^=(1<<(32-j));
	}
	return n;
}

int main() {
	freopen("test6-5.in","r",stdin);
	int t, n, i;
	cin >> t;
	while (t--) {
		cin >> n >> i;
		cout << bitManipulation3(n, i) << endl;
	}
	return 0;
}