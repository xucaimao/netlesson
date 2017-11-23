/*
《算法基础与在线实践》练习题4-2 最大公约数 POJ3248
write by xucaimao,20171122 18:00测试通过
*/
#include<cstdio>

int gcd(int m,int n){
	//辗转相除法
	if(n>m){int t=m;m=n;n=t;}
	int r;
	do{
		r=m%n;
		m=n;
		n=r;
	}while(r);
	return m;
}

int gcd2(int m,int n){
	//递归法
	int r=m%n;
	if(r ==0)return n;
	else return gcd2(n,r);
}

int main(){
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
		printf("%d\n",gcd2(m,n));
	return 0;
}