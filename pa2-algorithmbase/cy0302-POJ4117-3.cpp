/*
程序设计与算法（二）第二周测验 2:简单的整数划分问题 POJ4117
5的划分为：5, 4+1, 3+2, 3+1+1, 2+2+1, 2+1+1+1, 1+1+1+1+1
write by xucaimao,20171130,AC

整数划分问题是算法中的一个经典命题之一。所谓整数划分，是指把一个正整数n写成如下形式：
    n=m1+m2+...+mi; （其中mi为正整数，并且1 <= mi <= n），则{m1,m2,...,mi}为n的一个划分。
如果{m1,m2,...,mi}中的最大值不超过m，即max(m1,m2,...,mi)<=m，则称它属于n的一个m划分。这里我
们记n的m划分的个数为f(n,m);
例如但n=4时，他有5个划分，{4},{3,1},{2,2},{2,1,1},{1,1,1,1};
注意4=1+3 和 4=3+1被认为是同一个划分。
该问题是求出n的所有划分个数，即f(n, n)。下面我们考虑求f(n,m)的方法;
2.递推法：
      综上所述：
                 f(n, m)=   1;              (n=1 or m=1)
   f(n,m)   =    f(n, n);                   (n<m)
                 1+ f(n, m-1);              (n=m)
                 f(n-m,m)+f(n,m-1);         (n>m)
*/
#include<cstdio>
const int maxn=60;
int f[maxn][maxn];
int main(){
	for(int i=1;i<=maxn;i++){
		f[i][1]=1;
		f[1][i]=1;
	}
	for(int n=2;n<=maxn;n++)
		for(int m=2;m<=maxn;m++){
			if(n==m) f[n][m]=1+f[n][m-1];
			else if(n<m) f[n][m]=f[n][n];
			else f[n][m]=f[n-m][m]+f[n][m-1];
		}

	int N;
	while(scanf("%d",&N) !=EOF){
		printf("%d\n",f[N][N]);
	}
	return 0;
}