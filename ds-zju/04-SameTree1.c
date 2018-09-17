/*中国大学MOOC-陈越、何钦铭-数据结构-2018春
 * 04-树4 是否同一棵二叉搜索树（25 分）
 * 动态存贮模式
 * wirte by xucaimao,2018-04-02
 * 提交只得17分，最大N多组合没有通过
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

int Comp(BinTree Ts,BinTree Tt){
    if(Ts==NULL && Tt==NULL)return 1;//二者都空
    else if(Ts==NULL && Tt)return 0;//有一个非空
    else if(Tt==NULL && Ts)return 0;//有一个非空
    else if(Ts->Data != Tt->Data)//二者都非空，但是节点值不同
        return 0;
    else if( Comp(Ts->Left,Tt->Left) && Comp(Ts->Right,Tt->Right) )
        return 1;
}
//删除二叉树释放所有节点空间
void Destroy( BinTree BT){
    //后续遍历删除节点
    if(BT==NULL)return;
    Destroy(BT->Left);
    Destroy(BT->Right);
    free(BT);
}

void InorderTraversal( BinTree BT ){
    if(BT==NULL)return;
    InorderTraversal(BT->Left);
    printf(" %d",BT->Data);
    InorderTraversal(BT->Right);
}
//向二叉树插入节点，递归程序
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

int main() {
    freopen("F:\\xcmprogram\\netlesson\\ds-zju\\in.txt","r",stdin);
    BinTree Ts, Tt;
    ElementType X;
    int N, L;

    Ts = NULL;
    Tt = NULL;
    scanf("%d", &N);
    while(N){
        Destroy(Ts);
        Ts= NULL;
        scanf("%d", &L);
        for (int i=0; i<N; i++ ) {//读入第一行数据并建立原始树
            scanf("%d", &X);
            Ts = Insert(Ts, X);
        }
//        printf("source : ");
//        InorderTraversal(Ts);
//        printf("\n");
        for(int k=0;k<L;k++ ){//读入L组待比较数据
            Destroy(Tt);
            Tt= NULL;
            for (int i=0; i<N; i++ ) {//读入一组待比较数据并建树
                scanf("%d", &X);
                Tt = Insert(Tt, X);
            }
//            printf("target : ");
//            InorderTraversal(Ts);
//            printf("\n");
            int ans=Comp(Ts,Tt);
            if(ans)printf("Yes\n");
            else printf("No\n");
        }
        scanf("%d", &N);
    }
    return 0;
}

