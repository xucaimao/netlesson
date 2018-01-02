/*
程序设计与算法（二）第六周测验 1:拦截导弹
write by xucaimao,2017-12-21 22:38 AC at 2017-12-21 23:13:05
求最长下降子序列，与最长上升子序列是同一类问题
*/

#include<cstdio>
const int maxn=30;
int data[maxn];
int maxLen[maxn];

int main(){
	freopen("in.txt","r",stdin);
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&data[i]);
		maxLen[i]=1;
	}
	for(int k=2;k<=n;k++){
		//求以data[k]为终点的最长下降序列的长度
		//首先求以data[i](i<k)为终点的，所有的下降序列的长度，的最大值
		int maxleft=0;
		for(int i=1;i<k;i++){
			if(data[k]<=data[i])
				if(maxLen[i]>maxleft)
					maxleft=maxLen[i];
		}
		maxLen[k]=maxleft+1;
		if(ans<maxLen[k])ans=maxLen[k];
	}

	printf("%d\n",ans );
	return 0;
}