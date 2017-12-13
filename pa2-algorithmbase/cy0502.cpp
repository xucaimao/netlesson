/*
程序设计与算法（二）第五周测验 2:求排列的逆序数 
采用归并排序，在归并的同时，统计
write by xucaimao,2017-12-13 AC at 21:59:48
*/
#include<cstdio>

const int maxn=100000+10;
int data[maxn];
int temp[maxn];
int k=0;
long long int sum=0;

template<typename T>
void merge(T arr[],int l,int mid,int r){
	//对数组arr[l...mid]与arr[mid+1...r]进行合并，同时统计逆序对的数量
	int i=l;//指向左半
	int j=mid+1;//指向右半
	int k=l;//指向temp
	while(k<=r){
		if(i>mid)
			temp[k++]=arr[j++];
		else if(j>r)
			temp[k++]=arr[i++];
		else if(arr[i]<=arr[j])
			temp[k++]=arr[i++];
		else{
			//arr[i]>arr[j],此时arr[i...mid]之间的元素和arr[j]都构成逆序对
			temp[k++]=arr[j++];
			sum+=(mid-i+1);
		}
	}
	//数据拷贝回data
	for(int i=l;i<=r;i++)
		data[i]=temp[i];
}

template<typename T>
void mergeSortRevNum(T arr[],int l,int r){
	//对数组arr[l...r]进行归并排序，同时统计逆序对数量
	if(l>=r)return;
	int mid=l+(r-l)/2;
	mergeSortRevNum(arr,l,mid);
	mergeSortRevNum(arr,mid+1,r);
	if(arr[mid]>arr[mid+1])
		merge(arr,l,mid,r);
}

int main(){
	freopen("cy0502.in","r",stdin);
	int n;
	sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&data[i]);
	mergeSortRevNum(data,0,n-1);
	// for(int i=0;i<n;i++)
	// 	printf("%d ",data[i] );
	printf("%lld\n",sum );
	return 0;
}