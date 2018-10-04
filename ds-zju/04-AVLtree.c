/*中国大学MOOC-陈越、何钦铭-数据结构-2018秋
 * AVL树的实现
 * wirte by xucaimao,2018-10-04
 * 采用维基百科上的定义：树的高度为最大层次。即空的二叉树的高度是0，
 * 非空树的高度等于它的最大层次(根的层次为1，根的子节点为第2层，依次类推)。
 * 树叶的高度为0;节点的高度，是从该节点到，以该节点为根的树叶，的路径长度的最大值。
 * todo
 * */
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct AVLNode{
    ElementType Data;
    int Height;
    struct AVLNode* Left;
    struct AVLNode* Right;
}Node,*AVLTree;

//生成一个节点
Node* AVLCreatNode(ElementType d,Node* left,Node* right){
    Node* p;
    if( (p=(Node*)malloc(sizeof(Node)))==NULL )
        return NULL;
    p->Right=right;
    p->Left=left;
    p->Data=d;
    return p;
}

int Max(int a,int b){
    return a>b ? a:b;
}

int height(AVLTree t){
    if(t==NULL)return 0;
    else return t->Height;
}
//对失去平衡的AVL根节点k2，执行ll旋转，返回新的根节点
Node* AVL_LeftLeft(AVLTree k2){
    Node* k1;
    k1=k2->Left;
    k2->Left=k1->Right;
    k1->Right=k2;
    k2->Height=Max( height(k2->Left),height(k2->Right) )+1;
    k1->Height=Max( height(k1->Left),k2->Height )+1;
    return k1;
}
//对失去平衡的AVL根节点k2，执行rr旋转，返回新的根节点
Node* AVL_RightRight(AVLTree k1){
    Node* k2;
    k2=k1->Right;
    k1->Right=k2->Left;
    k2->Left=k1;
    k1->Height=Max( height(k1->Left),height(k1->Right) )+1;
    k2->Height=Max( k1->Height,height(k2->Right) )+1;
    return k2;
}