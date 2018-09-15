//
// Created by xcm on 2018/9/14.
//

//复数类

#include <iostream>
using namespace std;

class Complex{
private:
    double real,image;
public:
    //构造函数，也是类型转换函数
    Complex(double r=0,double i=0):real{r},image{i} {}
    //复制构造函数
    Complex(const Complex & c):real{c.real},image{c.image}{}
    void print(){
        cout<<real<<" + "<<image<<"i"<<endl;
    }
    //重载加法运算符，采用传值形式返回值
    friend Complex operator + (const Complex & a, const Complex & b);
    //重载输出流，采用传引用形式返回，可以作为左值
    friend ostream & operator <<(ostream & os,const Complex & c);
    friend istream & operator >>(istream & is,const Complex & c);
};

//因为需要在外部操作Complex对象的成员，所以需要采用友元
Complex operator + (const Complex & a, const Complex & b){
    Complex t;
    t.real=a.real+b.real;
    t.image=a.image+b.image;
    return  t;
}

ostream & operator <<(ostream & os,const Complex & c){
    os<<c.real<<"+"<<c.image<<"i";
    return os;
}

int main() {
    Complex a(2, 3), b(1, 4);
    Complex c = a + b;
    cout << c << endl;
    c.print();
    Complex d = 2 + a;
    d.print();
    Complex e = b + 4;
    e.print();
    return 0;
}