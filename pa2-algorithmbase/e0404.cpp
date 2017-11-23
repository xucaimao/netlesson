/*
《算法基础与在线实践》练习题4-4 逆波兰表达式 POJ2694
write by xucaimao,20171122 20:40开始编程，20:53测试通过
*/
#include<cstdio>
#include <cstdlib>
using namespace std;
const int maxn=10000;
char s[maxn];

double exp(){
	scanf("%s",s);
	switch(s[0]){
		case '*':
			return exp()*exp();
		case '+':
			return exp()+exp();
		case '-':
			return exp()-exp();
		case '/':
			return exp()/exp();
		default:
			return atof(s);
	}
}

int main(){
	freopen("e0404.in","r",stdin);
	printf("%f\n",exp());
	return 0;
}