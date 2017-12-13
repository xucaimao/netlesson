/*
程序设计与算法（二）算法基础 第五周 分治 例题2 快速排序
write by xucaimao,2017-12-12 22:00,
liuyubobo老师讲解的很清晰，重点是数组边界的定义和维护
本程序实现的是双路快速排序，同时考虑了数据的随机化选取
*/
#include <cstdio>
#include <ctime>
#include <iostream>//swap
using namespace std;
const int maxn=25;
int data[maxn];

template<typename T>
int partition(T arr[],int l,int r){
	//对arr[l...r],找到一个位置p,使得arr[l...p-1]里的元素都<=arr[p];
	//同时使得arr[p+1...r]里的元素都>=arr[p]
	//下面这一句，是为了使得划分的两部分尽量均匀，避免有序数组极端情况的出现
	int s=rand()%(r-l+1)+l;
	swap( arr[l],arr[s] );
	T v=arr[l];
	//arr[l+1 ...i)<=v;arr(j...r]>=v
	//初始i和j的设置，保证了上面两部分集合开始时都为空
	int i=l+1;
	int j=r;
	while(1){
		while(i<=j && arr[i]<v)i++;
		while(j>=i && arr[j]>v)j--;
		if(i>j)break;
		swap(arr[i],arr[j]);
		i++;
		j--;
	}
	swap(arr[l],arr[j]);
	return j;
}

template<typename T>
void quickSort(T arr[],int l,int r){
	//双路快速排序
	//对arr[l...r]进行快速排序
	if(l>=r)return;//这一句坑了我一天
	int p=0;
	p=partition(arr,l,r);
	quickSort(arr,l,p-1);
	quickSort(arr,p+1,r);
}

int main(){
	freopen("f0601.in","r",stdin);
	int n=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&data[i]);
	srand(time(NULL));
	quickSort(data,0,n-1);
	for(int i=0;i<n;i++)
		printf("%d ",data[i] );
	printf("\n");

	return 0;
}