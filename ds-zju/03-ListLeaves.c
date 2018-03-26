/*中国大学MOOC-陈越、何钦铭-数据结构-2018春
 * 03-树2 List Leaves（25 分）
 * 用结构数组表示二叉树
 * wirte by xucaimao,2018-03-25
 * */

#include <stdio.h>
#include <string.h>
#define MaxTree 10
#define Tree int
#define Null -1

struct TreeNode{
    Tree add;
    Tree left;
    Tree right;
}T[MaxTree];

int stat[10];//用于标识该节点有没有父亲节点，如果没有则说明该节点是根节点
int leafnum=0;//用于记录叶子节点的数量，并用于控制打印格式

//简易的队列
struct List{
    struct TreeNode data[MaxTree+5];
    int head,tail;
};

//输入数据存储入数组,返回树根在数组中的下标
Tree BuildTree(struct TreeNode T[]){
    int N;
    Tree root=Null;
    char l,r;
    scanf("%d\n",&N);
    memset(stat,0, sizeof(stat));
    for(int i=0;i<N;i++){
        T[i].add =i;
        scanf("%c %c\n",&l,&r);
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


//层次遍历以r为根节点的树T，输出叶子节点
void bfs(struct TreeNode T[],Tree root){
    struct List L;
    L.data[0]=T[root];//树根节点入队列
    L.head=0;
    L.tail=1;
    while (L.head<L.tail){//队列非空
        struct TreeNode nod=L.data[L.head];//取队头元素
        L.head++;
        if(nod.left==Null && nod.right==Null){//是叶子节点
            if(leafnum>0) printf(" ");
            printf("%d",nod.add);
            leafnum++;
        }
        if(nod.left!=Null){//左孩子非空，入队
            L.data[L.tail]=T[nod.left];
            L.tail++;
        }
        if(nod.right!=Null){//左孩子非空，入队
            L.data[L.tail]=T[nod.right];
            L.tail++;
        }
    }
    printf("\n");
}

int main(){
    //freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    Tree R1;
    R1=BuildTree(T);
    //printf("The root is %d\n",R1);
    bfs(T,R1);
    return 0;
}

