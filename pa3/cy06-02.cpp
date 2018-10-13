/*
 程序设计实习MOOC /程序设计与算法（三）第六周测验(2018秋季)
 2:Fun和Do
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
    void Do()
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
void Call(B &p) {
    p.Fun();    //类B中没有定义Fun(),此时会执行从A继承的Fun()
    p.Do();     //基类B中，Do定义为virtual,此时p指向C类型，所以执行C::Do()
}
int main() {
    C c;
    Call( c);
    return 0;
}