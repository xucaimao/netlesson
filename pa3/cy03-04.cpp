/*
 程序设计实习MOOC /程序设计与算法（三）第三周测验(2018春季)
 4:这个指针哪来的
 write by xucaimao,2018-04-03,AC
*/
//主要考察const 的运用
//const放在后面，说明该函数是常量成员函数，此时不能调用非常量的成员变量和成员函数
//const放在前面，说明返回值是一个常量，主要是用于类型匹配

#include <iostream>
using namespace std;

struct A
{
    int v;
    A(int vv):v(vv) { }
    const A *  getPointer(){
        return this;
//      const A& p=*this;
//      return &p;
    }
// 在此处补充你的代码
};

int main()
{
    const A a(10);
    const A * p = a.getPointer();
    cout << p->v << endl;
    p->v++;//p是const A * 类型，如果这样写编译会报错

    return 0;
}