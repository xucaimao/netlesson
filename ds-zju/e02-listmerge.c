/*中国大学MOOC-陈越、何钦铭-数据结构-2018春
 * 02-线性结构1 两个有序链表序列的合并（15 分）
 * write by xucaimao,2018-03-12
 * 注意这一句：应直接使用原序列中的结点
 * */


#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node * PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    //freopen("F:\\xcmprogram\\clion\\linklist\\in.txt","r",stdin);
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Read(){
    List Head=(List)malloc(sizeof(struct Node));//生成头结点,L指向头结点
    Head->Next=NULL;
    List Tail=Head;//初始化尾结点
    int n,m;
    scanf("%d",&n);
    while(n--){
        List Nd=(List)malloc(sizeof(struct Node));//生成数据结点
        scanf("%d",&m);
        Nd->Data=m;
        Nd->Next=NULL;
        Tail->Next=Nd;
        Tail=Nd;
    }
    return Head;
}

void Print( List L ){
    List P=L->Next;//指向第一个结点
    if(P==NULL){
        printf("NULL\n");
        return;
    }

    while(P){
        printf("%d ",P->Data);
        P=P->Next;
    }
    printf("\n");
}

List Merge( List L1, List L2 ){
    List Head=(List)malloc(sizeof(struct Node));    //初始化头结点
    Head->Next=NULL;
    List Tail=Head;                                 //初始化尾结点
    List P1=L1->Next,P2=L2->Next;                   //指向第一个数据结点
    while(P1 && P2){
        if(P1->Data <= P2->Data){
            Tail->Next=P1;
            Tail=P1;
            P1=P1->Next;
        }
        else{
            Tail->Next=P2;
            Tail=P2;
            P2=P2->Next;
        }
    }
    if (P1) Tail->Next=P1;
    if (P2) Tail->Next=P2;
    L1->Next=NULL;
    L2->Next=NULL;
    return Head;
}
