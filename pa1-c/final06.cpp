/*
程序设计实习MOOC / 程序设计与算法（一）期末考试(2017冬季)  
6:大整数加法
write by xucaimao,2018-01-10 23:08
*/

#include<cstdio>
int a[25],b[25];
char s1[210],s2[210];

void str2dig(char s[]){
	
}

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