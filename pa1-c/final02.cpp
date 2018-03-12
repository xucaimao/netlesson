/*
程序设计实习MOOC / 程序设计与算法（一）期末考试(2017冬季)  
2:求分数序列和
write by xucaimao,2018-01-10 23:00
*/

#include<cstdio>

int main(){
	int p=1,q=2,n;
	double ans;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		ans+=q*1.0/p;
		int t=p;
		p=q;
		q=q+t;
	}
	printf("%.4lf\n",ans);
	return 0;
}