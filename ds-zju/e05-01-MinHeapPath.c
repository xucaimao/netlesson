/*中国大学MOOC-陈越、何钦铭-数据结构-2018秋
 * 05-树7 堆中的路径 （25 分）
 * 最小二叉堆
 * wirte by xucaimao,2018-10-04
 * 提交通过
 * */
#include <stdio.h>
#include <stdlib.h>
#define maxSize 1010
typedef int ElementType;
typedef struct{
    int capacity;//堆的容量
    int size;   //堆的有效元素数量
    ElementType data[maxSize];
}MinHeap;

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

void printHeap(MinHeap* heap,int i){
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

int main(){
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    int N,M;
    scanf("%d %d",&N,&M);
    MinHeap* h=initHeap();
    for(int i=0;i<N;i++){
        ElementType d;
        scanf("%d",&d);
        insertHeap(h,d);
    }
    for(int i=0;i<M;i++){
        ElementType d;
        scanf("%d",&d);
        printHeap(h,d);
    }
    return 0;
}
