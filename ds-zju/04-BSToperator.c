
/*中国大学MOOC-陈越、何钦铭-数据结构-2018春
 * 04-树7 二叉搜索树的操作集（30 分）
 * 动态存贮模式
 * wirte by xucaimao,2018-04-01
 * */

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
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

int main() {
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {//建树
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);//需要查找的数据的数量
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

void PreorderTraversal( BinTree BT ){
    if(BT==NULL)return;
    printf(" %d",BT->Data);
    PreorderTraversal(BT->Left);
    PreorderTraversal(BT->Right);
}
void InorderTraversal( BinTree BT ){
    if(BT==NULL)return;
    InorderTraversal(BT->Left);
    printf(" %d",BT->Data);
    InorderTraversal(BT->Right);
}

/* 你的代码将被嵌在这里 */
BinTree Insert( BinTree BST, ElementType X ){
    if(BST==NULL){
        BST=(Position)malloc(sizeof(struct TNode));
        BST->Data=X;
        BST->Left=NULL;
        BST->Right=NULL;
    }
    else{
        if(X<BST->Data)
            BST->Left=Insert(BST->Left,X);
        if(X>BST->Data)
            BST->Right=Insert(BST->Right,X);
    }
    return BST;
}

Position FindMin( BinTree BST ){
    if(BST==NULL)return NULL;
    while(BST->Left)
        BST=BST->Left;
    return BST;
}

Position FindMax( BinTree BST ){
    if(BST==NULL)return NULL;
    while(BST->Right)
        BST=BST->Right;
    return BST;
}

Position Find( BinTree BST, ElementType X ){
    while(BST){
        if(X > BST->Data)
            BST=BST->Right;
        else if(X < BST->Data)
            BST=BST->Left;
        else
            return BST;
    }
    return NULL;
}

BinTree Delete( BinTree BST, ElementType X ){
    Position Tmp;
    if(!BST) printf("Not Found\n");
    else if(X < BST->Data)
        BST->Left=Delete(BST->Left,X);
    else if(X > BST->Data)
        BST->Right=Delete(BST->Right,X);
    else{//找到节点
        if(BST->Right && BST->Left){//被删除的节点同时有左右子节点
            //也可以采用找左子树中最大值的方法
            Tmp=FindMin(BST->Right);//找右子树中的最小节点
            BST->Data=Tmp->Data;//右子树最小节点的值赋给当前节点
            BST->Right=Delete(BST->Right,Tmp->Data);//删除右子树中的最小节点
        }
        else{//被删除的节点只有一个左子节点或者右子节点
            Tmp=BST;
            if(BST->Left==NULL)
                BST=BST->Right;
            else if(BST->Right==NULL)
                BST=BST->Left;
            free(Tmp);
        }
    }
    return BST;
}

