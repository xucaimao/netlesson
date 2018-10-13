/*
 程序设计实习MOOC /程序设计与算法（三）第六周测验(2018秋季)
 1:看上去像多态
 write by xucaimao,2018-10-10,AC at 2018-10-10
*/

#include <iostream>
using namespace std;
class B {
private:
    int nBVal;
public:
    void Print()
    { cout << "nBVal="<< nBVal << endl; }
    void Fun()
    {cout << "B::Fun" << endl; }
    B ( int n ) { nBVal = n;}
};
// 在此处补充你的代码
class D:public B
{
private:
    int nDVal;
public:
    D(int n) :B(3*n),nDVal(n){}
    void Fun()
    {
        cout << "D::Fun" << endl;
    }
    void Print()
    {
        B::Print();
        cout << "nDVal=" << nDVal << endl;
    }
};

int main() {
    B * pb;
    D * pd;
    D d(4);         //debug发现，此时d={ B{nBval=12}, nDval=4}
    //也就是说class D 虽然没有明显声明一个B类型的变量，但是D的构造函数中显示声明了B的初始化
    d.Fun();        //output: D::Fun,D的Fun()覆盖了B的Fun()
    pb = new B(2);
    pb -> Fun();    //output: B::Fun
    pd = new D(8);
    pd->Fun();      //output: D::Fun,D的Fun()覆盖了B的Fun()
    pb->Print ();   //output: nBval=2
    pd->Print ();   //output: nBval=24
    //output: nDval=8
    //D的Print()覆盖了B的Print()
    pb = & d;       //pb是B*类型，会执行B里面定义的相应函数，这也是多态的基础特征
    pb->Fun();      //output: B::Fun
    pb->Print();    //仍然运行B::Print()
    return 0;
}