/*
程序设计实习MOOC / 程序设计与算法（一）第三周测验(2017冬季)  
9:乘方计算

*/

#include<cstdio>

int main(){
	int n,a;
	scanf("%d%d",&a,&n);
	int ans=1;
	while(n--){
		ans*=a;
	}
	printf("%d\n",ans );	
	return 0;
}

