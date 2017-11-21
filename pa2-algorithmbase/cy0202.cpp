/*
程序设计与算法（二）第二周测验 2:2的幂次方表示 POJ
write by xucaimao,20171121

*/
#include<cstdio>

void solve(int n){
	if(n==1){printf("2(0)" );return;}
	else if(n==2){printf("2" );return;}
	else{
		int zs=0,yu=0;//指数余数
		int t=1;
		while(t*2<=n){
			t*=2;zs++;
		}
		yu=n-t;
		if(zs>1){
			printf("2(");
			solve(zs);
			printf(")");
		}
		else printf("2");
		
		if(yu>0){
			printf("+");
			solve(yu);
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	solve(n);
	printf("\n");
	return 0;
}