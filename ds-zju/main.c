/*中国大学MOOC-陈越、何钦铭-数据结构-2018春
 * 编程作业程序
 * 把后面的程序粘贴进来，就可以修改编译
 * */

//中国大学MOOC-陈越、何钦铭-数据结构-2018春
// 02-线性结构4 Pop Sequence（25 分）
// write by xucaimao,2018-03-15
// 采用数组模拟栈
// 当我们遇见输出x时，则要考虑的是x前的元素，即小于等于x的元素都先push栈，才会有pop x；
// 1。栈为空时，判断需要填入的数 是否小于 栈的容量(即M)
// 2。若后一个数比前一个数大，又要push其之前的数 再判断　
// 3。若后一个数比前一个数小，则要判断栈顶元素是否与其相等

#include <stdio.h>
#include <stdlib.h>

#define MAXN 1010
#define ERROR -1
#define OK 0

typedef struct Stack{
    int data[MAXN];
    int top,size;
}Stack;

Stack st;
int targ[MAXN];//数据

int M,N,K;

void InitStack(int n){
    for(int i=0;i<n;i++)
        st.data[i]=0;
    st.size=MAXN;
    st.top=-1;
    st.size=n;
}

int Push(int d){
    if(st.top<st.size){
        st.top++;
        st.data[st.top]=d;
        return OK;
    }
    else
        return ERROR;
}

int Pop(int * d){
    if(st.top>=0){
        *d=st.data[st.top];
        st.top--;
        return OK;
    }
    else
        return ERROR;
}

//取栈顶元素，但是元素不出栈
int GetTop(int * d){
    if(st.top>=0){
        *d=st.data[st.top];
        return OK;
    }
    else
        return ERROR;
}

//对存放在输出队列arr[]中的n个数据，判断
int Check(int arr[],int n){
    int p=0;//指向arr中元素的位置
    Push(1);
    while(p<n){
        while(arr[p]>)
    }
}

int main(){
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    scanf("%d%d%d",&M,&N,&K);
    printf("M=%d N=%d K=%d\n",M,N,K);
    for(int i=0;i<K;i++){//处理K行数据
        InitStack(M);
        for(int j=0;j<N;j++)//读取每行的N个数据
            scanf("%d",&targ[j]);
        for(int j=0;j<N;j++)
            printf("%d ",targ[j]);
        printf("\n");
        int ans=Check(targ,N);
        if(ans)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}