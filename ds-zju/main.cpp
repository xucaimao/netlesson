/*中国大学MOOC-陈越、何钦铭-数据结构-2018秋
 * 04-树6 Complete Binary Search Tree （30 分）
 * wirte by xucaimao,2018-11-19
 * 假设二叉树每一层的高度为h(根节点h=1),则每一层的最大节点数为2^(h-1)
 * 对于完全二叉树，假设除了最底层的高度为H,此时除了底层的树是满二叉树，其节点总数为2^H-1
 * 假设底层的节点数为X，则有2^H-1+X=N(N为二叉树的总节点数)
 * 则有 H = log(N+1-X) / log(2.0)
 * 当X==0时，H = log(N+1) / log(2.0)
 * X的最小值是0
 * X的最大值时2^(
 * */
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxN=1000+10;
int data[maxN];

int getLeftLength(int n){    //利用二叉树的性质：满二叉树第i层有 2^(i-1) 个结点， 高为h的满二叉树有 2^h - 1 个结点（从1开始）
    double h, x, L, t;
    h = (double)(int)( log((double)n+1) / log(2.0) );
    //h = floor( log((double)n+1) / log(2.0) );
    x = n - pow(2.0, h) + 1 ;
    t = pow(2.0, h - 1.0);
    x = x < t ? x : t;
    L = t - 1 + x;
    return (int)L;
}

int leftSubtreeNodeNum(int n){
    //n为树的节点总数，本函数计算左子树的结点个数
    int x, h, i;
    //计算树的总高度
    for (i = 0; pow(2, i) <= n; i++);
    h = i - 1;; //计算log(n+1)的下届
    x = n + 1 - pow(2, h);
    if (x>pow(2, h - 1))
        return pow(2, h) - 1;
    else
        return n - pow(2, h - 1);
}

int main(){
    freopen("in.txt","r",stdin);
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>data[i];
    sort(data,data+N);
    getLeftLength(N);
    leftSubtreeNodeNum(N);
    return 0;
}