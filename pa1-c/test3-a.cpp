/*
程序设计实习MOOC / 程序设计与算法（一）第三周测验(2017冬季)  
A:鸡尾酒疗法

*/

#include<cstdio>

int main(){
	freopen("in.txt","r",stdin);
	int n;
	int a,b;
	scanf("%d",&n);
	scanf("%d%d",&a,&b);
	float pbase=b*100.0/a;
	int t=n-1;
	while(t--){
		scanf("%d%d",&a,&b);
		float p=b*100.0/a;//开始用*100,导致计算错误
		if((p-pbase-5.0)>1e-6)
			printf("better\n");
		else if(pbase-p-5.0 >1e-6)
			printf("worse\n");
		else printf("same\n");
	}	
	return 0;
}

