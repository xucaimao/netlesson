/*中国大学MOOC-陈越、何钦铭-数据结构-2018秋
 * 09-排序1 排序 （25 分）
 * wirte by xucaimao,2018-11-04
 * */
#include <iostream>
using namespace std;

void insertSort(long long int arr[],int n){
    for(int i=1;i<n;i++){
        long long int t=arr[i];
        int j;
        for(j=i;j>0 && t < arr[j-1];j--)
            arr[j]=arr[j-1];
        arr[j]=t;
    }
}

//对于数组arr[left...mid-1]和arr[mid,r]两部分进行归并
void merge(long long int arr[],int left,int mid,int right){
    long long int* tmp=new long long int[right-left+1];
    int i=left,j=mid,k=0;
    while(i<=mid-1 && j<=right){
        if(arr[i]<arr[j])
            tmp[k++]=arr[i++];
        else
            tmp[k++]=arr[j++];
    }
    while(i<=mid-1)
        tmp[k++]=arr[i++];
    while(j<=right)
        tmp[k++]=arr[j++];
    //数据复制回原处
    for(i=left,k=0;i<=right;i++,k++)
        arr[i]=tmp[k];
    delete []tmp;
}

void __mergeSort(long long int arr[],int l,int r){
    if(r==l)
        return;
    int mid=(r-l)/2+l;
    __mergeSort(arr,l,mid);
    __mergeSort(arr,mid+1,r);
    merge(arr,l,mid+1,r);
}

void mergeSort(long long int arr[],int n){
    __mergeSort(arr,0,n-1);
}

//非递归形式的mergeSort
void mergeSort2(long long int arr[],int n){
    int step=1;
    int l,m,r;
    while(step<n){
        l=0;
        for(;;){
            m=l+step;
            if(m>n-1)break;
            r=m+step-1;
            if(r>n-1)r=n-1; //防止越界
            merge(arr,l,m,r);
            l=r+1;
        }
        step*=2;
    }
}



int main(){
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    int n;
    cin>>n;
    long long int* a=new long long int[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    //insertSort(a,n);
    mergeSort2(a,n);
    for(int i=0;i<n;i++){
        if(i>0)cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    delete []a;
    return 0;
}