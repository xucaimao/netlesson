/*中国大学MOOC-陈越、何钦铭-数据结构-2018春
 * 03-树1 树的同构（25 分）
 * 用结构数组表示二叉树
 * wirte by xucaimao,2018-03-25
 * */

#include <stdio.h>
#include <string.h>
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode{
    ElementType value;
    Tree left;
    Tree right;
}Ta[MaxTree],Tb[MaxTree];

int stat[10];//用于标识该节点有没有父亲节点，如果没有则说明该节点是根节点

//输入数据存储入数组,返回树根在数组中的下标
Tree BuildTree(struct TreeNode T[]){
    int N;
    Tree root=Null;
    char l,r;
    scanf("%d\n",&N);
    memset(stat,0, sizeof(stat));
    for(int i=0;i<N;i++){
        scanf("%c %c %c\n",&T[i].value,&l,&r);
        T[i].left =l-'0';
        if(T[i].left<0) T[i].left=Null;
        else stat[T[i].left]=1;
        T[i].right=r-'0';
        if(T[i].right<0) T[i].right=Null;
        else stat[T[i].right]=1;
    }
    for(int i=0;i<N;i++){
        if(stat[i]==0){
            root=i;
            break;
        }
    }
    return root;
}

int Isomorphic(Tree ra,Tree rb){
    //递归方法
    if(ra==Null && rb==Null)//两棵空树
        return 1;
    if( (ra==Null && rb!=Null) || (ra!=Null && rb==Null))//一棵为空另一棵非空
        return 0;
    if(Ta[ra].value != Tb[rb].value)//根节点不相同
        return 0;
    if(Ta[ra].left==Null && Tb[rb].left==Null)
        //两棵树的左子树都为空，则看它们的右子树是否同构
        return Isomorphic(Ta[ra].right,Tb[rb].right);
    if(Ta[ra].left!=Null && Tb[rb].left!=Null &&
       Ta[Ta[ra].left].value==Tb[Tb[rb].left].value)
        //两棵树的左子树都非空，且它们的左子树的根节点相同
        //看它们的左子树同构，且右子树也需要同构
        return (Isomorphic( Ta[ra].left,Tb[rb].left ) &&
                Isomorphic( Ta[ra].right,Tb[rb].right) );
    else
        //两棵树的左子树都非空，且它们的左子树的根节点不相同
        //左子树与右子树有一个非空
        //交叉判断
        return (Isomorphic( Ta[ra].left,Tb[rb].right ) &&
                Isomorphic( Ta[ra].right,Tb[rb].left) );
}

int main(){
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    Tree R1,R2;
    R1=BuildTree(Ta);
    //printf("The root is %d\n",R1);
    R2=BuildTree(Tb);
    //printf("The root is %d\n",R2);
    if(Isomorphic(R1,R2)) printf("Yes\n");
    else printf("No\n");

    return 0;
}