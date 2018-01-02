/*
程序设计与算法（二）第二周测验 2:简单的整数划分问题 POJ4117
write by xucaimao,20171130,AC
根据网络程序修改。还是很难理解，需要努力！！
经过调整优化，总算是理解了！！happy!! 
采用回溯法打印所有解，并统计解的个数。但是当n>50时就非常慢了
5的划分为：5, 4+1, 3+2, 3+1+1, 2+2+1, 2+1+1+1, 1+1+1+1+1
*/
#include<cstdio>
int sum=0,ansnum=0;
int ans[200];//解的序列

void dfs(int n,int k){
	//求一个正整数n的所有划分的第k位数
	if(sum==n){
		ansnum++;//解的数量加1
		//开始打印解
		printf("%d=",n);
		for(int i=1;i<k-1;i++)
			printf("%d+",ans[i] );
		printf("%d\n",ans[k-1] );
	}
	else
		for(int i=ans[k-1];i>=1;i--){//从大到小尝试各个数字
			//正常采用 i=n;i>=1;i--,上面的语句可以减少循环数量
			//采用i=ans[k-1],下面的i<=ans[k-1] 的判断可以不要了
			sum+=i;
			if(sum<=n && i<=ans[k-1]){
				//后一个数字不能大于前一个
				ans[k]=i;
				dfs(n,k+1);//求解的下一位
			}
			sum-=i;//回溯
		}
}

int main(){
	int n;
	scanf("%d",&n);
	ans[0]=n;//为了使得后面ans[k-1]不出现越界
	dfs(n,1);
	printf("Total answer number is: %d.\n",ansnum );
	return 0;
}