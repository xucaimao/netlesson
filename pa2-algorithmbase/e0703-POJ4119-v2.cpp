/*
《算法基础与在线实践》练习题7-3 复杂的整数划分问题 POJ4119
write by xucaimao,2018-01-02,AC 
采用递推法

*/
#include<cstdio>
#include <cstring>
const int maxn=55;
int f[maxn][maxn];
int g[maxn][maxn];//偶数划分

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
定义f(n,k)为把整数n分成k个数之和(也就是分成k份)的分法数量(划分数)
1.当k=1时,划分只有一个,即{n},所以f(n,k)=1
2.当n<k时,划分不存在,所以f(n,k)=0
3.当n=k时,划分只有一个,即{n个1},所以f(n,k)=1
4.当n>k时,根据划分中是否包含1,有下面两种情况:
	a.划分中包含1,即{1,{x1,x2...xn}},其中x1+x2+...+xn=(n-1).
	  把划分转化为n-1的k-1个划分,即f(n-1,k-1)
	b.划分中不包含1,即划分中的k个数都>=2.为了达到这个目的,可以先拿出k个1放
	  到每一份,然后把剩下的(n-k)再分成k份即可.所以分法为f(n-k,k)
*/
int  f2(int N,int K){
	//N划分成K个正整数之和
	for(int i=1;i<=N;i++){
		f[i][1]=1;
	}
	for(int n=1;n<=N;n++)
		for(int k=1;k<=K;k++){
			if(k==1)f[n][k]=1;
			if(n<k)f[n][k]=0;
			if(n==k)f[n][k]=1;
			if(n>k)f[n][k]=f[n-1][k-1]+f[n-k][k];
		}
	return f[N][K];
}


/*[ N划分成若干个不同正整数之和 ]
与[ N划分成若干个正整数之和 ]区别在于:
1.当n=1时,f[n][m]=1;当m=1 n>1时,f[n][m]=0
2.当n>m时,根据划分中是否包含m,有下面两种情况:
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
定义f(n,k)为把整数n分成k个奇数数之和,的分法数量(划分数)
不理解,需要努力
*/
int  f4(int N){
	//N划分成若干个奇数之和
	f[0][0]=1;
	g[0][0]=1;
	for(int n=1;n<=N;n++ )
		for(int k=1;k<=n;k++){
			g[n][k]=f[n-k][k];
			f[n][k]=f[n-1][k-1]+g[n-k][k];
		}
	int ans=0;
	for(int i=0;i<=N;i++)
		ans+=f[N][i];
	return ans;
}

int main(){
	freopen("in.txt","r",stdin);
	int N,K;
	while(scanf("%d%d",&N,&K)!=EOF){
		//N划分成若干个正整数之和
		// memset(f,0,sizeof(f));
		// printf("some add\n");
		// printf("%d\n",f1(N));

		//N划分成K个正整数之和
		memset(f,0,sizeof(f));
		// printf("K num add\n");
		printf("%d\n",f2(N,K));


		//N划分成若干不同正整数之和
		memset(f,0,sizeof(f));
		// printf("some diffrent add\n");
		printf("%d\n",f3(N));

		//N划分成若干个奇数之和
		memset(f,0,sizeof(f));
		// printf("some odd add\n");
		printf("%d\n",f4(N));
	}
	return 0;
}