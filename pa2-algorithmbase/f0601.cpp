/*
程序设计与算法（二）算法基础 第五周 分治 例题1 归并排序
write by xucaimao,2017-12-11 22:00,
liuyubobo老师讲解的很清晰，重点是数组边界的定义和维护
*/
#include <cstdio>
const int maxn=1000;
int data[maxn];
int tmp[maxn];

template<typename T>
void merge(T arr[],int left,int mid,int right,int temp[]){
	//对排好序的arr[left...mid]和arr[mid+1,right]两部分，
	//通过临时数组,进行归并
	int i=left,j=mid+1;
	int k=left;
	while(k<=right){
		if(i>mid)temp[k++]=arr[j++];
		else if(j>right)temp[k++]=arr[i++];
		else if(arr[i]<arr[j])temp[k++]=arr[i++];
		else temp[k++]=arr[j++];
		//此处的逻辑优化是重点！下面是我刚开始写的，虽然正确但是效率要低不少
		// if(arr[i]<arr[j] && i<=mid)temp[k++]=arr[i++];
		// else if(arr[i]>=arr[j] && j<=right)temp[k++]=arr[j++];
		// else if(i>mid && j<=right)temp[k++]=arr[j++];
		// else if(j>right && i<=mid)temp[k++]=arr[i++];
	}
	i=left;k=left;
	while(k<=right)//拷贝回原来的数组arr
		arr[i++]=temp[k++];
}

template<typename T>
void mergesort(T arr[],int left,int right,T temp[]){
	//对数组arr[left...right]进行归并排序，数组temp为零时空间
	if(left<right){
		int mid=left+(right-left)/2;
		mergesort(arr,left,mid,temp);
		mergesort(arr,mid+1,right,temp);
		merge(arr,left,mid,right,temp);
	}
}
int main(){
	freopen("f0601.in","r",stdin);
	int n=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&data[i]);
	mergesort(data,0,n-1,tmp);
	for(int i=0;i<n;i++)
		printf("%d ",data[i] );
	printf("\n");

	return 0;
}