/*
 程序设计实习MOOC /程序设计与算法（三）第八周测验(2018秋季)
 1:goodcopy
 write by xucaimao,2018-10-24
 考察的重点是倒序拷贝
*/

#include <iostream>
using namespace std;


template <class T>
struct GoodCopy {
// 在此处补充你的代码
public:
    void operator()(T* s,T* e,T* t){
        T* nt=t+(e-s);
        for(;e>=s;e--,nt--)
            *nt=*e;
    }
};

int a[10];
int b[10];
string c[200];
string d[200];

template <class T>
void Print(T s,T e) {
    for(; s != e; ++s)
        cout << * s << ",";
    cout << endl;
}

int main()
{
    freopen("/Users/xcm/xcmprogram/netlesson/pa3/in.txt","r",stdin);
    int t;
    cin >> t;
    while( t -- ) {
        int m ;
        cin >> m;
        for(int i = 0;i < m; ++i)   //输入整数
            cin >> a[i];
        GoodCopy<int>()(a,a+m,b);
        Print(b,b+m);
        GoodCopy<int>()(a,a+m,a+m/2);
        Print(a+m/2,a+m/2 + m);

        for(int i = 0;i < m; ++i)   //输入字符串
            cin >> c[i];
        GoodCopy<string>()(c,c+m,d);
        Print(c,c+m);
        GoodCopy<string>()(c,c+m,c+m/2);
        Print(c+m/2,c+m/2 + m);
    }
    return 0;
}