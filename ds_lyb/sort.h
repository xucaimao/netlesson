//
// Created by xcm on 2020/5/7.
//

#ifndef DS_LYB_SORT_H
#define DS_LYB_SORT_H

#include "SortTestHelper.h"

template <typename T>
void selectSort(T arr[],int n){
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++)
            if(arr[j]<arr[minIndex]) minIndex=j;
        std::swap(arr[i],arr[minIndex]);
    }
    return;
}

//优化后的插入排序
template <typename T>
void insertSort(T arr[],int n){
    for(int i=1;i<n;i++){
        T e=arr[i];
        int j=i;
        for(;j>0 && arr[j-1]>e;j--)
            arr[j]=arr[j-1];
        arr[j]=e;
    }
}

//归并排序
//将arr[l...mid]和arr[mid+1,r]两部分进行归并
template <typename T>
void __merge(T arr[],int l,int mid,int r){
    T aux[r-l+1];
    for(int i=l;i<=r;i++)
        aux[i-l]=arr[i];
    int i=0,j=mid-l+1;      //指向aux
    int aux_mid=mid-l;
    int aux_right=r-l;
    for(int k=l;k<=r;k++){
        if(i>aux_mid) arr[k]=aux[j++];
        else if(j>aux_right) arr[k]=aux[i++];
        else if(aux[i]>aux[j]) arr[k]=aux[j++];
        else arr[k]=aux[i++];
    }
    return;
}
//递归使用归并排序，对arr[l...r]的范围进行排序
template <typename T>
void __mergeSort(T arr[],int l,int r){
    if(l>=r) return;

    int mid=(r-l)/2+l;
    __mergeSort(arr,l,mid);
    __mergeSort(arr,mid+1,r);
    if(arr[mid] > arr[mid+1])   //优化一
        __merge(arr,l,mid,r);
}
//递归使用归并排序，对arr[0...n-1]的范围进行排序
template <typename T>
void mergeSort(T arr[],int n){
    __mergeSort(arr,0,n-1);
}

//自底向上的归并排序（非递归），对arr[0...n-1]的范围进行排序
//可以扩展用于链表的排序
template <typename T>
void mergeSortBU(T arr[],int n){
    for(int sz=1;sz<=n;sz+=sz){     //每次进行归并的元素数量
//        for(int i=0;i<n;i=i+sz+sz)
//            __merge(arr,i,i+sz-1,i+sz+sz-1);
//为了防止mid 和 right越界，修改成下面的语句
        for(int i=0;i+sz<n;i=i+sz+sz)
            __merge( arr,i,i+sz-1,min(i+sz+sz-1,n-1) );
    }
}

//返回p，使得arr[l...p-1]<arr[p]<arr[p+1...r]
template <typename T>
int partition(T arr[],int l,int r){
    T v=arr[l];

    //arr[l+1...p]<v;初始[l+1...l]为空区间
    //arr[p+1...i-1]>v;初始[l+1...l]为空区间
    //维护区间的有效性非常关键
    int p=l;
    for(int i=l+1;i<=r;i++){
        if(arr[i]<v){
            swap(arr[p+1],arr[i]);
            p++;
        }
    }
    swap(arr[l],arr[p]);
    return p;
}

//快速排序，对arr[l...r]部分进行排序
template <typename T>
void __quickSort(T arr[],int l,int r){
    if(l>=r)return;
    int p=partition(arr,l,r);
    __quickSort(arr,l,p-1);
    __quickSort(arr,p+1,r);
}
//快速排序，对有n个元素的数组arr进行排序
template <typename T>
void quickSort(T arr[],int n){
    __quickSort(arr,0,n-1);
}

//快速排序，对arr[l...r]部分进行排序
template <typename T>
void __quickSort3way(T arr[],int l,int r){
    if(l>=r)return;
    swap(arr[l],arr[ rand()%(r-l+1) +l ]);
    T v=arr[l];

    //begin of prtition
    //arr[l+1...lt]<v
    //arr[lt+1...i-1]==v
    //arr[gt...r]>v
    int lt=l;   //[l+1...lt]<v 初始为空区间
    int i=l+1;  //[lt+1...i-1]==v 初始为空区间
    int gt=r+1; //[gt...r]>v 初始为空区间
    while(i<gt){
        if( arr[i]>v ){
            swap(arr[i],arr[gt-1]);
            gt--;
        }
        else if(arr[i]<v){
            swap(arr[i],arr[lt+1]);
            lt++;
            i++;
        }
        else i++;   //arr[i]==v
    }
    swap(arr[l],arr[lt]);
    lt--;
    //end of partition
    __quickSort3way(arr,l,lt);
    __quickSort3way(arr,gt,r);
}
//快速排序，对有n个元素的数组arr进行排序
template <typename T>
void quickSort3way(T arr[],int n){
    srand(time(NULL));
    __quickSort3way(arr,0,n-1);
}




int mymain() {
    int n=1000000;
    int *arr=SortTestHelper::generateRandomArray(n,0,100);
//    int *arr=SortTestHelper::generateNearlyOrderArray(n,10);

//    mergeSortBU(arr,n);
    int *arr2=SortTestHelper::copyIntArray(arr,n);
//    SortTestHelper::printArray(arr,n);
    SortTestHelper::testSort("merge      Sort",mergeSort,arr,n);
    SortTestHelper::testSort("quick Sort 3way",quickSort3way,arr2,n);
    delete[] arr;
    delete[] arr2;
    return 0;
}

#endif //DS_LYB_SORT_H
