/*
程序设计实习MOOC / 程序设计与算法（一）第四周测验(2017冬季)  
6:数字统计
write by xucaimao,2017-11-28-21:23
*/

#include<cstdio>
#include <cstring>

int solve(int n){
	int sum=0;
	while(n>0){
		int d=n%10;
		if(d==2)sum++;
		n/=10;
	}
	return sum;
}

int main(){
	int left,right;
	int sum=0;
	scanf("%d%d",&left,&right);
	for(int i=left;i<=right;i++)
		sum+=solve(i);
	printf("%d\n",sum );
	return 0;
}

