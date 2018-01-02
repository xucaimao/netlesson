/*
用于测试两个程序的运行时间 
*/

#include<cstdio>
#include<ctime>
#include<iostream>
using namespace std;

int* generateRandomArray(int len,int l,int r){
	//生成一个长度为len的整型数组，元素在[l...r)内随机排列 
	int *arr=new int[len];
	for(int i=0;i<len;i++)
		arr[i]=rand()%(r-l+1)+l;
	return arr;
}

int* generateNearlyOrderArray(int len,int swaptime){
	//生成一个长度为len的整型数组，元素在[0...len)内基本有序排列 
	int *arr=new int[len];
	for(int i=0;i<len;i++)
		arr[i]=i;
	for(int i=0;i<swaptime;i++){
		int a=rand()%len;
		int b=rand()%len;
		swap(arr[a],arr[b]);
	} 
	return arr;
}

int* copyArray(int arr[],int len){
	//拷贝数组arr
	int *arr1=new int[len];
	for(int i=0;i<len;i++)
		arr1[i]=arr[i];
	return arr1; 
}

void printArray(int arr[],int len){
	for(int i=0;i<len;i++)
		printf("%d ",arr[i]);
	printf("\n");
} 

void insertionSort(int arr[],int l,int r){
	//对数组arr[l...r]中的元素进行插入排序
	for(int i=l+1;i<=r;i++){
		int v=arr[i];
		int j;
		for(j=i;j>l && arr[j-1]>arr[j];j--)
			swap(arr[j-1],arr[j]);
		arr[j]=v;
	}		
}

void __merge(int arr[],int l,int mid,int r){
	//对数组arr[l...mid],arr[mid+1,r]进行归并
	int len=r-l+1;
	int* tmp=new int[len];
	int i=l,j=mid+1;
	int k=0;//指向tmp数组
	while(k<len){
		//把两部分数据按从小到大的顺序放在tmp
		if(i>mid)tmp[k++]=arr[j++];
		else if(j>r)tmp[k++]=arr[i++];
		else if(arr[i]<arr[j])tmp[k++]=arr[i++];
		else tmp[k++]=arr[j++];
	}
	//把数据拷贝回arr
	for(int i=0;i<len;i++)
		arr[i+l]=tmp[i];
	delete[] tmp;
}

void __mergeSort(int arr[],int l,int r){
	// if(r-l<15){
	// 	insertionSort(arr,l,r);
	// 	return;
	// }
	if(l>=r)return;
	int mid=l+(r-l)/2;
	__mergeSort(arr,l,mid);
	__mergeSort(arr,mid+1,r);
	__merge(arr,l,mid,r);
}

void __mergeSort2(int arr[],int l,int r){
	if(r-l<15){
		insertionSort(arr,l,r);
		return;
	}
	// if(l>=r)return;
	int mid=l+(r-l)/2;
	__mergeSort(arr,l,mid);
	__mergeSort(arr,mid+1,r);
	if(arr[mid]>arr[mid+1])
		__merge(arr,l,mid,r);
}

void mergeSort(int arr[],int len){
	//接口函数
	__mergeSort(arr,0,len-1);
}

void mergeSort2(int arr[],int len){
	//接口函数
	__mergeSort2(arr,0,len-1);
}

int main(){
	srand(time(NULL));
	//生成测试数据
	int len=100000;
	//int* arr1=generateRandomArray(len,0,100);
	int* arr1=generateNearlyOrderArray(len,10);
	int* arr2=copyArray(arr1,len);
	int* arr3=copyArray(arr1,len);
	// printf("Array befor sort is:\n");
	// printArray(arr1,len);
	
	//测试一
	clock_t startTime=clock(); 
	//此处插入测试程序
	mergeSort(arr1,len);
	clock_t endTime=clock();
	cout << "my mergeSort1 time is: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s"<<endl; 
	
	//测试二 
	startTime=clock(); 
	//此处插入测试程序
	mergeSort2(arr2,len);
	endTime=clock();
	cout << "my mergesort2 time is: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s"<<endl; 
	
	//测试三
	startTime=clock(); 
	//此处插入测试程序
	sort(arr3,arr3+len);
	endTime=clock();
	cout << "std sort time is: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s"<<endl;

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	return 0;
} 
