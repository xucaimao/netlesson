/*中国大学MOOC-陈越、何钦铭-数据结构-2018秋
 * 04-树4 是否同一棵二叉搜索树（25 分）
 * 动态存贮模式
 * wirte by xucaimao,2018-10-03
 * 提交通过
 * */
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
void DeleteTree(BinTree BST){
    if(BST){
        DeleteTree(BST->Left);
        DeleteTree(BST->Right);
        free(BST);
    }
}

//判断两个树a、b是否为同相同的二叉树，相同返回1，否则返回0
int sameTree(BinTree ta,BinTree tb){
    if(ta==NULL && tb==NULL) return 1;
    else if(ta && !tb)return 0;
    else if(tb && !ta)return 0;
    else {    //两棵树根都非空
        if(ta->Data == tb->Data)
            return sameTree(ta->Left,tb->Left) && sameTree(ta->Right,tb->Right);
        else return 0;
    }
}

void PreorderTraversal( BinTree BT ){
    if(BT){
        printf(" %d",BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}

int main(){
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    int nodeNum,treeNum;
    while( scanf("%d",&nodeNum) && nodeNum){
        scanf("%d",&treeNum);
        BinTree ta;
        ta=NULL;
        for(int i=0;i<nodeNum;i++){ //读入原始树
            ElementType d;
            scanf("%d",&d);
            ta=Insert(ta,d);
        }
//        printf("The tree a is: ");
//        PreorderTraversal(ta); printf("\n");
        for(int i=0;i<treeNum;i++){ //读入待比较树
            BinTree tb;
            tb=NULL;
            for(int i=0;i<nodeNum;i++){
                ElementType d;
                scanf("%d",&d);
                tb=Insert(tb,d);
            }
//            printf("The tree b is: ");
//            PreorderTraversal(tb);printf("\n");
            if(sameTree(ta,tb))printf("Yes\n");
            else printf("No\n");
            DeleteTree(tb);
        }
        DeleteTree(ta);
    }
    return 0;
}
