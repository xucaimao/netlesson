/*
 程序设计实习MOOC /程序设计与算法（三）第六周测验(2018秋季)
 4:怎么又是Fun和Do
 write by xucaimao,2018-10-10,AC at 2018-10-10
*/

#include <iostream>
using namespace std;
class A {
private:
    int nVal;
public:
    void Fun()
    { cout << "A::Fun" << endl; };
    virtual void Do()
    { cout << "A::Do" << endl; }
};
class B:public A {
public:
    virtual void Do()
    { cout << "B::Do" << endl;}
};
class C:public B {
public:
    void Do( )
    { cout <<"C::Do"<<endl; }
    void Fun()
    { cout << "C::Fun" << endl; }
};
void Call(A* p) {
    p->Fun(); p->Do();
}
int main() {
    Call( new A());
    Call( new C());
    return 0;
}