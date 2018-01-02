/*
《算法基础与在线实践》练习题5-1 查找最接近的元素 POJ4134
write by xucaimao,2017-12-14 23:45开始编程，AC 2017-12-15 20:24:48
*/
#include<cstdio>
#include<iostream>
using namespace std;

const int maxn=100000+10;
int data[maxn];

int search(int arr[],int len,int x){
	//在长度为len的数组arr中查找最接近值x的最小的值
	int ans=0;
	int ok=0;
	int l=0,r=len-1;
	if(x<=arr[l])ans=arr[l];
	else if(x>=arr[r])ans=arr[r];
	else{//arr[0]<x<arr[len-1]	
		while(l<=r){
			int mid=(r-l)/2+l;
			if(arr[mid]==x){
				ans=arr[mid];
				ok=1;
				break;
			}
			else if(arr[mid]<x)
				l=mid+1;
			else
				r=mid-1;
		}
		if(!ok){
			//此时r指向小于x的数，l指向大于x的数
			//printf("target=%d : arr[l]= %d ; arr[r]= %d \n",x,arr[l],arr[r]);
			if( abs( arr[l]-x ) < abs(arr[r]-x) )
				ans=arr[l];
			else ans=arr[r];
		}
	}
	
	return ans;
}

int main(){
	freopen("e0501.in","r",stdin);
	int n,m,t,ans;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&data[i]);
	scanf("%d",&m);
	while(m--){
		scanf("%d",&t);
		ans=search(data,n,t);
		printf("%d\n",ans );
	}
	return 0;
}