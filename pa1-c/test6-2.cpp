/*
程序设计实习MOOC / 程序设计与算法（一）第六周测验(2017冬季)  
2:求最大公约数问题
题目没看清楚就做题，很要命的事情
write by xucaimao,2017-12-12 13:20,AC 
*/

#include<cstdio> 

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	while(a%b !=0){
		int t=a;
		a=b;
		b=t%b;		
	}
	printf("%d\n",b);
	return 0;
}