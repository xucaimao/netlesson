// 程序设计与算法（三）期末考试(2018秋季)
// 014:编程填空：又见模板
// Created by Administrator on 2018-11-10.
// 使用数组,很简单。但是提交通不过
//
/*
输入
第一行是整数n，表示有n组数据
每组数据有3行
第一行是10个整数
第二行是5个小数
第三行是4个不带空格的字符串，它们之间用空格分隔
输出
先输出10个整数里面的第三个
再输出5个小数的和 (不用考虑小数点后面几位，用cout直接输出即可）
再输出4个字符串连在一起的字符串
 * */

#include <iostream>
#include <string>
using namespace std;
// 在此处补充你的代码
template<typename T,int size>
class A{
public:
    T data[size];
    A(T * b){
        for(int i=0;i<size;i++)
            data[i]=b[i];
    }
    T operator[](int i){
        return data[i];
    }
    T sum(){
        T ans;
        for(int i=0;i<size;i++ )
            ans=ans+data[i];
        return ans;
    }
};
int main() {
    freopen("/Users/xcm/xcmprogram/netlesson/pa3/in.txt","r",stdin);
    //freopen("/Users/xcm/xcmprogram/netlesson/pa3/out.txt","w",stdout);
    int t;
    cin >> t;
    while( t -- ) {
        int b1[10];
        for(int i = 0;i < 10; ++i)

            cin >> b1[i];
        A<int, 10> a1 = b1;
        cout << a1[2] << endl;


        double b2[5] ;
        for(int i = 0;i < 5; ++i)
            cin >> b2[i];

        A<double, 5> a2 = b2;
        cout << a2.sum() << endl;


        string b3[4] ;
        for(int i = 0;i < 4; ++i)
            cin >> b3[i];

        A<string, 4> a3 = b3;
        cout << a3.sum() << endl;
    }
    return 0;
}