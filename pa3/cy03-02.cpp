/*
 程序设计实习MOOC /程序设计与算法（三）第三周测验(2018春季)
 2:Big & Base 封闭类问题
 write by xucaimao,2018-04-03,AC
*/

#include <iostream>
#include <string>
using namespace std;
class Base {
public:
    int k;
    Base(int n):k{n} { }
};
class Big
{
public:
    int v;
    Base b;
    //如果不在Big类的初始化列表中指定b的初始化方法，这里就会默认采用Base类的无参构造函数
    //但是Base类没有定义无参构造函数，从而导致程序出错
    //成员变量是另外一个类，这个类叫做封闭(enclosing)类
    //本例中，Big类包含了一个Base类的成员b
    //任何生成封闭类对象的语句，都要让编译器明白，对象中的成员对象是如何初始化的
    //具体做法就是，通过封闭类的构造函数初始化列表，来进行成员对象的初始

// 在此处补充你的代码
    Big(int n):v{n},b{ Base(n) }{}
};
int main()
{
    freopen("/Users/xcm/xcmprogram/netlesson/pa3/in.txt","r",stdin);
    int n;
    while(cin >>n) {
        Big a1(n);
        Big a2 = a1;
        cout << a1.v << "," << a1.b.k << endl;
        cout << a2.v << "," << a2.b.k << endl;
    }
}