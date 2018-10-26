/*
 程序设计实习MOOC /程序设计与算法（三）第八周测验(2018秋季)
 2:按距离排序
 write by xucaimao,2018-10-24
 非常神奇的函数对象,
*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
template <class T1,class T2>
struct Closer {
// 在此处补充你的代码
private:
    T1 n;
    T2 op;
public:
    Closer(T1 n_,T2 op_):n(n_),op(op_){}
    bool operator()(T1 &a,T1 &b){
        if( op(n,a)<op(n,b) )
            return true;
        else if( op(n,a)==op(n,b) && a<b )
            return true;
        else
            return false;
    }
};

int Distance1(int n1,int n2) {
    return abs(n1-n2);
}
int Distance2(const string & s1, const string & s2)
{
    return abs((int)s1.length()- (int) s2.length());
}
int a[10] = { 0,3,1,4,7,9,20,8,10,15};
string b[6] = {"American","Jack","To","Peking","abcdefghijklmnop","123456789"};
int main()
{
    freopen("/Users/xcm/xcmprogram/netlesson/pa3/in.txt","r",stdin);
    int n;string s;
    while( cin >> n >> s ) {
        sort(a,a+10,Closer<int ,int (*)(int ,int)> (n,Distance1));
        for(int i = 0;i < 10; ++i)
            cout << a[i] << "," ;
        cout << endl;
        sort(b,b+6,Closer<string,int (*)(const string &,const string &  )> (s,Distance2));
        for(int i = 0;i < 6; ++i)
            cout << b[i] << "," ;
        cout << endl;
    }
    return 0;
}