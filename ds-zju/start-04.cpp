//中国大学MOOC-陈越、何钦铭-数据结构-起步能力自测题
//自测-4 Have Fun with Numbers
//20位数，超过了unsigned long long int的范围，必须采用自定义的乘法函数
//输入一个数字X，X乘以2后得到的数字Y，如果Y就是X的各位上的数字重新排列后的结果
//也就是说，假如X中有三个‘1’，Y中也只能有三个'1'，只是排列的位置可以不同
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

bool check(char * s,char * t){
    int ls=strlen(s);
    int lt=strlen(t);
    if(ls!=lt)
        return false;
    int dig[10]={0};
    char *ps=s;
    char *pt=t;
    for(int i=0;i<ls;i++){
        dig[*(ps+i)-'0']++;
        dig[*(pt+i)-'0']--;
    }
    for(int i=0;i<10;i++){
        if(dig[i]!=0)return false;
    }
    return true;
}

//字符串形式的数字乘2，t=s*2
void StrNumDouble(char * s,char * t){
    int ls=strlen(s);
    int lt=0;                                   //目标字符串的长度
    char *ps=s+ls-1;                            //ps指向源串数字低位(字符串最后一位)
    char *pt=t;
    int inc=0;                                  //进位标志
    //开始乘法操作，结果倒序存放在tar字符数组中
    for(int i=ls;i>0;i--){
        *pt= ( (*ps-'0')*2 + inc )%10+'0';
        inc=( (*ps-'0')*2 + inc )/10;
        pt++;
        lt++;
        ps--;
    }
    if(inc>0){          //处理最高位的进位
        *pt=inc+'0';
        pt++;
        lt++;
    }
    *pt='\0';
    //开始逆序操作
    char * p1=t;
    char * p2=t+lt-1;
    int swaptime=lt/2;
    for(int i=0;i<swaptime;i++){
        char t=*p1;
        *p1=*p2;
        *p2=t;
        p1++;p2--;
    }
}


int main() {
    char src[30],tar[30];
    scanf("%s",src);
    StrNumDouble(src,tar);

    if( check(src,tar) )
        printf("Yes\n");
    else
        printf("No\n");
    printf("%s",tar);
    return 0;
}