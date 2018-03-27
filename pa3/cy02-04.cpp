/*
 程序设计实习MOOC /程序设计与算法（三）第二周测验(2018春季)
 004:哪来的输出
 write by xucaimao,2018-03-27,AC
*/
#include <iostream>
using namespace std;
class A {
public:
    int i;
    A(int x) { i = x; }
// 在此处补充你的代码
    ~A(){
        printf("%d\n",i);
    }
};
int main()
{
    A a(1);
    A * pa = new A(2);
    delete pa;
    return 0;
}