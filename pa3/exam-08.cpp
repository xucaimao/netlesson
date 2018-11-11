// 程序设计与算法（三）期末考试(2018秋季)
// 008:编程填空：还是Fun和Do
// Created by Administrator on 2018-11-10.
//填写代码，使输出结果为
//A::Fun
//B::Do
//C::Fun
//C::Do
//A::Fun
//B::Do
//
#include <iostream>
using namespace std;

class A {
public:
    virtual void Fun() {
        cout << "A::Fun" << endl;
    };
    virtual void Do() {
        cout << "A::Do" << endl;
    }
};
// 在此处补充你的代码

class B:public A{
public:
    void Do() {
        cout << "B::Do" << endl;
    }
};
class C:public B{
public:
    virtual void Fun() {
        cout << "C::Fun" << endl;
    };
    virtual void Do() {
        cout << "C::Do" << endl;
    }
};
//这里的&很关键，没有的话，这个p就是执行A类型的了
void Call1(A &p)
{
    p.Fun();
    p.Do();
}

void Call2(B p) {
    p.Fun();
    p.Do();
}



int main() {
    C c;
    B b;
    Call1(b);
    Call1(c);
    Call2(c);
    return 0;
}