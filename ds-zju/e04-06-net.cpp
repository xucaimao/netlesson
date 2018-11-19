/*中国大学MOOC-陈越、何钦铭-数据结构-2018秋
 * 04-树6 Complete Binary Search Tree （30 分）
 * wirte by xucaimao,2018-11-19
 * 二叉树每一层的高度为h(根节点h=1),则每一层的最大节点数为2^(h-1)
 * 满二叉树，假设除了最底层的高度为H,底层的节点数为X，则有2^H-1+X=N(N为二叉树的总节点数)
 * 则有 H = log(N+1-X) / log(2.0)
 * X的最小值是0
 * X的最大值时2^(
 * */

#include<iostream>
#include<fstream>
#include<cmath>
#include<algorithm>
using namespace std;
#define max 100
class Tree{
public:
    int a[max];
    int last;
};
Tree*T=new Tree; //建立一颗空的二叉搜索树
void CreateBinaryT(int p[],int left,int right,int TRoot);
int main(){
    ifstream sin("a.txt");
    int n,i;
    int p[max];
    while (sin >>n){
        T->last = n;
        for (i = 0; i < n; i++)
            sin >> p[i];
        sort(p, p + n);
        CreateBinaryT(p, 0, n - 1,0); //树的根节点在下标为0的位置开始
        for (i = 0; i < T->last; i++)
            cout << T->a[i] << " "; //层序输出
        cout << endl;
    }
    return 0;
}
int Getleftson(int n){/*此函数计算左子树结点个数*/
    int l, h, i;
    for (i = 0; pow(2, i) <= n; i++);
    h = i - 1;; //计算log(n+1)的下届
    l = n + 1 - pow(2, h);
    if (l>pow(2, h - 1))
        return pow(2, h) - 1;
    else
        return n - pow(2, h - 1);
}
void CreateBinaryT(int p[], int left, int right,int TRoot){
    int n = right - left + 1;
    if (n == 0)
        return; //p中没有元素要处理是递归出口
    int l = Getleftson(right - left + 1); //获得左子树节点个数
    T->a[TRoot] = p[left + l];
    CreateBinaryT(p, left, left + l - 1,TRoot*2+1); //左子树递归
    CreateBinaryT(p, left + l + 1, right,TRoot*2+2); //右子树递归
}