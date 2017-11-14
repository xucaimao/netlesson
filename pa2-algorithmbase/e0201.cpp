/*
《算法基础与在线实践》练习题2-1 与7无关的数 POJ2701
*/
#include<cstdio>

bool has7(int n){
	//判断一个数是否含有数字7
	while(n>0){
		int m=n%10;
		if(m==7)return true;
		n/=10;
	}
	return false;
}

int main(){
	int n,sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		if(i%7 != 0 && !has7(i))
			sum+=i*i;
	printf("%d\n",sum);
	return 0;
}