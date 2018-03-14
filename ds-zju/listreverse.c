/*中国大学MOOC-陈越、何钦铭-数据结构-2018春
 * 02-线性结构3 Reversing Linked List（25 分）
 * write by xucaimao,2018-03-12
 * 采用静态链表来实现
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#define MAXN 100010
struct Nod{
    int add;
    int value;
    int next;
};

int N,K;
int Head=MAXN-1;//Head为头指针
struct Nod data[MAXN];//静态链表,头结点放在数组最后一个元素

//字符串转int
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
//打印链表
void PrintList(){
    int ptr=data[Head].next;
    while(ptr>=0){
        printf("%05d %d ",data[ptr].add,data[ptr].value);
        if(data[ptr].next==-1) printf("-1\n");
        else  printf("%05d\n",data[ptr].next);
        ptr=data[ptr].next;
    }
}
//用于反向的函数
void ReverseList(){
    if(N==1 || K==1)return;
    //定义标记点
    int pre=data[Head].next,p=data[pre].next;
    int pnext=data[p].next;
    int tail=data[Head].next;//指向反向段的尾
    int k=K;
    while(k>1){//开始反向结点
        data[p].next=data[pre].add;//后点指向前点
        //修改标记点
        pre=data[p].add;
        if(pnext>=0){//pnext==-1到表尾,防止越界
            p=data[pnext].add;
            pnext=data[pnext].next;
        }
        k--;
    }
    //修改头结点
    data[Head].next=data[pre].add;
    //连接反向段与剩余段
    if(pnext==-1)data[tail].next=-1;
    else data[tail].next=data[p].add;
}

int main() {
    //freopen("F:\\xcmprogram\\clion\\reverselink\\in.txt","r",stdin);
    ReadList();
    //PrintList();
    ReverseList();
    //printf("After reverse : \n");
    PrintList();
    return 0;
}