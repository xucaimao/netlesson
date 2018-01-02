/*
《算法基础与在线实践》练习题7-3 复杂的整数划分问题 POJ4119
write by xucaimao,2018-01-02,AC 
采用递推法

*/
#include<cstdio>
#include <cstring>
const int maxn=55;
int f[maxn][maxn];
int fk[maxn][maxn][maxn];

int  f1(int N){
	//N划分成若干个正整数之和
	for(int i=1;i<=N;i++){
		f[1][i]=1;
		f[i][1]=1;
	}
	for(int n=2;n<=N;n++)
		for(int m=2;m<=N;m++){
			if(n<m)f[n][m]=f[n][n];
			if(n==m)f[n][m]=1+f[n][m-1];
			if(n>m)f[n][m]=f[n-m][m]+f[n][m-1];
		}
	return f[N][N];
}

/*[ N划分成K个正整数之和 ]

*/
int  f2(int N,int K){
	//N划分成K个正整数之和
	for(int i=1;i<=N;i++){
		f[1][i]=1;
		f[i][1]=1;
	}
	for(int n=2;n<=N;n++)
		for(int m=2;m<=N;m++){
			if(n<m)f[n][m]=f[n][n];
			if(n==m)f[n][m]=1+f[n][m-1];
			if(n>m)f[n][m]=f[n-m][m]+f[n][m-1];
		}
	return f[N][N];
}


/*[ N划分成若干个不同正整数之和 ]
与[ N划分成若干个正整数之和 ]区别在于:
1.当n=1时,f[n][m]=1;当m=1 n>1时,f[n][m]=0
2.当n>m时,
	a.划分中包含m,即{m,{x1,x2...xn}},其中x1+x2+...+xn=(n-m).
	  其总数是f[n-m][m-1],注意后面的m-1,是因为m已经取值,后面的xn必须小于m
	b.划分中不包括m,即f[n][m-1]
*/
int  f3(int N){
	//N划分成若干个不同正整数之和
	for(int i=1;i<=N;i++){
		f[1][i]=1;
	}
	for(int n=2;n<=N;n++)
		for(int m=2;m<=N;m++){
			if(n<m)f[n][m]=f[n][n];
			if(n==m)f[n][m]=1+f[n][m-1];
			if(n>m)f[n][m]=f[n-m][m-1]+f[n][m-1];
		}
	return f[N][N];
}

/*[ N划分成若干个奇数之和 ]
与[ N划分成若干个正整数之和 ]区别在于:
1.当n<m时,f[n][m]=f[n][n],但要考虑到所有的划分数都是奇数,所以有:
	a.当n为奇数时,f[n][m]=f[n][n](n为奇数)
	b.当n为偶数时,f[n][m]=f[n][n-1](n-1为奇数)
2.当n>m时,
	a.划分中包含m,即{m,{x1,x2...xn}},其中x1+x2+...+xn=(n-m).
	  其总数是f[n-m][m]
	b.划分中不包括m,即f[n][m-2],注意后面的m-2,是因为m是奇数,其后一个奇数是m-2
3.当n=m时,
	a.其中包含m,划分数为1,即{m}
	b.其中不包含m,划分数为f[n][m-2],注意后面的m-2,是因为m是奇数,其后一个奇数是m-2
*/
int  f4(int N){
	//N划分成若干个奇数之和
	for(int i=1;i<=N;i++){
		f[1][i]=1;//n=1 f[n][m]=1
		f[i][1]=1;//m=1 f[n][m]=1
	}
	for(int n=2;n<=N;n++)
		for(int m=3;m<=N;m+=2){
			if(n<m && n%2==1)f[n][m]=f[n][n];
			if(n<m && n%2==0)f[n][m]=f[n][n-1];
			if(n==m)f[n][m]=1+f[n][m-2];
			if(n>m)f[n][m]=f[n-m][m]+f[n][m-2];
		}
	return f[N][N];
}

int main(){
	freopen("in.txt","r",stdin);
	int N,K;
	while(scanf("%d%d",&N,&K)!=EOF){
		//N划分成若干个正整数之和
		memset(f,0,sizeof(f));
		printf("some add\n");
		printf("%d\n",f1(N));

		//N划分成K个正整数之和
		memset(f,0,sizeof(f));
		printf("K num add\n");
		printf("%d\n",f2(N,K));


		//N划分成若干不同正整数之和
		memset(f,0,sizeof(f));
		printf("some diffrent add\n");
		printf("%d\n",f3(N));

		//N划分成若干个奇数之和
		memset(f,0,sizeof(f));
		printf("some odd add\n");
		printf("%d\n",f4(N));
	}
	return 0;
}