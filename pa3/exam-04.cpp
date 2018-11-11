// 程序设计与算法（三）期末考试(2018秋季)
// 004:编程填空：MyClass
// Created by Administrator on 2018-11-10.
// 考察虚函数、类继承中基类的初始化
// 补充下列代码，使得程序的输出为：
// A:3
// A:15
// B:5
// 3
// 15
// 5
#include <iostream>
using namespace std;
class CMyClassA {
    int val;
public:
    CMyClassA(int);
    void virtual print();
};
CMyClassA::CMyClassA(int arg) {
    val = arg;
    printf("A:%d\n", val);
}
void CMyClassA::print() {
    printf("%d\n", val);
    return;
}
// 在此处补充你的代码

class CMyClassB:public CMyClassA{
private:
    int valb;
public:
    //此处基类的初始化是重点
    CMyClassB(int v):CMyClassA(15),valb(v){
        printf("B:%d\n", valb);
    }
    void print() {
        printf("%d\n", valb);
        return;
    }
};

int main(int argc, char** argv) {
    CMyClassA a(3), *ptr;
    CMyClassB b(5);
    ptr = &a;
    ptr->print();   //3
    a = b;
    a.print();      //15
    ptr = &b;
    ptr->print();   //5
    return 0;
}