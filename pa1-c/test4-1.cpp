/*
程序设计实习MOOC / 程序设计与算法（一）第四周测验(2017冬季)  
1:角谷猜想
write by xucaimao,2017-11-28-19:10
题目很简单，就是中间运算过程会出现比较大的数，必须使用long long intå
*/

#include<cstdio>

int main(){
	long long int n;
	scanf("%lld",&n);
	while(n>1){
		long long int t=n;
		if((n%2)==1){
			n=n*3+1;
			printf("%lld*3+1=%lld\n", t,n);
		}
		else{
			n=n/2;
			printf("%lld/2=%lld\n",t,n );
		}
	}
	printf("End\n");
	return 0;
}

