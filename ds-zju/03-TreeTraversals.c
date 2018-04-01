/*中国大学MOOC-陈越、何钦铭-数据结构-2018春
 * 编程作业程序
 * 03-树3 Tree Traversals Again
 * write by xucaimao,2018-03-26
 * */
//在输入格式中Push的过程就是二叉树前序遍历的结果，而Pop的过程及为二叉树的中序遍历的结果。
//前序序列第一个节点为根，后序序列最后一个节点为根
#include <stdio.h>
#include <string.h>
#define MaxTree 40
#define Null -1

int preorder[MaxTree],p_pre=0;
int inorder[MaxTree],p_in=0;
int N;
int numofnode=0;
//简易的栈
struct Stack{
    int data[MaxTree];
    int top;
    int size;
};

struct Node{
    int left,right;
};

struct Node tree[MaxTree];//静态数组表示树

void InitStack(struct Stack * s){
    s->top=0;
    s->size=0;
}

void Push(struct Stack * s,int n){
    s->top++;
    s->data[s->top]=n;
}
void Pop(struct Stack * s){
    if(s->top>=0){
        //if(p_in>0) printf(" ");
        //printf("%d",s->data[s->top]);
        inorder[p_in++]=s->data[s->top];
        s->top--;
    }
}

//根据数据建立树的前序序列preorder[]和中序序列inorder[]
void ReadTree(){
    struct Stack St;
    InitStack(&St);
    int num;
    char s[10];
    scanf("%d\n",&N);
    for(int i=0;i<2*N;i++){
        scanf("%s",s);
        if(s[1]=='u'){
            scanf("%d",&num);
            Push(&St,num);
            preorder[p_pre++]=num;
        }
        if(s[1]=='o'){
            Pop(&St);
        }
    }
}

//根据中序inorder[li...ri]和前序preorder[lp...rp]的数据建立二叉树，并返回树的根
//建立的二叉树以静态数组形式存在tree[]中
int BuildTree(int li,int ri,int lp,int rp){
    if(li>ri)//空树
        return Null;
    int root=preorder[lp];//找到当前树的根节点
    int p=li;
    while(inorder[p]!=root) //在中序序列中找到根节点
        p++;
    int cnt=p-li;//左子树的节点数
    //递归找到左子树的根
    tree[root].left=BuildTree(li,p-1,lp+1,lp+cnt);
    //递归找到右子树的根
    tree[root].right=BuildTree(p+1,ri,lp+cnt+1,rp);
    return root;
}

//后序遍历以root为根的静态树tree
void PostOrder(int root){
    if(root==Null)return;
    PostOrder(tree[root].left);
    PostOrder(tree[root].right);
    if(numofnode>0)printf(" ");
    printf("%d",root);
    numofnode++;
}

int main(){
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    ReadTree();
//    printf("\n");
//    for(int i=0;i<N;i++)
//        printf("%d ",preorder[i]);
//    printf("\n");
//    for(int i=0;i<N;i++)
//        printf("%d ",inorder[i]);
//    printf("\n");
    BuildTree(0,N-1,0,N-1);
    PostOrder(preorder[0]);
    return 0;
}