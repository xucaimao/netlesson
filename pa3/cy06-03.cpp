/*
 程序设计实习MOOC /程序设计与算法（三）第六周测验(2018秋季)
 3:这是什么鬼delete
 write by xucaimao,2018-10-10,AC at 2018-10-10
*/

#include <iostream>
using namespace std;
class A
{
public:
    A() { }
// 在此处补充你的代码
    virtual ~A(){
        cout << "destructor A" << endl;
    }
};
class B:public A {
public:
    ~B() { cout << "destructor B" << endl; }
};
int main()
{
    A * pa;
    pa = new B;
    delete pa;  //pa指向B类型的元素
    return 0;
}