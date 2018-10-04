/*中国大学MOOC-陈越、何钦铭-数据结构-2018秋
 * 编程作业程序
 * 01--树7 二叉搜索树的操作集
 * write by xucaimao,2018-10-03
 * */

//函数Insert将X插入二叉搜索树BST并返回结果树的根结点指针；
//函数Delete将X从二叉搜索树BST中删除，并返回结果树的根结点指针；如果X不在树中，则打印一行Not Found并返回原树的根结点指针；
//函数Find在二叉搜索树BST中找到X，返回该结点的指针；如果找不到则返回空指针；
//函数FindMin返回二叉搜索树BST中最小元结点的指针；
//函数FindMax返回二叉搜索树BST中最大元结点的指针

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode * Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    printf("Inorder:"); InorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
/* 你的代码将被嵌在这里 */
BinTree Insert(BinTree BST,ElementType X){
    if(BST==NULL){  //当前节点为空，找到插入位置
        BST=(Position)malloc(sizeof(struct TNode));
        BST->Left=NULL;
        BST->Right=NULL;
        BST->Data=X;
    }
    else{
        if(X < BST->Data)
            BST->Left= Insert(BST->Left,X);
        if(X > BST->Data)
            BST->Right= Insert(BST->Right,X);
    }
    return BST;
}

Position FindMin( BinTree BST ){
    if(BST==NULL) return NULL;
    while(BST->Left)    //存在左子树，说明还不是最小值
        BST=BST->Left;
    return BST;
}

Position FindMax( BinTree BST ){
    if(BST==NULL)return NULL;
    while(BST->Right)   //存在右子树，说明还不是最大值
        BST=BST->Right;
    return BST;
}

Position Find( BinTree BST, ElementType X ){
    while(BST){
        if(X==BST->Data)return BST;
        else if(X>BST->Data)
            BST=BST->Right;
        else
            BST=BST->Left;
    }
    return NULL;
}

BinTree Delete( BinTree BST, ElementType X ){
    Position tp;
    if(BST == NULL)printf("Not Found\n");
    else if(X < BST->Data)         //在左子树中执行删除
        BST->Left=Delete(BST->Left,X);
    else if(X > BST->Data)    //在右子树中执行删除
        BST->Right=Delete(BST->Right,X);
    else{   //找到节点
        if(BST->Left && BST->Right){    //同时有左右儿子
            tp=FindMin(BST->Right);     //在右子树中找最小值
            BST->Data=tp->Data;         //节点值转移
            //上面的方法，对于数据成员为结构的情况，需要左相应的改变
            BST->Right=Delete(BST->Right,tp->Data); //在右子树中删除最小节点
        }
        else{   //只有一个孩子或者全空
            tp=BST;
            if(BST->Left == NULL)   //两个全空执行这一句
                BST=BST->Right;
            else if(BST->Right == NULL) //这里注意时else if,不能是if.
                //否则对于左边为空右边不空的情况，会导致执行错误
                BST=BST->Left;
            free(tp);
        }
    }
    return BST;
}

void PreorderTraversal( BinTree BT ){
    if(BT){
        printf(" %d",BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}

void InorderTraversal( BinTree BT ){
    if(BT){
        InorderTraversal(BT->Left);
        printf(" %d",BT->Data);
        InorderTraversal(BT->Right);
    }
}

