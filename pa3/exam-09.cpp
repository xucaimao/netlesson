// 程序设计与算法（三）期末考试(2018秋季)
// 009:编程填空：简单的对象
// Created by Administrator on 2018-11-11.
// 考察：const对象只能调用const成员函数
/*
程序填空，使得程序输出:
2
1
1
0
 * */
#include <iostream>
using namespace std;
class A
{
    static int num;
public:
    A(){num+=1;}
    void func()
    {
        cout<< num <<endl;
    }
// 在此处补充你的代码
    void func() const{
        cout<< --num <<endl;
    }
};

int A::num=1;

int main()
{
    A a1;               //A::num=2
    const A a2 = a1;    //a2 const
    A & a3 = a1;        //a3-->a1
    const A & a4 = a1;  //a4(const)-->a1

    a1.func();          //调用func()显示num
    a2.func();          //调用func()const,--num并显示
    a3.func();          //调用func()显示num
    a4.func();          //调用func()const,--num并显示

    return 0;
}