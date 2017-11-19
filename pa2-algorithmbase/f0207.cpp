/*
《算法基础与在线实践》例题2-7 排列 POJ1833
write by xucaimao,20171118,21:30测试通过
1.给定排列中的n个数X0,X1,X2,...X(n-1)
2.从X(n-1)开始向左查找，直到找到某个位置j,满足X(j-1)<Xj
3.在Xj,X(j+1),...X(n-1)中找到比X(j-1)大的数中最小的那一个，将其与X(j-1)交换
4.将j...n位置的所有的数按从小到大排序。
5.特别地，如果X0,X1,X2,...X(n-1)已经是降序排列，则下一个排列为它的倒序
学习了插入排序
*/
#include<cstdio>
const int maxn=1025;
int data[maxn];

void sort(int arr[],int s,int e){
	//把数组arr[s..e]中的元素,按从小到大的顺序排列
	//采用插入排序的方法
	for(int i=s+1;i<=e;i++){
		int e=arr[i];
		int j;
		for(j=i;j>s && arr[j-1]>e;j--)
			arr[j]=arr[j-1];
		arr[j]=e;
	}
}

void nextpermutation(int arr[],int n){
	//求长度为n的数组arr[0..n)的下一排列
	int j;
	for(j=n-1;j>=1 && arr[j-1]>arr[j];j--);
	if(j==0){//说明data已经是降序排列了,把数组倒序
		int mid=(n-1)/2;
		for(int i=0;i<=mid;i++){
			int t=arr[i];
			arr[i]=arr[n-1-i];
			arr[n-1-i]=t;
		}		
	}
	else{
		int minp=j;
		for(int i=j;i<=n-1;i++)//找到比d[j-1]大的最小的元素的位置
			if(arr[i]>arr[j-1] && arr[i]<arr[minp])minp=i;
		int t=arr[minp];
		arr[minp]=arr[j-1];
		arr[j-1]=t;
		//把数组d[j..n-1]排序
		sort(arr,j,n-1);
	}
}

int main(){
	freopen("f0207.in","r",stdin);
	int m,n,k;
	scanf("%d",&m);
	while(m--){
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)
			scanf("%d",&data[i]);
		for(int i=0;i<k;i++)//执行k次
			nextpermutation(data,n);
		for(int i=0;i<n;i++){//打印
			if(i>0)printf(" ");
			printf("%d", data[i]);
		}
		printf("\n");
	}
}