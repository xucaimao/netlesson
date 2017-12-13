/*
程序设计与算法（二）第五周测验 1:输出前k大的数 
采用双路快排进行局部优化
write by xucaimao,2017-12-13
*/
#include<cstdio>
#include <ctime>
#include <iostream>
using namespace std;

const int maxn=100000+10;
int data[maxn];
int k=0;

template<typename T>
int partition(T arr[],int l,int r){
	//对数组arr[l...r]进行划分，使得arr[l...p-1]>=v
	//arr[p+1...r]<=v，arr[p]==v
	swap(arr[l],arr[ rand()%(r-l+1)+l ]);
	T v=arr[l];
	//arr[l+1...i)和arr(j...r]初始为空
	int i=l+1;
	int j=r;
	while(1){
		while(i<=j && arr[i]>v)i++;
		while(j>=i && arr[j]<v)j--;
		if(i>j)break;
		swap(arr[i],arr[j]);
		i++;j--;
	}
	//此时i已经越界，j指向比arr[l]大的元素
	swap(arr[l],arr[j]);
	return j;
}

template<typename T>
void quickSort(T arr[],int l,int r){
	//采用双路快速排序的方法,对数组有效部分进行从大到小的排序
	if(l>=r)return;
	int p=partition(arr,l,r);
	quickSort(arr,l,p-1);
	if(p-1<k)//速度快就体现在这里，相当于剪枝的作用
		quickSort(arr,p+1,r);
}

int main(){
	freopen("cy0501.in","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&data[i]);
	scanf("%d",&k);
	srand(time(NULL));
	quickSort(data,0,n-1);
	for(int i=0;i<k;i++)
		printf("%d\n",data[i] );
	return 0;
}