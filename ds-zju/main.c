/*中国大学MOOC-陈越、何钦铭-数据结构-2018春
 * 编程作业程序
 * 把后面的程序粘贴进来，就可以修改编译
 * */
//在输入格式中Push的过程就是二叉树前序遍历的结果，而Pop的过程及为二叉树的中序遍历的结果。
#include <stdio.h>
#include <string.h>
#define MaxTree 40

int preorder[MaxTree],p_pre=0;
int inorder[MaxTree],p_in=0;
int N;
//简易的栈
struct Stack{
    int data[MaxTree];
    int top;
    int size;
};

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
        if(p_in>0) printf(" ");
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

//根据前序preorder[l1...r1]和中序inorder[l2...r2]的数据建立二叉树，并返回树的根

int BuildTree(int l1,int r1,int l2,int r2){
    return 0;
}

int main(){
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    ReadTree();
    printf("\n");
    for(int i=0;i<N;i++)
        printf("%d ",preorder[i]);
    printf("\n");
    for(int i=0;i<N;i++)
        printf("%d ",inorder[i]);
    printf("\n");
    return 0;
}