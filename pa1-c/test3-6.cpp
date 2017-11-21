/*
程序设计实习MOOC / 程序设计与算法（一）第三周测验(2017冬季)  
6:求整数的和与均值

*/

#include<cstdio>

int main(){
	int x,n;
	long long int sum=0;
	scanf("%d",&n);
	int t=n;
	while(t--){
		scanf("%d",&x);
		sum+=x;
	}
	printf("%lld %.5lf\n",sum,sum*1.0/n );	
	return 0;
}

