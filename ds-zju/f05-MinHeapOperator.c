/*中国大学MOOC-陈越、何钦铭-数据结构-2018秋
 * 最小二叉堆
 * wirte by xucaimao,2018-10-07
 * 增加了通过数组初始化堆的程序，实现了堆的树形打印
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define maxSize 1010

typedef int ElementType;
typedef struct{
    int capacity;//堆的容量
    int size;   //堆的有效元素数量
    ElementType data[maxSize];
}MinHeap;

int myLog2(int x){
    int ret=0;
    while ( x > 1 ) {
        x /= 2;
        ret ++;
    }
    return ret;
}


MinHeap* initHeap(){
    MinHeap* heap=malloc(sizeof(MinHeap));
    heap->size=0;
    heap->capacity=maxSize-1;
    return heap;
}

void insertHeap(MinHeap* heap,ElementType x){
    if(heap->size>=heap->capacity){
        printf("heap is full!\n");
        return;
    }
    heap->data[0]=x;    //哨兵位置
    //实现上滤过程
    int hole=++heap->size;
    for(;heap->data[hole/2]>x;hole/=2)
        heap->data[hole]=heap->data[hole/2];
    heap->data[hole]=x;
}



//下滤
void percolateDown(MinHeap* heap,int hole){
    int child;
    ElementType t=heap->data[hole];
    //hole*2指向hole的左孩子，先判断左孩子是否存在
    while(hole*2 <= heap->size){
        //存在左孩子，child指向左孩子
        child=hole*2;
        //child < heap->size 最极端的情况是child==heap->size-1,此时child+1(右孩子)才有意义
        if( child < heap->size && heap->data[child+1]<heap->data[child] )
            child++;    //point to right child

        if(heap->data[child]<t){
            heap->data[hole]=heap->data[child];
            hole=child;
        }
        else
            break;
    }
    heap->data[hole]=t;
}

//用一个包含n个元素的数组arr，初始化堆
void initHeapWithArray(MinHeap* heap,ElementType * arr,int n){
    for(int i=0;i<n;i++)
        heap->data[i+1]=arr[i];
    heap->size=n;
    //从第一个非叶子节点开始执行下滤操作
    for(int i=n/2;i>=1;i--)
        percolateDown(heap,i);
}

//删除堆顶元素
void deleteMinMin(MinHeap* heap){
    if(heap->size==0){
        printf("heap is empty!!!\n");
        return;
    }
    heap->data[1]=heap->data[heap->size--];
    percolateDown(heap,1);
}
//打印节点i到堆顶的路径
void printHeapPath(MinHeap* heap,int i){
    if(i>heap->size){
        printf("Error\n");
        return;
    }
    int j=i;
    for(;j>=1;j/=2){
        if(j<i)printf(" ");
        printf("%d",heap->data[j]);
    }
    printf("\n");
}

//使用层序遍历，打印树形堆，堆中元素不要超过两位数
void printHeap(MinHeap* heap){
    int dw=2;//数字显示宽度
    int ds=2;//数字间距
    int treeHeight=myLog2(heap->size);
    int dp=1;//指向当前打印的元素在数组中的下标
    int width=pow(2,treeHeight)*dw+ (pow(2,treeHeight)-1)*ds;//计算最底层的最大宽度
    for(int h=0;h<=treeHeight && dp<=heap->size;h++){//按层打印
        int numOfLevel=pow(2,h);
        if(h>0){
            int ddp=dp;
            for(int i=0;i<(width-dw)/2;i++)
                printf(" ");//打印行前空格
            for(int n=1;n<=numOfLevel && ddp<=heap->size;){//每层最多有n个节点
                if(n%2 ==1) printf(" /"); //打印连接符号
                else printf(" \\");
                ddp++;
                n++;
                if(n>1 && n<=numOfLevel){
                    for(int i=0;i<width;i++)
                        printf(" ");//
                }
            }
            printf("\n");   //每层末尾打印回车
        }
        for(int i=0;i<(width-dw)/2;i++)
            printf(" ");//打印行前空格
        for(int n=1;n<=numOfLevel && dp<=heap->size;){//每层最多有n个节点
            printf("%2d",heap->data[dp++]);
            n++;
            if(n>1 && n<=numOfLevel){
                for(int i=0;i<width;i++)
                    printf(" ");//
            }
        }
        width=(width-dw)/2;
        printf("\n");   //每层末尾打印回车
    }

}



int main(){
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    int N,M;
    ElementType inputNum[20];
    scanf("%d %d",&N,&M);
    MinHeap* h=initHeap();
    for(int i=0;i<N;i++){
        scanf("%d",&inputNum[i]);
        insertHeap(h,inputNum[i]);
    }
    printf("After insert init , the tree is: \n");
    printHeap(h);


    MinHeap* h2=initHeap();
    initHeapWithArray(h2,inputNum,N);
    printf("After array init , the tree is: \n");
    printHeap(h2);


//    int aa=h->size;
//    for(int i=1;i<aa;i++){
//        deleteMinMin(h);
//        printf("After delete min,the tree is: \n");
//        printHeap(h);
//    }

//    for(int i=0;i<M;i++){
//        ElementType d;
//        scanf("%d",&d);
//        printHeapPath(h,d);
//    }
    return 0;
}