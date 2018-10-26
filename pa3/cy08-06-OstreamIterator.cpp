/*
 程序设计实习MOOC /程序设计与算法（三）第八周测验(2018秋季)
 6:我自己的 ostream_iterator
 write by xucaimao,2018-10-25
*/
#include <iostream>
#include <list>
#include <string>
using namespace std;

template <class T1,class T2>
void Copy(T1 s,T1 e, T2 x)
{
    for(; s != e; ++s,++x)
        *x = *s;
}


template<class T>
class myostream_iteraotr
{
// 在此处补充你的代码
//main中output定义了构造函数的参数和类型
//Copy中列出了T2（也就是本类）需重载的运算符（左++、*、=）
//对于 *x=*s ，先执行operator*,再执行operator=
private:
    string s;
    ostream & os;
public:
    myostream_iteraotr(ostream & os_,string s_):os(os_),s(s_){}

    myostream_iteraotr<T>& operator++(){
        return *this;
    }
    myostream_iteraotr<T>& operator*(){
        return *this;
    }
    myostream_iteraotr<T>& operator=(T a){
        os<<a<<s;
        return *this;
    }
};


int main()
{	const int SIZE = 5;
    int a[SIZE] = {5,21,14,2,3};
    double b[SIZE] = { 1.4, 5.56,3.2,98.3,3.3};
    list<int> lst(a,a+SIZE);
    myostream_iteraotr<int> output(cout,",");
    Copy( lst.begin(),lst.end(),output);
    cout << endl;
    myostream_iteraotr<double> output2(cout,"--");
    Copy(b,b+SIZE,output2);
    return 0;
}