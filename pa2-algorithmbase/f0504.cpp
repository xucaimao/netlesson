/*
程序设计与算法（二）算法基础 第四周 二分 例题3
《算法基础与在线实践》例题5.4 Values whose Sum is 0 POJ3441
write by xucaimao,2017-12-09 22:30,AC 2017-12-15 22:07:41

*/
#include <cstdio>
#include <algorithm>
const int maxn=4005;
const int maxnn=16000010;
int a[maxn],b[maxn],c[maxn],d[maxn];
int sum1[maxnn],sum2[maxnn];

template<typename T>
int search(T arr[],int len,T target){
	//在有len个元素的有序数组arr中，查找target元素出现的次数
	int l=0,r=len-1;
	int mid;
	while(l<r){
		if(r-l ==1)mid=r;
		else mid=l+(r-l)/2;
		if(target>=arr[mid])//这一句时重点
			l=mid;
		else//target<arr[mid]
			r=mid-1;
	}
	//上面这一段就是ceil函数的基础
	//while结束时，l=r都指向最后一个target元素的位置
	int sum=0;
	while(arr[l]==target && l>=0){
		sum++;
		l--;
	}
	return sum;
}

template<typename T>
int search2(T arr[],int len,T target){
	//在有len个元素的有序数组arr中，查找target元素出现的次数
	int l=0,r=len-1;
	while(l<r){
		int mid=l+(r-l)/2;
		if(target<=arr[mid])//这一句时重点
			r=mid;
		else
			l=mid+1;
	}
	//上面这一段就是floor函数的基础
	//while结束时，l=r都指向第一个target元素的位置
	int sum=0;
	while(arr[l]==target && l<len){
		sum++;
		l++;
	}
	return sum;
}

int main(){
	freopen("in.txt","r",stdin);
	int n=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
	int sn=0;
	//计算可能的和
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			sum1[sn]=a[i]+b[j];
			sum2[sn]=c[i]+d[j];
			sn++;
		}
		
	std::sort(sum1,sum1+sn);
	std::sort(sum2,sum2+sn);

	int ans=0;
	int t=0;
	for(int i=0;i<sn;i++){
		t=search(sum2,sn,-sum1[i]);
		ans+=t;
	}
	printf("%d\n",ans );
	return 0;
}