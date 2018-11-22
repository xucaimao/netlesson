/*中国大学MOOC-陈越、何钦铭-数据结构-2018秋
 * 04-树6 Complete Binary Search Tree （30 分）
 * wirte by xucaimao,2018-11-19
 * 假设二叉树每一层的高度为h(根节点h=1),则每一层的最大节点数为2^(h-1)
 * 对于完全二叉树，假设除了最底层的高度为H,此时除了底层的树是满二叉树，其节点总数为2^H-1
 * 假设底层的节点数为X，则有2^H-1+X=N(N为二叉树的总节点数)
 * 则有 H = log(N+1-X) / log(2.0)
 * 当X==0时，得到最小 H = log(N+1) / log(2.0)，也就是除了底层的树的高度
 * 得到H值后，由前式可得 X=N+1-2^H;
 *
 *
 * */
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxN=1000+10;
int data[maxN];
int tree[maxN];

int getLeftLength(int n){
    //利用二叉树的性质：满二叉树第i层有 2^(i-1) 个结点， 高为h的满二叉树有 2^h - 1 个结点（数的高度从1开始）
    int  h, x, lenthOfLeft, t;
    //求得除了最底层的高度为H
    h = (double)(int)( log((double)n+1) / log(2.0) );
    //h = floor( log((double)n+1) / log(2.0) );
    //求得底层的节点数
    x = n - pow(2, h) + 1 ;
    //倒数第二层的节点数，也就是左子树最多可能的底层节点数。X值不可能大于t
    t = pow(2, h - 1);
    //取二者的最小值
    x = x < t ? x : t;
    //
    lenthOfLeft = t - 1 + x;
    return lenthOfLeft;
}

void solve(int Dleft,int Dright,int Troot){
    //对于有序数组data[Dleft...Dright]，转化成以tree数组形式存放的完全二叉搜索树，其根节点为Troot
    //初始调用solve(0,N-1,0)
    int len=Dright-Dleft+1;
    if(len==0)
        return;
    int leftSize=getLeftLength(len);
    //计算左右子树的根
    int leftRoot=Troot*2+1;
    int rightRoot=leftRoot+1;
    tree[Troot]=data[Dleft+leftSize];       //根节点赋值
    solve(Dleft,Dleft+leftSize-1,leftRoot);
    solve(Dleft+leftSize+1,Dright,rightRoot);
}

int main(){
    freopen("in.txt","r",stdin);
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>data[i];
    sort(data,data+N);
    solve(0,N-1,0);
    for(int i=0;i<N;i++){
        if(i>0)cout<<" ";
        cout<<tree[i];
    }
    cout<<endl;
    return 0;
}