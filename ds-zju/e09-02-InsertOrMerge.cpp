/*中国大学MOOC-陈越、何钦铭-数据结构-2018秋
 * 09-排序2 Insert or Merge （25 分
 * wirte by xucaimao,2018-11-04
 * */
#include <iostream>
using namespace std;
const int maxN=110;
int in1[maxN],in2[maxN],tar[maxN],NUM;

//比较两个有n个元素的数组是否相同
bool sameArray(int A[],int B[],int n){
    for(int i=0;i<n;i++)
        if(A[i]!=B[i])return false;
    return true;
}

void insertSort(int arr[],int n){
    bool haveans=false;
    for(int i=1;i<n;i++){
        if(sameArray(arr,tar,n)){
            cout<<"Insertion Sort"<<endl;
            haveans=true;
        }

        int t=arr[i];
        int j;
        for(j=i;j>0 && t < arr[j-1];j--)
            arr[j]=arr[j-1];
        arr[j]=t;
        //已经找到相同序列，再执行一次循环跳出
        if(haveans){
            for(int k=0;k<n;k++){
                if(k>0)cout<<" ";
                cout<<arr[k];
            }
            cout<<endl;
            break;
        }
    }
}

//对于数组arr[left...mid-1]和arr[mid,r]两部分进行归并
void merge(int arr[],int left,int mid,int right){
    int* tmp=new int[right-left+1];
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

//非递归形式的mergeSort
void mergeSort(int arr[],int n){
    bool haveans=false;
    int step=1;
    int l,m,r;
    while(step<n){

        if(sameArray(arr,tar,n)){
            cout<<"Merge Sort"<<endl;
            haveans=true;
        }
        //做一次归并
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

        if(haveans){
            for(int k=0;k<n;k++){
                if(k>0)cout<<" ";
                cout<<arr[k];
            }
            cout<<endl;
            break;
        }
    }
}

int main(){
    //freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    cin>>NUM;
    int a;
    for(int i=0;i<NUM;i++){
        cin>>a;
        in1[i]=in2[i]=a;
    }
    for(int i=0;i<NUM;i++)
        cin>>tar[i];

    insertSort(in1,NUM);
    mergeSort(in2,NUM);
    return 0;
}