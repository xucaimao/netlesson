/*中国大学MOOC-陈越、何钦铭-数据结构-2018春
 * 02-线性结构3 Reversing Linked List（25 分）
 * write by xucaimao,2018-03-12
 * 采用静态链表来实现
 * 注意:数据的位置不能改变
 * */
#include <stdio.h>
#include <stdlib.h>

#define MAXN 100010

struct Nod{
    int add;
    int value;
    int next;
};

int N,K,Head;//Head为头指针
struct Nod data[MAXN];//静态链表
struct Nod tmp[MAXN];//静态链表

int str2int(char s[],int n){
    if(s[0]=='-') return -1;
    int num=0;
    for(int i=0;i<n;i++)
        num=num*10+(s[i]-'0');
    return num;
}

void ReadList(){
    char address[10];
    scanf("%s",address);
    Head=str2int(address,5);
    scanf("%d%d",&N,&K);
    getchar();//行尾忽略空格
    struct Nod node;
    int d;
    for(int i=1;i<=N;i++){
        scanf("%s",address);
        node.add=str2int(address,5);
        scanf("%d",&d);
        node.value=d;
        scanf("%s",address);
        node.next=str2int(address,5);
        data[node.add]=node;
    }
}

void PrintList(struct Nod arr[]){
    int ptr=Head;
    while(ptr>=0){
        printf("%05d %d ",data[ptr].add,data[ptr].value);
        if(data[ptr].next==-1)printf("%d\n",data[ptr].next);
        else printf("%05d\n",data[ptr].next);
        ptr=data[ptr].next;
    }
    printf("\n");
}

void PrintTmp(struct Nod arr[],int n){
    int ptr=arr[0].next;
    for(int i=0;i<=n;i++){
        printf("%05d %d %05d\n",tmp[i].add,tmp[i].value,tmp[i].next);
    }
    printf("\n");
}

void ReverseList(struct Nod arr[]){

    int l=1,r=K;
    while(l<r){//交换元素
        int ptr=Head;
        tmp[0].next=Head;//虚拟头结点
        tmp[0].add=-1;
        tmp[0].value=-1;
        for(int i=1;i<=K;i++){//把链表按元素顺序放入一个辅助数组，便于后期交换数据
            tmp[i]=data[ptr];
            ptr=data[ptr].next;
        }
        printf("Data in temp before swap: \n");
        PrintTmp(tmp,K);

        int lnext=tmp[l].next;
        int lpre=l-1;
        int rnext=tmp[r].next;
        int rpre=r-1;

        tmp[lpre].next=tmp[r].add;
        tmp[r].next=lnext;
        tmp[rpre].next=tmp[l].add;
        tmp[l].next=rnext;

        l++;r--;
        printf("Data in temp after a swap : \n");
        PrintTmp(tmp,K);

        for(int i=1;i<=K;i++)//交换后的元素放回原来的静态链表
            data[tmp[i].add].value=tmp[i].value;
        Head=tmp[0].next;

    }

}

int main() {
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/reverselink/in.txt","r",stdin);
    ReadList();
    PrintList(data);
    ReverseList(data);
    printf("After reverse : \n");
    PrintList(data);
    return 0;
}