// 程序设计与算法（三）期末考试(2018秋季)
// 005:编程填空：又是MyClass
// Created by Administrator on 2018-11-10.
// 考察类中动态分配内存空间的初始化、运算符重载
/*
 输入
 第一行是整数t表示数据组数
 每组数据有两行
 第一行开头是整数m，然后后面是m个整数(5 < m < 30)
 第二行是一个没有空格的字符串，长度不超过50
 输出
 对每组数据 先输出m个整数中的第5个，然后输出字符串中的第7个字符。
 "第i个"中的 i 是从0开始算的。
 * */

#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;
// 在此处补充你的代码
template <typename T>
class CMyClass{
private:
    T * data;
public:
    CMyClass(T arr[],int size):data(new T[size]){
        for(int i=0;i<size;i++)
            data[i]=arr[i];
    }
    ~CMyClass(){
        delete []data;
    }
    T operator[](int i){
        return data[i];
    }
};

int  a[40];
int main(int argc, char** argv) {
    freopen("/Users/xcm/xcmprogram/netlesson/pa3/in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while ( t -- ) {
        int m;
        scanf("%d",&m);
        for (int i = 0;i < m; ++i)
            scanf("%d",a+i);
        char s[100];
        scanf("%s",s);
        CMyClass<int> b(a, m);
        CMyClass<char> c(s, strlen(s));
        printf("%d %c\n", b[5], c[7]);
    }
    return 0;
}