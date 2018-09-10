//中国大学MOOC-陈越、何钦铭-数据结构-2018春
// 02-线性结构4 Pop Sequence（25 分）
// write by xucaimao,2018-03-17
// 采用数组模拟栈

#include <stdio.h>
#include <stdlib.h>

#define MAXN 1010
#define ERROR -1
#define OK 0
typedef int Status;

typedef struct {
    int data[MAXN];
    int top,size;
}Stack;

Stack st;
int targ[MAXN];//数据

int M,N,K;

//初始化容量为n的堆栈
void InitStack(int n){
    for(int i=0;i<n;i++)
        st.data[i]=0;
    st.top=-1;
    st.size=n;
}

Status Push(int d){
    if(st.top<st.size){
        st.top++;
        st.data[st.top]=d;
        return OK;
    }
    else
        return ERROR;
}
//元素出栈
Status Pop(){
    if(st.top>=0){
        st.top--;
        return OK;
    }
    else
        return ERROR;
}

//取栈顶元素，但是元素不出栈
int Top(){
    int ans=-1;
    if(st.top>=0){
        ans=st.data[st.top];
    }
    return ans;
}
//返回栈内现有元素个数
int StackSize(){
    return st.top+1;
}

//对存放在输出队列arr[0...n-1]中的n个数据，判断
// 当我们遇见输出x时，则要考虑的是x前的元素，即小于等于x的元素都先push栈，才会有pop x；
// 1。栈为空时，判断需要填入的数 是否小于 栈的容量(即M)
// 2。若后一个数比前一个数大，又要push其之前的数 再判断　
// 3。若后一个数比前一个数小，则要判断栈顶元素是否与其相等
int Check(int arr[],int n){
    int p=0;//指向arr中待比较的数字的位置
    int num=1;//准备入栈的数字
    Push(num);
    num++;
    while(p<n){
        while(arr[p]>Top() && StackSize()<M){
            //待比较的数比栈顶数字大 && 栈还有空间
            Push(num);
            num++;
        }
        if(arr[p]==Top()){
            Pop();
            p++;
        }
        else
            return 0;
    }
    return 1;
}

int main(){
    freopen("F:\\xcmprogram\\netlesson\\ds-zju\\in.txt","r",stdin);
    scanf("%d%d%d",&M,&N,&K);
    for(int i=0;i<K;i++){//处理K行数据
        InitStack(M);
        for(int j=0;j<N;j++)//读取每行的N个数据
            scanf("%d",&targ[j]);

        int ans=Check(targ,N);
        if(ans)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}