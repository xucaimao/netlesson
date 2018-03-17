/*中国大学MOOC-陈越、何钦铭-数据结构-2018春
 * 编程作业程序
 * 把后面的程序粘贴进来，就可以修改编译
 * */

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
    int d,add;
    for(int i=1;i<=N;i++){
        scanf("%s",address);
        add=str2int(address,5);
        scanf("%d",&d);
        node.value=d;
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
void ReverseList(){
    //定义标记点
    int pnew=data[Head].next,pold=data[pnew].next;
    int temp;

    int k=1;
    while(k<K){//开始反向结点
        temp=data[pold].next;
        data[pold].next=pnew;//后点指向前点
        //修改标记点
        pnew=pold;//向后移位
        pold=temp;//向后移位
        k++;
    }
    //修改头结点
    data[ data[Head].next ].next=pold;//修改原来第一结点的后续
    data[Head].next=pnew;
}

int main() {
    freopen("F:\\xcmprogram\\netlesson\\ds-zju\\in.txt","r",stdin);
    ReadList();
    PrintList();
    ReverseList();
    printf("After reverse : \n");
    PrintList();
    return 0;
}
