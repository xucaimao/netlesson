/*中国大学MOOC-陈越、何钦铭-数据结构-2018秋
 * 10-排序6 Sort with Swap(0, i)
 * wirte by xucaimao,2018-11-04
 * 回溯法
 * todo 没有通过测试，无限递归了
 * */
#include <iostream>
#include <vector>
using namespace std;

const int maxN=5;
int data[maxN];
int vis[maxN][maxN];
int minSwapTime=1000000;
vector<int> ord(maxN);    //用于记录与0进行swap操作的元素
vector<int> minOrd(maxN);

//返回0在数组arr[0...n)中的下标
int findZero(int arr[],int n){
    for(int i=0;i<n;i++)
        if(arr[i]==0)return i;
    return -1;
}
bool isSorted(int arr[],int n){
    for(int i=0;i<n-1;i++)
        if(arr[i]>arr[i+1])return false;
    return true;
}

void dfs(int arr[],int n,int swapTime){
    if(swapTime>=minSwapTime)
        return;
    int z=findZero(arr,n);
    if(z==0)return; //
    for(int i=0;i<n;i++)
        if(arr[i]>arr[z] && vis[0][arr[i]]==0){
            swap(arr[i],arr[z]);
            vis[0][arr[i]]=1;
            if(swapTime>ord.size())
                ord.resize(swapTime*2);
            ord[swapTime]=i;    //记录操作步骤
            //数组已经有序，记录最小次数及具体操作
            if(isSorted(arr,n) && swapTime<minSwapTime){
                minSwapTime=swapTime;
                minOrd=ord;
            }
            dfs(arr,n,swapTime+1);
            swap(arr[i],arr[z]);    //恢复原始状态
            vis[0][arr[i]]=0;
        }
}

int main(){
    //int numOfUser,numOfProblems,numOfSubmissions;
    int N;
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>data[i];
    dfs(data,N,0);
    cout<<minSwapTime+1<<endl;
    for(int i=0;i<=minSwapTime;i++)
        cout<<"swap(0, "<<minOrd[i]<<")"<<endl;
    return 0;
}