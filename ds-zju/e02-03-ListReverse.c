/*中国大学MOOC-陈越、何钦铭-数据结构-2018春
 * 02-线性结构3 Reversing Linked List（25 分）
 * 反转单链表，给定常数K和单链表L，要求按每K个节点反转单链表，如：L: 1->2->3->4->5->6 K=3,
 * 输出:3->2->1->6->5->4，如果K=4,输出：4->3->2->1->5->6.
 * write by xucaimao,2018-09-10测试通过
 * 采用静态链表来实现
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#define MAXN 100010
struct Nod{
    int value;
    int next;
};

int N,K;
int Head=MAXN-1;//Head为头节点在结构数组中的下标
struct Nod data[MAXN];//静态链表,头结点放在数组最后一个元素

//字符串的前n位转为int
int str2int(char s[],int n){
    if(s[0]=='-') return -1;
    int num=0;
    for(int i=0;i<n;i++)
        num=num*10+(s[i]-'0');
    return num;
}

//读数据并初始化链表
void ReadList(){
    char address[10];
    scanf("%s",address);
    data[Head].next=str2int(address,5);//头结点赋值
    scanf("%d%d",&N,&K);
    getchar();//忽略行尾空格
    struct Nod node;
    int v,add;
    for(int i=1;i<=N;i++){
        scanf("%s",address);
        add=str2int(address,5);
        scanf("%d",&v);
        node.value=v;
        scanf("%s",address);
        node.next=str2int(address,5);
        data[add]=node;
    }
}
//打印链表
void PrintList(){
    int ptr=data[Head].next;
    while(ptr>=0){
        printf("%05d %d ",ptr,data[ptr].value);
        if(data[ptr].next==-1) printf("-1\n");
        else  printf("%05d\n",data[ptr].next);
        ptr=data[ptr].next;
    }
}
//用于反向的函数
//需要注意，读入的数据，有的节点可能不在链表上，因此需要重新统计有效的节点数
void ReverseList(){
    //统计有效的节点数
    int nodenum=0;
    int p=data[Head].next;
    while(p != -1){
        nodenum++;
        p=data[p].next;
    }
    //计算反转的段数
    int times=nodenum/K;

    int head=Head;//head指向第一个要翻转的节点的前驱
    while(times--){
        int pnew=data[head].next;
        int pold=data[pnew].next;
        int temp;
        int k=1;
        while(k<K){//开始反转结点
            temp=data[pold].next;
            data[pold].next=pnew;//后点指向前点
            //修改标记点
            pnew=pold;//向后移位
            pold=temp;//向后移位
            k++;
        }
        temp=data[head].next;
        data[ data[head].next ].next=pold;//修改原来第一结点的后续
        data[head].next=pnew;//修改头结点的后续
        head=temp;
    }

}

int main() {
//    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    ReadList();
//    PrintList();
    ReverseList();
//    printf("After reverse : \n");
    PrintList();
    return 0;
}
