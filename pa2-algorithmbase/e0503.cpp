/*
《算法基础与在线实践》练习题5-3 和为给定数 POJ4143
write by xucaimao,2017-12-14 23:30开始编程，AC 2017-12-14 23:42:13
*/
#include<cstdio>
#include <algorithm>

const int maxn=100000+10;
int data[maxn];

int search(int arr[],int l,int r,int x){
	//在arr[l...r]范围内查找值x,查找失败返回-1
	int ans=-1;
	while(l<=r){
		int mid=(r-l)/2+l;
		if(arr[mid]==x){
			ans=x;
			break;
		}
		else if(arr[mid]<x)l=mid+1;
		else r=mid-1;
	}
	return ans;
}

int main(){
	//freopen("e0404.in","r",stdin);
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&data[i]);
	scanf("%d",&m);
	std::sort(data,data+n);
	int ok=0;
	int a=-1,b=-1;
	for(int i=0;i<n;i++){
		a=data[i];
		if(a>=m)break;
		b=search(data,i+1,n-1,m-a);
		if(b>=0){ok=1;break;}
	}
	if(ok)printf("%d %d\n",a,b );
	else printf("No\n");
	return 0;
}