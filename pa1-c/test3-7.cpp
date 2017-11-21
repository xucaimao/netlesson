/*
程序设计实习MOOC / 程序设计与算法（一）第三周测验(2017冬季)  
7:整数序列的元素最大跨度值

*/

#include<cstdio>

int main(){
	int x,n,maxn,minn;
	scanf("%d",&n);
	scanf("%d",&maxn);
	minn=maxn;
	int t=n-1;
	while(t--){
		scanf("%d",&x);
		if(x<minn)minn=x;
		else if(x>maxn)maxn=x;
	}
	printf("%d\n",maxn-minn );	
	return 0;
}

