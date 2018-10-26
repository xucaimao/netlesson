/*
 程序设计实习MOOC /程序设计与算法（三）第八周测验(2018秋季)
 4:函数对象的过滤器
 write by xucaimao,2018-10-25
 非常神奇的函数对象,
*/
#include <iostream>
#include <vector>
using namespace std;


struct A {
    int v;
    A() { }
    A(int n):v(n) { };
    bool operator<(const A & a) const {
        return v < a.v;
    }
};
// 在此处补充你的代码
template <class T>
class FilterClass{
private:
    T m,n;
public:
    FilterClass(int m_,int n_):m(m_),n(n_){}
    bool operator()(T a){
        //因为class A只重载了<运算符，所以这里也只能用<进行比较
        return ( m < a && a < n );
    }
};

template <class T>
void Print(T s,T e)
{
    for(;s!=e; ++s)
        cout << *s << ",";
    cout << endl;
}
template <class T1, class T2,class T3>
T2 Filter( T1 s,T1 e, T2 s2, T3 op)
{
    for(;s != e; ++s) {
        if( op(*s)) {
            * s2 = * s;
            ++s2;
        }
    }
    return s2;
}

ostream & operator <<(ostream & o,A & a)
{
    o << a.v;
    return o;
}
vector<int> ia;
vector<A> aa;
int main()
{
    freopen("/Users/xcm/xcmprogram/netlesson/pa3/in.txt","r",stdin);
    int m,n;
    while(cin >> m >> n) {
        ia.clear();
        aa.clear();
        int k,tmp;
        cin >> k;
        for(int i = 0;i < k; ++i) {
            cin >> tmp;
            ia.push_back(tmp);
            aa.push_back(tmp);
        }
        vector<int> ib(k);
        vector<A> ab(k);
        vector<int>::iterator p =  Filter(ia.begin(),ia.end(),ib.begin(),FilterClass<int>(m,n));
        Print(ib.begin(),p);
        vector<A>::iterator pp = Filter(aa.begin(),aa.end(),ab.begin(),FilterClass<A>(m,n));
        Print(ab.begin(),pp);

    }
    return 0;
}