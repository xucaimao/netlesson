/*
《算法基础与在线实践》练习题7-3 复杂的整数划分问题 POJ4119
write by xucaimao,2018-01-02 18:00,
采用回溯法打印所有解，并统计解的个数。可以求解但是会超时

*/
#include<cstdio>
#include <cstring>
int sum=0,ansnum=0;
int ans[100];//解的序列

void dfs1(int n,int j){
	//N划分成若干个正整数之和,求其第j个数
	if(sum==n){
		ansnum++;
		printf("DFS1: %d =",n);
		for(int i=1;i<j-1;i++)
			printf(" %d +",ans[i] );
		printf(" %d\n",ans[j-1] );
	}
	else
		for(int m=n-sum;m>0;m--){
			//枚举所有小于等于前一个数的数字
			if(m<=ans[j-1]){
				ans[j]=m;
				sum+=m;
				dfs1(n,j+1);
				sum-=m;
			}	
		}	
}

void dfs2(int n,int k,int j){
	//N划分成K个正整数之和,求第j位
	if(sum==n && j==k+1){
		ansnum++;
	}
	else
		for(int m=n-sum;m>0;m--){
			//枚举所有小于等于前一个数的数字
			if(m<=ans[j-1]){
				ans[j]=m;
				sum+=m;
				dfs2(n,k,j+1);
				sum-=m;
			}	
		}	
}

void dfs3(int n,int j){
	//N划分成若干个不同正整数之和,求第j位
	if(sum==n){
		ansnum++;
	}
	else
		for(int m=n-sum;m>0;m--){
			//枚举所有小于等于前一个数的数字
			if(m<ans[j-1]){
				ans[j]=m;
				sum+=m;
				dfs3(n,j+1);
				sum-=m;
			}	
		}	
}

void dfs4(int n,int j){
	//N划分成若干个奇数之和,求其第j个数
	if(sum==n){
		ansnum++;
	}
	else
		for(int m=n-sum;m>0;m--){
			//枚举所有小于等于前一个数的数字
			if(m<=ans[j-1] && m%2){
				ans[j]=m;
				sum+=m;
				dfs4(n,j+1);
				sum-=m;
			}	
		}	
}


int main(){
	freopen("e0703.in","r",stdin);
	int N,K;
	while(scanf("%d%d",&N,&K)!=EOF){
		//N划分成K个正整数之和
		sum=0;ansnum=0;
		memset(ans,0,sizeof(ans));
		ans[0]=N;//为了使得后面ans[k-1]不出现越界
		dfs2(N,K,1);
		printf("%d\n",ansnum );

		//N划分成若干不同正整数之和
		sum=0;ansnum=0;
		memset(ans,0,sizeof(ans));
		ans[0]=N+1;//为了使得后面ans[k-1]不出现越界
		dfs3(N,1);
		printf("%d\n",ansnum );

		//N划分成若干个奇数之和
		sum=0;ansnum=0;
		ans[0]=N;//为了使得后面ans[k-1]不出现越界
		dfs4(N,1);
		printf("%d\n",ansnum );	
	}
	return 0;
}