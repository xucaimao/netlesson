

/*中国大学MOOC-陈越、何钦铭-数据结构-2018春
 * 栈的应用--表达式计算
 * 严蔚敏《数据结构C语言版》P52
 * write by xucaimao,2018-03-19
 * 用数组模拟栈
 * */
#include <stdio.h>
#include <stdlib.h>
#define MAXN 100010
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -2
#define OVERFLOW -2

typedef int Status;
typedef int ElementType;
struct St{
    ElementType Data[MAXN];
    int capacity,top;
};
typedef struct St Stack;

Status InitStack(Stack * s){
    if(!s)
        return ERROR;
    s->.top=-1;
    s->capacity=MAXN;
    return OK;
}

Status StackEmpty(Stack * s){
    if(s->top==-1)
        return TRUE;
    else
        return FALSE;
}

Status GetTop(Stack * s,ElementType * e){
    if(s->top == -1)
        return ERROR;
    *e=s->Data[s->top];
    return OK;
}

Status Push(Stack * s,ElementType e){
    if(s->top < s->capacity-1){
        s->top++;
        s->Data[s->top]=e;
        return OK;
    }
    return OVERFLOW;
}

Status Pop(Stack * s,ElementType * e){
    if(s->top >=0){
        *e=s->Data[s->top];
        s->top--;
        return OK;
    }
    return INFEASIBLE;
}

//字符串转int
int str2int(char s[],int n){
    if(s[0]=='-') return -1;
    int num=0;
    for(int i=0;i<n;i++)
        num=num*10+(s[i]-'0');
    return num;
}

//判断字符c是否为系统能识别的运算符
Status In(char c,char op[]){
    char * p=op;
    while(*p !='\0'){
        if(c==*p)return TRUE;
    }
    return FALSE;
}

//比较运算符a与b的优先级，返回 > = <
char Precede(char a,char b){

}

int main() {
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);

    return 0;
}
