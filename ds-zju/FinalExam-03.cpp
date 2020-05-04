/* 给定的一棵二叉树的后序遍历和中序遍历结果，输出该树的先序遍历结果
 *
 * */
#include <iostream>
using namespace std;
const int maxN=32;
int pre[maxN],in[maxN],post[maxN];
//post[]中，以postL为起点的n个元素；in[]中，以inL为起点的n个元素
//pre[]中，以preL为起点的n个元素
void solve(int postL,int inL,int preL,int n){
    if(n==0)return;
    int root=post[postL+n-1];
    if(n==1){
        pre[preL]=root;
        return;
    }
    pre[preL]=root;//记录根节点
    int i;
    for(i=0;i<n && in[inL+i] != root;i++);
    //通过查找树根在in[]中的位置，得到左右子树的节点数量
    int numOfLeftTree=i;
    int numOfRightTree=n-numOfLeftTree-1;
    //递归调用左子树
    solve(postL,inL,preL+1,numOfLeftTree);
    //递归调用右子树
    solve(postL+numOfLeftTree,inL+numOfLeftTree+1,preL+numOfLeftTree+1,numOfRightTree);
}

int main(){
    freopen("in.txt","r",stdin);
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>post[i];
    for(int i=0;i<N;i++)
        cin>>in[i];
    solve(0,0,0,N);
    cout<<"Preorder:";
    for(int i=0;i<N;i++)
        cout<<" "<<pre[i];

    return 0;
}