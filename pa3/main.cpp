/*
程序拷贝进来编译执行
 //TODO
*/

#include <iostream>
using namespace std;

struct A
{
    int v;
    A(int vv):v(vv) { }
    const A *  getPointer()const {
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
    p->v++;
    return 0;
}